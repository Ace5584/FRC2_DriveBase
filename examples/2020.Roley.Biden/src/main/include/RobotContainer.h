/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/XboxController.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/Command.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/StartEndCommand.h>

#include "Constants.h"
#include "subsystems/SubDriveBase.h"
#include "commands/CmdComplexAuto.h"

namespace ac = AutoConstants;

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

  void SetupAutonomous();

  void SetupTeleop();

 private:
  // The driver's controller
  frc::XboxController m_driverController{OIConstants::kDriverControllerPort};

  // The robot's subsystems and commands are defined here...

  // The robot's subsystems
  SubDriveBase m_drive;

  // The autonomous routines
  frc2::ParallelRaceGroup m_simpleAuto1 =
      frc2::StartEndCommand(
          [this] { m_drive.ArcadeDrive(ac::kAutoDriveSpeed1, 0); },
          [this] { m_drive.ArcadeDrive(0, 0); }, {&m_drive})
          .BeforeStarting([this] { m_drive.ResetEncoder(); })
          .WithInterrupt([this] {
            return m_drive.GetEncoderDistance() >=
                   ac::kAutoDriveDistanceInches1;
          });
  frc2::ParallelRaceGroup m_simpleAuto2 =
      frc2::StartEndCommand(
          [this] { m_drive.ArcadeDrive(ac::kAutoDriveSpeed2, 0); },
          [this] { m_drive.ArcadeDrive(0, 0); }, {&m_drive})
          .BeforeStarting([this] { m_drive.ResetEncoder(); })
          .WithInterrupt([this] {
            return m_drive.GetEncoderDistance() >=
                   ac::kAutoDriveDistanceInches2;
          });
  CmdComplexAuto m_complexAuto1{&m_drive};

  // Assorted commands to be bound to buttons
  frc2::InstantCommand m_driveHalfSpeed{[this] { m_drive.SetMaxOutput(0.5); },
                                        {}};
  frc2::InstantCommand m_driveFullSpeed{[this] { m_drive.SetMaxOutput(1); },
                                        {}};

  // The chooser for the autonomous routines
  frc::SendableChooser<frc2::Command*> m_chooser;

  void ConfigureButtonBindings();
};
