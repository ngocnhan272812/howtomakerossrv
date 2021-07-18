#include "ros/ros.h"
#include "<package_name>/<srv_file_name>.h"


// Function provides the service for "geometry_type"
bool <give a function name>(<package_name>::<srv_file_name>::Request   &req,
                            <package_name>::<srv_file_name>::Response  &res)
{
	

}

	
}
int main(int argc, char **argv)
{
	/****  Initialize server name   ****/
        ros::init(argc, argv, "<give a server name>");
        ros::NodeHandle n;

        ros::ServiceServer service = n.advertiseService("geometry_type_move", <bool_function>);   //Service is created and advertised over ROS
       
	
        ros::spin();
        return 0;
}
