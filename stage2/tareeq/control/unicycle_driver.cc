#include "unicycle_driver.h"

namespace tareeq {
  namespace control {
    
    UniCycleDriver::UniCycleDriver(Motor& right_motor, Motor& left_motor):
      right_motor_(right_motor),
      left_motor_(left_motor){};

    /**
    */
    bool UniCycleDriver::Apply(const State& error)
    {
      return true;
    }

    /**
    */
    bool UniCycleDriver::Start()
    {
      
      right_motor_.Start();
      //left_motor_.Start();
      //return (
      //	      right_motor_.IsStarted() &&
      //      left_motor_.IsStarted()
      //      );
      return true;
    }

    bool UniCycleDriver::Stop()
    {
      right_motor_.Stop();
      left_motor_.Stop();
      return (
	      !right_motor_.IsStarted() &&
	      !left_motor_.IsStarted()
	      );
    }
    
    
  } // end namespace control
} // end namespace tareeq


/* namespace tareeq { */
/*   namespace control { */
    
/*       class Motor */
/*     { */
/*     public: */
      
/*       virtual ~Motor() = default; */

/*       virtual void Run() = 0; */
/*       virtual void Stop() = 0; */
/*       virtual void ApplyRotationRate(double rotation_rate) = 0; */
      
/*     }; */

/*       // simple factor method */
/*       std::unique_ptr<Motor> MakeMotor(); */
    
/*   } // namespace control */
/* } // namespace tareeq */
/* #endif // TAREEQ_MOTOR_ */


// #include "tareeq/gpio/pwm.h"
// #include "tareeq/gpio/output.h"

// #include "actuators.h"

// namespace tareeq {
//   namespace control {
      
//       class UnicycleDriver : public Actuators {
//       private:
// 	class Motor {
// 	  bool initialized = true;
// 	public:
// 	  Motor() = default;
// 	  ~Motor(){this->Stop();};

// 	  bool Init(
// 		    std::unique_ptr<tareeq::gpio::Pwm>&& pwm,
// 		    std::unique_ptr<tareeq::gpio::Output> control_a,
// 		    std::unique_ptr<tareeq::gpio::Output> control_b)
// 	  {
// 	    speed_pin_     = std::move(pwm);
// 	    control_pin_a_ = std::move(control_a);
// 	    control_pin_b_ = std::move(control_b);

// 	    initialized = true;
// 	    return initialized; // TO-DO: actual success check
// 	  };
	  
// 	  bool RunForward()
// 	  {
// 	    this->control_pin_a_->On();
// 	    this->control_pin_b_->Off();
// 	    this->speed_pin_->Start();
// 	    return true; // TO-DO: actual success check
// 	  }

// 	  bool RunBackward()
// 	  {
// 	    this->control_pin_a_->Off();
// 	    this->control_pin_b_->On();
// 	    this->speed_pin_->Start();
// 	    return true; // TO-DO: actual success check
// 	  }
	  
// 	  bool Stop()
// 	  {
// 	    this->speed_pin_->Stop();
// 	    this->control_pin_a_->Off();
// 	    this->control_pin_b_->Off();
// 	    return true; // TO-DO: actual success check
// 	  };
	  
// 	  bool ApplyRotationRate(double rotation_rate)
// 	  {
// 	    this->speed_pin_->SetSpeed(rotation_rate);
// 	    return true; // TO-DO: actual success check
// 	  };
	  
// 	  std::unique_ptr<tareeq::gpio::Pwm> speed_pin_;
// 	  std::unique_ptr<tareeq::gpio::Output> control_pin_a_;
// 	  std::unique_ptr<tareeq::gpio::Output> control_pin_b_;
// 	};

// 	bool initialized = true;
// 	Motor right_motor_;
// 	Motor left_motor_;
	
//       public:
//         UnicycleDriver() = default;
// 	~UnicycleDriver() = default;

// 	bool Init() override {return true;};
// 	bool Start() override {return true;};
// 	bool Stop() override {return true;};
// 	bool Drive()  override {return true;};
	
//       };

//      std::unique_ptr<Actuators> MakeAcutator()
//      {
//        return std::make_unique<UnicycleDriver>();
//      }

//   } // namespace control
// } // namespace tareeq
      
