//============================================================================
// Name        : Strategy.cpp
// Created on  : 15.04.2020
// Author      : Tokmakov Andrey
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Strategy pattern tests
//============================================================================

#include "Strategy.h"

class IStrategy {
public:
	virtual ~IStrategy() = default;
	virtual void use() noexcept = 0;
};

class Strategy_1 : public IStrategy {
public:
	void use() noexcept override {
		std::cout << "Strategy_1" << std::endl;
	}
};

class Strategy_2 : public IStrategy {
public:
	void use() noexcept override {
		std::cout << "Strategy_2" << std::endl;
	}
};

class Strategy_3 : public IStrategy {
public:
	void use() noexcept override {
		std::cout << "Strategy_3" << std::endl;
	}
};

class IContext {
protected:
	std::unique_ptr<IStrategy> operation;

public:
	virtual ~IContext() {}
	virtual void useStrategy() = 0;
	virtual void setStrategy(std::unique_ptr<IStrategy>) = 0;
};

class Client : public IContext
{
public:
	void useStrategy() {
		operation->use();
	}

	void setStrategy(std::unique_ptr<IStrategy> strategy) {
		operation = std::move(strategy);
	}
};

void Strategy_Pattern_Tests::Test()
{
	Client customClient;

	customClient.setStrategy(std::make_unique<Strategy_1>());
	customClient.useStrategy();
	customClient.setStrategy(std::make_unique<Strategy_2>());
	customClient.useStrategy();
	customClient.setStrategy(std::make_unique<Strategy_3>());
	customClient.useStrategy();
}
