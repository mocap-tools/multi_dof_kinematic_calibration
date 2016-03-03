#ifndef MULTI_DOF_KINEMATIC_CALIBRATION_PTUIMAGECAPTURE_H
#define MULTI_DOF_KINEMATIC_CALIBRATION_PTUIMAGECAPTURE_H

#include "visual_marker_mapping/CameraModel.h"

#include <vector>
#include <functional>
#include <opencv2/opencv.hpp>


// struct PanTiltImageInfo
//{
//    int cameraId = -1;
//    std::string imagePath;
//    double panAngle = 0.;
//    double tiltAngle = 0.;
//    int panTicks = 0;
//    int tiltTicks = 0;
//};

namespace multi_dof_kinematic_calibration
{
struct JointImageInfo
{
    int locationId;
    int cameraId = -1;
    std::string imagePath = "";
    std::vector<int> jointConfiguration; // jointName --> {ticks}
};


struct PtuImageCapture
{
    PtuImageCapture(const std::string& filePath);

    // contains for every camera the corresponding camera model
    std::map<int, visual_marker_mapping::CameraModel> cameraModelById;
    std::vector<JointImageInfo> ptuImagePoses;
    std::vector<std::string> jointNames;
};
}

#endif
