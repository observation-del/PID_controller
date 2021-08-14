#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;

  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;

  twid_flag = false;

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  d_error = cte - p_error; 
  p_error = cte;
  i_error += cte;

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  double total_error;
  total_error = -(p_error * Kp + i_error * Ki + d_error * Kd);

  return total_error;  // TODO: Add your total error calc here!
}

std::vector<double> PID::Twiddle(double &tolerance, double &cte){
  static std::vector<double> p{0.0, 0.0, 0.0};
  static std::vector<double> dp{1.0, 1.0, 1.0};

  // Calculate the error
  this -> Init(p[0], p[1], p[2]);
  this -> UpdateError(cte);
  double best_error = std::pow(this -> TotalError(), 2.0);
  
  for(unsigned int i = 0; i < 3; i++){
    p[i] += dp[i];
    this -> Init(p[0], p[1], p[2]);
    this -> UpdateError(cte);
    double error = this -> TotalError();
    if(error < best_error){
      best_error = error;
      dp[i] *= 1.1;
    }
    else{
      p[i] -= 2.0 * dp[i];
      this -> Init(p[0], p[1], p[2]);
      this -> UpdateError(cte);
      error = this -> TotalError();
      if(error < best_error){
        best_error = error;
        dp[i] *= 1.1;
      }
      else{
        p[i] -= 2.0 * dp[i];
        this -> Init(p[0], p[1], p[2]);
        this -> UpdateError(cte);
        error = this -> TotalError();
      }
    }
  }
  std::cout << "error : " << best_error << std::endl;

  if(std::accumulate(p.begin(), p.end(), 0) < tolerance){
    twid_flag = false;
  }

  return p;

}
