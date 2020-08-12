//============================================================================
// Name        : FabricMethod.h
// Created on  : 
// Author      : Tokmakov Andrey
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : FabricMethod tests
//============================================================================

#ifndef FABRIC_METHOD_TESTS__H__
#define FABRIC_METHOD_TESTS__H__

#include <iostream>
#include <string>

namespace FabricMethod {

	class IProduct {
	public:
		IProduct() {}
		virtual ~IProduct() = default;
		virtual std::string getName() = 0;
	};

	class ICreator {
	public:
		virtual std::shared_ptr<IProduct> factoryMethod() = 0;
	};




	class ProductA : public IProduct {
	public:
		ProductA() {}
		virtual std::string getName() override final;
	};
	
	class ProductB : public IProduct {
	public:
		ProductB() {}
		virtual std::string getName() override final;
	};




	class ConcreteCreatorA : public ICreator {
	public:
		std::shared_ptr<IProduct> factoryMethod() override final;
	};

	class ConcreteCreatorB : public ICreator {
	public:
		std::shared_ptr<IProduct> factoryMethod() override final;
	};

	void Test();

}
#endif // !FABRIC_METHOD_TESTS__H__