//============================================================================
// Name        : Bridge.cpp
// Created on  : 08.06.2020
// Author      : Tokmakov Andrey
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Bridge tests
//============================================================================

#define _CRT_SECURE_NO_WARNINGS

#include "Bridge.h"

#include <chrono>
#include <iostream>
#include <string>
#include <string_view>
#include <thread>

namespace Bridge {

	LockupAlarmClock::LockupAlarmClock(std::unique_ptr<AlarmClockImpl> bridgeImpl,
									   int hour, int minutes) {
		// this->bridge.reset(bridgeImpl.release());
		this->bridge = std::move(bridgeImpl);
		this->waitForWake = false;
		this->hourAlarm = hour;
		this->minutesAlarm = minutes;
	}

	void LockupAlarmClock::toWake() {
		this->bridge->notify();
		this->bridge->ring();
	}

	void LockupAlarmClock::start() noexcept {
		time_t rawtime;
		tm* timeinfo;

		std::cout << "ArarmClock stared" << std::endl;

		waitForWake = true;
		while (waitForWake) {
			time(&rawtime);
			timeinfo = localtime(&rawtime);
			if (timeinfo->tm_hour == this->hourAlarm && timeinfo->tm_min == this->minutesAlarm) {
				waitForWake = false;
			} else {
				std::cout << "Dont need to Ring" << std::endl;
			}
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		toWake();
	}

	void LockupAlarmClock::stop() noexcept {
		// stop lockup process
		waitForWake = false;
	}


	ShellMP3AlarmClock::ShellMP3AlarmClock(const std::string& cmd) {
		this->cmdplay = cmd;
	}

	void ShellMP3AlarmClock::ring() noexcept {
		// run command
		// system(cmdplay.c_str());
		std::cout << cmdplay.c_str() << std::endl;
	}

	void ShellMP3AlarmClock::notify() noexcept {
		std::cout << "ALARMING!" << std::endl;
	}
}


void Bridge::TEST_ALL() {

	std::unique_ptr<AlarmClockImpl> clockImpl = std::make_unique< ShellMP3AlarmClock>("DING DING DING");
	std::shared_ptr<AlarmClock> clock = std::make_shared< LockupAlarmClock>(std::move(clockImpl), 9, 46);
	clock->start();

}