#pragma once

/**\file tf_to_link_state.h
 * \brief Description...
 *
 * @version 1.0
 * @author Carlos Miguel Correia da Costa
 */

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  <includes>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// std includes
#include <string>
#include <vector>

// ROS includes
#include <ros/ros.h>
#include <ros/rate.h>
#include <tf/transform_listener.h>
#include <gazebo_msgs/LinkState.h>

// external libs includes

// project includes

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </includes>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

namespace gazebo_projection_mapping {
// #############################################################################   TFToLinkState   #############################################################################
/**
 * \brief Description...
 */
class TFToLinkState {
		// ====================================================================   <public-section>   ===========================================================================
	public:

		// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <constructors-destructor>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		TFToLinkState() : state_published_(false), publish_rate_(30.0) {}
		virtual ~TFToLinkState() {}
		// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </constructors-destructor>  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

		// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <TFToLinkState-functions>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		void setupConfigurationFromParameterServer(ros::NodeHandlePtr& node_handle, ros::NodeHandlePtr& private_node_handle);
		void publishLinkStateFromTF();
		// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </TFToLinkState-functions>  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	// ========================================================================   </public-section>  ===========================================================================

	// ========================================================================   <protected-section>   ========================================================================
	protected:
	// ========================================================================   </protected-section>  ========================================================================

	// ========================================================================   <private-section>   ==========================================================================
	private:
		// configuration fields
		std::string tf_source_frame_;
		std::string tf_target_frame_;
		gazebo_msgs::LinkState link_state_;
		bool state_published_;

		// state fields
		tf::TransformListener tf_listener_;
		ros::Rate publish_rate_;

		// ros communication fields
		ros::NodeHandlePtr node_handle_;
		ros::Publisher link_state_publisher_;
	// ========================================================================   </private-section>  ==========================================================================
};

} /* namespace gazebo_projection_mapping */

