#include "Observer.h"

namespace Observer_Tests {

	void SupervisedString::_Notify() {
		for (auto& observer : _observers) {
			observer->handleEvent(*this);
		}
	}

	void SupervisedString::add(IObserver& ref) {
		_observers.push_back(&ref);
	}

	void SupervisedString::remove(IObserver& ref) {
		_observers.remove(&ref);
	}

	const std::string& SupervisedString::get() const {
		return _str;
	}

	void SupervisedString::reset(std::string str) {
		_str = str;
		_Notify();
	}

	void Reflector::handleEvent(const SupervisedString& ref) {
		std::cout << ref.get() << std::endl;
	}

	void Counter::handleEvent(const SupervisedString& ref) {
		std::cout << "length = " << ref.get().length() << std::endl;
	}
}

namespace Observer_Tests {

	void Test1() {
		SupervisedString supervisedString;
		Reflector refl;
		Counter cnt;

		supervisedString.add(refl);
		supervisedString.reset("Hello, World!");
		std::cout << std::endl;

		supervisedString.reset("Hello, World 123");
		std::cout << std::endl;
	
		supervisedString.remove(refl);
		supervisedString.add(cnt);
		supervisedString.reset("World, Hello!");
	}
}