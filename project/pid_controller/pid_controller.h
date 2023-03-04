/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

class PID {
public:

   /**
   * TODO: Create the PID class
   **/
    
   
    /*
    * Errors
    */
    // As per the pid controller lesson, we need
    // few variables to store the different errors
    //cte - cross track error
    //diff_cte - differential cross track error
    //int_cte - integral cross track error 
    //cte_as_of_now - momentary variable to store temporary cross track error
    double cte;
    double diff_cte;
    double int_cte;
    double cte_as_of_now;

    /*
    * Coefficients
    */
    // we need 3 coefficients 
    // tau_p - proportional coefficient 
    // tau_d - differential coefficient 
    // tau_i - integral coefficient 
    double tau_p;
    double tau_d;
    double tau_i;
  

    /*
    * Output limits
    */
    // As per the project instructions, the control
    // needs to be with in a defined boundary
    // we need 2 variables for it
    double output_limit_maximum;
    double output_limit_minimum;
    
    /*
    * Delta time
    */
    // variable for time frequency delta
    double delta_time;
    
    /*
    * Constructor
    */
    PID();

    /*
    * Destructor.
    */
    virtual ~PID();

    /*
    * Initialize PID.
    */
    void Init(double Kp, double Ki, double Kd, double output_lim_max, double output_lim_min);

    /*
    * Update the PID error variables given cross track error.
    */
    void UpdateError(double cte);

    /*
    * Calculate the total PID error.
    */
    double TotalError();
  
    /*
    * Update the delta time.
    */
    double UpdateDeltaTime(double new_delta_time);
};

#endif //PID_CONTROLLER_H


