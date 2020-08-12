#include "AbstractFactory.h"

namespace AbstractFactory_Pattern_Tests {

	std::shared_ptr<IAbstractProductA> ConcreteFactory1::createProductA() {
		return std::make_shared<ProductA1>();
	}

	std::shared_ptr<IAbstractProductB> ConcreteFactory1::createProductB() {
		return std::make_shared<ProductB1>();
	}

	std::shared_ptr<IAbstractProductA> ConcreteFactory2::createProductA() {
		return std::make_shared<ProductA2>();
	}

	std::shared_ptr<IAbstractProductB> ConcreteFactory2::createProductB() {
		return std::make_shared<ProductB2>();
	}


	void ProductA1::interact(std::shared_ptr<IAbstractProductB> product) {
		std::cout << this->getName() << " interacts with " << product->getName() << std::endl;
	}

	const std::string ProductA1::getName() const noexcept {
		return "ProductA1";
	}

	void ProductB1::interact(std::shared_ptr<IAbstractProductA> product) {
		std::cout << this->getName() << " interacts with " << product->getName() << std::endl;
	}

	const std::string ProductB1::getName() const noexcept {
		return "ProductB1";
	}

	void ProductA2::interact(std::shared_ptr<IAbstractProductB> product) {
		std::cout << this->getName() << " interacts with " << product->getName() << std::endl;
	}

	const std::string ProductA2::getName() const noexcept {
		return "ProductA2";
	}

	void ProductB2::interact(std::shared_ptr<IAbstractProductA> product) {
		std::cout << this->getName() << " interacts with " << product->getName() << std::endl;
	}

	const std::string ProductB2::getName() const noexcept {
		return "ProductB2";
	}


	Client::Client(std::shared_ptr<IAbstractFactory> factory) {
		productA = factory->createProductA();
		productB = factory->createProductB();
	}

	void Client::execute() {
		this->productB->interact(this->productA);
	}

	void Test()
	{
		std::shared_ptr<Client> client1 = std::make_shared<Client>(std::make_shared<ConcreteFactory1>());
		client1->execute();
	
		std::shared_ptr<Client> client2 = std::make_shared<Client>(std::make_shared<ConcreteFactory2>());
		client2->execute();
	}

}