#pragma once
#include "Executor.hpp"

//PoseHandler��Ľӿ�
namespace adas_Executor
{
	class PoseHandler
	{
	public:
		PoseHandler(const Pose& pose_) noexcept;
		PoseHandler(const PoseHandler&) = delete;
		PoseHandler& operator=(const PoseHandler&) = delete;

	public:  //ָ����ӿ�
		void Move(void);  //�ƶ��ӿ�
		void TurnLeft(void);  //��ת��ӿ�
		void TurnRight(void);  //��ת��ӿ�
	    void Fast(void);  //�����ж��ӿ�
		void Reverse(void);  //�����ӿ�
		void Backward(void);  //��ͷ�ӿ�
		Pose GetPose(void) const;  //��ȡ����λ�˽ӿ�
		bool IsFast(void) const; //��ȡis_Fast����
		bool IsReverse(void) const; //��ȡis_Reverse����
		bool IsBus(void) const; //��ȡis_Bus����
		bool IsRoadster(void) const; //��ȡis_Roadster����
		void SetCar(std::string& car_type);  //���ó����ͽӿ�

	public:  //������ӿ�
		void SetPose(const Pose& in_pose);  //��ʼ��λ�˽ӿ�
		void SetBus(void);  //�����Ƿ�Ϊ�������ӿ�
		void SetRoadster(void);  //�����Ƿ�Ϊ�ܳ��ӿ�

	private:
		Pose pose_;
		bool is_Bus{ false };
		bool is_Roadster{ false };
		bool is_Fast{ false };
		bool is_Reverse{ false };
	};
}