/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <wpi/math>
#include <rev/CANSparkMax.h>

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or bool constants.  This should not be used for any other purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace DriveConstants {

// TalonSRX CAN IDs
constexpr int kDollyEncoderPort = 7; // REVISIT: this is a TalonSRX on ROLEY that is shared with another
                                     // subsystem so we need to do something smarter here (refer to 
                                     // Utilities/EncoderTalon code in 2020.Roley project)

// REV Spark CAN IDs
constexpr int kLeftMotor1Port = 1;
constexpr int kLeftMotor2Port = 2;
constexpr int kRightMotor1Port = 3;
constexpr int kRightMotor2Port = 4;

constexpr rev::CANSparkMaxLowLevel::MotorType kLeftMotor1Type = rev::CANSparkMaxLowLevel::MotorType::kBrushless;
constexpr rev::CANSparkMaxLowLevel::MotorType kLeftMotor2Type = rev::CANSparkMaxLowLevel::MotorType::kBrushless;
constexpr rev::CANSparkMaxLowLevel::MotorType kRightMotor1Type = rev::CANSparkMaxLowLevel::MotorType::kBrushless;
constexpr rev::CANSparkMaxLowLevel::MotorType kRightMotor2Type = rev::CANSparkMaxLowLevel::MotorType::kBrushless;

constexpr rev::CANSparkMax::IdleMode kAutoMotorIdleMode = rev::CANSparkMax::IdleMode::kBrake;
constexpr rev::CANSparkMax::IdleMode kTeleMotorIdleMode = rev::CANSparkMax::IdleMode::kCoast;

constexpr double kAutoMotorOpenLoopRampRate = 0.4;
constexpr double kTeleMotorOpenLoopRampRate = 0.2;

constexpr int kDollyEncoderPorts[]{0, 1};
constexpr bool kDollyEncoderReversed = true;

constexpr int kDollyEncoderCPR = 4096;
constexpr double kDollyWheelDiameterInches = 2;
constexpr double kDollyEncoderDistancePerPulse =
    (kDollyWheelDiameterInches * wpi::math::pi) / static_cast<double>(kDollyEncoderCPR);
}  // namespace DriveConstants

namespace AutoConstants {
constexpr double kAutoDriveDistanceInches1 = 60;
constexpr double kAutoDriveDistanceInches2 = 30;
constexpr double kAutoDriveSpeed1 = 0.6;
constexpr double kAutoDriveSpeed2 = 0.3;
constexpr double kAutoBackupDistanceInches = 15;

}  // namespace AutoConstants

namespace OIConstants {
constexpr int kDriverControllerPort = 1;
}  // namespace OIConstants
