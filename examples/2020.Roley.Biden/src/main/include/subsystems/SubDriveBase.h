/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/Encoder.h>
#include <frc2/command/SubsystemBase.h>

#include <rev/CANSparkMax.h>
#include <ctre/Phoenix.h>

#include "Constants.h"

class SubDriveBase : public frc2::SubsystemBase {
 public:
  SubDriveBase();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  // Subsystem methods go here.

  /**
   * Drives the robot using arcade controls.
   *
   * @param fwd the commanded forward movement
   * @param rot the commanded rotation
   */
  void ArcadeDrive(double fwd, double rot);

  /**
   * Resets the dolly encoder to currently read a position of 0.
   */
  void ResetEncoder();

  /**
   * Gets the distance of the encoder.
   *
   * @return the encoder reading
   */
  double GetEncoderDistance();

  /**
   * Gets the dolly encoder.
   *
   * @return the dolly encoder
   */
  ctre::phoenix::motorcontrol::can::TalonSRX& GetEncoder();

  /**
   * Sets the max output of the drive.  Useful for scaling the drive to drive
   * more slowly.
   *
   * @param maxOutput the maximum output to which the drive will be constrained
   */
  void SetMaxOutput(double maxOutput);

  /**
   * Set up drive base for Autonomus Period
   */
  void AutoConfig();

  /**
   * Set up drive base for Teleop Period
   */
  void TeleConfig();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  // The motor controllers
  rev::CANSparkMax m_left1;
  rev::CANSparkMax m_left2;
  rev::CANSparkMax m_right1;
  rev::CANSparkMax m_right2;

  // The motors on the left side of the drive
  frc::SpeedControllerGroup m_leftMotors{m_left1, m_left2};

  // The motors on the right side of the drive
  frc::SpeedControllerGroup m_rightMotors{m_right1, m_right2};

  // The robot's drive
  frc::DifferentialDrive m_drive{m_leftMotors, m_rightMotors};

  // The dolly encoder
  ctre::phoenix::motorcontrol::can::TalonSRX m_dollyEncoder;

};
