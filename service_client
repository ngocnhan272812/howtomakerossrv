#include "ros/ros.h"
#include "turtlesim_tutorial/geometry_type.h"
#include <cstdlib>

int main(int argc, char **argv)
{
        //Initialize node name "move_client"
        ros::init(argc, argv, "move_client");

        ros::NodeHandle n;
        ros::ServiceClient client = n.serviceClient<turtlesim_tutorial::geometry_type>("geometry_type_move");
        turtlesim_tutorial::geometry_type  srv;

        // Input requests 
        srv.request.speed = 2;
        srv.request.clockwise = 0;

        if (client.call(srv))
        {
                ROS_INFO(" Respone: %s ", srv.response.name.c_str() );
        }
        else
        {
                ROS_ERROR("Failed to call sever geometry_type_move");
                return 1;
        }

        return 0;


}
