//============================================================================
// Name        : State.h
// Created on  : 15.04.2020
// Author      : Tokmakov Andrey
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : State pattern tests
//============================================================================

#ifndef STATE_PATTERN_TESTS__H_
#define STATE_PATTERN_TESTS__H_

#include <iostream>
#include <string>
#include <memory>

namespace State_Pattern_Tests {

	class StateContext;
	using String = std::string;
	using CString = const String&;

	class IState {
	public:
		virtual const String GetName() const noexcept = 0;
		virtual void Freeze(std::shared_ptr<StateContext> context) = 0;
		virtual void Heat(std::shared_ptr<StateContext> context) = 0;
	};


	class State : public IState {
	private:
		String name;
	public:
		State(CString name);
		virtual const String GetName() const noexcept override;
	};
	
	
	class StateContext : public std::enable_shared_from_this<StateContext>{
	private:
		std::unique_ptr<IState> state;

	public:
		StateContext(std::unique_ptr<IState> state);
		virtual ~StateContext();

	public:
		void Freeze();
		void Heat();
		void SetState(std::unique_ptr<IState> state) noexcept;
		std::unique_ptr<IState> GetState() noexcept;
	};


	class SolidState : public State {
	public:
		SolidState();
		virtual void Freeze(std::shared_ptr<StateContext> context);
		virtual void Heat(std::shared_ptr<StateContext> context);
	};


	class LiquidState : public State {
	public:
		LiquidState();
		virtual void Freeze(std::shared_ptr<StateContext> context);
		virtual void Heat(std::shared_ptr<StateContext> context);
	};


	class GasState : public State {
	public:
		GasState();
		virtual void Freeze(std::shared_ptr<StateContext> context);
		virtual void Heat(std::shared_ptr<StateContext> context);
	};

	void Test();
}


#endif /* STATE_PATTERN_TESTS__H_ */


