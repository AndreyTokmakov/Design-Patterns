
#include "Singleton.h"

namespace Singleton {

	Singleton* Singleton::Singleton::instance = nullptr;

	Singleton::Singleton() {
		this->counter = 0;
		std::cout << "Singleton::Singleton()" << std::endl;
	}

	Singleton* Singleton::Instance() {
		if (nullptr == instance) {
			instance = new Singleton();
		}
		return instance;
	}
}

namespace Singleton::SharedPtrSingleton {

	SingletonSharedPtr::SingletonSharedPtr() {
		this->counter = 0;
		std::cout << "SingletonSharedPtr::SingletonSharedPtr()" << std::endl;
	}

	std::shared_ptr<SingletonSharedPtr> SingletonSharedPtr::Instance() {
		struct make_shared_enabler : public SingletonSharedPtr {};
		static std::shared_ptr<make_shared_enabler> instance = std::make_shared<make_shared_enabler>();
		return instance;
	}

	///////////////////////////////////////////
	
	void Test() {
		std::shared_ptr<SingletonSharedPtr> s1 = SingletonSharedPtr::Instance();
		std::shared_ptr<SingletonSharedPtr> s2 = SingletonSharedPtr::Instance();

		std::cout << s1->GetCounter() << std::endl;
		std::cout << s2->GetCounter() << std::endl;

		s1->Increment();

		std::cout << s1->GetCounter() << std::endl;
		std::cout << s2->GetCounter() << std::endl;

		s2->Increment();

		std::cout << s1->GetCounter() << std::endl;
		std::cout << s2->GetCounter() << std::endl;

		s1->Increment();

		std::cout << s1->GetCounter() << std::endl;
		std::cout << s2->GetCounter() << std::endl;
	}
}

namespace Singleton::SingletonTests {

	void Test1() {
		Singleton* s1 = Singleton::Instance();
		Singleton* s2 = Singleton::Instance();

		std::cout << s1->GetCounter() << std::endl;
		std::cout << s2->GetCounter() << std::endl;

		s1->Increment();

		std::cout << s1->GetCounter() << std::endl;
		std::cout << s2->GetCounter() << std::endl;

		s2->Increment();

		std::cout << s1->GetCounter() << std::endl;
		std::cout << s2->GetCounter() << std::endl;

		s1->Increment();

		std::cout << s1->GetCounter() << std::endl;
		std::cout << s2->GetCounter() << std::endl;

	}

	void Singleton_SharedPtr() {
		Singleton* s1 = Singleton::Instance();
		Singleton* s2 = Singleton::Instance();

		std::cout << s1->GetCounter() << std::endl;
		std::cout << s2->GetCounter() << std::endl;

		s1->Increment();

		std::cout << s1->GetCounter() << std::endl;
		std::cout << s2->GetCounter() << std::endl;

		s2->Increment();

		std::cout << s1->GetCounter() << std::endl;
		std::cout << s2->GetCounter() << std::endl;

		s1->Increment();

		std::cout << s1->GetCounter() << std::endl;
		std::cout << s2->GetCounter() << std::endl;

	}
}

////////////////////////////////////////////////////////////////////////////////////


namespace Singleton::MeyersSingleton {

	MSingleton* MSingleton::Instance() {
		static MSingleton theSingleInstance;
		return &theSingleInstance;
	}

	MSingleton::MSingleton() {
		std::cout << "MSingleton::MSingleton()" << std::endl;
	};

	///////////////////// BAD ////////////////////////////////////


	MSingletonBad& MSingletonBad::Instance() {
		static MSingletonBad theSingleInstance;
		return theSingleInstance;
	}

	MSingletonBad::MSingletonBad() {
		std::cout << "MSingletonBad::MSingletonBad()" << std::endl;
	};

}

/////////////////////////////////////////

namespace Singleton::MeyersSingletonTests {

	using namespace MeyersSingleton;

	void Test1() {
		MSingleton* s1 = MSingleton::Instance();
		MSingleton* s2 = MSingleton::Instance();

		s1->Increment();
		std::cout << s2->GetCounter() << std::endl;
		s2->Increment();
		std::cout << s1->GetCounter() << std::endl;
	}

	void TestBad() {
		MSingletonBad& s1 = MSingletonBad::Instance();
		MSingletonBad& s2 = MSingletonBad::Instance();

		std::cout << s1.GetCounter() << std::endl;
		std::cout << s2.GetCounter() << std::endl;

		s1.Increment();

		std::cout << s1.GetCounter() << std::endl;
		std::cout << s2.GetCounter() << std::endl;

		s1.Increment();

		std::cout << s1.GetCounter() << std::endl;
		std::cout << s2.GetCounter() << std::endl;
	}
}

void Singleton::TEST_ALL() {

	 MeyersSingletonTests::Test1();
	// MeyersSingletonTests::TestBad();

	// SingletonTests::Test1();

	// SharedPtrSingleton::Test();
}
