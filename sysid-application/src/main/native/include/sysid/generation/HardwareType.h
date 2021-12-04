// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <array>
#include <string_view>

namespace sysid {
struct HardwareType {
  /**
   * The name of the hardware device to facillitate comparisons
   */
  std::string_view name;

  /**
   * The display name of the hardware device to facilitate GUI display
   */
  const char* displayName;

  constexpr explicit HardwareType(std::string_view deviceName)
      : name{deviceName}, displayName{name.data()} {}

  constexpr bool operator==(const HardwareType& rhs) const {
    return name == rhs.name;
  }
  constexpr bool operator!=(const HardwareType& rhs) const {
    return !operator==(rhs);
  }
};

namespace motorcontroller {

constexpr HardwareType kPWM{"PWM"};
constexpr HardwareType kTalonSRX{"TalonSRX"};
constexpr HardwareType kVictorSPX{"VictorSPX"};
constexpr HardwareType kTalonFX{"TalonFX"};
constexpr HardwareType kSPARKMAXBrushless{"SPARK MAX (Brushless)"};
constexpr HardwareType kSPARKMAXBrushed{"SPARK MAX (Brushed)"};
constexpr HardwareType kVenom{"Venom"};

constexpr std::array<HardwareType, 7> kMotorControllers = {
    kPWM,     kTalonSRX,          kVictorSPX,
    kTalonFX, kSPARKMAXBrushless, kSPARKMAXBrushed,
    kVenom};

/**
 * Returns an existing motor controller HardwareType from a string_view. Throws
 * if the passed name doesn't exist.
 *
 * @param name The name of the motor controller.
 *
 * @return The motor controller HardwareType associated with the inputted name.
 */
HardwareType FromMotorControllerName(std::string_view name);
}  // namespace motorcontroller

namespace encoder {
constexpr HardwareType kRoboRIO{"roboRIO quadrature"};
constexpr HardwareType kCANCoder{"CANCoder"};
constexpr HardwareType kBuiltInSetting{"Built-in"};
constexpr HardwareType kCTRETachometer{"Tachometer"};
constexpr HardwareType kSMaxEncoderPort{"Encoder Port"};
constexpr HardwareType kSMaxDataPort{"Data Port"};

constexpr std::array<HardwareType, 6> kEncoders = {
    kRoboRIO,        kCANCoder,        kBuiltInSetting,
    kCTRETachometer, kSMaxEncoderPort, kSMaxDataPort};

/**
 * Returns an existing encoder HardwareType from a string_view. Throws if the
 * passed name doesn't exist.
 *
 * @param name The name of the encoder.
 *
 * @return The encoder HardwareType associated with the inputted name.
 */
HardwareType FromEncoderName(std::string_view name);
}  // namespace encoder

namespace gyro {
constexpr HardwareType kAnalogGyro{"Analog Gyro"};
constexpr HardwareType kADXRS450{"ADXRS450"};
constexpr HardwareType kNavX{"NavX"};
constexpr HardwareType kPigeon{"Pigeon"};
constexpr HardwareType kRomiGyro{"Romi"};
constexpr HardwareType kNoGyroOption{"None"};

constexpr std::array<HardwareType, 6> kGyros = {
    kAnalogGyro, kADXRS450, kNavX, kPigeon, kRomiGyro, kNoGyroOption};

/**
 * Returns an existing gyro HardwareType from a string_view. Throws if the
 * passed name doesn't exist.
 *
 * @param name The name of the gyro.
 *
 * @return The gyro HardwareType associated with the inputted name.
 */
HardwareType FromGyroName(std::string_view name);
}  // namespace gyro
}  // namespace sysid