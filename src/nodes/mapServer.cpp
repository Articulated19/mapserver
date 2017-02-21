
#include "ros/ros.h"
#include "mapserver/getMarkPos.h"
#include "../map.h"


Map g_map;

bool getMarkingPosition(mapserver::getMarkPos::Request &req,
                   mapserver::getMarkPos::Response &res)
{
//    Map g_map;
    int id, x, y = 0;
    id = (int) req.id;
    g_map.getMarkingPos(id,x,y);
    ROS_INFO("request id: %d", req.id);
    ROS_INFO("markpos: (%d,%d)",res.x, res.y);
    return true;
}

//bool isForbiddenPos(){}




int main(int argc, char **argv)
{
    ros::init(argc, argv, "mapserver");
    ros::NodeHandle n;

    ros::ServiceServer service1 = n.advertiseService("markingPos", getMarkingPosition);

    //ros::ServiceServer service2 = n.advertiseService("forbiddenPos", isForbiddenPos);
    ROS_INFO("Ready to serve");
    ros::spin();
    return 0;
}
