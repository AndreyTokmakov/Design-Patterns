//============================================================================
// Name        : ChainOfResponsibility.h
// Created on  : 19.04.2020
// Author      : Tokmakov Andrey
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Chain of pesponsibility pattern tests
//============================================================================

#ifndef ABSTRACT_FACTORY_PATTERN_TESTS__H_
#define ABSTRACT_FACTORY_PATTERN_TESTS__H_

#include <iostream>
#include <string>
#include <memory>

namespace AbstractFactory_Pattern_Tests {

	class IAbstractProductA;
	class IAbstractProductB;

	class IAbstractFactory {
	public:
		virtual std::shared_ptr<IAbstractProductA> createProductA() = 0;
		virtual std::shared_ptr<IAbstractProductB> createProductB() = 0;
	};

	class IProduct {
	public:
		virtual const std::string getName() const noexcept = 0;
	};

	class IAbstractProductA: public IProduct  {
	public:
		virtual void interact(std::shared_ptr<IAbstractProductB> b) = 0;
		
	virtual const std::string getName() const noexcept = 0;
	};

	class IAbstractProductB {
	public:
		virtual void interact(std::shared_ptr<IAbstractProductA> a) = 0;
		virtual const std::string getName() const noexcept = 0;
	};



	class ConcreteFactory1: public IAbstractFactory {
	public:
		virtual std::shared_ptr<IAbstractProductA> createProductA() override;
		virtual std::shared_ptr<IAbstractProductB> createProductB() override;
	};

	class ConcreteFactory2 : public IAbstractFactory {
	public:
		virtual std::shared_ptr<IAbstractProductA> createProductA() override;
		virtual std::shared_ptr<IAbstractProductB> createProductB() override;
	};



	class ProductA1 : public IAbstractProductA {
	public:
		virtual void interact(std::shared_ptr<IAbstractProductB> product) override;
		virtual const std::string getName() const noexcept override;
	};

	class ProductB1 : public IAbstractProductB {
	public:
		virtual void interact(std::shared_ptr<IAbstractProductA> product) override;
		virtual const std::string getName() const noexcept override;
	};

	class ProductA2 : public IAbstractProductA {
	public:
		virtual void interact(std::shared_ptr<IAbstractProductB> product) override;
		virtual const std::string getName() const noexcept override;
	};

	class ProductB2 : public IAbstractProductB {
	public:
		virtual void interact(std::shared_ptr<IAbstractProductA> product) override;
		virtual const std::string getName() const noexcept override;
	};


	class Client {
	private:
		std::shared_ptr<IAbstractProductA> productA;
		std::shared_ptr<IAbstractProductB> productB;

	public:
		Client(std::shared_ptr<IAbstractFactory> factory);

	public:
		virtual void execute();
	};

	void Test();
};

#endif // !ABSTRACT_FACTORY_PATTERN_TESTS__H_