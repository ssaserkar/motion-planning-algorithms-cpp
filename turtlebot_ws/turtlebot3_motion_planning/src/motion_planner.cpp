#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include <chrono>

using namespace std::chrono_literals;

class MotionPlanner : public rclcpp::Node {
public:
    MotionPlanner() : Node("motion_planner") {
        cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
        timer_ = this->create_wall_timer(500ms, std::bind(&MotionPlanner::plan, this));
    }

private:
    void plan() {
        auto message = geometry_msgs::msg::Twist();
        // Basic motion planning logic: move forward
        message.linear.x = 0.2;
        message.angular.z = 0.0;
        cmd_vel_pub_->publish(message);
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MotionPlanner>());
    rclcpp::shutdown();
    return 0;
}

