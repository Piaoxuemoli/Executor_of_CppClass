#include <iostream>
#include "MyExecutor.hpp"
#include <tuple>
#include <gtest/gtest.h>

namespace adas_Executor
{
	bool operator==(const Pose& lhs, const Pose& rhs)
	{   //ΪPose����==���������
		return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
	}

	//����Bus״̬{0,0,'N'}��ִ������M���Ƿ񷵻���ȷ����һ״̬{0,1,'N'}
	TEST(MyExecutorTest, Bus_should_return_y_plus_1_given_states_0_0_N_and_command_M)
	{
		//given
		MyExecutor executor({ 0, 0, 'N' });
		//when
		executor.SetPose({ 0, 0, 'N' });
		executor.Execute("M");
		std::string bus = "Bus";
		executor.SetCar(bus);
		//then
		const Pose& target_pose = { 0, 1, 'N' };
		EXPECT_EQ(target_pose, executor.GetPose());
	}
}