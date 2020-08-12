#include <iostream>
#include <string>
#include <list>

namespace Observer_Tests {

	class SupervisedString;
	class IObserver
	{
	public:
		virtual void handleEvent(const SupervisedString&) = 0;
	};

	// Observable class
	class SupervisedString {
	private:
		std::string _str;
		std::list<IObserver*> _observers;

	private:
		void _Notify();

	public:
		void  add(IObserver& ref);
		void  remove(IObserver& ref);
		const std::string& get() const;
		void  reset(std::string str);
	};

	// Prints the observed string into cout
	class Reflector : public IObserver {
	public:
		virtual void handleEvent(const SupervisedString& ref);
	};

	// Prints the length of observed string into cout
	class Counter : public IObserver {
	public:
		virtual void handleEvent(const SupervisedString& ref);
	};


	void Test1();
}