#include "ros/ros.h"
#include "<package_name>/<srv_name>.h"
#include <cstdlib>

int main(int argc, char **argv)
{
        //Initialize node name "<give a node name>"
        ros::init(argc, argv, "<node name>");

        ros::NodeHandle n;
        ros::ServiceClient client = n.serviceClient<package_name::srv_name>("geometry_type_move");
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
