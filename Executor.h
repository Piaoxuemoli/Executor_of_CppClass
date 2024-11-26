#pragma once
#include <string>

//Executor�ĳ�����ӿ�
namespace adas_Executor
{
	struct Pose  //����λ��
	{
		int x, y;  //����
		char heading;  //��ͷ����

		Pose() : x(0), y(0), heading('N') {}  //Ĭ�Ϲ��캯��
		Pose(int x, int y, char heading) : x(x), y(y), heading(heading) {} //�ṹ��Ĺ��캯��
	};

	class Executor  //Executor�ĳ�����ӿ�
	{
	public:
		Executor(void) = default;  //Ĭ�Ϲ��캯��
		virtual ~Executor(void) = default;

		Executor(const Executor&) = delete;  //��ֹ���󿽱�
		Executor& operator=(const Executor&) = delete;

	public:  //���麯���ӿ�
		virtual void IniPose(const Pose& pose) = 0;  //��ʼ������λ�˽ӿ�
		virtual void Execute(const std::string& command) = 0;  //ִ��ָ��ӿڣ��ж���ת��
		virtual Pose GetPose(void) const = 0;  //��ȡ����λ�˽ӿ�

	public:  //ָ����ӿ�
		virtual void Move(void) = 0;  //�ƶ��ӿ�
		virtual void TurnLeft(void) = 0;  //��ת��ӿ�
		virtual void TurnRight(void) = 0;  //��ת��ӿ�
		virtual void Fast(void) = 0;  //�����ж��ӿ�

	public:
		class ICommand
		{
		public:
			virtual ~ICommand() = default;  //����������
			virtual void DoOperate(Executor& executor) const noexcept = 0;
		};

	public:  //ָ����
		class MoveCommand :public ICommand   //�ƶ�ָ����
		{
		public:
			void DoOperate(Executor& executor) const noexcept//ִ��ָ��ӿ�
			{
				executor.Move();
			}
		};
		class TurnLeftCommand :public ICommand   //��ת��ָ����
		{
		public:
			void DoOperate(Executor& executor) const noexcept
			{
				executor.TurnLeft();
			}
		};
		class TurnRightCommand :public ICommand  //��ת��ָ����
		{
		public:
			void DoOperate(Executor& executor) const noexcept
			{
				executor.TurnRight();
			}
		};
		class FastCommand :public ICommand  //�����ж�ָ����
		{
		public:
			void DoOperate(Executor& executor) const noexcept
			{
				executor.Fast();
			}
		};
	public:
		int is_Fast = 0;  //�Ƿ�����ж�
	};	
}
