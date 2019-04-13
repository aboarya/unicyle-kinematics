#pragma once

namespace tareeq {
  namespace control {

      class Actuators {
      public:
	virtual ~Actuators() = default;

	virtual bool Init() = 0;
	virtual bool Start() = 0;
	virtual bool Stop() = 0;
	virtual bool Drive() = 0;
      };

      std::unique_ptr<Actuators> MakeAcutator();

  } // namespace control
} // namespace tareeq
