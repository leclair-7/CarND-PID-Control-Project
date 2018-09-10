#include <math.h>
#include <string>
#include <iostream>
#include "PID.h"
#include <vector>

using namespace std;

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
	
	is_initialized = true;
}

void PID::UpdateError(double cte_input) {
	numruns += 1;
	cte = cte_input;	
	p_error  = cte_input;	
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
	
	double pid_output = -1 * Kp * p_error -   Kd * d_error -  Ki * i_error;

    return pid_output;
}

