#include "Executor.h"
#include <string>
#include <map>
#include <functional>

using namespace std;
using namespace adas_Executor;

class MyExecutor : public Executor  //抽象adas_Executor的实现
{
public:
    MyExecutor()
    {
        IniPose(Pose(0, 0, 'N'));  //初始化初始姿态
    }  

public:
    void IniPose(const Pose& pose) override  //初始化姿态
    {
        pose_ = pose;
    }

    void Execute(const std::string& command) override  //读入命令并执行，然后更新姿态
    {
        std::map<std::string, std::function<void()>> commandMap;  //根据命令调用对应的函数
        commandMap["M"] = [this]() { Move(); };
        commandMap["L"] = [this]() { TurnLeft(); };
        commandMap["R"] = [this]() { TurnRight(); };
    }

    void Move() //移动
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

    void TurnLeft()  //左转
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

    void TurnRight()  //右转
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

    Pose GetPose() const override  //获取当前姿态
    {
        return pose_;
    }

private:
    Pose pose_;  // 成员变量位姿
};