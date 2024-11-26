#include "Executor.h"
#include <string>
#include <map>
#include <functional>
#include <stdexcept>
#include <memory>
#include <iostream>

using namespace std;
using namespace adas_Executor;

class MyExecutor : public Executor  //抽象adas_Executor的实现
{
public:
    MyExecutor()
    {
        IniPose(Pose(0, 0, 'N'));  //初始化初始姿态
        is_Fast = 0;  //初始化快速为0
    }

public:
    void IniPose(const Pose& pose) override  //初始化姿态
    {
        pose_ = pose;
    }

    void Execute(const std::string& command) override  //读入命令并执行，然后更新姿态
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

    Pose GetPose() const override  //获取当前姿态
    {
        return pose_;
    }

    void Move() //移动
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
        else  //快速
        {
            if (pose_.heading == 'N')
            {
                pose_.y += 1;
                pose_.y += 1;  //两步执行
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

    void TurnLeft()  //左转
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
        else  //快速
        {
            if (pose_.heading == 'N')
            {
                pose_.y += 1;
                pose_.heading = 'W';  //两步执行
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

    void TurnRight()  //右转
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
        else  //快速
        {
            if (pose_.heading == 'N')
            {
                pose_.y += 1;
                pose_.heading = 'E';  //两步执行
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

    void Fast()  //快速
    {
        is_Fast = !is_Fast;
    }

public:
    Pose pose_;  // 成员变量位姿
    bool is_Fast;  // 成员变量快速
};