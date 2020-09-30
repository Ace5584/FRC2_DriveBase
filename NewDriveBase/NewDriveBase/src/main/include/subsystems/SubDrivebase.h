/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include<frc2/command/SubsystemBase.h>
#include<ctre/Phoenix.h>
#include<frc/drive/DifferentialDrive.h>
#include<frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/Subsystem.h>
#include<stdio.h>

class SubDriveBase : public frc2::SubsystemBase {
 public:
  SubDriveBase();
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();


 private:
  std::shared_ptr<WPI_TalonSRX> _srxFrontLeft;
  std::shared_ptr<WPI_TalonSRX> _srxFrontRight;
  std::shared_ptr<WPI_TalonSRX> _srxBackLeft;
  std::shared_ptr<WPI_TalonSRX> _srxBackRight;
  std::unique_ptr<frc::DifferentialDrive>DiffDrive;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
