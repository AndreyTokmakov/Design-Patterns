
#include <iostream> 
#include <string> 

namespace Singleton {

	class SingletonBase {
	protected:
		long counter;

	public:
		inline void Increment() noexcept {
			this->counter++;
		}

		inline long GetCounter() const noexcept {
			return this->counter;
		}
	};
}

namespace Singleton::MeyersSingleton {


	class MSingletonBad {
	public:
		static MSingletonBad& Instance();

	public:
		inline void Increment() noexcept {
			this->counter++;
		}

		inline long GetCounter() const noexcept {
			return this->counter;
		}

	protected:
		long counter;

	private:
		MSingletonBad();
		MSingletonBad(const MSingletonBad& root) = default;

		MSingletonBad operator=(const MSingletonBad&) = delete;

	};

	///////////////////////////////////////////

	class MSingleton {
	protected:
		long counter;

	public:
		static MSingleton* Instance();

	public:
		inline void Increment() noexcept {
			this->counter++;
		}

		inline long GetCounter() const noexcept {
			return this->counter;
		}

	private:
		MSingleton();

	public:
		MSingleton(const MSingleton& obj) = delete;
		MSingleton(MSingleton&& obj) noexcept = delete;
		MSingleton& operator=(const MSingleton& obj) = delete;
		MSingleton& operator=(MSingleton&& obj) noexcept = delete;
	};

	/*
	class MSingletonTest {
	private:
		MSingletonTest(); // Disallow instantiation outside of the class.

	public:
		MSingletonTest(const MSingletonTest&) = delete;
		MSingletonTest& operator=(const MSingletonTest &) = delete;
		MSingletonTest(MSingletonTest &&) = delete;
		MSingletonTest & operator=(MSingletonTest &&) = delete;

		static auto& instance() {
			static MSingletonTest test;
			return test;
		}
	};*/
};

namespace Singleton::SharedPtrSingleton {

	/*
	template<class T>
	class TrackingAllocator
	{
	public:
		using value_type = T;
		using pointer = T * ;
		using const_pointer = const T *;
		using size_type = size_t;

		TrackingAllocator() = default;

		template<class U>
		TrackingAllocator(const TrackingAllocator<U> &other) {
			// TODO:
		}

		~TrackingAllocator() = default;

		pointer allocate(size_type numObjects) {
			std::cout << "Custom allocate <" << typeid(T).name() << "> object" << std::endl;
			return static_cast<pointer>(operator new(sizeof(T) * numObjects));
		}

		void deallocate(pointer p, size_type numObjects) {
			std::cout << "Custom deallocate <" << typeid(T).name() << "> object" << std::endl;
			operator delete(p);
		}
	};
	*/

	class SingletonSharedPtr: public SingletonBase {
	protected:
		SingletonSharedPtr();

	public:
		SingletonSharedPtr(SingletonSharedPtr const&) = delete;
		SingletonSharedPtr(SingletonSharedPtr&&) noexcept = delete;
		SingletonSharedPtr& operator=(SingletonSharedPtr const&) = delete;
		SingletonSharedPtr& operator=(SingletonSharedPtr&&) noexcept = delete;

		virtual ~SingletonSharedPtr() = default;

	public:
		static std::shared_ptr<SingletonSharedPtr> Instance();
	};
}


namespace Singleton {

	class Singleton: public SingletonBase {
	protected:
		static Singleton* instance;
		Singleton();

	public:
		Singleton(Singleton const&) = delete;
		Singleton(Singleton&&) noexcept = delete;
		Singleton& operator=(Singleton const&) = delete;
		Singleton& operator=(Singleton&&) noexcept = delete;

		virtual ~Singleton() = default;

	public:
		static Singleton* Instance();
	};

	void TEST_ALL();
}

