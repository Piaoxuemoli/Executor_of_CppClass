#include "Executor.h"
#include <string>
#include <map>
#include <functional>
#include <stdexcept>
#include <memory>
#include <iostream>

using namespace std;
using namespace adas_Executor;

class MyExecutor : public Executor  //����adas_Executor��ʵ��
{
public:
    MyExecutor()
    {
        IniPose(Pose(0, 0, 'N'));  //��ʼ����ʼ��̬
        is_Fast = 0;  //��ʼ������Ϊ0
    }

public:
    void IniPose(const Pose& pose) override  //��ʼ����̬
    {
        pose_ = pose;
    }

    void Execute(const std::string& command) override  //�������ִ�У�Ȼ�������̬
    {
        for (const auto& cmd : command)
        {
            unique_ptr<ICommand> cmder;
            if (cmd == 'M')
            {
                cmder = make_unique<MoveCommand>();
            }
            else if (cmd == 'L')
            {
                cmder = make_unique<TurnLeftCommand>();
            }
            else if (cmd == 'R')
            {
                cmder = make_unique<TurnRightCommand>();
            }
            else if (cmd == 'F')
            {
                cmder = make_unique<FastCommand>();
            }
            if (cmder)
            {
                cmder->DoOperate(*this);
            }
        }
    }

    Pose GetPose() const override  //��ȡ��ǰ��̬
    {
        return pose_;
    }

    void Move() //�ƶ�
    {
        if (!is_Fast)
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
        else  //����
        {
            if (pose_.heading == 'N')
            {
                pose_.y += 1;
                pose_.y += 1;  //����ִ��
            }
            else if (pose_.heading == 'S')
            {
                pose_.y -= 1;
                pose_.y -= 1;
            }
            else if (pose_.heading == 'E')
            {
                pose_.x += 1;
                pose_.x += 1;
            }
            else if (pose_.heading == 'W')
            {
                pose_.x -= 1;
                pose_.x -= 1;
            }
        }
    }

    void TurnLeft()  //��ת
    {
        if (!is_Fast)
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
        else  //����
        {
            if (pose_.heading == 'N')
            {
                pose_.y += 1;
                pose_.heading = 'W';  //����ִ��
            }
            else if (pose_.heading == 'S')
            {
                pose_.y -= 1;
                pose_.heading = 'E';
            }
            else if (pose_.heading == 'E')
            {
                pose_.x += 1;
                pose_.heading = 'N';
            }
            else if (pose_.heading == 'W')
            {
                pose_.x -= 1;
                pose_.heading = 'S';
            }
        }
    }

    void TurnRight()  //��ת
    {
        if (!is_Fast) {
            if (pose_.heading == 'N')
                pose_.heading = 'E';
            else if (pose_.heading == 'S')
                pose_.heading = 'W';
            else if (pose_.heading == 'E')
                pose_.heading = 'S';
            else if (pose_.heading == 'W')
                pose_.heading = 'N';
        }
        else  //����
        {
            if (pose_.heading == 'N')
            {
                pose_.y += 1;
                pose_.heading = 'E';  //����ִ��
            }
            else if (pose_.heading == 'S')
            {
                pose_.y -= 1;
                pose_.heading = 'W';
            }
            else if (pose_.heading == 'E')
            {
                pose_.x += 1;
                pose_.heading = 'S';
            }
            else if (pose_.heading == 'W')
            {
                pose_.x -= 1;
                pose_.heading = 'N';
            }
        }
    }

    void Fast()  //����
    {
        is_Fast = !is_Fast;
    }

public:
    Pose pose_;  // ��Ա����λ��
    bool is_Fast;  // ��Ա��������
};