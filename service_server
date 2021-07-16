#include "ros/ros.h"
#include "turtlesim_tutorial/geometry_type.h"
#include "turtlesim/Pose.h"
#include <sstream>
#include "geometry_msgs/Twist.h"

ros::Publisher velocity_publisher;

const double PI = 3.14159265359;
void rotate(double angular_speed, double angle, bool clockwise);
void move(double speed, double distance, bool isForward);
void move_square(double speed,bool clockwise);
void move_circle(double speed, bool clockwise);


// Function provides the service for "geometry_type"
bool move_style(turtlesim_tutorial::geometry_type::Request   &req,
                                 turtlesim_tutorial::geometry_type::Response  &res)
{
	
	res.name = "I'M MOVING";
        ROS_INFO ("request :  speed = %0.2f,  clockwise = %0.2f", (double)req.speed, (double)req.clockwise);
        ROS_INFO ("respone: %s", res.name.c_str());
	move_square((double)req.speed, req.clockwise);
	move_circle((double)req.speed, req.clockwise);
      
}

//Function for rotate turtle
void rotate(double angular_speed, double angle, bool clockwise)
{
	geometry_msgs::Twist vel_msg;

	vel_msg.linear.x = 0;
	vel_msg.linear.y = 0;
	vel_msg.linear.z = 0;

	vel_msg.angular.x = 0;
	vel_msg.angular.y = 0;

	if(clockwise)
		vel_msg.angular.z = -abs(angular_speed);
	else
		vel_msg.angular.z = abs(angular_speed);
	
	double t0 = ros::Time::now().toSec();
	double current_angle = 0.0;
	ros::Rate loop_rate(100);
	do{
		velocity_publisher.publish(vel_msg);
		double t1 = ros::Time::now().toSec();
		current_angle = angular_speed*(t1 - t0);
		ros::spinOnce();
		loop_rate.sleep();
	}
	while(current_angle < angle);

	vel_msg.angular.z = 0;
	velocity_publisher.publish(vel_msg);	
	
		
}
//Function for move turtle
void move(double speed, double distance, bool isForward)
{
    // distance = speed*time;
    //distanceTraveled += distance;
	geometry_msgs::Twist vel_msg;
	//set a random linear velocity in the x-axis
	if (isForward)
		vel_msg.linear.x = abs(speed);
	else
		vel_msg.linear.x = -abs(speed);
	vel_msg.linear.y =0;
	vel_msg.linear.z =0;
	//set a random angular velocity in the y-axis
	vel_msg.angular.x = 0;
	vel_msg.angular.y = 0;
	vel_msg.angular.z = 0;

	double t0 = ros::Time::now().toSec();
	double current_distance = 0.0;
	ros::Rate loop_rate(100);
	do{
		velocity_publisher.publish(vel_msg);
		double t1 = ros::Time::now().toSec();
		current_distance = speed * (t1-t0);
		ros::spinOnce();
		loop_rate.sleep();
		//cout<<(t1-t0)<<", "<<current_distance <<", "<<distance<<endl;
	}while(current_distance<distance);
	vel_msg.linear.x =0;
	velocity_publisher.publish(vel_msg);

}

void move_square(double speed,bool clockwise)
{
	ros::Rate loop_rate(10);
	move(speed,4,true);
	loop_rate.sleep();
	rotate(PI/2,PI/2,clockwise);
	loop_rate.sleep();
	move(speed,4,true);
	loop_rate.sleep();
	rotate(PI/2,PI/2,clockwise);
	loop_rate.sleep();
}

void move_circle(double speed, bool clockwise)
{
	geometry_msgs::Twist vel_msg;
	
	ros::Rate loop_rate(10);
	while(ros::ok())
	{
		vel_msg.linear.x = speed;
		vel_msg.linear.y = 0;
		vel_msg.linear.z = 0;

		vel_msg.angular.x = 0;
		vel_msg.angular.y = 0;

		if(clockwise)
			vel_msg.angular.z = -PI/6;
		else
			vel_msg.angular.z = PI/6;

		loop_rate.sleep();
		velocity_publisher.publish(vel_msg);
	}
	
}
int main(int argc, char **argv)
{
	//Initialize node name "move_server"
        ros::init(argc, argv, "move_server");
        ros::NodeHandle n;

        velocity_publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
        ros::ServiceServer service = n.advertiseService("geometry_type_move", move_style);   //Service is created and advertised over ROS
        ROS_INFO("Ready to move.");
        ros::spin();
        return 0;
}
