/*
 * PID.cpp
 *
 *  Created on: 13 July, 2017
 *  Author: Junsheng Fu
 */

#include <iostream>
#include "PID.h"

using namespace std;

/**
 * Constructor
 */
PID::PID() {}

/**
 * Destructor.
 */
PID::~PID() {}


/**
 * Initialize PID.
 * @param kp the proportional value for PID controller
 * @param ki the integral value for PID controller
 * @param kd the derivative value for PID controller
 */
void PID::Init(double kp, double ki, double kd) {
  Kp = kp;
  Ki = ki;
  Kd = kd;

  p_error = 0;
  i_error = 0;
  d_error = 0;
}


/**
 * Update the PID error variables given cross track error
 * @param cte the current cross track error
 */
void PID::UpdateError(double cte) {

  double pre_cte = p_error;

  p_error  = cte;
  i_error += cte;
  d_error  = cte - pre_cte;
}


/**
 * Compute the control command value according to PID controller
 * @return the steering angle
 */
double PID::OutputSteerAng() {

  return -Kp*p_error - Ki*i_error - Kd*d_error;
}


/**
 * Compute the throttle by PID controller
 * @param max_thro max throttle value
 * @return the computed throttle value
 */
double PID::OutputThrottle(double max_thro){

  return max_thro - Kp*p_error - Ki*i_error - Kd*d_error;
}