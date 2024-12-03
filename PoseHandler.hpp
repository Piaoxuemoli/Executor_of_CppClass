#pragma once
#include "Executor.hpp"

// 定义PoseHandler类的接口
namespace adas_Executor
{
	class PoseHandler
	{
	public:
		PoseHandler(const Pose& pose_) noexcept;
		PoseHandler(const PoseHandler&) = delete;
		PoseHandler& operator=(const PoseHandler&) = delete;

	public:  //指令类接口
		void Move(void);  //移动接口
		void TurnLeft(void);  //左转向接口
		void TurnRight(void);  //右转向接口
	    void Fast(void);  //快速行动接口
		void Reverse(void);  //倒车接口
		void Backward(void);  //掉头接口
		Pose GetPose(void) const;  //获取车辆位姿接口
		bool IsFast(void) const; //获取is_Fast变量
		bool IsReverse(void) const; //获取is_Reverse变量

	public:  //设置类接口
		void SetPose(const Pose& in_pose);  //初始化位姿接口

	private:
		Pose pose_;
		bool is_Fast{ false };
		bool is_Reverse{ false };
	};
}