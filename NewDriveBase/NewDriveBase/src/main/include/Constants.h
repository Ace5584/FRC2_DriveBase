/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <wpi/math>

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

constexpr int kDollyEncoderPort = 7; // REVISIT: this is a TalonSRX on ROLEY that is shared with another
                                     // subsystem so we need to do something smarter here (refer to 
                                     // Utilities/EncoderTalon code in 2020.Roley project)

enum SPM{
    SPM_DriveBaseFrontLeft = 1,
    SPM_DriveBaseBackLeft = 2,
    SPM_DriveBaseFrontRight = 3,
    SPM_DriveBaseBackRight = 4,
    SPM_ShooterLeft = 5,
    SPM_ShooterRight = 6,
};

namespace OIConstants {
    constexpr int kDriverControllerPort = 1;
}  // namespace OIConstants

namespace AutoConstants {
constexpr double kAutoDriveDistanceInches = 60;
constexpr double kAutoBackupDistanceInches = 20;
constexpr double kAutoDriveSpeed = 0.5;
}  // namespace AutoConstants

constexpr int kDollyEncoderCPR = 4096;
constexpr double kDollyWheelDiameterInches = 2;
constexpr double kDollyEncoderDistancePerPulse =
    (kDollyWheelDiameterInches * wpi::math::pi) / static_cast<double>(kDollyEncoderCPR);


