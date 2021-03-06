/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc2/command/Subsystem.h>
#include <rev/CANSparkMax.h>
#include <frc/SpeedControllerGroup.h>
#include <ctre/Phoenix.h>

#include "Constants.h"

class SubDriveBase : public frc2::SubsystemBase {
 public:
  SubDriveBase();
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */

  void Drive(double speed, double rotation);

  void Periodic();
  
  void ResetEncoder();

  double GetEncoderDistance();


 private:
  rev::CANSparkMax _spmFrontLeft;
  rev::CANSparkMax _spmFrontRight;
  rev::CANSparkMax _spmBackLeft;
  rev::CANSparkMax _spmBackRight;

  frc::SpeedControllerGroup _spmLeftGroup{_spmFrontLeft, _spmFrontRight};
  frc::SpeedControllerGroup _spmRightGroup{_spmBackLeft, _spmFrontRight};

  frc::DifferentialDrive DiffDrive{_spmLeftGroup, _spmRightGroup};

  ctre::phoenix::motorcontrol::can::TalonSRX m_dollyEncoder;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
