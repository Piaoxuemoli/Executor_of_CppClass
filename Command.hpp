#pragma once
#include "PoseHandler.hpp"

//�������ָ�����ӿ�
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
			}  //����ǿ����ж������ִ��һ���ƶ�����
			poseHandler.Move();
			if (poseHandler.IsRoadster())
			{
				if (poseHandler.IsFast())
				{
					poseHandler.Move();
				}
				poseHandler.Move();
			}  //������ܳ�������ִ��һ���ƶ�������ֱ��ʱ�ܳ���Ҫ�������ƶ���
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
			if (poseHandler.IsBus())
			{
				poseHandler.Move();   //����ǹ������������ƶ�һ��
			}
			if (poseHandler.IsFast())
			{
				poseHandler.Move();
			}
			poseHandler.TurnLeft();
			if (poseHandler.IsRoadster())
			{
				poseHandler.Move();
			}  //������ܳ�������ִ��һ���ƶ�����
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
			if (poseHandler.IsBus())
			{
				poseHandler.Move();   //����ǹ������������ƶ�һ��
			}
			if (poseHandler.IsFast())
			{
				poseHandler.Move();
			}
			poseHandler.TurnRight();
			if (poseHandler.IsRoadster())
			{
				poseHandler.Move();
			}  //������ܳ�������ִ��һ���ƶ�����
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