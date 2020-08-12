//============================================================================
// Name        : Command.h
// Created on  : 12.04.2020
// Author      : Tokmakov Andrey
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Command pattern tests
//============================================================================

#include "Command.h"

namespace Command_Pattern_Tests {

	void Light::on() {
		std::cout << "The light is ON" << std::endl;
	}

	void Light::off() {
		std::cout << "The light is OFF" << std::endl;
	}


	LightOnCommand::LightOnCommand(std::shared_ptr<Light> light) : mLight(light) {
	}

	void LightOnCommand::execute() {
		this->mLight->on();
	}


	LightOffCommand::LightOffCommand(std::shared_ptr<Light> light) : mLight(light) {
	}

	void LightOffCommand::execute() {
		this->mLight->off();
	}


	void RemoteControl::setCommand(std::unique_ptr<ICommand> cmd) {
		this->command = std::move(cmd);
	}

	void RemoteControl::buttonPressed() {
		command->execute();
	}

}

void Command_Pattern_Tests::Test()
{
	// Receiver 
	std::shared_ptr<Light> light = std::make_shared<Light>();
	std::shared_ptr<RemoteControl> control = std::make_shared<RemoteControl>();

	// concrete Command objects 
	// std::unique_ptr<LightOnCommand> lightOn = std::make_unique<LightOnCommand>(new LightOnCommand(light));
	std::unique_ptr<LightOnCommand> lightOn = std::make_unique<LightOnCommand>(light);
	std::unique_ptr<LightOffCommand> lightOff = std::make_unique<LightOffCommand>(light);

	// execute
	control->setCommand(std::move(lightOn));
	control->buttonPressed();
	control->setCommand(std::move(lightOff));
	control->buttonPressed();

}
