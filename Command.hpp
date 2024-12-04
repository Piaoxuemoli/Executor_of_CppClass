#pragma once
#include "PoseHandler.hpp"

namespace adas_Executor
{
	class ICommand
	{
	public:
		virtual ~ICommand() = default;  //虚析构函数
		virtual void DoOperate(PoseHandler& poseHandler) const noexcept = 0;
	};

	class MoveCommand :public ICommand   //移动指令类
	{
	public:
		void DoOperate(PoseHandler& poseHandler) const noexcept override //执行指令接口
		{
			if (poseHandler.IsReverse())
			{
				poseHandler.Backward();  //掉头模拟倒车
			}
			if (poseHandler.IsFast())
			{
				poseHandler.Move();
			}
			poseHandler.Move();
			if (poseHandler.IsReverse())
			{
				poseHandler.Backward();  //掉头回去，模拟倒车结束
			}
			
		}
	};

	class TurnLeftCommand :public ICommand   //左转向指令类
	{
	public:
		void DoOperate(PoseHandler& poseHandler) const noexcept
		{
			if (poseHandler.IsReverse())
			{
				poseHandler.Backward();  //掉头模拟倒车，但是转向之后不用再掉头回去
			}
			if (poseHandler.IsFast())
			{
				poseHandler.Move();
			}
			poseHandler.TurnLeft();
		}
	};

	class TurnRightCommand :public ICommand  //右转向指令类
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

	class FastCommand :public ICommand  //快速行动指令类
	{
	public:
		void DoOperate(PoseHandler& poseHandler) const noexcept
		{
			poseHandler.Fast();
		}
	};

	class ReverseCommand :public ICommand  //倒车行动指令类
	{
	public:
		void DoOperate(PoseHandler& poseHandler) const noexcept
		{
			poseHandler.Reverse();
		}
	};
}