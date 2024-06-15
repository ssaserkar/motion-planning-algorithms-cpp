# TurtleBot3 Motion Planning

This project implements various motion planning algorithms for a TurtleBot3 robot using ROS2 and C++. The goal is to navigate the robot through multiple predefined targets while avoiding obstacles detected by its sensors.

## Features
- **Path Planning Algorithms**: Includes implementations of BFS, DFS, A*, Dijkstra, and more.
- **Obstacle Avoidance**: Utilizes sensor data to detect and avoid obstacles dynamically.
- **Multiple Targets**: Defines a sequence of targets for the robot to navigate to.
- **ROS2 Integration**: Fully integrated with ROS2, allowing for easy simulation and testing in Gazebo.

## Installation
1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/turtlebot3_motion_planning.git
   cd turtlebot3_motion_planning
2. **Build the package**:
   ```bash
   cd ~/turtlebot_ws
   colcon build --packages-select turtlebot3_motion_planning
   source install/local_setup.bash

## Usage
1. **Launch TurtleBot3 Simulation**:
   ```bash
   export TURTLEBOT3_MODEL=burger
   ros2 launch turtlebot3_gazebo turtlebot3_world.launch.py
2. **Run the Motion Planner Node**:
   ```bash
   ros2 run turtlebot3_motion_planning motion_planner
