#include <iostream>
#include "Executor.cpp"
#include <tuple>
#include <gtest/gtest.h>

namespace adas_Executor
{
	bool operator==(const Pose& lhs, const Pose& rhs)
	{   //为Pose定义==运算符重载
		return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
	}

	//测试状态{0,0,'E'}下执行命令FM后，是否返回正确的下一状态{2,0,'E'}
	TEST(ExecutorTest, should_return_x_plus_2_given_states_0_0_E_and_command_FM)
	{
		//given
		MyExecutor executor;
		//when
		executor.IniPose({ 0, 0, 'E' });
		executor.Execute("FM");
		//then
		const Pose& target_pose = { 2, 0, 'E' };
		ASSERT_EQ(target_pose, executor.GetPose());
	}

	//测试状态{0,0,'N'}下执行命令FFM后，是否返回正确的下一状态{0,1,'N'}
	TEST(ExecutorTest, should_return_y_plus_1_given_states_0_0_N_and_command_FFM)
	{
		//given
		MyExecutor executor;
		//when
		executor.IniPose({ 0, 0, 'N' });
		executor.Execute("FFM");
		//then
		const Pose& target_pose = { 0, 1, 'N' };
		ASSERT_EQ(target_pose, executor.GetPose());
	}

}
