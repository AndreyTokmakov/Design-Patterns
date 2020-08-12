//============================================================================
// Name        : Builder.h
// Created on  : 19.04.2020
// Author      : Tokmakov Andrey
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Builder design pattern tests
//============================================================================

#ifndef BUILDER_DESIGN_PATTERN_TESTS__H_
#define BUILDER_DESIGN_PATTERN_TESTS__H_

#include <iostream>
#include <string>
#include <memory>

namespace Builder_Pattern_Tests {

	using String = std::string;
	using CString = const String&;

	/** "Product" */
	class Pizza {
	private:
		String dough;
		String sauce;
		String topping;
		String name;

	public:
		Pizza();
		virtual ~Pizza();

	public:
		virtual void setDough(CString dough) noexcept;
		virtual void setSauce(CString sauce) noexcept;
		virtual void setTopping(CString topping) noexcept;

		virtual void setName(CString name) noexcept;
		virtual String getName() const noexcept;
	};


	/** "Abstract Builder" */
	class PizzaBuilder {
	protected:
		std::shared_ptr<Pizza> pizza;

	public:
		std::shared_ptr<Pizza> getPizza() noexcept;
		virtual void createNewPizzaProduct();

		virtual void setName() = 0;
		virtual void buildDough() = 0;
		virtual void buildSauce() = 0;
		virtual void buildTopping() = 0;
	};


	/** "HawaiianPizzaBuilder" */
	class HawaiianPizzaBuilder: public PizzaBuilder {
	public:
		virtual void setName() override;
		virtual void buildDough() override;
		virtual void buildSauce() override;
		virtual void buildTopping() override;
	};

	/** SpicyPizzaBuilder:  */
	class SpicyPizzaBuilder : public PizzaBuilder {
	public:
		virtual void setName() override;
		virtual void buildDough() override;
		virtual void buildSauce() override;
		virtual void buildTopping() override;
	};

	/** "Director" */
	class Waiter {
	private:
		std::shared_ptr<PizzaBuilder> pizzaBuilder;

	public:
		void setPizzaBuilder(std::shared_ptr<PizzaBuilder> pizzaBuilder) noexcept;
		std::shared_ptr<Pizza> getPizza() noexcept;

	public:
		void constructPizza() noexcept;
	};

	void Test();
};


#endif // (!BUILDER_DESIGN_PATTERN_TESTS__H_)