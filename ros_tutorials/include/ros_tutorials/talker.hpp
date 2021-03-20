
/** \brief
 *  \file talker.hpp
 *  \author Kristijan Polovic
 *  \date 20.3.2021
 *  \version 1.0
 *  \place: Slovenia
 */

#ifndef talker_hpp___
#define talker_hpp___ 

//basic
#include <ros/ros.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "std_msgs/String.h"
#include <sys/time.h>
#include <sstream>
#include <time.h>
#include <geometry_msgs/Twist.h>
#include "turtlesim/Pose.h"


using namespace std;
namespace talker  //split up code more classes whit the same name
{
    class talker
    {
        private:

        /** \brief Copyconstruction is not allowed.
         */
       	talker(const talker &src);

        public:
        ros::NodeHandle nh_;
	ros::Timer timer;
	ros::Publisher chatter_pub; 
	ros::Publisher pot_pub;  
	ros::Subscriber polozaj_sub;  
	talker(ros::NodeHandle nh);
	
	//Spremenljivke
	int publish_frequency_;
	int count = 0;
	
	//Funkcije
	void init();
	void call_test(const ros::TimerEvent& event);
	void navigacija(const turtlesim::Pose& data);


    };
}

#endif




