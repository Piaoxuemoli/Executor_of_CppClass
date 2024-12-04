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

}
