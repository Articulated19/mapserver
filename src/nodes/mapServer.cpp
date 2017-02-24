
#include "ros/ros.h"
#include "mapserver/getMarkPos.h"
#include "mapserver/isFPos.h"
#include "../map.h"

Map g_map;


bool getMarkingPosition(mapserver::getMarkPos::Request &req,
                   mapserver::getMarkPos::Response &res)
{
    int id, x, y = 0;
    id = (int) req.id;
    g_map.getMarkingPos(id,x,y);
    res.x = x;
    res.y = y;
    ROS_INFO("request id: %d", req.id);
    ROS_INFO("markpos: (%d,%d)",res.x, res.y);
    return true;
}

bool isForbiddenPos(mapserver::isFPos::Request &req,
                   mapserver::isFPos::Response &res)
{
    int x = req.x;
    int y = req.y;
    bool b = false;
    g_map.isForbiddenPos(x, y, b);
    res.b = b;
    ROS_INFO("pos(%d,%d)", x, y);
    ROS_INFO("result: %d" + b );
    return true;
}




int main(int argc, char **argv)
{
    ros::init(argc, argv, "mapserver");
    ros::NodeHandle n;

    ros::ServiceServer service1 = n.advertiseService("markingPos", getMarkingPosition);

    ros::ServiceServer service2 = n.advertiseService("forbiddenPos", isForbiddenPos);
   
    ROS_INFO("Ready to serve");
    ros::spin();
    return 0;
}
