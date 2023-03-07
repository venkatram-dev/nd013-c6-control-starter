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
  
  //momentary variable to store temporary cross track error
  cte_as_of_now = 0;
  
  //initialize boundary condition variables
  output_limit_minimum = output_lim_mini;
  output_limit_maximum = output_lim_maxi;
  

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
  diff_cte = (cte - previous_cterror)/delta_time;
  int_cte += (cte * delta_time);
  
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
    
    cout << "delta_time" <<delta_time<<endl;
    cout << "cte" << cte <<endl;
    cout << "tau_p" << tau_p <<endl;
    cout << "tau_d" << tau_d <<endl;
    cout << "tau_i" << tau_i <<endl;
    cout << "diff_cte" << diff_cte <<endl;
    cout << "int_cte" << int_cte <<endl;
    cout << "tmp_control" << tmp_control <<endl;
    cout << "output_limit_minimum" << output_limit_minimum << endl;
    cout << "output_limit_maximum" << output_limit_maximum << endl;
    
    // control needs to be with in boundary conditions
    // ex output_lim_mini = 10, output_lim_maxi = 20
    // if tmp_control = 30, we need output_lim_maxi 20 
    // i tmp_control = 5, we need output_lim_mini 10
    // if tmp_control = 15, we need 15
    
    // find if control is with in minimum boundary
    if (tmp_control < output_limit_minimum){
        tmp_control = output_limit_minimum;
    }
    // find if control is with in maximum boundary
    if (tmp_control > output_limit_maximum){
        tmp_control = output_limit_maximum;
    }
    
    cout << "control after if" << tmp_control << endl;
      
    control = tmp_control;
    
    return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
  delta_time = new_delta_time;
  return delta_time;
}