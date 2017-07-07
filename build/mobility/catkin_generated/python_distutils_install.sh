#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/swarmie/rover_workspace/src/mobility"

# snsure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/swarmie/rover_workspace/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/swarmie/rover_workspace/install/lib/python2.7/dist-packages:/home/swarmie/rover_workspace/build/mobility/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/swarmie/rover_workspace/build/mobility" \
    "/usr/bin/python" \
    "/home/swarmie/rover_workspace/src/mobility/setup.py" \
    build --build-base "/home/swarmie/rover_workspace/build/mobility" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/swarmie/rover_workspace/install" --install-scripts="/home/swarmie/rover_workspace/install/bin"
