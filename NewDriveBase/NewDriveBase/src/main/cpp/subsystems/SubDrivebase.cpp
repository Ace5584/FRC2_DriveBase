/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/SubDriveBase.h"
#include "commands/CmdDrive.h"
#include "Constants.h"

SubDriveBase::SubDriveBase() {
  _spmFrontLeft.reset(new rev::CANSparkMax(SPM_DriveBaseFrontLeft, rev::CANSparkMaxLowLevel::MotorType::kBrushless));
  _spmFrontRight.reset(new rev::CANSparkMax(SPM_DriveBaseFrontRight, rev::CANSparkMaxLowLevel::MotorType::kBrushless));
  _spmBackLeft.reset(new rev::CANSparkMax(SPM_DriveBaseBackLeft, rev::CANSparkMaxLowLevel::MotorType::kBrushless));
  _spmBackRight.reset(new rev::CANSparkMax(SPM_DriveBaseBackRight, rev::CANSparkMaxLowLevel::MotorType::kBrushless));

  _spmFrontLeft->RestoreFactoryDefaults();
  _spmFrontRight->RestoreFactoryDefaults();
  _spmBackLeft->RestoreFactoryDefaults();
  _spmBackRight->RestoreFactoryDefaults();

  _spmBackLeft->Follow(*_spmFrontLeft);
  _spmBackRight->Follow(*_spmFrontRight);

  SubDriveBase::DiffDrive.reset(new frc::DifferentialDrive(*_spmFrontLeft, *_spmFrontRight));
}

// This method will be called once per scheduler run
void SubDriveBase::Periodic() {
    
}
