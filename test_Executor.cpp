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

}
