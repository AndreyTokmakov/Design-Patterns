#include "FabricMethod.h"

namespace FabricMethod {

	std::string ProductA::getName() {
		return "ProductA";
	}

	std::string ProductB::getName() {
		return "ProductB";
	}

	std::shared_ptr<IProduct> ConcreteCreatorA::factoryMethod() {
		return std::make_shared<ProductA>();
	}

	std::shared_ptr<IProduct> ConcreteCreatorB::factoryMethod() {
		return std::make_shared <ProductB>();
	}

	void Test() {
		ConcreteCreatorA CreatorA;
		ConcreteCreatorB CreatorB;
		ICreator* creators[] = {&CreatorA, &CreatorB};

		for (auto&& creator : creators) {
			std::shared_ptr<IProduct> product = creator->factoryMethod();
			std::cout << "New product: " <<  product->getName() << std::endl;
		}
	}
}
