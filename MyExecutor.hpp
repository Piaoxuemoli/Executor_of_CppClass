#include <iostream>
#include "Executor.hpp"
#include "PoseHandler.hpp"

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
		void Execute(const std::string& command) noexcept override;
		Pose GetPose(void) const noexcept override;
		void SetPose(const Pose& pose) noexcept;

	private:
		PoseHandler poseHandler;  //poseHandlerµÄÊµÀý»¯
	};
}