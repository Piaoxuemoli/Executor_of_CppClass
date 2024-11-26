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

	//����״̬{0,0,'E'}��ִ������FM���Ƿ񷵻���ȷ����һ״̬{2,0,'E'}
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
}
