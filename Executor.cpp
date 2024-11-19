#include "Executor.h"
#include <string>
#include <map>
#include <functional>

using namespace std;
using namespace adas_Executor;

class MyExecutor : public Executor  //����adas_Executor��ʵ��
{
public:
    MyExecutor()
    {
        IniPose(Pose(0, 0, 'N'));  //��ʼ����ʼ��̬
    }  

public:
    void IniPose(const Pose& pose) override  //��ʼ����̬
    {
        pose_ = pose;
    }

    void Execute(const std::string& command) override  //�������ִ�У�Ȼ�������̬
    {
        std::map<std::string, std::function<void()>> commandMap;  //����������ö�Ӧ�ĺ���
        commandMap["M"] = [this]() { Move(); };
        commandMap["L"] = [this]() { TurnLeft(); };
        commandMap["R"] = [this]() { TurnRight(); };
    }

    void Move() //�ƶ�
    {
        if (pose_.heading == 'N')
            pose_.x += 1;
        else if (pose_.heading == 'S')
            pose_.x -= 1;
        else if (pose_.heading == 'E')
            pose_.y += 1;
        else if (pose_.heading == 'W')
            pose_.y -= 1;
    }

    void TurnLeft()  //��ת
    {
        if (pose_.heading == 'N')
            pose_.heading = 'W';
        else if (pose_.heading == 'S')
            pose_.heading = 'E';
        else if (pose_.heading == 'E')
            pose_.heading = 'N';
        else if (pose_.heading == 'W')
            pose_.heading = 'S';
    }

    void TurnRight()  //��ת
    {
        if (pose_.heading == 'N')
            pose_.heading = 'E';
        else if (pose_.heading == 'S')
            pose_.heading = 'W';
        else if (pose_.heading == 'E')
            pose_.heading = 'S';
        else if (pose_.heading == 'W')
            pose_.heading = 'N';
    }

    Pose GetPose() const override  //��ȡ��ǰ��̬
    {
        return pose_;
    }

private:
    Pose pose_;  // ��Ա����λ��
};