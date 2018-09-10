#ifndef PID_H
#define PID_H
#include <deque> 
class PID {
public:
  
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;
  
  double cte;
  /*
  * Is initialized
  */
  bool is_initialized;
  
  /*
  *  Previous Error
  */
  double cte_prev;

  /*
  * Integral Error helpers
  */
  std::deque<double> integ_error_queue;
  int int_capacity;
  double integral_sum;
  
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
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  /*
  * run - output the steering angle
  */
  double run();
  
  /*
  * This updates the integral part with a queue for the sum
  */
  void Update_i_error(double cte);
};

#endif /* PID_H */
