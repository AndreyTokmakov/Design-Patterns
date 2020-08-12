//============================================================================
// Name        : Command.h
// Created on  : 12.04.2020
// Author      : Tokmakov Andrey
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Command pattern tests
//============================================================================

#ifndef COMMAND_PATTERN__TESTS_H__
#define COMMAND_PATTERN__TESTS_H__

#include <iostream>
#include <string>

namespace Command_Pattern_Tests {

	// Command Interface
	class ICommand {
	public:
		virtual void execute() = 0;
	};

	// Receiver Class
	class Light {
	public:
		virtual void on();
		virtual void off();
	};

	/*
	class Command : public ICommand {
	public:
		Command(std::shared_ptr<Light> light) {
		}
		virtual void execute() override {
			std::cout << "CMD" << std::endl;
		}
	};
	*/

	// Command for turning on the light
	class LightOnCommand : public ICommand {
	public:
		LightOnCommand(std::shared_ptr<Light> light);
		void execute() override;
	private:
		std::shared_ptr<Light> mLight;
	};

	// Command for turning off the light
	class LightOffCommand : public ICommand {
	public:
		LightOffCommand(std::shared_ptr<Light> light);
		void execute() override;
	private:
		std::shared_ptr<Light> mLight;
	};

	// Invoker: Stores the ConcreteCommand object 
	class RemoteControl {
	private:
		std::unique_ptr<ICommand> command;

	public:
		void setCommand(std::unique_ptr<ICommand> cmd);
		void buttonPressed();
	};


	void Test();
}

#endif //COMMAND_PATTERN__TESTS_H__