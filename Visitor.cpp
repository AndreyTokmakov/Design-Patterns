//============================================================================
// Name        : Visitor.cpp
// Created on  : 17.04.2020
// Author      : Tokmakov Andrey
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Visitor pattern tests
//============================================================================

#include "Visitor.h"

void Visitor_Pattern_Tests::Foo::accept(IVisitor & v) {
	v.visit(*this);
}

void Visitor_Pattern_Tests::Bar::accept(IVisitor & v) {
	v.visit(*this);
}

void Visitor_Pattern_Tests::Baz::accept(IVisitor & v) {
	v.visit(*this);
}



void Visitor_Pattern_Tests::CustorVisitor::visit(Foo & ref) {
	value = "Foo";
}

void Visitor_Pattern_Tests::CustorVisitor::visit(Bar & ref) {
	value = "Bar";
}

void Visitor_Pattern_Tests::CustorVisitor::visit(Baz & ref) {
	value = "Baz";
}


void Visitor_Pattern_Tests::test() {
	Foo foo;
	Bar bar;
	Baz baz;
	IElement *elements[] = { &foo, &bar, &baz };

	CustorVisitor visitor;
	for (auto elem : elements) {
		elem->accept(visitor);
		std::cout << visitor.value << std::endl;
	}
}	