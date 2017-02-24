
#include "ros/ros.h"
#include "mapserver/isFPos.h"


int main(int argc, char **argv)
{
	ros::init(argc, argv, "isForbiddenPosClient");
    if(argc != 3){
        ROS_INFO("usage: getMarkPos x y");
        return 1;
    }

    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<mapserver::isFPos>("forbiddenPos");
    mapserver::isFPos srv;
    srv.request.x = atoll(argv[1]);
    srv.request.y = atoll(argv[2]);
    if(client.call(srv)){
        ROS_INFO("ans: %d", srv.response.b);
    }else{
        ROS_ERROR("Failed to call service ..");
    }

    return 0;
}
