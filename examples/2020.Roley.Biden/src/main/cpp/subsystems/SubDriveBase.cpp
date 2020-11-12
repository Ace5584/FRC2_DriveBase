/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/SubDriveBase.h"

using namespace DriveConstants;

SubDriveBase::SubDriveBase()
    : m_left1{kLeftMotor1Port,kLeftMotor1Type},
      m_left2{kLeftMotor2Port,kLeftMotor2Type},
      m_right1{kRightMotor1Port,kRightMotor1Type},
      m_right2{kRightMotor2Port,kRightMotor2Type},
      m_dollyEncoder{kDollyEncoderPort} {
  
  // Make sure REV Spark motor controllers are not carrying any baggage
  m_left1.RestoreFactoryDefaults();
  m_left2.RestoreFactoryDefaults();
  m_right1.RestoreFactoryDefaults();
  m_right2.RestoreFactoryDefaults();

  // Make sure CTRE Talon motor controllers are not carrying any baggage
  m_dollyEncoder.ConfigFactoryDefault();

  // Set followers to follow
  m_left2.Follow(m_left1);
  m_right2.Follow(m_right1);

}

void SubDriveBase::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void SubDriveBase::ArcadeDrive(double fwd, double rot) {
  m_drive.ArcadeDrive(fwd, rot);
}

void SubDriveBase::ResetEncoder() {
  m_dollyEncoder.SetSelectedSensorPosition(0.0);
}

double SubDriveBase::GetEncoderDistance() {
  return kDollyEncoderDistancePerPulse * m_dollyEncoder.GetSelectedSensorPosition();
  ;
}

ctre::phoenix::motorcontrol::can::TalonSRX& SubDriveBase::GetEncoder() { return m_dollyEncoder; }

void SubDriveBase::SetMaxOutput(double maxOutput) {
  m_drive.SetMaxOutput(maxOutput);
}

void SubDriveBase::AutoConfig() {
  m_left1.SetIdleMode(kAutoMotorIdleMode);
  m_left2.SetIdleMode(kAutoMotorIdleMode);
  m_right1.SetIdleMode(kAutoMotorIdleMode);
  m_right2.SetIdleMode(kAutoMotorIdleMode);
  m_left1.SetOpenLoopRampRate(kAutoMotorOpenLoopRampRate);
  m_left2.SetOpenLoopRampRate(kAutoMotorOpenLoopRampRate);
  m_right1.SetOpenLoopRampRate(kAutoMotorOpenLoopRampRate);
  m_right2.SetOpenLoopRampRate(kAutoMotorOpenLoopRampRate);
}

void SubDriveBase::TeleConfig() {
  m_left1.SetIdleMode(kTeleMotorIdleMode);
  m_left2.SetIdleMode(kTeleMotorIdleMode);
  m_right1.SetIdleMode(kTeleMotorIdleMode);
  m_right2.SetIdleMode(kTeleMotorIdleMode);
  m_left1.SetOpenLoopRampRate(kTeleMotorOpenLoopRampRate);
  m_left2.SetOpenLoopRampRate(kTeleMotorOpenLoopRampRate);
  m_right1.SetOpenLoopRampRate(kTeleMotorOpenLoopRampRate);
  m_right2.SetOpenLoopRampRate(kTeleMotorOpenLoopRampRate);
}
