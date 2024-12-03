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
		virtual void Execute(const std::string& command) = 0;  //执行指令接口（行动或转向）
		virtual Pose GetPose(void) const = 0;  //获取车辆位姿接口
	};	
}
