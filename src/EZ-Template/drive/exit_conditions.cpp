/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "EZ-Template/util.hpp"
#include "main.h"

using namespace ez;

void Drive::pid_drive_exit_condition_set(int p_small_exit_time, double p_small_error, int p_big_exit_time, double p_big_error, int p_velocity_exit_time, int p_mA_timeout) {
  leftPID.exit_condition_set(p_small_exit_time, p_small_error, p_big_exit_time, p_big_error, p_velocity_exit_time, p_mA_timeout);
  rightPID.exit_condition_set(p_small_exit_time, p_small_error, p_big_exit_time, p_big_error, p_velocity_exit_time, p_mA_timeout);
  forward_drivePID.exit_condition_set(p_small_exit_time, p_small_error, p_big_exit_time, p_big_error, p_velocity_exit_time, p_mA_timeout);
}

void Drive::pid_drive_exit_condition_set(okapi::QTime p_small_exit_time, okapi::QLength p_small_error, okapi::QTime p_big_exit_time, okapi::QLength p_big_error, okapi::QTime p_velocity_exit_time, okapi::QTime p_mA_timeout) {
  // Convert okapi units to doubles
  double se = p_small_error.convert(okapi::inch);
  double be = p_big_error.convert(okapi::inch);
  double set = p_small_exit_time.convert(okapi::millisecond);
  double bet = p_big_exit_time.convert(okapi::millisecond);
  double vet = p_velocity_exit_time.convert(okapi::millisecond);
  double mAt = p_mA_timeout.convert(okapi::millisecond);

  pid_drive_exit_condition_set(set, se, bet, be, vet, mAt);
}

void Drive::pid_turn_exit_condition_set(int p_small_exit_time, double p_small_error, int p_big_exit_time, double p_big_error, int p_velocity_exit_time, int p_mA_timeout) {
  turnPID.exit_condition_set(p_small_exit_time, p_small_error, p_big_exit_time, p_big_error, p_velocity_exit_time, p_mA_timeout);
}

void Drive::pid_turn_exit_condition_set(okapi::QTime p_small_exit_time, okapi::QAngle p_small_error, okapi::QTime p_big_exit_time, okapi::QAngle p_big_error, okapi::QTime p_velocity_exit_time, okapi::QTime p_mA_timeout) {
  // Convert okapi units to doubles
  double se = p_small_error.convert(okapi::degree);
  double be = p_big_error.convert(okapi::degree);
  double set = p_small_exit_time.convert(okapi::millisecond);
  double bet = p_big_exit_time.convert(okapi::millisecond);
  double vet = p_velocity_exit_time.convert(okapi::millisecond);
  double mAt = p_mA_timeout.convert(okapi::millisecond);

  pid_turn_exit_condition_set(set, se, bet, be, vet, mAt);
}

void Drive::pid_odom_drive_exit_condition_set(int p_small_exit_time, double p_small_error, int p_big_exit_time, double p_big_error, int p_velocity_exit_time, int p_mA_timeout) {
  xyPID.exit_condition_set(p_small_exit_time, p_small_error, p_big_exit_time, p_big_error, p_velocity_exit_time, p_mA_timeout);
}

void Drive::pid_odom_drive_exit_condition_set(okapi::QTime p_small_exit_time, okapi::QLength p_small_error, okapi::QTime p_big_exit_time, okapi::QLength p_big_error, okapi::QTime p_velocity_exit_time, okapi::QTime p_mA_timeout) {
  // Convert okapi units to doubles
  double se = p_small_error.convert(okapi::inch);
  double be = p_big_error.convert(okapi::inch);
  double set = p_small_exit_time.convert(okapi::millisecond);
  double bet = p_big_exit_time.convert(okapi::millisecond);
  double vet = p_velocity_exit_time.convert(okapi::millisecond);
  double mAt = p_mA_timeout.convert(okapi::millisecond);

  pid_odom_drive_exit_condition_set(set, se, bet, be, vet, mAt);
}

void Drive::pid_odom_turn_exit_condition_set(int p_small_exit_time, double p_small_error, int p_big_exit_time, double p_big_error, int p_velocity_exit_time, int p_mA_timeout) {
  aPID.exit_condition_set(p_small_exit_time, p_small_error, p_big_exit_time, p_big_error, p_velocity_exit_time, p_mA_timeout);
}

void Drive::pid_odom_turn_exit_condition_set(okapi::QTime p_small_exit_time, okapi::QAngle p_small_error, okapi::QTime p_big_exit_time, okapi::QAngle p_big_error, okapi::QTime p_velocity_exit_time, okapi::QTime p_mA_timeout) {
  // Convert okapi units to doubles
  double se = p_small_error.convert(okapi::degree);
  double be = p_big_error.convert(okapi::degree);
  double set = p_small_exit_time.convert(okapi::millisecond);
  double bet = p_big_exit_time.convert(okapi::millisecond);
  double vet = p_velocity_exit_time.convert(okapi::millisecond);
  double mAt = p_mA_timeout.convert(okapi::millisecond);

  pid_odom_turn_exit_condition_set(set, se, bet, be, vet, mAt);
}

void Drive::pid_swing_exit_condition_set(int p_small_exit_time, double p_small_error, int p_big_exit_time, double p_big_error, int p_velocity_exit_time, int p_mA_timeout) {
  swingPID.exit_condition_set(p_small_exit_time, p_small_error, p_big_exit_time, p_big_error, p_velocity_exit_time, p_mA_timeout);
}

void Drive::pid_swing_exit_condition_set(okapi::QTime p_small_exit_time, okapi::QAngle p_small_error, okapi::QTime p_big_exit_time, okapi::QAngle p_big_error, okapi::QTime p_velocity_exit_time, okapi::QTime p_mA_timeout) {
  // Convert okapi units to doubles
  double se = p_small_error.convert(okapi::degree);
  double be = p_big_error.convert(okapi::degree);
  double set = p_small_exit_time.convert(okapi::millisecond);
  double bet = p_big_exit_time.convert(okapi::millisecond);
  double vet = p_velocity_exit_time.convert(okapi::millisecond);
  double mAt = p_mA_timeout.convert(okapi::millisecond);

  pid_swing_exit_condition_set(set, se, bet, be, vet, mAt);
}

// User wrapper for exit condition
void Drive::pid_wait() {
  // Let the PID run at least 1 iteration
  pros::delay(util::DELAY_TIME);

  if (mode == DRIVE) {
    exit_output left_exit = RUNNING;
    exit_output right_exit = RUNNING;
    while (left_exit == RUNNING || right_exit == RUNNING) {
      left_exit = left_exit != RUNNING ? left_exit : leftPID.exit_condition(left_motors[0]);
      right_exit = right_exit != RUNNING ? right_exit : rightPID.exit_condition(right_motors[0]);
      pros::delay(util::DELAY_TIME);
    }
    if (print_toggle) std::cout << "  Left: " << exit_to_string(left_exit) << " Exit, error: " << leftPID.error << ".   Right: " << exit_to_string(right_exit) << " Exit, error: " << rightPID.error << ".\n";

    if (left_exit == mA_EXIT || left_exit == VELOCITY_EXIT || right_exit == mA_EXIT || right_exit == VELOCITY_EXIT) {
      interfered = true;
    }
  }

  // Point to Point Exit
  else if (mode == POINT_TO_POINT || mode == PURE_PURSUIT) {
    exit_output xy_exit = RUNNING;
    exit_output a_exit = RUNNING;

    // Wait until pure pursuit is on the last point, then continue as normal
    if (mode == PURE_PURSUIT) {
      while (pp_index != pp_movements.size() - 1) {
        xy_exit = xy_exit != RUNNING ? xy_exit : xyPID.exit_condition({left_motors[0], right_motors[0]});
        a_exit = a_exit != RUNNING ? a_exit : aPID.exit_condition({left_motors[0], right_motors[0]});

        if (xy_exit == mA_EXIT || xy_exit == VELOCITY_EXIT || a_exit == mA_EXIT || a_exit == VELOCITY_EXIT)
          break;

        pros::delay(util::DELAY_TIME);
      }
    }

    // When we're at the last point in PP / we're just going to point
    while (xy_exit == RUNNING || a_exit == RUNNING) {
      xy_exit = xy_exit != RUNNING ? xy_exit : xyPID.exit_condition({left_motors[0], right_motors[0]});
      a_exit = a_exit != RUNNING ? a_exit : aPID.exit_condition({left_motors[0], right_motors[0]});
      pros::delay(util::DELAY_TIME);
    }
    if (print_toggle) std::cout << "  XY: " << exit_to_string(xy_exit) << " Exit, error: " << xyPID.error << ".   Angle: " << exit_to_string(a_exit) << " Exit, error: " << aPID.error << ".\n";

    if (xy_exit == mA_EXIT || xy_exit == VELOCITY_EXIT || a_exit == mA_EXIT || a_exit == VELOCITY_EXIT) {
      interfered = true;
    }
  }

  // Turn Exit
  else if (mode == TURN || mode == TURN_TO_POINT) {
    exit_output turn_exit = RUNNING;
    while (turn_exit == RUNNING) {
      turn_exit = turn_exit != RUNNING ? turn_exit : turnPID.exit_condition({left_motors[0], right_motors[0]});
      pros::delay(util::DELAY_TIME);
    }
    if (print_toggle) std::cout << "  Turn: " << exit_to_string(turn_exit) << " Exit, error: " << turnPID.error << ".\n";

    if (turn_exit == mA_EXIT || turn_exit == VELOCITY_EXIT) {
      interfered = true;
    }
  }

  // Swing Exit
  else if (mode == SWING) {
    exit_output swing_exit = RUNNING;
    pros::Motor& sensor = current_swing == ez::LEFT_SWING ? left_motors[0] : right_motors[0];
    while (swing_exit == RUNNING) {
      swing_exit = swing_exit != RUNNING ? swing_exit : swingPID.exit_condition(sensor);
      pros::delay(util::DELAY_TIME);
    }
    if (print_toggle) std::cout << "  Swing: " << exit_to_string(swing_exit) << " Exit, error: " << swingPID.error << ".\n";

    if (swing_exit == mA_EXIT || swing_exit == VELOCITY_EXIT) {
      interfered = true;
    }
  }
}

void Drive::wait_until_drive(double target) {
  pros::delay(10);

  // Make sure mode is correct
  if (!(mode == DRIVE || mode == POINT_TO_POINT || mode == PURE_PURSUIT)) {
    printf("Mode needs to be drive!\n");
    return;
  }

  // Calculate error between current and target (target needs to be an in between position)
  double l_tar = l_start + target;
  double r_tar = r_start + target;
  double l_error = l_tar - drive_sensor_left();
  double r_error = r_tar - drive_sensor_right();
  double l_sgn = util::sgn(l_error);
  double r_sgn = util::sgn(r_error);

  exit_output left_exit = RUNNING;
  exit_output right_exit = RUNNING;

  while (true) {
    l_error = l_tar - drive_sensor_left();
    r_error = r_tar - drive_sensor_right();

    // Before robot has reached target, use the exit conditions to avoid getting stuck in this while loop
    if (util::sgn(l_error) == l_sgn || util::sgn(r_error) == r_sgn) {
      if (left_exit == RUNNING || right_exit == RUNNING) {
        left_exit = left_exit != RUNNING ? left_exit : leftPID.exit_condition(left_motors[0]);
        right_exit = right_exit != RUNNING ? right_exit : rightPID.exit_condition(right_motors[0]);
        pros::delay(util::DELAY_TIME);
      } else {
        if (print_toggle) std::cout << "  Left: " << exit_to_string(left_exit) << " Wait Until Exit.   Right: " << exit_to_string(right_exit) << " Wait Until Exit.\n";

        if (left_exit == mA_EXIT || left_exit == VELOCITY_EXIT || right_exit == mA_EXIT || right_exit == VELOCITY_EXIT) {
          interfered = true;
        }
        return;
      }
    }
    // Once we've past target, return
    else if (util::sgn(l_error) != l_sgn || util::sgn(r_error) != r_sgn) {
      if (print_toggle) printf("  Drive Wait Until Exit.  Left: %f   Right: %f\n", drive_sensor_left() - l_start, drive_sensor_right() - r_start);
      return;
    }

    pros::delay(util::DELAY_TIME);
  }
}

// Function to wait until a certain position is reached.  Wrapper for exit condition.
void Drive::wait_until_turn_swing(double target) {
  // Make sure mode is correct
  if (!(mode == TURN || mode == TURN_TO_POINT || mode == SWING)) {
    printf("Mode needs to be swing or turn!\n");
    return;
  }

  // Calculate error between current and target (target needs to be an in between position)
  double g_error = target - drive_imu_get();
  double g_sgn = util::sgn(g_error);

  exit_output turn_exit = RUNNING;
  exit_output swing_exit = RUNNING;

  pros::Motor& sensor = current_swing == ez::LEFT_SWING ? left_motors[0] : right_motors[0];

  while (true) {
    g_error = target - drive_imu_get();

    // If turning...
    if (mode == TURN || mode == TURN_TO_POINT) {
      // Before robot has reached target, use the exit conditions to avoid getting stuck in this while loop
      if (util::sgn(g_error) == g_sgn) {
        if (turn_exit == RUNNING) {
          turn_exit = turn_exit != RUNNING ? turn_exit : turnPID.exit_condition({left_motors[0], right_motors[0]});
          pros::delay(util::DELAY_TIME);
        } else {
          if (print_toggle) std::cout << "  Turn: " << exit_to_string(turn_exit) << " Wait Until Exit.\n";

          if (turn_exit == mA_EXIT || turn_exit == VELOCITY_EXIT) {
            interfered = true;
          }
          return;
        }
      }
      // Once we've past target, return
      else if (util::sgn(g_error) != g_sgn) {
        if (print_toggle) printf("  Turn Wait Until Exit.  Triggered at: %f\n", drive_imu_get());
        return;
      }
    }

    // If swinging...
    else {
      // Before robot has reached target, use the exit conditions to avoid getting stuck in this while loop
      if (util::sgn(g_error) == g_sgn) {
        if (swing_exit == RUNNING) {
          swing_exit = swing_exit != RUNNING ? swing_exit : swingPID.exit_condition(sensor);
          pros::delay(util::DELAY_TIME);
        } else {
          if (print_toggle) std::cout << "  Swing: " << exit_to_string(swing_exit) << " Wait Until Exit.\n";

          if (swing_exit == mA_EXIT || swing_exit == VELOCITY_EXIT) {
            interfered = true;
          }
          return;
        }
      }
      // Once we've past target, return
      else if (util::sgn(g_error) != g_sgn) {
        if (print_toggle) std::cout << "  Swing Wait Until Exit.\n";
        return;
      }
    }

    pros::delay(util::DELAY_TIME);
  }
}

void Drive::pid_wait_until(okapi::QLength target) {
  // If robot is driving...
  if (mode == DRIVE || mode == POINT_TO_POINT || mode == PURE_PURSUIT) {
    wait_until_drive(target.convert(okapi::inch));
  } else {
    printf("QLength not supported for turn or swing!\n");
  }
}

void Drive::pid_wait_until(okapi::QAngle target) {
  // If robot is driving...
  if (mode == TURN || mode == TURN_TO_POINT || mode == SWING) {
    wait_until_turn_swing(target.convert(okapi::degree));
  } else {
    printf("QAngle not supported for drive!\n");
  }
}

void Drive::pid_wait_until(double target) {
  // If driving...
  if (mode == DRIVE || mode == POINT_TO_POINT || mode == PURE_PURSUIT) {
    wait_until_drive(target);
  }
  // If turning or swinging...
  else if (mode == TURN || mode == TURN_TO_POINT || mode == SWING) {
    wait_until_turn_swing(target);
  } else {
    printf("Not in a valid drive mode!\n");
  }
}

void Drive::pid_wait_until_pp(int index) {
  // Let the PID run at least 1 iteration
  pros::delay(util::DELAY_TIME);

  if (index > injected_pp_index.size() || index < 0)
    printf("  Wait Until PP Error!  Index %i is not within range!  %i is max!\n", index, injected_pp_index.size());

  while (pp_index < injected_pp_index[index]) {
    pros::delay(util::DELAY_TIME);
  }
  if (print_toggle) printf("  Wait Until PP at (%f, %f)\n", pp_movements[pp_index].target.x, pp_movements[pp_index].target.y);
}