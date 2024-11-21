#include "Executor.h"
#include <string>
#include <map>
#include <functional>
#include <stdexcept>
#include <memory>

using namespace std;
using namespace adas_Executor;

class MyExecutor : public Executor  //����adas_Executor��ʵ��
{
public:
    MyExecutor()
    {
        IniPose(Pose(0, 0, 'N'));  //��ʼ����ʼ��̬
        //����������ö�Ӧ�ĺ���
        commandMap["M"] = [this]() { Move(); };
        commandMap["L"] = [this]() { TurnLeft(); };
        commandMap["R"] = [this]() { TurnRight(); };
    }

public:
    void IniPose(const Pose& pose) override  //��ʼ����̬
    {
        pose_ = pose;
    }

    void Execute(const std::string& command) override  //�������ִ�У�Ȼ�������̬
    {
        // ��������Ƿ����
        if (commandMap.find(command) != commandMap.end())
        {
            // ִ�ж�Ӧ������
            commandMap[command]();
        }
        else
        {
            // ����δ֪����
            throw std::invalid_argument("Unknown command: " + command);
        }
    }

    Pose GetPose() const override  //��ȡ��ǰ��̬
    {
        return pose_;
    }

private:
    Pose pose_;  // ��Ա����λ��
    std::map<std::string, std::function<void()>> commandMap;  //����������ö�Ӧ�ĺ���
    void Move() //�ƶ�
    {
        if (pose_.heading == 'N')
            pose_.y += 1;
        else if (pose_.heading == 'S')
            pose_.y -= 1;
        else if (pose_.heading == 'E')
            pose_.x += 1;
        else if (pose_.heading == 'W')
            pose_.x -= 1;
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
};