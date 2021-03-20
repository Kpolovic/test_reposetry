
/** \brief
 *  \file listener.hpp
 *  \author Kristijan Polovic
 *  \date 20.3.2021
 *  \version 1.0
 *  \place: Slovenia
 */

#ifndef listener_hpp___
#define listener_hpp___ 

//basic
#include <ros/ros.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
#include "std_msgs/String.h"
#include <sys/time.h>
#include <sstream>
#include <time.h>


using namespace std;
namespace listener  //split up code more classes whit the same name
{
    class listener
    {
        private:

        /** \brief Copyconstruction is not allowed.
         */
       	listener(const listener &src);

        public:
        ros::NodeHandle nh_;
	ros::Subscriber sub;   
	listener(ros::NodeHandle nh);
	
	//Spremenljivke
	int publish_frequency_;
	int count = 0;
	
	//Funkcije
	void init();
	void chatterCallback(const std_msgs::String::ConstPtr& msg);


    };
}

#endif




