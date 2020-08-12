//============================================================================
// Name        : ChainOfResponsibility.cpp
// Created on  : 19.04.2020
// Author      : Tokmakov Andrey
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Chain of pesponsibility pattern tests
//============================================================================

#include "ChainOfResponsibility.h"

namespace ChainOfResponsibility_Pattern_Tests {

	CriminalAction::CriminalAction(int complexity, CString description) :
		complexity(complexity), description(description) {

	}

	//////////////////


	Policeman::Policeman(int deduction) :
		deduction(deduction), next(nullptr) {
	}

	Policeman::~Policeman() {
		// delete next;
		// std::cout << __FUNCTION__ << " " << typeid(*this).name() <<  std::endl;
	}

	std::shared_ptr<Policeman> Policeman::setNext(std::shared_ptr <Policeman> policeman) {
		next = policeman;
		return next;
	}

	void Policeman::investigate(std::shared_ptr<CriminalAction> criminalAction) {
		if (deduction < criminalAction->complexity) {
			if (next) {
				next->investigate(criminalAction);
			}
			else {
				std::cout << "This case is not disclosed to anyone." << std::endl;
			}
		}
		else {
			investigateConcrete(criminalAction->description);
		}
	}



	void MartinRiggs::investigateConcrete(CString description) {
		std::cout << "Case investigation '" << description << "' leads Sergeant Martin Riggs" << std::endl;
	}

	MartinRiggs::MartinRiggs(int deduction) : Policeman(deduction) {
	}





	void JohnMcClane::investigateConcrete(CString description) {
		std::cout << "Case investigation '" << description << "' leads Detective John McClanes" << std::endl;
	}

	JohnMcClane::JohnMcClane(int deduction) : Policeman(deduction) {
	}





	void VincentHanna::investigateConcrete(CString description) {
		std::cout << "Case investigation '" << description << "' leads Lieutenant Vincent Hanna" << std::endl;
	}

	VincentHanna::VincentHanna(int deduction) : Policeman(deduction) {
	}





	void Test()
	{
		std::shared_ptr<Policeman> policeman = std::make_shared<MartinRiggs>(3);
		policeman->setNext(std::make_shared<JohnMcClane>(5))->setNext(std::make_shared<VincentHanna>(8));
		policeman->investigate(std::make_shared<CriminalAction>(2, "Drug trade from Vietnam"));
		policeman->investigate(std::make_shared<CriminalAction>(7, "Cheeky bank robbery in downtown Los Angeles"));
		policeman->investigate(std::make_shared<CriminalAction>(5, "A series of explosions in downtown New York"));
	}

}