/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/CmdDriveDistance.h"

#include <cmath>

CmdDriveDistance::CmdDriveDistance(double inches, double speed,
                             SubDriveBase* subsystem)
    : m_drive(subsystem), m_distance(inches), m_speed(speed) {
  AddRequirements({subsystem});
}

void CmdDriveDistance::Initialize() {
  m_drive->Drive(m_speed, 0);
}

void CmdDriveDistance::End(bool interrupted) { m_drive->Drive(0, 0); }

bool CmdDriveDistance::IsFinished() {
  return std::abs(m_drive->GetEncoderDistance()) >= m_distance;
}
