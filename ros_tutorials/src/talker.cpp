/*
rostopic pub /turtle1/cmd_vel geometry_msgs/Twist -r 1 -- '[2.0, 0.0, 0.0]' '[0.0, 0.0, -1.8]'
*/


#include "/home/myjobhereisdone/catkin_ws/src/ros_tutorials/include/ros_tutorials/talker.hpp"
# define M_PI       3.14159265358979323846  /* pi */
namespace talker
{
    talker::talker(ros::NodeHandle nh)    //constructor for the class
    : nh_(nh)
    {



	
	   ros::NodeHandle private_nh("~");
           private_nh.param<int>("publish_frequency", publish_frequency_, 10);


  }

	void talker::init(){

	 chatter_pub = nh_.advertise<std_msgs::String>("chatter", 1);
	 timer = nh_.createTimer(ros::Duration(1), &talker::call_test, this);
	 pot_pub = nh_.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);
	 polozaj_sub =nh_.subscribe("/turtle1/pose", 1000, &talker::navigacija,this);
	
	}



        void talker::navigacija(const turtlesim::Pose& data){

	double x=data.x;
	double y=data.y;
	double theta=data.theta;
	geometry_msgs::Twist msg2;
	double theta_zel0=0; 
	double theta_zel90=M_PI/2;
	double theta_zel180=M_PI;
	double theta_zel270=M_PI*1.5;
	int flag;
	theta=abs(theta);
	

	/*
	algoritem zelvice, da bo narisala kocko
	*/
	
	msg2.angular.z=-2;
	msg2.linear.x=1;
	pot_pub.publish(msg2);


	}


	void talker::call_test(const ros::TimerEvent& event){

	    std_msgs::String msg;
	    
	    std::stringstream ss;
	    ss << "Info = " << count;
	    msg.data = ss.str();
	    //ROS_ERROR("Talker:%s", msg.data.c_str());
	    chatter_pub.publish(msg);
	    count++;


}
	
}


int main (int argc, char** argv)
{
	ros::init(argc, argv, "talker");
	ros::NodeHandle nh;
	talker::talker talker_handler(nh);
	talker_handler.init();
	int count = 0;
	

	ros::Rate loop_rate(talker_handler.publish_frequency_);  
	while (ros::ok())
	    {
		
		ros::spinOnce();
		
	    }
	    return 0;
}
 

