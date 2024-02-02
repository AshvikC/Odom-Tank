/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#pragma once

#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>

#include "api.h"

/**
 * Controller.
 */
extern pros::Controller master;

namespace ez {

/**
 * Prints our branding all over your pros terminal
 */
void ez_template_print();

/**
 * Prints to the brain screen in one string.  Splits input between lines with
 * '\n' or when text longer then 32 characters.
 *
 * @param text
 *        Input string.  Use '\n' for a new line
 * @param line
 *        Starting line to print on, defaults to 0
 */
void screen_print(std::string text, int line = 0);

/////
//
// Public Variables
//
/////

/**
 * Enum for split and single stick arcade.
 */
enum e_type { SINGLE = 0,
              SPLIT = 1 };

/**
 * Enum for split and single stick arcade.
 */
enum e_swing { LEFT_SWING = 0,
               RIGHT_SWING = 1 };

/**
 * Enum for PID::exit_condition outputs.
 */
enum exit_output { RUNNING = 1,
                   SMALL_EXIT = 2,
                   BIG_EXIT = 3,
                   VELOCITY_EXIT = 4,
                   mA_EXIT = 5,
                   ERROR_NO_CONSTANTS = 6 };

/**
 * Enum for split and single stick arcade.
 */
enum e_mode { DISABLE = 0,
              SWING = 1,
              TURN = 2,
              TURN_TO_POINT = 3,
              DRIVE = 4 };

/**
 * Enum for turn types
 */
enum turn_types { FWD = 0,
                  fwd = FWD,
                  REV = 1,
                  rev = REV,
};

typedef struct pose {
  double x;
  double y;
  double theta;
} pose;

/**
 * Outputs string for exit_condition enum.
 */
std::string exit_to_string(exit_output input);

namespace util {
extern bool AUTON_RAN;

/**
 * Returns 1 if input is positive and -1 if input is negative
 */
int sgn(double input);

/**
 * Returns true if the input is < 0
 */
bool reversed_active(double input);

/**
 * Returns input restricted to min-max threshold
 */
double clamp(double input, double max, double min);

/**
 * Is the SD card plugged in?
 */
const bool SD_CARD_ACTIVE = pros::usd::is_installed();

/**
 * Delay time for tasks
 */
const int DELAY_TIME = 10;

double to_deg(double input);
double to_rad(double input);
double absolute_angle_to_point(pose itarget, pose icurrent);
double wrap_angle(double theta);

}  // namespace util
}  // namespace ez
