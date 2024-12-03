#include "MyExecutor.hpp"
#include "Command.hpp"
#include <string>
#include <map>
#include <functional>
#include <stdexcept>
#include <memory>
#include <iostream>

using namespace std;

namespace adas_Executor
{

    MyExecutor::MyExecutor(const Pose& pose_) noexcept: poseHandler(pose_){}   //构造函数，初始化姿态

    void MyExecutor::Execute(const std::string& command) noexcept  //读入命令并执行，然后更新姿态
    {      
        for (const auto cmd : command)
        {
            unordered_map<char, unique_ptr<ICommand>> cmderMap;
            cmderMap.emplace('M', std::make_unique<MoveCommand>());
            cmderMap.emplace('L', std::make_unique<TurnLeftCommand>());
            cmderMap.emplace('R', std::make_unique<TurnRightCommand>());
            cmderMap.emplace('F', std::make_unique<FastCommand>());
            cmderMap.emplace('B', std::make_unique<ReverseCommand>());

            const auto it = cmderMap.find(cmd);

            if (it != cmderMap.end())
            {
                it->second->DoOperate(poseHandler);
            }
        }
    }

    Pose MyExecutor::GetPose() const noexcept
    {
        return poseHandler.GetPose();
    }

    void MyExecutor::SetPose(const Pose& pose_) noexcept
    {
        poseHandler.SetPose(pose_);
    }
}