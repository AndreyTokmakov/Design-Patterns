
#include "Proxy.h"
#include "Document.h"
#include "Proxy_Pattern_Tests.h"

namespace Proxy_Pattern_Tests {

	void Test() {
		std::unique_ptr<ICar> car = std::make_unique<ProxyCar>(14);
		car->DriveCar();
		car = std::make_unique<ProxyCar>(25);
		car->DriveCar();
	}

	void Test2() {
		Document doc;

		doc.open();             // by default it opens page 1
		doc.changeToPage(4);
		doc.changeToPage(15);
		doc.changeToPage(24);
		doc.changeToPage(1);
		doc.changeToPage(37);
		doc.changeToPage(59);
	}
}