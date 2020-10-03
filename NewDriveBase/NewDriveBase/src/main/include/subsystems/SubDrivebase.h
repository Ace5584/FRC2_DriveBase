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
#include <rev/CANSparkMax.h>
#include<stdio.h>

class SubDriveBase : public frc2::SubsystemBase {
 public:
  SubDriveBase();
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */

  void Drive(double speed, double rotation, bool squaredInputs = true);

  void Periodic();


 private:
  std::shared_ptr<rev::CANSparkMax> _spmFrontLeft;
  std::shared_ptr<rev::CANSparkMax> _spmFrontRight;
  std::shared_ptr<rev::CANSparkMax> _spmBackLeft;
  std::shared_ptr<rev::CANSparkMax> _spmBackRight;
  std::unique_ptr<frc::DifferentialDrive>DiffDrive;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
