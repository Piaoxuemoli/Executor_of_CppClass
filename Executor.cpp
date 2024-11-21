#include "Executor.h"
#include <string>
#include <map>
#include <functional>
#include <stdexcept>
#include <memory>

using namespace std;
using namespace adas_Executor;

class MyExecutor : public Executor  //抽象adas_Executor的实现
{
public:
    MyExecutor()
    {
        IniPose(Pose(0, 0, 'N'));  //初始化初始姿态
        //根据命令调用对应的函数
        commandMap["M"] = [this]() { Move(); };
        commandMap["L"] = [this]() { TurnLeft(); };
        commandMap["R"] = [this]() { TurnRight(); };
    }

public:
    void IniPose(const Pose& pose) override  //初始化姿态
    {
        pose_ = pose;
    }

    void Execute(const std::string& command) override  //读入命令并执行，然后更新姿态
    {
        // 检查命令是否存在
        if (commandMap.find(command) != commandMap.end())
        {
            // 执行对应的命令
            commandMap[command]();
        }
        else
        {
            // 处理未知命令
            throw std::invalid_argument("Unknown command: " + command);
        }
    }

    Pose GetPose() const override  //获取当前姿态
    {
        return pose_;
    }

private:
    Pose pose_;  // 成员变量位姿
    std::map<std::string, std::function<void()>> commandMap;  //根据命令调用对应的函数
    void Move() //移动
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
};