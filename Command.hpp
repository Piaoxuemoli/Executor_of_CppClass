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
			if (poseHandler.IsReverse())
			{
				poseHandler.Backward();  //��ͷģ�⵹��
			}
			if (poseHandler.IsFast())
			{
				poseHandler.Move();
			}
			poseHandler.Move();
			if (poseHandler.IsReverse())
			{
				poseHandler.Backward();  //��ͷ��ȥ��ģ�⵹������
			}
			
		}
	};

	class TurnLeftCommand :public ICommand   //��ת��ָ����
	{
	public:
		void DoOperate(PoseHandler& poseHandler) const noexcept
		{
			if (poseHandler.IsReverse())
			{
				poseHandler.Backward();  //��ͷģ�⵹��������ת��֮�����ٵ�ͷ��ȥ
			}
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
			if (poseHandler.IsReverse())
			{
				poseHandler.Backward();
			}
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

	class ReverseCommand :public ICommand  //�����ж�ָ����
	{
	public:
		void DoOperate(PoseHandler& poseHandler) const noexcept
		{
			poseHandler.Reverse();
		}
	};
}