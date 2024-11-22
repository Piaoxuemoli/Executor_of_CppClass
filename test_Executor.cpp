#include <iostream>
#include "Executor.cpp"
#include <tuple>
#include <gtest/gtest.h>

namespace adas_Executor
{
	bool operator==(const Pose& lhs, const Pose& rhs)
	{   //ΪPose����==���������
		return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
	}
	//����δ��ʼ��Executorʱ��GetPose()���س�ʼλ���Ƿ�Ϊ{0,0,��E��}
	TEST(ExecutorTest, should_return_init_pose_when_without_command)
	{
		//given
		auto executor = std::make_shared<MyExecutor>();
		executor->IniPose({ 0, 0, 'E' });
		//when
		//then
		const Pose target({ 0, 0, 'E' });
		ASSERT_EQ(target, executor->GetPose());
	}

	//���Գ�ʼ��Ϊ{1��1����N��}��GetPose()����{1��1����N��}
	TEST(ExecutorTest, should_return_seted_pose_when_initialized_with_command)
	{
		//given
		auto executor = std::make_shared<MyExecutor>();
		executor->IniPose({ 1, 1, 'N' });
		//when
		//then
		const Pose target({ 1, 1, 'N' });
		ASSERT_EQ(target, executor->GetPose());
	}

	//���Գ�ʼλ��Ϊ{0��0����E��}��ִ������M��GetPose()����{1��0����E��}
	TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
	{
		// given
		auto executor = std::make_shared<MyExecutor>();
		executor->IniPose({ 0, 0, 'E' });
		// when
		executor->Execute("M");
		// then
		const Pose target({ 1, 0, 'E' });
		ASSERT_EQ(target, executor->GetPose());
	}

	//���Գ�ʼλ��Ϊ{0��0����W��}��ִ������M��GetPose()����{-1��0����W��}
	TEST(ExecutorTest, should_return_x_minus_1_given_command_is_M_and_facing_is_W)
	{
		// given
		auto executor = std::make_shared<MyExecutor>();
		executor->IniPose({ 0, 0, 'W' });
		// when
		executor->Execute("M");
		// then
		const Pose target({ -1, 0, 'W' });
		ASSERT_EQ(target, executor->GetPose());
	}

	//���Գ�ʼλ��Ϊ{0��0����N��}��ִ������M��GetPose()����{0��1����N��}
	TEST(ExecutorTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N)
	{
		// given
		auto executor = std::make_shared<MyExecutor>();
		executor->IniPose({ 0, 0, 'N' });
		// when
		executor->Execute("M");
		// then
		const Pose target({ 0, 1, 'N' });
		ASSERT_EQ(target, executor->GetPose());
	}

	//���Գ�ʼλ��Ϊ{0��0����S��}��ִ������M��GetPose()����{0��-1����S��}
	TEST(ExecutorTest, should_return_y_minus_1_given_command_is_M_and_facing_is_S)
	{
		// given
		auto executor = std::make_shared<MyExecutor>();
		executor->IniPose({ 0, 0, 'S' });
		// when
		executor->Execute("M");
		// then
		const Pose target({ 0, -1, 'S' });
		ASSERT_EQ(target, executor->GetPose());
	}

	//���Գ�ʼλ��Ϊ{0��0����E��}��ִ������L��GetPose()����{0��0����N��}
	TEST(ExecutorTest, should_return_facing_N_given_command_is_L_and_facing_is_E)
	{
		// given
		auto executor = std::make_shared<MyExecutor>();
		executor->IniPose({ 0, 0, 'E' });
		// when
		executor->Execute("L");
		// then
		const Pose target({ 0, 0, 'N' });
		ASSERT_EQ(target, executor->GetPose());
	}

	//���Գ�ʼλ��Ϊ{0��0����W��}��ִ������L��GetPose()����{0��0����S��}
	TEST(ExecutorTest, should_return_facing_S_given_command_is_L_and_facing_is_W)
	{
		// given
		auto executor = std::make_shared<MyExecutor>();
		executor->IniPose({ 0, 0, 'W' });
		// when
		executor->Execute("L");
		// then
		const Pose target({ 0, 0, 'S' });
		ASSERT_EQ(target, executor->GetPose());
	}

	//���Գ�ʼλ��Ϊ{0��0����N��}��ִ������L��GetPose()����{0��0����W��}
	TEST(ExecutorTest, should_return_facing_W_given_command_is_L_and_facing_is_N)
	{
		// given
		auto executor = std::make_shared<MyExecutor>();
		executor->IniPose({ 0, 0, 'N' });
		// when
		executor->Execute("L");
		// then
		const Pose target({ 0, 0, 'W' });
		ASSERT_EQ(target, executor->GetPose());
	}

	//���Գ�ʼλ��Ϊ{0��0����S��}��ִ������L��GetPose()����{0��0����E��}
	TEST(ExecutorTest, should_return_facing_E_given_command_is_L_and_facing_is_S)
	{
		// given
		auto executor = std::make_shared<MyExecutor>();
		executor->IniPose({ 0, 0, 'S' });
		// when
		executor->Execute("L");
		// then
		const Pose target({ 0, 0, 'E' });
		ASSERT_EQ(target, executor->GetPose());
	}

	//���Գ�ʼλ��Ϊ{0��0����E��}��ִ������R��GetPose()����{0��0����S��}
	TEST(ExecutorTest, should_return_facing_S_given_command_is_R_and_facing_is_E)
	{
		// given
		auto executor = std::make_shared<MyExecutor>();
		executor->IniPose({ 0, 0, 'E' });
		// when
		executor->Execute("R");
		// then
		const Pose target({ 0, 0, 'S' });
		ASSERT_EQ(target, executor->GetPose());
	}

	//���Գ�ʼλ��Ϊ{0��0����W��}��ִ������R��GetPose()����{0��0����N��}
	TEST(ExecutorTest, should_return_facing_N_given_command_is_R_and_facing_is_W)
	{
		// given
		auto executor = std::make_shared<MyExecutor>();
		executor->IniPose({ 0, 0, 'W' });
		// when
		executor->Execute("R");
		// then
		const Pose target({ 0, 0, 'N' });
		ASSERT_EQ(target, executor->GetPose());
	}
}
