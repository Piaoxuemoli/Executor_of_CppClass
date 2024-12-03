#include "PoseHandler.hpp"

//PoseHandler��ʵ��
namespace adas_Executor
{
    PoseHandler::PoseHandler(const Pose& in_pose) noexcept : pose_(in_pose) {} 
    //���캯��

    void PoseHandler::SetPose(const Pose& in_pose)//���õ�ǰ��̬
    {
        pose_ = in_pose;
    }

    void PoseHandler::Move() //�ƶ�
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

    void PoseHandler::TurnLeft()  //��ת
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

    void PoseHandler::TurnRight()  //��ת
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

    void PoseHandler::Backward()  //��ͷ
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

    void PoseHandler::Fast()  //����
    {
        is_Fast = !is_Fast;
    }

    void PoseHandler::Reverse()  //����
    {
        is_Reverse = !is_Reverse;
    }

    Pose PoseHandler::GetPose() const  //��ȡ��ǰ��̬
    {
        return pose_;
    }

    bool PoseHandler::IsFast() const  //��ȡ��ǰ�ٶ�
    {
        return is_Fast;
    }

    bool PoseHandler::IsReverse() const  //��ȡ��ǰ����״̬
    {
        return is_Reverse;
    }
}