#include <iostream>
#include "MyExecutor.hpp"
#include <tuple>
#include <gtest/gtest.h>

namespace adas_Executor
{
	bool operator==(const Pose& lhs, const Pose& rhs)
	{   //为Pose定义==运算符重载
		return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
	}

	//测试Bus状态{0,0,'N'}下执行命令M后，是否返回正确的下一状态{0,1,'N'}
	TEST(MyExecutorTest, Bus_should_return_y_plus_1_given_states_0_0_N_and_command_M)
	{
		//given
		MyExecutor executor({ 0, 0, 'N' });
		//when
		executor.SetPose({ 0, 0, 'N' });
		std::string bus = "Bus";
		executor.SetCar(bus);
		executor.Execute("M");
		//then
		const Pose& target_pose = { 0, 1, 'N' };
		EXPECT_EQ(target_pose, executor.GetPose());
	}

	//测试Roadster状态{0,0,'N'}下执行命令M后，是否返回正确的下一状态{0,2,'N'}
	TEST(MyExecutorTest, Roadster_should_return_y_plus_2_given_states_0_0_N_and_command_M)
	{
		//given
		MyExecutor executor({ 0, 0, 'N' });
		//when
		executor.SetPose({ 0, 0, 'N' });
		std::string roadster = "Roadster";
		executor.SetCar(roadster);
		executor.Execute("M");
		//then
		const Pose& target_pose = { 0, 2, 'N' };
		EXPECT_EQ(target_pose, executor.GetPose());
	}

}