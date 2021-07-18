#include "ros/ros.h"
#include "<package_name>/<srv_file_name>.h"
#include <cstdlib>

int main(int argc, char **argv)
{
        /** Initialize node name "<give a node name>" **/
        ros::init(argc, argv, "<node name>");

        ros::NodeHandle n;
        ros::ServiceClient client = n.serviceClient<package_name::srv_file_name>("<service_name>");
        package_name>::<srv_flie_name>.h  srv;

        /**** Input requests **** 
        rv.request.service1 = 2;
        srv.request.service2 = 0;
        ......    
        */
        
        /**** call service ****
        if (client.call(srv))
        {
                ROS_INFO(" Respone: %s ", srv.response.name.c_str() );    //check response
        }
        else
        {
                ROS_ERROR("Failed to call sever geometry_type_move");
                return 1;
        }
        */

        return 0;


}
