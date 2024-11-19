#pragma once
#include<string>

//Executor�ĳ�����ӿ�
namespace adas_Executor
{
	struct Pose  //����λ��
	{
		int x,y;  //����
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
		Executor & operator=(const Executor&) = delete;

	public:  //���麯���ӿ�
		virtual void IniPose(const Pose& pose) = 0;  //��ʼ������λ�˽ӿ�
		virtual void Execute(const std::string& command) = 0;  //ִ��ָ��ӿڣ��ж���ת��
		virtual Pose GetPose(void) const = 0;  //��ȡ����λ�˽ӿ�
	};
}
