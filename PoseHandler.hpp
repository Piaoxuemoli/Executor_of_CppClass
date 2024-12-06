#pragma once
#include "Executor.hpp"

//PoseHandler类的接口
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
		bool IsBus(void) const; //获取is_Bus变量
		bool IsRoadster(void) const; //获取is_Roadster变量
		void SetCar(std::string& car_type);  //设置车类型接口

	public:  //设置类接口
		void SetPose(const Pose& in_pose);  //初始化位姿接口
		void SetBus(void);  //设置是否为公交车接口
		void SetRoadster(void);  //设置是否为跑车接口

	private:
		Pose pose_;
		bool is_Bus{ false };
		bool is_Roadster{ false };
		bool is_Fast{ false };
		bool is_Reverse{ false };
	};
}