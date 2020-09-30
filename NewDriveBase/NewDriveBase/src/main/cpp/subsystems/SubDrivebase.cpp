/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/SubDriveBase.h"
#include "commands/CmdDrive.h"

SubDriveBase::SubDriveBase() {
  _srxFrontLeft.reset(new WPI_TalonSRX(1));
  _srxFrontRight.reset(new WPI_TalonSRX(3));
  _srxBackLeft.reset(new WPI_TalonSRX(2));
  _srxBackRight.reset(new WPI_TalonSRX(4));
  _srxBackLeft->Follow(*_srxFrontLeft);
  _srxBackRight->Follow(*_srxFrontRight);

  SubDriveBase::DiffDrive.reset(new frc::DifferentialDrive(*_srxFrontLeft, *_srxFrontRight));
}

// This method will be called once per scheduler run
void SubDriveBase::Periodic() {
    
}
