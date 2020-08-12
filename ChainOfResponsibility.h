//============================================================================
// Name        : ChainOfResponsibility.h
// Created on  : 19.04.2020
// Author      : Tokmakov Andrey
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Chain of pesponsibility pattern tests
//============================================================================

#ifndef CHAIN_OF_RESPONSIBILITY_PATTERN_TESTS__H_
#define CHAIN_OF_RESPONSIBILITY_PATTERN_TESTS__H_

#include <iostream>
#include <string>
#include <memory>

namespace ChainOfResponsibility_Pattern_Tests {

	using String = std::string;
	using CString = const String&;

	/** Criminal action class: **/
	class CriminalAction {
	private:
		friend class Policeman;

		/** Case complexity: **/
		int complexity;

		/** Case brif description: **/
		String description;

	public:
		CriminalAction(int complexity, CString description);

		virtual ~CriminalAction() { 
			// std::cout << __FUNCTION__ << std::endl; 
		}
	};



	/** Abstract policeman who can investigate crimes. **/
	class Policeman {
	protected:
		/** Deduction (the ability to unravel complex cases) with this police officer. **/
		int deduction;

		/** a more skilled policeman who will receive a case if it is too complicated for the current one. **/
		std::shared_ptr<Policeman> next;

		/** The investigation. **/
		virtual void investigateConcrete(CString description) = 0;

	public:
		Policeman(int deduction);

		virtual ~Policeman();

		// Adds to the chain of responsibility a more experienced policeman who can take over investigation if the current fails
		std::shared_ptr<Policeman> setNext(std::shared_ptr<Policeman> policeman);

		// A policeman begins an investigation or, if the case is too complicated, passes it to a more experienced colleague
		void investigate(std::shared_ptr<CriminalAction> criminalAction);
	};


	/** Martin Riggs the Policeman. **/
	class MartinRiggs : public Policeman {
	protected:
		void investigateConcrete(CString description);

	public:
		MartinRiggs(int deduction);
	};

	/** John McClane the Policeman. **/
	class JohnMcClane : public Policeman {
	protected:
		void investigateConcrete(CString description);

	public:
		JohnMcClane(int deduction);
	};

	/** Vincent Hanna the Policeman. **/
	class VincentHanna : public Policeman {
	protected:
		void investigateConcrete(CString description);

	public:
		VincentHanna(int deduction);
	};

	void Test();
}

#endif /* CHAIN_OF_RESPONSIBILITY_PATTERN_TESTS__H_ */


