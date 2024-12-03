#pragma once
#include "PoseHandler.hpp"

namespace adas_Executor
{
	class ICommand
	{
	public:
		virtual ~ICommand() = default;  //����������
		virtual void DoOperate(PoseHandler& poseHandler) const noexcept = 0;
	};

	class MoveCommand :public ICommand   //�ƶ�ָ����
	{
	public:
		void DoOperate(PoseHandler& poseHandler) const noexcept override //ִ��ָ��ӿ�
		{
			if (poseHandler.IsFast())
			{
				poseHandler.Move();
			}
			poseHandler.Move();
		}
	};
	class TurnLeftCommand :public ICommand   //��ת��ָ����
	{
	public:
		void DoOperate(PoseHandler& poseHandler) const noexcept
		{
			if (poseHandler.IsFast())
			{
				poseHandler.Move();
			}
			poseHandler.TurnLeft();
		}
	};
	class TurnRightCommand :public ICommand  //��ת��ָ����
	{
	public:
		void DoOperate(PoseHandler& poseHandler) const noexcept
		{
			if (poseHandler.IsFast())
			{
				poseHandler.Move();
			}
			poseHandler.TurnRight();
		}
	};
	class FastCommand :public ICommand  //�����ж�ָ����
	{
	public:
		void DoOperate(PoseHandler& poseHandler) const noexcept
		{
			poseHandler.Fast();
		}
	};
}