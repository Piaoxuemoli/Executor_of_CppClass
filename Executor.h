#pragma once
#include <string>

//Executor的抽象类接口
namespace adas_Executor
{
	struct Pose  //车辆位姿
	{
		int x, y;  //坐标
		char heading;  //车头朝向

		Pose() : x(0), y(0), heading('N') {}  //默认构造函数
		Pose(int x, int y, char heading) : x(x), y(y), heading(heading) {} //结构体的构造函数
	};

	class Executor  //Executor的抽象类接口
	{
	public:
		Executor(void) = default;  //默认构造函数
		virtual ~Executor(void) = default;

		Executor(const Executor&) = delete;  //防止错误拷贝
		Executor& operator=(const Executor&) = delete;

	public:  //纯虚函数接口
		virtual void IniPose(const Pose& pose) = 0;  //初始化车辆位姿接口
		virtual void Execute(const std::string& command) = 0;  //执行指令接口（行动或转向）
		virtual Pose GetPose(void) const = 0;  //获取车辆位姿接口

	public:  //指令类接口
		virtual void Move(void) = 0;  //移动接口
		virtual void TurnLeft(void) = 0;  //左转向接口
		virtual void TurnRight(void) = 0;  //右转向接口
		virtual void Fast(void) = 0;  //快速行动接口

	public:
		class ICommand
		{
		public:
			virtual ~ICommand() = default;  //虚析构函数
			virtual void DoOperate(Executor& executor) const noexcept = 0;
		};

	public:  //指令类
		class MoveCommand :public ICommand   //移动指令类
		{
		public:
			void DoOperate(Executor& executor) const noexcept//执行指令接口
			{
				executor.Move();
			}
		};
		class TurnLeftCommand :public ICommand   //左转向指令类
		{
		public:
			void DoOperate(Executor& executor) const noexcept
			{
				executor.TurnLeft();
			}
		};
		class TurnRightCommand :public ICommand  //右转向指令类
		{
		public:
			void DoOperate(Executor& executor) const noexcept
			{
				executor.TurnRight();
			}
		};
		class FastCommand :public ICommand  //快速行动指令类
		{
		public:
			void DoOperate(Executor& executor) const noexcept
			{
				executor.Fast();
			}
		};
	public:
		int is_Fast = 0;  //是否快速行动
	};	
}
