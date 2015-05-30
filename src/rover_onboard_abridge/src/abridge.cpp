/*
 * Author: Karl A. Stolleis
 * Maintainer: Karl A. Stolleis
 * Email: karl.a.stolleis@nasa.gov; kurt.leucht@nasa.gov
 * NASA Center: Kennedy Space Center
 * Mail Stop: NE-C1
 * 
 * Project Name: Swarmie Robotics NASA Center Innovation Fund
 * Principal Investigator: Cheryle Mako
 * Email: cheryle.l.mako@nasa.gov
 * 
 * Date Created: June 6, 2014
 * Safety Critical: NO
 * NASA Software Classification: D
 * 
 * This software is copyright the National Aeronautics and Space Administration (NASA)
 * and is distributed under the GNU LGPL license.  All rights reserved.
 * Permission to use, copy, modify and distribute this software is granted under
 * the LGPL and there is no implied warranty for this software.  This software is provided
 * "as is" and NASA or the authors are not responsible for indirect or direct damage
 * to any user of the software.  The authors and NASA are under no obligation to provide
 * maintenence, updates, support or modifications to the software.
 * 
 * Revision Log:
 *      
 */

#include <string.h>
#include <unistd.h>  
#include <sstream>
#include <vector>
#include <usbSerial.h>
#include <math.h>

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/UInt64.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Quaternion.h>
#include <sensor_msgs/Range.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/NavSatFix.h>
#include <tf/transform_datatypes.h>
#include <tf/tf.h>
//#include <nav_msgs/Odometry.h>

using namespace std;

#ifndef M_PI
    const double M_PI = 3.14159265358979323846264338327950288419716939937510582;
#endif

void cmdHandler(const geometry_msgs::Twist::ConstPtr& message);
//void teleopHBHandler(const std_msgs::UInt64::ConstPtr& message);
//void updateHB(const ros::TimerEvent& e);
void serialActivityTimer(const ros::TimerEvent& e);
void publishRosTopics();
//void updateOdometry();
void parseData(string data);

char host[128];
char delimiter = ',';
vector<string> dataSet;
//long serverHB = 0;
//long internalHB = 0;

USBSerial usb;
char port[] = "/dev/ttyUSB0";
const int baud = 115200;
char dataCmd[] = "d\n";
char moveCmd[16];

std_msgs::String rtime;
std_msgs::String status;
sensor_msgs::Range usLeft;
sensor_msgs::Range usCenter;
sensor_msgs::Range usRight;
sensor_msgs::Imu imu;
sensor_msgs::NavSatFix gps;
//nav_msgs::Odometry odometry;

ros::Subscriber moveSubscriber;

//ros::Subscriber hbSubscriber;
//ros::Timer hbTimer;

ros::Publisher imuPublish;
ros::Publisher gpsPublish;
ros::Publisher usLeftPublish;
ros::Publisher usCenterPublish;
ros::Publisher usRightPublish;
ros::Publisher timePublish;
ros::Publisher statusPublish;
//ros::Publisher odometryPublish;
//ros::Publisher wheelOdomPublish;
ros::Timer publishTimer;

//double x = 0.0; //imu calculated position
//double y = 0.0; //imu calculated position
//double wX = 0.0; //wheel dead reckoned position
//double wY = 0.0; //wheel dead reckoned position
//double wTh = 0.0;
//double th = 0.0;
//double vx = 0.1;
//double vy = -0.1;
//double vth = 0.1;
float linearSpeed = 0;
float turnSpeed = 0;

const float deltaTime = 0.25; //delta t, in seconds

int main(int argc, char **argv) {

    gethostname(host, sizeof (host));
    string hostname(host);
    string publishedName;

    ros::init(argc, argv, (hostname + "_ABRIDGE"));
    usb.openUSBPort(port, baud);

    sleep(5);

    ros::NodeHandle aNH;
    
    if (argc >= 2) {
        publishedName = argv[1];
        cout << "Welcome to the world of tomorrow " << publishedName << "!  ABridge module started." << endl;
    } else {
        publishedName = hostname;
        cout << "No Name Selected. Default is: " << publishedName << endl;
    }

    moveSubscriber = aNH.subscribe((publishedName + "/mobility"), 10, cmdHandler);
    //hbSubscriber = aNH.subscribe((publishedName + "/teleop/heartbeat"), 10, teleopHBHandler);
    //hbTimer = aNH.createTimer(ros::Duration(1.0), updateHB);

    imuPublish = aNH.advertise<sensor_msgs::Imu>((publishedName + "/imu"), 10);
    gpsPublish = aNH.advertise<sensor_msgs::NavSatFix>((publishedName + "/gps"), 10);
    timePublish = aNH.advertise<std_msgs::String>((publishedName + "/time"), 1);
    statusPublish = aNH.advertise<std_msgs::String>((publishedName + "/status"), 1);
    //odometryPublish = aNH.advertise<nav_msgs::Odometry>((publishedName + "/odom"), 1);
    //wheelOdomPublish = aNH.advertise<nav_msgs::Odometry>((publishedName + "/wheelOdom"), 1);
    publishTimer = aNH.createTimer(ros::Duration(deltaTime), serialActivityTimer);
    
    usLeftPublish = aNH.advertise<sensor_msgs::Range>((publishedName + "/USLeft"), 10);
    usCenterPublish = aNH.advertise<sensor_msgs::Range>((publishedName + "/USCenter"), 10);
    usRightPublish = aNH.advertise<sensor_msgs::Range>((publishedName + "/USRight"), 10);
    
    usLeft.radiation_type = 0;
    usLeft.field_of_view = 55;
    usCenter.radiation_type = 0;
    usCenter.field_of_view = 55;
    usRight.radiation_type = 0;
    usRight.field_of_view = 55;
    
    status.data = "INITIALIZED";

    //while (ros::ok()) {
       ros::spin();
    //}

    return EXIT_SUCCESS;
}

//void teleopHBHandler(const std_msgs::UInt64::ConstPtr& message) {
//    serverHB = message->data;
//    internalHB = serverHB;
//}

//void updateHB(const ros::TimerEvent& e) {
//    //if (serverHB < (internalHB - 5)) {
//        //cout << "stop" << endl;
//        sprintf(moveCmd, "s\n");
//        usb.sendData(moveCmd);
//        //cout << "                       STOP TIMEOUT" << endl;
//    //}
//    internalHB++;
//}

void cmdHandler(const geometry_msgs::Twist::ConstPtr& message) {
    //cout << "MOVE COMMAND" << endl;

    // remove artificial factor that was multiplied for simulation. this scales it back down to -1.0 to +1.0
    linearSpeed = (message->linear.x) / 1.5;
    turnSpeed = (message->angular.z) / 8;
    
//TODO: Remove unnecessary code below
    if (linearSpeed < 0) {
        sprintf(moveCmd, "m,%d,%d\n", (int) (linearSpeed * 255), (int) (linearSpeed * 255));
        usb.sendData(moveCmd);
        //cout << "forward" << endl;
    } else if (linearSpeed > 0) {
        sprintf(moveCmd, "m,%d,%d\n", (int) (linearSpeed * 255), (int) (linearSpeed * 255));
        usb.sendData(moveCmd);
        //cout << "back" << endl;
    } else if (turnSpeed > 0) {
        sprintf(moveCmd, "t,%d\n", (int) (turnSpeed * 255));
        usb.sendData(moveCmd);
        //cout << "left" << endl;
    } else if (turnSpeed < 0) {
        sprintf(moveCmd, "t,%d\n", (int) (turnSpeed * 255));
        usb.sendData(moveCmd);
        //cout << "right" << endl;
    } else if (turnSpeed == 0 || linearSpeed == 0) {
        sprintf(moveCmd, "s\n");
        usb.sendData(moveCmd);
        //cout << "STOP" << endl;
    }
    memset(&moveCmd, '\0', sizeof (moveCmd));
}

void serialActivityTimer(const ros::TimerEvent& e) {
    usb.sendData(dataCmd);
    parseData(usb.readData());
    //updateOdometry();
    //status.data = "ONLINE";
    publishRosTopics();
}

void publishRosTopics() {
    timePublish.publish(rtime);
    usLeftPublish.publish(usLeft);
    usCenterPublish.publish(usCenter);
    usRightPublish.publish(usRight);
    imuPublish.publish(imu);
    gpsPublish.publish(gps);
    statusPublish.publish(status);
    //odometryPublish.publish(odometry);
}

void parseData(string str) {
    istringstream oss(str);
    string word;
    while (getline(oss, word, delimiter)) {
        dataSet.push_back(word);
    }
    if (dataSet.size() >= 14) {
        rtime.data = dataSet.at(0);
        gps.latitude = atof(dataSet.at(1).c_str())*100;
        gps.longitude = atof(dataSet.at(2).c_str())*100;
        imu.orientation = tf::createQuaternionMsgFromYaw(atof(dataSet.at(3).c_str()) * M_PI / 180.0);
        imu.orientation.z = fmod(-1 * imu.orientation.z, 360.0);
        imu.angular_velocity.x = atof(dataSet.at(4).c_str());
        imu.angular_velocity.y = atof(dataSet.at(5).c_str());
        imu.angular_velocity.z = atof(dataSet.at(6).c_str());
        imu.linear_acceleration.x = atof(dataSet.at(7).c_str());
        imu.linear_acceleration.y = atof(dataSet.at(8).c_str());
        imu.linear_acceleration.z = atof(dataSet.at(9).c_str());
        usCenter.range = atof(dataSet.at(10).c_str()) / 100.0;
        usLeft.range = atof(dataSet.at(11).c_str()) / 100.0;
        usRight.range = atof(dataSet.at(12).c_str()) / 100.0;
        int gpsStatus = (int) atof(dataSet.at(13).c_str());
        if(gpsStatus <= 0){
            gps.status.STATUS_NO_FIX; // is this a function call?  
        } else {
            gps.status.STATUS_FIX; // is this a function call? 
        }
    	status.data = "ONLINE";
    }
    
    dataSet.clear();
}

/* void updateOdometry() {
    vx += imu.linear_acceleration.x * deltaTime;
    vy += imu.linear_acceleration.y * deltaTime;
    vth = imu.angular_velocity.z;
    
    double delta_x = (vx * cos(th) - vy * sin(th)) * deltaTime;
    double delta_y = (vx * sin(th) + vy * cos(th)) * deltaTime;
    double delta_th = vth * deltaTime;
    
    x += delta_x;
    y += delta_y;
    th += delta_th;
    
    odometry.pose.pose.position.x = x;
    odometry.pose.pose.position.y = y;
    odometry.pose.pose.position.z = 0.0;
    odometry.pose.pose.orientation = tf::createQuaternionMsgFromYaw(th);
    odometry.twist.twist.linear.x = vx;
    odometry.twist.twist.linear.y = vy;
    odometry.twist.twist.angular.z = vth;
    
    odometryPublish.publish(odometry);
    
    //Estimate position from wheel spin
    delta_x = linearSpeed * cos(th) * deltaTime;
    delta_y = linearSpeed * sin(th) * deltaTime;
    delta_th = turnSpeed * deltaTime;
    
    wX += delta_x;
    wY += delta_y;
    wTh += delta_th;
    
    odometry.pose.pose.position.x = wX;
    odometry.pose.pose.position.y = wY;
    odometry.pose.pose.position.z = 0.0;
    odometry.pose.pose.orientation = tf::createQuaternionMsgFromYaw(th);
    odometry.twist.twist.linear.x = linearSpeed;
    odometry.twist.twist.linear.y = 0;
    odometry.twist.twist.angular.z = turnSpeed;
} */