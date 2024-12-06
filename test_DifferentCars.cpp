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
		std::string bus = "Bus";
		executor.SetCar(bus);
		executor.Execute("M");
		//then
		const Pose& target_pose = { 0, 1, 'N' };
		EXPECT_EQ(target_pose, executor.GetPose());
	}

	//����Roadster״̬{0,0,'N'}��ִ������M���Ƿ񷵻���ȷ����һ״̬{0,2,'N'}
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

	//����Bus״̬{0,0,'N'}��ִ������L���Ƿ񷵻���ȷ����һ״̬{-1,0,'W'}
	TEST(MyExecutorTest, Bus_should_return_x_minus_1_and_heading_W_given_states_0_0_N_and_command_L)
	{
		//given
		MyExecutor executor({ 0, 0, 'N' });
		//when
		executor.SetPose({ 0, 0, 'N' });
		std::string bus = "Bus";
		executor.SetCar(bus);
		executor.Execute("L");
		//then
		const Pose& target_pose = { 0, 1, 'W' };
		EXPECT_EQ(target_pose, executor.GetPose());
	}

	//����Roadster״̬{0,0,'N'}��ִ������L���Ƿ񷵻���ȷ����һ״̬{-1,0,'W'}
	TEST(MyExecutorTest, Roadster_should_return_x_minus_1_and_heading_W_given_states_0_0_N_and_command_L)
	{
		//given
		MyExecutor executor({ 0, 0, 'N' });
		//when
		executor.SetPose({ 0, 0, 'N' });
		std::string roadster = "Roadster";
		executor.SetCar(roadster);
		executor.Execute("L");
		//then
		const Pose& target_pose = { -1, 0, 'W' };
		EXPECT_EQ(target_pose, executor.GetPose());
	}

	//����Bus״̬{0,0,'N'}��ִ������BL���Ƿ񷵻���ȷ����һ״̬{0,-1,'E'}
	TEST(MyExecutorTest, Bus_should_return_y_minus_1_and_heading_E_given_states_0_0_N_and_command_BL)
	{
		//given
		MyExecutor executor({ 0, 0, 'N' });
		//when
		executor.SetPose({ 0, 0, 'N' });
		std::string bus = "Bus";
		executor.SetCar(bus);
		executor.Execute("BL");
		//then
		const Pose& target_pose = { 0, -1, 'E' };
		EXPECT_EQ(target_pose, executor.GetPose());
	}

	//����Roadster״̬{0,0,'N'}��ִ������BL���Ƿ񷵻���ȷ����һ״̬{-1,0,'E'}
	TEST(MyExecutorTest, Roadster_should_return_x_minus_1_and_heading_E_given_states_0_0_N_and_command_BL)
	{
		//given
		MyExecutor executor({ 0, 0, 'N' });
		//when
		executor.SetPose({ 0, 0, 'N' });
		std::string roadster = "Roadster";
		executor.SetCar(roadster);
		executor.Execute("BL");
		//then
		const Pose& target_pose = { -1, 0, 'E' };
		EXPECT_EQ(target_pose, executor.GetPose());
	}
}