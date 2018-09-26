FROM ros:kinetic-ros-base-xenial

MAINTAINER Lander Usategui <lander@aliasrobotics.com>

RUN apt-get update && apt-get install -y \
    ros-kinetic-robot=1.3.2-0* \
    && rm -rf /var/lib/apt/lists/*

COPY scenario3-local /root/ros_catkin_ws/src/scenario3

RUN /bin/bash -c "cd /root/ros_catkin_ws \
  && source /opt/ros/kinetic/setup.bash \
  && catkin_make_isolated --install --install-space /opt/ros/kinetic \
  && cd && rm -r /root/ros_catkin_ws"

RUN rm -rf /etc/update-motd.d/* && rm -rf /etc/legal && sed -i 's/\#force_color_prompt=yes/force_color_prompt=yes/' /root/.bashrc

COPY motd /etc/motd

COPY launch_script.bash /root/

RUN echo "cat /etc/motd" >> /root/.bashrc

ENTRYPOINT ["/root/launch_script.bash"]
