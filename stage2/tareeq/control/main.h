/* #include <iostream> */
/* #include <stdio.h> */
/* #include <math.h> */

/* #include "encoder.h" */
/* #include "motor.h" */

/* class State */
/* { */
/*  public: */
/*   double x_ = 0.; */
/*   double y_ = 0.; */
/*   double theta_rad_  = 0.; */

/*   double omega_      = 0; */
/*   double v_          = 1.4; */
/* }; */

/* class Odometry */
/* { */

/*  public: */
/*   void Update() */
/*   { */

/*     d_right_ = encoder_r_.GetDistanceTraveled(); */
/*     d_left_  = encoder_l_.GetDistanceTraveled(); */

/*     //std::cout << " d_left " << d_left_ << " d_right " << d_left_ << std::endl; */
  
/*     d_center_ = (d_left_ + d_right_) / 2.0; */

/*   }; */

/*   void UpdateRotationRates() */
/*   { */
/*     rotation_rate_r_ = encoder_r_.GetRotationRate(); */
/*     rotation_rate_l_ = encoder_l_.GetRotationRate(); */
/*     //std::cout << " rotation rate r = " << rotation_rate_r_ << " and rotation rate l " << rotation_rate_l_ << std::endl; */
/*   }; */

  

/*   Encoder encoder_r_{Encoder(17)}; // hardcode gpio pins for now */
/*   Encoder encoder_l_{Encoder(18)}; // hardcode gpio pins for now */

/*   double d_right_  = 0; */
/*   double d_left_   = 0; */
/*   double d_center_ = 0; */

/*   double rotation_rate_r_ = 0.; */
/*   double rotation_rate_l_ = 0.; */
/*   double d_baseline_ = 10 / 100.; // in meters */
/*   double wheel_radius_m_ = encoder_r_.GetWheelRadius(); */
  
/* }; */


/* class PIDController */
/* { */
/*  public: */
  
/*   inline void ComputeError(State &target_state, State &current_state) */
/*   { */
/*     // calcualte error based on distance between current */
/*     // state and target state; */
    
/*     // assuming constant velocity for now */
/*     // using only propotional gain for now */
    
/*     double e = target_state.theta_rad_ - current_state.theta_rad_; */
/*     // ensure error is between -Pi and +Pi */
/*     e_prime_ = atan2(sin(e), cos(e)); */
    
/*   }; */
  
/*   void ComputeOmega(State &target_state, State &current_state) */
/*   { */
/*     ComputeError(target_state, current_state); */
/*     current_state.omega_ = kp_ * e_prime_; */
/*     //std::cout << " omega = " << current_state.omega_ << " and error = " << e_prime_ << std::endl; */

/*   }; */

/*   inline double RegulateRotationRate(const double &w_desired, const double &w_actual) */
/*   { */
/*     //std::cout << "setting new freq " << -.5 * (w_desired - w_actual) << std::endl; */

/*     double tmp = (w_desired - w_actual); */
/*     if (tmp < 0.) */
/*       return -.35 * (w_desired - w_actual); */
/*     return .35 * (w_desired - w_actual); */
/*   }; */
  
/*   double kp_ = .5; */
/*   double e_prime_ = 0; */
  
/* }; */


/* class ControlAgent */
/* { */

/*  public: */
  
/*   ControlAgent() */
/*     { */

/*       std::cout << "starting control agent" << std::endl; */
/*       active_state_.x_ = .5; */
/*       active_state_.y_ = 0; */
/*       active_state_.theta_rad_ = 1.5708; */
      
/*       target_state_.x_ = -.5; */
/*       target_state_.y_ = 2.0; */
/*       target_state_.theta_rad_ = 2.35619; */

/*       this->is_running_ = true; */

/*       //start encoders */
/*       odometry_.encoder_r_.Run(); */
/*       odometry_.encoder_l_.Run(); */

/*       // start motors */
/*       motor_r_.Run(); */
/*       motor_l_.Run(); */
     
/*     }; */

/*   ~ControlAgent() */
/*     { */
/*       this->is_running_ = false; */
/*       // make sure to disable motors */
/*       motor_r_.~Motor(); */
/*       motor_l_.~Motor(); */
/*     }; */

/*   inline double NormalizeTheta(double theta) */
/*   { */
/*     theta = fmod(theta, 2*M_PI); */
/*     if (theta < 0) */
/*       theta += (2*M_PI); */
/*     return theta; */
/*     // ensure theta is between -2pi and 0 */
/*     //while (theta < -2 * M_PI) */
/*     // { */
/*     //	theta + (2*M_PI); */
/*     //} */
/*     //    while (theta > 2 * M_PI) */
/*     //{ */
/*     //	theta - (2*M_PI); */
/*     //} */
   
/*     //    return theta; */
/*   } */
  
/*   inline double ComputeTheta() */
/*   { */
/*     double theta =  (odometry_.d_right_ - odometry_.d_left_) / odometry_.d_baseline_; */

/*     return NormalizeTheta(theta); */
/*   }; */
  
/*   inline void UpdatePosition() */
/*   { */
/*     // update distance traveled using encoders */
/*     odometry_.Update(); */

/*     // computer orientation based on distance traveled */
/*     double theta = ComputeTheta(); */
/*     // std::cout << " >>>> theta = " << theta << " and d_right " << odometry_.d_right_ << " and d_left " <<  odometry_.d_left_ << " and d_baseline " <<  odometry_.d_baseline_ << std::endl; */

/*     // update (x,y) position based on distance & orientation */
/*     active_state_.x_ += (odometry_.d_center_ * cos(active_state_.theta_rad_)); */
/*     active_state_.y_ += (odometry_.d_center_ * sin(active_state_.theta_rad_)); */

/*     // update heading */
/*     double tmp = active_state_.theta_rad_  + theta; */
/*     active_state_.theta_rad_ = NormalizeTheta(tmp); */

    
/*   }; */

/*   inline void ComputeActuators() */
/*   { */
/*     w_r_ = ( */
/* 	    (2 * active_state_.v_) + */
/* 	    (active_state_.omega_ * odometry_.d_baseline_) */
/* 	    ) / */
/*       (2 * odometry_.wheel_radius_m_); */

/*     w_l_ = ( */
/* 	    (2 * active_state_.v_) - */
/* 	    (active_state_.omega_ * odometry_.d_baseline_) */
/* 	    ) / */
/*       (2 * odometry_.wheel_radius_m_); */

/*     //std::cout << " w_r = " << w_r_ << " and w_l = " << w_l_ << std::endl; */
/*   }; */

/*   void RegulateActuators() */
/*   { */
/*     while(this->is_running_) */
/*       { */
/* 	// caluclate actual rotation rate of the wheels */
/* 	//odometry_.encoder_r_.CalculateRotationRate(); */
/* 	//odometry_.encoder_l_.CalculateRotationRate(); */
	
/* 	// use PID regulator to stabilize the power output */
/* 	// to the motors using the error as the duty cycle	 */

/* 	odometry_.UpdateRotationRates(); */
/* 	motor_r_.SetSpeed(pid_controller_.RegulateRotationRate( */
/* 							       w_r_, */
/* 							       odometry_.rotation_rate_r_)); */
	
/* 	motor_l_.SetSpeed(pid_controller_.RegulateRotationRate( */
/* 							    w_l_, */
/* 							    odometry_.rotation_rate_l_)); */
	
/* 	std::this_thread::sleep_for( inner_loop_window_ ); // 10 milliseconds */
/*       } */
/*   } */

/*   void ComputeCommand() */
/*   { */
/*     while(this->is_running_) */
/*       { */
/* 	// update position using only odometry for now */
/* 	UpdatePosition(); */

/* 	// compute required angular velocity to reach the goal */
/* 	// assuming a constant linear velocity for now */
/* 	pid_controller_.ComputeOmega(target_state_, active_state_); */
	
/* 	// affect angular velocity */
/* 	ComputeActuators(); */
	
/* 	std::this_thread::sleep_for( outer_loop_window_ ); // 100 milliseconds */
/*       } */
/*   }; */

/*   void run() */
/*   { */
    
/*     std::cout << "starting out loop thread " << std::endl; */
/*     std::thread command_routine(&ControlAgent::ComputeCommand, this); */
/*     command_routine.detach(); */

/*     std::cout << "starting inner loop thread " << std::endl; */
/*     std::thread actuator_routine(&ControlAgent::RegulateActuators, this); */
/*     actuator_routine.detach(); */
    
/*   }; */

/*   void log() */
/*   { */
/*     std::cout << "current state : " << std::endl; */
/*     std::cout << "       x        = " << active_state_.x_ << std::endl; */
/*     std::cout << "       y        = " << active_state_.y_ << std::endl; */
/*     std::cout << "       theta    = " << active_state_.theta_rad_ << std::endl; */
/*     std::cout << "----------------" << std::endl; */
/*     std::cout << "actual w_r      = " << odometry_.rotation_rate_r_ << std::endl; */
/*     std::cout << "actual w_l      = " << odometry_.rotation_rate_l_ << std::endl; */
/*     std::cout << " ---------------" << std::endl; */
/*     std::cout << "target w_r      = " << w_r_ << std::endl; */
/*     std::cout << "target w_l      = " << w_l_ << std::endl; */
/*     std::cout << " ------------- " << std::endl; */
/*     std::cout << "distance traveled = " << odometry_.d_center_ << std::endl; */
/*     std::cout << "---------------------------------" << std::endl << std::endl; */
/*   } */


/*   bool   is_running_ = false; */
/*   double w_r_ = 0; */
/*   double w_l_ = 0; */
  
/*   State active_state_; */
/*   State target_state_; */
  
/*   Odometry odometry_; */
/*   PIDController pid_controller_; */

/*   Motor motor_r_{Motor(26, 21, 20)}; // hardcode gpio pins for now */
/*   Motor motor_l_{Motor(12, 13, 6)}; // hardcode gpio pins for now */

/*   // out loop window (omega regulator) */
/*   std::chrono::milliseconds outer_loop_window_ = std::chrono::milliseconds(50); */

/*   // inner loop window (motor speed regulator) */
/*   std::chrono::milliseconds inner_loop_window_ = std::chrono::milliseconds(5); */
/* }; */
