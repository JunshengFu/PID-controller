/*
 * PID.h
 *
 *  Created on: 13 July, 2017
 *  Author: Junsheng Fu
 */

#ifndef PID_H
#define PID_H

#include <uWS/uWS.h>

class PID {
public:
  /**
   * Error terms for PID controller
   */
  double p_error;
  double i_error;
  double d_error;

  /**
   * Coefficients
   */
  double Kp;
  double Ki;
  double Kd;

  /**
   * Constructor
   */
  PID();

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param kp the proportional value for PID controller
   * @param ki the integral value for PID controller
   * @param kd the derivative value for PID controller
   */
  void Init(double kp, double ki, double kd);

  /**
   * Update the PID error variables given cross track error
   * @param cte the current cross track error
   */
  void UpdateError(double cte);

  /**
   * Compute the control command value according to PID controller
   * @return the steering angle
   */
  double OutputSteerAng();

  /**
   * Compute the throttle by PID controller
   * @param max_thro max throttle value
   * @return the computed throttle value
   */
  double OutputThrottle(double max_thro);
};

#endif /* PID_H */
