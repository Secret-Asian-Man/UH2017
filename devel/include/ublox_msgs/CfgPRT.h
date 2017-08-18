// Generated by gencpp from file ublox_msgs/CfgPRT.msg
// DO NOT EDIT!


#ifndef UBLOX_MSGS_MESSAGE_CFGPRT_H
#define UBLOX_MSGS_MESSAGE_CFGPRT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ublox_msgs
{
template <class ContainerAllocator>
struct CfgPRT_
{
  typedef CfgPRT_<ContainerAllocator> Type;

  CfgPRT_()
    : portID(0)
    , reserved0(0)
    , txReady(0)
    , mode(0)
    , baudRate(0)
    , inProtoMask(0)
    , outProtoMask(0)
    , reserved4(0)
    , reserved5(0)  {
    }
  CfgPRT_(const ContainerAllocator& _alloc)
    : portID(0)
    , reserved0(0)
    , txReady(0)
    , mode(0)
    , baudRate(0)
    , inProtoMask(0)
    , outProtoMask(0)
    , reserved4(0)
    , reserved5(0)  {
  (void)_alloc;
    }



   typedef uint8_t _portID_type;
  _portID_type portID;

   typedef uint8_t _reserved0_type;
  _reserved0_type reserved0;

   typedef uint16_t _txReady_type;
  _txReady_type txReady;

   typedef uint32_t _mode_type;
  _mode_type mode;

   typedef uint32_t _baudRate_type;
  _baudRate_type baudRate;

   typedef uint16_t _inProtoMask_type;
  _inProtoMask_type inProtoMask;

   typedef uint16_t _outProtoMask_type;
  _outProtoMask_type outProtoMask;

   typedef uint16_t _reserved4_type;
  _reserved4_type reserved4;

   typedef uint16_t _reserved5_type;
  _reserved5_type reserved5;


    enum { CLASS_ID = 6u };
     enum { MESSAGE_ID = 0u };
     enum { PORT_ID_UART1 = 1u };
     enum { PORT_ID_UART2 = 2u };
     enum { PORT_ID_USB = 3u };
     enum { TX_READY_EN = 1u };
     enum { TX_READY_POLARITY_HIGH_ACTIVE = 0u };
     enum { TX_READY_POLARITY_LOW_ACTIVE = 2u };
     enum { TX_READY_PIN_SHIFT = 2u };
     enum { TX_READY_PIN_MASK = 124u };
     enum { TX_READY_THRES_SHIFT = 7u };
     enum { TX_READY_THRES_MASK = 65408u };
     enum { MODE_RESERVED1 = 16u };
     enum { MODE_CHAR_LEN_MASK = 192u };
     enum { MODE_CHAR_LEN_5BIT = 0u };
     enum { MODE_CHAR_LEN_6BIT = 64u };
     enum { MODE_CHAR_LEN_7BIT = 128u };
     enum { MODE_CHAR_LEN_8BIT = 192u };
     enum { MODE_PARITY_MASK = 3584u };
     enum { MODE_PARITY_EVEN = 0u };
     enum { MODE_PARITY_ODD = 512u };
     enum { MODE_PARITY_NO = 2048u };
     enum { MODE_STOP_BITS_MASK = 12288u };
     enum { MODE_STOP_BITS_1 = 0u };
     enum { MODE_STOP_BITS_15 = 4096u };
     enum { MODE_STOP_BITS_2 = 8192u };
     enum { MODE_STOP_BITS_05 = 12288u };
     enum { PROTO_UBX = 1u };
     enum { PROTO_NMEA = 2u };
     enum { PROTO_RTCM = 4u };
 

  typedef boost::shared_ptr< ::ublox_msgs::CfgPRT_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ublox_msgs::CfgPRT_<ContainerAllocator> const> ConstPtr;

}; // struct CfgPRT_

typedef ::ublox_msgs::CfgPRT_<std::allocator<void> > CfgPRT;

typedef boost::shared_ptr< ::ublox_msgs::CfgPRT > CfgPRTPtr;
typedef boost::shared_ptr< ::ublox_msgs::CfgPRT const> CfgPRTConstPtr;

// constants requiring out of line definition

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ublox_msgs::CfgPRT_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ublox_msgs::CfgPRT_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ublox_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'ublox_msgs': ['/home/swarmie/rover_workspace/src/ublox/ublox_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ublox_msgs::CfgPRT_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ublox_msgs::CfgPRT_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::CfgPRT_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::CfgPRT_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::CfgPRT_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::CfgPRT_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ublox_msgs::CfgPRT_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3679d3ad278d5329fb8543226a55acca";
  }

  static const char* value(const ::ublox_msgs::CfgPRT_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3679d3ad278d5329ULL;
  static const uint64_t static_value2 = 0xfb8543226a55accaULL;
};

template<class ContainerAllocator>
struct DataType< ::ublox_msgs::CfgPRT_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ublox_msgs/CfgPRT";
  }

  static const char* value(const ::ublox_msgs::CfgPRT_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ublox_msgs::CfgPRT_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# CFG-PRT (0x06 0x00)\n\
# Port Configuration for UART\n\
#\n\
# Several configurations can be concatenated to one input message. In this case the payload\n\
# length can be a multiple of the normal length (see the other versions of CFG-PRT). Output\n\
# messages from the module contain only one configuration unit.\n\
#\n\
\n\
uint8 CLASS_ID = 6\n\
uint8 MESSAGE_ID = 0\n\
\n\
uint8 portID              # Port Identifier Number (= 1 or 2 for UART ports)\n\
uint8 PORT_ID_UART1 = 1\n\
uint8 PORT_ID_UART2 = 2\n\
uint8 PORT_ID_USB = 3\n\
\n\
uint8 reserved0           # Reserved\n\
\n\
uint16 txReady            # reserved (Alwyas set to zero) up to Firmware 7.01,\n\
                          # TX ready PIN configuration (since Firmware 7.01)\n\
uint16 TX_READY_EN = 1                    # Enable TX ready feature for this port\n\
uint16 TX_READY_POLARITY_HIGH_ACTIVE = 0  # Polarity High-active\n\
uint16 TX_READY_POLARITY_LOW_ACTIVE = 2   # Polarity Low-active\n\
uint16 TX_READY_PIN_SHIFT = 2             # PIO to be used (must not be in use already by another function)\n\
uint16 TX_READY_PIN_MASK = 124            #\n\
uint16 TX_READY_THRES_SHIFT = 7           # Threshold\n\
uint16 TX_READY_THRES_MASK = 65408        # The given threshold is multiplied by 8 bytes.\n\
                                          # The TX ready PIN goes active after >= thres*8 bytes are pending for the port and going inactive after the last\n\
                                          # pending bytes have been written to hardware (0-4 bytes before end of stream).\n\
\n\
uint32 mode               # A bit mask describing the UART mode\n\
uint32 MODE_RESERVED1 = 16                # Default 1 for compatibility with A4\n\
uint32 MODE_CHAR_LEN_MASK = 192           # Character Length\n\
uint32 MODE_CHAR_LEN_5BIT = 0               # 5bit (not supported)\n\
uint32 MODE_CHAR_LEN_6BIT = 64              # 6bit (not supported)\n\
uint32 MODE_CHAR_LEN_7BIT = 128             # 7bit (supported only with parity)\n\
uint32 MODE_CHAR_LEN_8BIT = 192             # 8bit\n\
uint32 MODE_PARITY_MASK = 3584            #\n\
uint32 MODE_PARITY_EVEN = 0                 # Even Parity\n\
uint32 MODE_PARITY_ODD = 512                # Odd Parity\n\
uint32 MODE_PARITY_NO = 2048                # No Parity\n\
uint32 MODE_STOP_BITS_MASK = 12288        # Number of Stop Bits\n\
uint32 MODE_STOP_BITS_1 = 0                 # 1 Stop Bit\n\
uint32 MODE_STOP_BITS_15 = 4096             # 1.5 Stop Bit\n\
uint32 MODE_STOP_BITS_2 = 8192              # 2 Stop Bit\n\
uint32 MODE_STOP_BITS_05 = 12288            # 0.5 Stop Bit\n\
\n\
uint32 baudRate           # Baudrate in bits/second [bits/s]\n\
\n\
uint16 inProtoMask        # A mask describing which input protocols are active.\n\
                          # Each bit of this mask is used for a protocol.\n\
                          # Through that, multiple protocols can be defined\n\
                          # on a single port.\n\
\n\
uint16 outProtoMask       # A mask describing which output protocols are active.\n\
                          # Each bit of this mask is used for a protocol.\n\
                          # Through that, multiple protocols can be defined\n\
                          # on a single port.\n\
\n\
uint16 PROTO_UBX = 1\n\
uint16 PROTO_NMEA = 2\n\
uint16 PROTO_RTCM = 4\n\
\n\
uint16 reserved4          # Always set to zero\n\
uint16 reserved5          # Always set to zero\n\
";
  }

  static const char* value(const ::ublox_msgs::CfgPRT_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ublox_msgs::CfgPRT_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.portID);
      stream.next(m.reserved0);
      stream.next(m.txReady);
      stream.next(m.mode);
      stream.next(m.baudRate);
      stream.next(m.inProtoMask);
      stream.next(m.outProtoMask);
      stream.next(m.reserved4);
      stream.next(m.reserved5);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CfgPRT_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ublox_msgs::CfgPRT_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ublox_msgs::CfgPRT_<ContainerAllocator>& v)
  {
    s << indent << "portID: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.portID);
    s << indent << "reserved0: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.reserved0);
    s << indent << "txReady: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.txReady);
    s << indent << "mode: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.mode);
    s << indent << "baudRate: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.baudRate);
    s << indent << "inProtoMask: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.inProtoMask);
    s << indent << "outProtoMask: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.outProtoMask);
    s << indent << "reserved4: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.reserved4);
    s << indent << "reserved5: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.reserved5);
  }
};

} // namespace message_operations
} // namespace ros

#endif // UBLOX_MSGS_MESSAGE_CFGPRT_H