struct SensorConfig {
  // required config values
};

class Sensor {

  virtual ~Sensor() = default;

  virtual bool IsActive() = 0;

  virtual void Init(const SensorConfig& config) = 0;
  virtual vector<double> const ReadMeasurement() = 0;
  
};

class State {

 public:

  virtual ~State() = default;

  virtual void Update(const vector<double> values) = 0;
  virtual void Update(const vector<Sensor>& sensors) = 0;

  virtual vector<double> operator- const (const State& state) = 0;

};

class UnicycleModel : public State {

 public:
  UnicyleModel(double velocity, double omega, double wheel_radius, double distance_between_wheels);

  virtual void Update(vector<Sensor>& sensors)
  {
    if (sensors.size() < 2)
      {
	// FAIL with error message
      }
    Sensor r_wheel_odometry = sensors.at(0);
    Sensor l_wheel_odometry = sensors.at(1);

    double r_rotation_rate = r_wheel_odometry.ReadMeasurement().at(0);
    double l_rotation_rate = r_wheel_odometry.ReadMeasurement().at(0);

    // apply unicyle model equations to
    // set velocity_ and omega_;
    
  };

  virtual vector<double> operator- const (const State& state)
  {
    // example
    return vector{state.omega - this->omega_, state.velocity - this->velocity};
  }
  
 private:
  double velocity_;
  double omega_;
  double wheel_radius;
  double distance_between_wheels_;
  

};

class LongitudinalDynamicModel : public State {

  public:
  LongitudinalDynamicModel(double velocity, double theta, double phi, // etc);

  virtual void Update(vector<Sensor>& sensors)
  {
    
    // apply vehicle dynamics equations to
    // set state;
    
  };

  virtual vector<double> operator- const (const State& state)
  {
    // example
    return vector{state.velocity - this->velocity, //etc};
  }
 private:
  // state representation
};


class PID {

 public:
  virtual ~PID() = default;

  virtual State const CalculateError(const State& target_state, const State& current_state) = 0;

  virtual void SetProportionalGain(const double& kp) = 0;
  virtual void SetIntegralGain(const double& ki) = 0;
  virtual void SetDifferentialGain(const double& kd) = 0;

};

class Actuator {

 public:
  virtual ~Actuator() = default;

  virtual bool Apply(const State& error) = 0;
};

class Motor {
 pubic:
  Motor(Pwm speed_pin, Ouput control_a, Output control_b);

  inline bool Start();
  inline bool Stop();
  inline bool SpinForward();
  inline bool SpinBackward();
  
};

class UniCycleDriver : public Actuator {

 public:
  UniCycleDriver(Motor& right_motor, Motor& left_motor);
  
  virtual bool Apply(const State& error) {
    
  };

  inline bool Start();
  inline bool Stop();
  inline bool DriveForward();
  inline bool DriveBackward();

  inline const bool IsDrivnigForward();

 private:
  bool is_driving_forward_;
  Motor right_motor_;
  Motor left_motor_;
  
};

class FrontWheelDriver : public Actuator {

  public:
  
  virtual bool Apply(const State& error) {
    
  };

};


class ControlAgent {

  // set target state
  // measure current state
  // calculate error
  // apply error

 public:
  ControlAgent(const vector<Sensor>& sensors,
	       PID& regulator,
	       Actuator& actuator);

  void SetTargetState(const State& state);
  
  void ClosedLoop()
  {
    State error = regulator.CalculateError(target_state_, current_state_);
    
    while (target - error > some_threshold)
      {
	actuator.Apply(error);
	current_state_.Update(sensor);
	error = regulator.CalculateError(target_state_, current_state_);	
      }
  };
 private:
  State current_state_;
  State target_state_;
  
};
