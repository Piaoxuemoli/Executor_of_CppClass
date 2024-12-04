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

	//测试状态{0,0,'E'}下执行命令BM后，是否返回正确的下一状态{-1,0,'E'}
	TEST(ExecutorTest, should_return_x_minus_1_given_states_0_0_E_and_command_BM)
	{
		//given
		MyExecutor executor({ 0, 0, 'N' });
		//when
		executor.SetPose({ 0, 0, 'E' });
		executor.Execute("BM");
		//then
		const Pose& target_pose = { -1, 0, 'E' };
		ASSERT_EQ(target_pose, executor.GetPose());
	}

	//测试状态{0,0,'E'}下执行命令FM后，是否返回正确的下一状态{2,0,'E'}
	TEST(ExecutorTest, should_return_x_2_given_states_0_0_E_and_command_FM)
	{
		//given
		MyExecutor executor({ 0, 0, 'N' });
		//when
		executor.SetPose({ 0, 0, 'E' });
		executor.Execute("FM");
		//then
		const Pose& target_pose = { 2, 0, 'E' };
		ASSERT_EQ(target_pose, executor.GetPose());
	}

	//测试状态{0,0,'E'}下执行命令BFM后，是否返回正确的下一状态{-2,0,'E'}
	TEST(ExecutorTest, should_return_x_minus_2_given_states_0_0_E_and_command_BFM)
	{
		//given
		MyExecutor executor({ 0, 0, 'N' });
		//when
		executor.SetPose({ 0, 0, 'E' });
		executor.Execute("BFM");
		//then
		const Pose& target_pose = { -2, 0, 'E' };
		ASSERT_EQ(target_pose, executor.GetPose());
	}

	//测试状态{0,0,'N'}下执行命令BBM后，是否返回正确的下一状态{0,1,'N'}
	TEST(ExecutorTest, should_return_y_plus_1_given_states_0_0_N_and_command_BBM)
	{
		//given
		MyExecutor executor({ 0, 0, 'N' });
		//when
		executor.SetPose({ 0, 0, 'N' });
		executor.Execute("BBM");
		//then
		const Pose& target_pose = { 0, 1, 'N' };
		ASSERT_EQ(target_pose, executor.GetPose());
	}

	//测试状态{0,0,'N'}下执行命令FFM后，是否返回正确的下一状态{0,1,'N'}
	TEST(ExecutorTest, should_return_y_plus_1_given_states_0_0_N_and_command_FFM)
	{
		//given
		MyExecutor executor({ 0, 0, 'N' });
		//when
		executor.SetPose({ 0, 0, 'N' });
		executor.Execute("FFM");
		//then
		const Pose& target_pose = { 0, 1, 'N' };
		ASSERT_EQ(target_pose, executor.GetPose());
	}

	//测试状态{0,0,'E'}下执行命令BL后，是否返回正确的下一状态{0,0,'S'}
	TEST(ExecutorTest, should_return_heading_S_given_states_0_0_E_and_command_BL)
	{
		//given
		MyExecutor executor({ 0, 0, 'N' });
		//when
		executor.SetPose({ 0, 0, 'E' });
		executor.Execute("BL");
		//then
		const Pose& target_pose = { 0, 0, 'S' };
		ASSERT_EQ(target_pose, executor.GetPose());
	}

	//测试状态{0,0,'E'}下执行命令FL后，是否返回正确的下一状态{0,0,'N'}
	TEST(ExecutorTest, should_return_heading_N_and_x_plus_1_given_states_0_0_E_and_command_FL)
	{
		//given
		MyExecutor executor({ 0, 0, 'N' });
		//when
		executor.SetPose({ 0, 0, 'E' });
		executor.Execute("FL");
		//then
		const Pose& target_pose = { 1, 0, 'N' };
		ASSERT_EQ(target_pose, executor.GetPose());
	}

	//测试状态{0,0,'E'}下执行命令BFL后，是否返回正确的下一状态{-1,0,'S'}
	TEST(ExecutorTest, should_return_x_minus_1_and_heading_S_given_states_0_0_E_and_command_BFL)
	{
		//given
		MyExecutor executor({ 0, 0, 'N' });
		//when
		executor.SetPose({ 0, 0, 'E' });
		executor.Execute("BFL");
		//then
		const Pose& target_pose = { -1, 0, 'S' };
		ASSERT_EQ(target_pose, executor.GetPose());
	}

	//测试状态{0,0,'E'}下执行命令BR后，是否返回正确的下一状态{0,0,'N'}
	TEST(ExecutorTest, should_return_heading_N_given_states_0_0_E_and_command_BR)
	{
		//given
		MyExecutor executor({ 0, 0, 'N' });
		//when
		executor.SetPose({ 0, 0, 'E' });
		executor.Execute("BR");
		//then
		const Pose& target_pose = { 0, 0, 'N' };
		ASSERT_EQ(target_pose, executor.GetPose());
	}

}
