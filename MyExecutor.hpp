#include <iostream>
#include "Executor.hpp"
#include "PoseHandler.hpp"

//MyExecutor��Ľӿ�
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
		void Execute(const std::string& command) noexcept override;  //ִ��ָ��
		Pose GetPose(void) const noexcept override;  //��ȡ��ǰλ��
		void SetPose(const Pose& pose) noexcept;  //���õ�ǰλ��
		void SetCar(std::string& car) noexcept;  //���ó���

	private:
		PoseHandler poseHandler;  //poseHandler��ʵ����
	};
}