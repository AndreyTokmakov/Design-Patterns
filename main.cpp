
#include "Adapter.h"
#include "ObjectPools.h"
#include "Bridge.h"
#include "Observer.h"
#include "Singleton.h"
#include "Decorator.h"
#include "FabricMethod.h"
#include "Proxy_Pattern_Tests.h"
#include "Command.h"
#include "State.h"
#include "Visitor.h"
#include "Strategy.h"
#include "ChainOfResponsibility.h"
#include "AbstractFactory.h"
#include "Builder.h"

#include <chrono>
#include <thread>

int main(int argc, char** argv)
{
	// Adapter::TEST_ALL();
	// Observer_Tests::Test1();
	// Singleton::TEST_ALL();;
	// DecoratorTests::Test();
	// FabricMethod::Test();
	// Proxy_Pattern_Tests::Test();
	// Proxy_Pattern_Tests::Test2();
	// Command_Pattern_Tests::Test();
	// Visitor_Pattern_Tests::test();
	 State_Pattern_Tests::Test();
	// Strategy_Pattern_Tests::Test();
	// ChainOfResponsibility_Pattern_Tests::Test();
	// AbstractFactory_Pattern_Tests::Test();
	// Builder_Pattern_Tests::Test();
	// Bridge::TEST_ALL();
	// ObjectPools::TEST_ALL();


	std::this_thread::sleep_for(std::chrono::seconds(100));
}

