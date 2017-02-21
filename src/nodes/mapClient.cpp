
#include "ros/ros.h"
#include "mapserver/getMarkPos.h"


int main(int argc, char **argv)
{
	ros::init(argc, argv, "getMarkPosClient");
    if(argc != 2){
        ROS_INFO("usage: getMarkPos id");
        return 1;
    }

    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<mapserver::getMarkPos>("markingPos");
    mapserver::getMarkPos srv;
    srv.request.id = atoll(argv[1]);
    if(client.call(srv)){
        ROS_INFO("ans: (%d,%d)", srv.response.x, srv.response.y);
    }else{
        ROS_ERROR("Failed to call service ..");
    }

    return 0;
}
