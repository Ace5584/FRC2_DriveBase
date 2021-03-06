/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "Constants.h"
#include "subsystems/SubDriveBase.h"

/**
 * A complex auto command that drives forward and then drives backward.
 */
class CmdComplexAuto
    : public frc2::CommandHelper<frc2::SequentialCommandGroup, CmdComplexAuto> {
 public:
  /**
   * Creates a new ComplexAuto.
   *
   * @param drive The drive subsystem this command will run on
   */
  CmdComplexAuto(SubDriveBase* drive);
};