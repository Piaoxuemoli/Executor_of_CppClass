#include "PoseHandler.hpp"

//PoseHandler类实现
namespace adas_Executor
{
    PoseHandler::PoseHandler(const Pose& in_pose) noexcept : pose_(in_pose) {} 
    //构造函数

    void PoseHandler::SetPose(const Pose& in_pose)//设置当前姿态
    {
        pose_ = in_pose;
    }

    void PoseHandler::Move() //移动
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

    void PoseHandler::TurnLeft()  //左转
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

    void PoseHandler::TurnRight()  //右转
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

    void PoseHandler::Backward()  //掉头
    {
        if (pose_.heading == 'N')
            pose_.heading = 'S';
        else if (pose_.heading == 'S')
            pose_.heading = 'N';
        else if (pose_.heading == 'E')
            pose_.heading = 'W';
        else if (pose_.heading == 'W')
            pose_.heading = 'E';
    }

    void PoseHandler::SetCar(std::string& car_type)   //设置车型
    {
        if (car_type == "Bus")
        {
            SetBus();
        }
        else if (car_type == "Roadster")
        {
            SetRoadster();
        }
    }

    void PoseHandler::Fast()  //快速
    {
        is_Fast = !is_Fast;
    }

    void PoseHandler::Reverse()  //倒车
    {
        is_Reverse = !is_Reverse;
    }

    void PoseHandler::SetBus()  //设置为Bus
    {
        is_Bus = !is_Bus;
    }

    void PoseHandler::SetRoadster()  //设置为跑车
    {
        is_Roadster = !is_Roadster;
    }

    Pose PoseHandler::GetPose() const  //获取当前姿态
    {
        return pose_;
    }

    bool PoseHandler::IsFast() const  //获取当前速度
    {
        return is_Fast;
    }

    bool PoseHandler::IsReverse() const  //获取当前倒车状态
    {
        return is_Reverse;
    }

    bool PoseHandler::IsBus() const  //获取当前是否为Bus
    {
        return is_Bus;
    }

    bool PoseHandler::IsRoadster() const  //获取当前是否为跑车
    {
        return is_Roadster;
    }
}