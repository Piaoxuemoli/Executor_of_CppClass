#pragma once
#include "Executor.hpp"

// ����PoseHandler��Ľӿ�
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
		Pose GetPose(void) const;  //��ȡ����λ�˽ӿ�
		bool IsFast(void) const; //��ȡis_Fast����
		void SetPose(const Pose& in_pose);  //��ʼ��λ�˽ӿ�

	private:
		Pose pose_;
		bool is_Fast{ false };
	};
}