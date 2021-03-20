


#include "/home/myjobhereisdone/catkin_ws/src/ros_tutorials/include/ros_tutorials/listener.hpp"

namespace listener
{
    listener::listener(ros::NodeHandle nh)    //constructor for the class
    : nh_(nh)
    {



	
	   ros::NodeHandle private_nh("~");
           private_nh.param<int>("publish_frequency", publish_frequency_, 10);


  }

	void listener::init(){

	 sub = nh_.subscribe("chatter", 1000, &listener::chatterCallback,this);

	}



	void listener::chatterCallback(const std_msgs::String::ConstPtr& msg){
	
	ROS_ERROR("Listener:I heard: [%s]", msg->data.c_str());

	}
}


int main (int argc, char** argv)
{
	ros::init(argc, argv, "listener");
	ros::NodeHandle nh;
	listener::listener listener_handler(nh);
	listener_handler.init();
	int count = 0;
	

	ros::Rate loop_rate(listener_handler.publish_frequency_);  
	while (ros::ok())
	    {
		
		ros::spinOnce();
		
	    }
	    return 0;
}
 

