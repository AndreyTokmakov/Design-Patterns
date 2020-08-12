//============================================================================
// Name        : Builder.cpp
// Created on  : 19.04.2020
// Author      : Tokmakov Andrey
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Builder design pattern tests
//============================================================================

#include "Builder.h"

namespace Builder_Pattern_Tests {

	Pizza::Pizza(){
	}

	Pizza::~Pizza()
	{
	}

	void Pizza::setName(CString name) noexcept {
		this->name = name;
	}

	void Pizza::setDough(CString dough) noexcept {
		this->dough = dough;
	}

	void Pizza::setSauce(CString sauce) noexcept {
		this->sauce = sauce;
	}

	void Pizza::setTopping(CString topping) noexcept {
		this->topping = topping;
	}

	String Pizza::getName() const noexcept {
		return this->name;
	}


	std::shared_ptr<Pizza> PizzaBuilder::getPizza() noexcept {
		return this->pizza;
	}

	void PizzaBuilder::createNewPizzaProduct() {
		this->pizza = std::shared_ptr<Pizza>(new Pizza);
	}



	void HawaiianPizzaBuilder::setName() {
		this->pizza->setName("HawaiianPizzaBuilder");
	}

	void HawaiianPizzaBuilder::buildDough() {
		this->pizza->setDough("cross");
	}

	void HawaiianPizzaBuilder::buildSauce() {
		this->pizza->setSauce("mild");
	}

	void HawaiianPizzaBuilder::buildTopping() {
		this->pizza->setTopping("ham + pineapple");
	}




	void SpicyPizzaBuilder::setName() {
		this->pizza->setName("SpicyPizzaBuilder");
	}

	void SpicyPizzaBuilder::buildDough() {
		this->pizza->setDough("pan baked");
	}

	void SpicyPizzaBuilder::buildSauce() {
		this->pizza->setSauce("hot");
	}

	void SpicyPizzaBuilder::buildTopping() {
		this->pizza->setTopping("pepperoni + salami");
	}



	void Waiter::setPizzaBuilder(std::shared_ptr<PizzaBuilder> pizzaBuilder) noexcept {
		this->pizzaBuilder = pizzaBuilder;
	}

	std::shared_ptr<Pizza> Waiter::getPizza() noexcept {
		return this->pizzaBuilder->getPizza();
	}

	void Waiter::constructPizza() noexcept {
		pizzaBuilder->createNewPizzaProduct();
		pizzaBuilder->setName();
		pizzaBuilder->buildDough();
		pizzaBuilder->buildSauce();
		pizzaBuilder->buildTopping();
	}

	void Test()
	{
		Waiter* waiter = new Waiter();
		{
			std::shared_ptr<PizzaBuilder> builder = std::make_shared<HawaiianPizzaBuilder>();
			waiter->setPizzaBuilder(builder);
			waiter->constructPizza();

			std::shared_ptr<Pizza> pizza = waiter->getPizza();
			std::cout << "Pizza: " << pizza->getName() << std::endl;
		}

		{
			std::shared_ptr<PizzaBuilder> builder = std::make_shared<SpicyPizzaBuilder>();
			waiter->setPizzaBuilder(builder);
			waiter->constructPizza();

			std::shared_ptr<Pizza> pizza = waiter->getPizza();
			std::cout << "Pizza: " << pizza->getName() << std::endl;
		}
	}
};