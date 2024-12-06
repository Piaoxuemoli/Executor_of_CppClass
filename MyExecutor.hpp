#include <iostream>
#include "Executor.hpp"
#include "PoseHandler.hpp"

//MyExecutor类的接口
namespace adas_Executor
{
	class MyExecutor final : public Executor
	{
	public:
		explicit MyExecutor(const Pose& pose) noexcept;
		~MyExecutor() noexcept = default;
		MyExecutor(const MyExecutor&) = delete;
		MyExecutor& operator=(const MyExecutor&) = delete;

	public:
		void Execute(const std::string& command) noexcept override;  //执行指令
		Pose GetPose(void) const noexcept override;  //获取当前位姿
		void SetPose(const Pose& pose) noexcept;  //设置当前位姿
		void SetCar(std::string& car) noexcept;  //设置车型

	private:
		PoseHandler poseHandler;  //poseHandler的实例化
	};
}