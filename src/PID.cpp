#include <math.h>
#include <string>
#include <iostream>
#include "PID.h"
#include <vector>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
	is_initialized = false;
	int_capacity = 20;
}

PID::~PID() {}

void PID::Init(double Kp_input, double Ki_input, double Kd_input) {
	
	Kp = Kp_input;
	Ki = Ki_input;
	Kd = Kd_input;	

	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;

	numruns        = 1;
	error_curr     = 0;
	weighted_error = 0;

	is_initialized = true;
}

void PID::UpdateError(double cte_input) {
	numruns += 1;
	cte = cte_input;
	
	p_error  = cte_input;
	//i_error += cte_input;
	Update_i_error(cte_input);
	d_error  = cte_input - cte_prev;
	
	cte_prev = cte_input;
		
}

void PID::Update_i_error(double cte){

	if (integ_error_queue.size() == int_capacity){
  	 	integral_sum -= integ_error_queue.front();
	  	integ_error_queue.pop_front();
	  	integ_error_queue.push_back(cte);
	  	integral_sum += cte;
  	} else{
  		integ_error_queue.push_back(cte);
  		integral_sum += cte;
  	}

  	i_error = integral_sum;
}



double PID::TotalError() {

}

double PID::run(){
	
	//cout<< "Kp * p_error " << Kp * p_error << endl;
	//cout<< "Ki * i_error " << Ki * i_error << endl;
	//cout<< "Kd * d_error " << Kd * d_error << endl;
	
	//double steer_angle = -1 * Kp * p_error + (-1) * Ki * i_error - Kd * d_error;
    double steer_angle = -1 * Kp * p_error -   Kd * d_error -  Ki * i_error;
    
    
    return steer_angle;
}

