#!/bin/bash

source /opt/ros/kinetic/setup.bash

roscore &
sleep 4
rosrun scenario3 asker &

bash
