/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/CmdComplexAuto.h"

#include <frc2/command/InstantCommand.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/StartEndCommand.h>

using namespace AutoConstants;

CmdComplexAuto::CmdComplexAuto(SubDriveBase* drive) {
  AddCommands(
      // Drive forward the specified distance
      frc2::StartEndCommand([drive] { drive->ArcadeDrive(kAutoDriveSpeed1, 0); },
                            [drive] { drive->ArcadeDrive(0, 0); }, {drive})
          .BeforeStarting([drive] { drive->ResetEncoder(); })
          .WithInterrupt([drive] {
            return drive->GetEncoderDistance() >=
                   kAutoDriveDistanceInches1;
          }),
      // Drive backward the specified distance
      frc2::StartEndCommand(
          [drive] { drive->ArcadeDrive(-kAutoDriveSpeed2, 0); },
          [drive] { drive->ArcadeDrive(0, 0); }, {drive})
          .BeforeStarting([drive] { drive->ResetEncoder(); })
          .WithInterrupt([drive] {
            return drive->GetEncoderDistance() <=
                   kAutoBackupDistanceInches;
          }));
}
