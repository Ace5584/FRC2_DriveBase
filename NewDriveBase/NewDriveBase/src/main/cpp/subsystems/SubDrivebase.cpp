/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/SubDriveBase.h"
#include "commands/CmdDrive.h"
#include "Constants.h"

SubDriveBase::SubDriveBase()
    : _spmFrontLeft{SPM_DriveBaseFrontLeft, rev::CANSparkMaxLowLevel::MotorType::kBrushless},
    _spmFrontRight{SPM_DriveBaseBackRight, rev::CANSparkMaxLowLevel::MotorType::kBrushless}, 
    _spmBackLeft{SPM_DriveBaseBackLeft, rev::CANSparkMaxLowLevel::MotorType::kBrushless},
    _spmBackRight{SPM_DriveBaseBackRight, rev::CANSparkMaxLowLevel::MotorType::kBrushless},
    m_dollyEncoder{kDollyEncoderPort}{

  m_dollyEncoder.ConfigFactoryDefault();

  _spmFrontRight.RestoreFactoryDefaults();
  _spmFrontLeft.RestoreFactoryDefaults();
  _spmBackLeft.RestoreFactoryDefaults();
  _spmBackRight.RestoreFactoryDefaults();

  _spmBackLeft.Follow(_spmFrontLeft);
  _spmBackRight.Follow(_spmFrontRight);
}

// Drive function to drive the robot
void SubDriveBase::Drive(double speed, double rotation){
  DiffDrive.ArcadeDrive(-speed, rotation);
}

// This method will be called once per scheduler run
void SubDriveBase::Periodic() {
    
}

void SubDriveBase::ResetEncoder() {
  m_dollyEncoder.SetSelectedSensorPosition(0.0);
}

double SubDriveBase::GetEncoderDistance(){
  return kDollyEncoderDistancePerPulse * m_dollyEncoder.GetSelectedSensorPosition();
}