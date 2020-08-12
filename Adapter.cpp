#//============================================================================
// Name        : Adapter.h
// Created on  : 07.07.2020
// Author      : Tokmakov Andrey
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Adapter tests
//============================================================================

#include "Adapter.h"

#define interface class

namespace Adapter::Classic {
	
	// Existing environmental temperature sensor class
	class FahrenheitSensor {
	public:

		// Get temperature in degrees Fahrenheit
		float getFahrenheitTemp() {
			float t = 112.0;
			// Some code
			return t;
		}


	};


	interface ISensor {
	public:
		virtual ~ISensor() = default;
		virtual float getTemperature() = 0;
	};


	class Adapter : public ISensor {
	private:
		std::unique_ptr<FahrenheitSensor> p_fsensor;

	public:
		Adapter(std::unique_ptr<FahrenheitSensor> fSensor) :
			p_fsensor(std::move(fSensor)) {
		}

		virtual ~Adapter() = default;

	public:
		virtual float getTemperature() {
			return (p_fsensor->getFahrenheitTemp() - 32.0)*5.0 / 9.0;
		}
	};


	void Test() {
		std::unique_ptr<FahrenheitSensor> fSensor = std::make_unique<FahrenheitSensor>();
		std::shared_ptr<ISensor> sensor = std::make_shared<Adapter>(std::move(fSensor));
		std::cout << "Celsius temperature = " << sensor->getTemperature() << std::endl;
	}
}

namespace Adapter::PrivateInheritance {

	// Existing environmental temperature sensor class
	class FahrenheitSensor {
	private:
		float t = 112.0;

	public:
		// Get temperature in degrees Fahrenheit
		float getFahrenheitTemp() {
			// Some code
			return t;
		}

	protected:
		void adjust(float t) { // Sensor setup (protected method)
			this->t = t;
		}
	};

	interface ISensor {
	public:
		virtual ~ISensor() = default;
		virtual float getTemperature() = 0;
		virtual void adjust(float t) = 0;
	};

	class Adapter : public ISensor, private FahrenheitSensor {
	public:
		Adapter()  {
		}

		virtual ~Adapter() = default;

	public:
		virtual float getTemperature() {
			return (getFahrenheitTemp() - 32.0)*5.0 / 9.0;
		}

		void adjust(float t) {
			FahrenheitSensor::adjust(t);
		}
	};

	void Test() {
		std::shared_ptr<ISensor> sensor = std::make_shared<Adapter>();

		std::cout << "Celsius temperature = " << sensor->getTemperature() << std::endl;
		sensor->adjust(133);
		std::cout << "Celsius temperature = " << sensor->getTemperature() << std::endl;
	}
}

void Adapter::TEST_ALL()
{
	 Classic::Test();

	// PrivateInheritance::Test();
}
