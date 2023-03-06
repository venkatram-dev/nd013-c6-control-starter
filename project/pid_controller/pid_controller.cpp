/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
   // we need 3 coefficients 
   // tau_p - proportional coefficient 
   // tau_d - differential coefficient 
   // tau_i - integral coefficient 
  tau_p = Kpi;
  tau_d = Kdi;
  tau_i = Kii;
  
  //initialize boundary condition variables
  output_limit_minimum = output_lim_mini;
  output_limit_maximum = output_lim_maxi;
  
  //momentary variable to store temporary cross track error
  double cte_as_of_now = 0;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
    // As per the pid controller lesson, we can use
    // below formulae to update the PID errors based on cross track error
    
    //diff_cte = cte - prev_cte
    //int_cte += cte
    //prev_cte = cte
  
  double previous_cterror;
  previous_cterror = cte_as_of_now;
  diff_cte = cte - previous_cterror;
  int_cte += cte;
  
  cte_as_of_now = cte;
  
      
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
    double control;
    // As per the pid controller lesson, we can use
    // below formulae to find total error errors based on the 3 errors
    //and the 3 coefficients
    //steer = -tau_p * cte - tau_d * diff_cte - tau_i * int_cte
    
    double tmp_control = -tau_p * cte - tau_d * diff_cte - tau_i * int_cte;
      
    control = tmp_control;
    
    return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
  delta_time = new_delta_time;
}