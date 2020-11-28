/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/SubDrivebase.h"

class CmdDriveDistance
    : public frc2::CommandHelper<frc2::CommandBase, CmdDriveDistance> {
 public:
  CmdDriveDistance(double inches, double speed, SubDriveBase* subsystem);

  void Initialize() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  SubDriveBase* m_drive;
  double m_distance;
  double m_speed;
};

