//============================================================================
// Name        : Bridge.h
// Created on  : 08.06.2020
// Author      : Tokmakov Andrey
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Bridge tests
//============================================================================

#ifndef BRIDGE_TESTS__H_
#define BRIDGE_TESTS__H_

#include <iostream>
#include <memory>

namespace Bridge {

	class AlarmClockImpl {
	public:
		virtual void ring() noexcept = 0;
		virtual void notify() noexcept = 0;
	};

	class AlarmClock {
	private:
		virtual void toWake() = 0;

	protected:
		// It`s our bridge to implementation
		std::unique_ptr<AlarmClockImpl> bridge;

	public:
		virtual void start() noexcept = 0;
		virtual void stop() noexcept = 0;
	};


	class LockupAlarmClock : public AlarmClock {
	private:
		int hourAlarm; 
		int minutesAlarm;
		bool waitForWake;

	private:
		virtual void toWake() override;

	public:
		LockupAlarmClock(std::unique_ptr<AlarmClockImpl> bridgeImpl,
						 int hour, 
						 int minutes);

		virtual void start() noexcept override;
		virtual void stop() noexcept override;
	};

	class ShellMP3AlarmClock : public AlarmClockImpl {
	private:
		std::string cmdplay; 

	public:
		ShellMP3AlarmClock(const std::string& cmd);
		virtual ~ShellMP3AlarmClock() = default;

		virtual void ring() noexcept;
		virtual void notify() noexcept;

	};

	//////////////////////////////////////////

	void TEST_ALL();
}

#endif /* BRIDGE_TESTS__H_ */
