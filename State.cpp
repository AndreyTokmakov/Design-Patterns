#include "State.h"

namespace State_Pattern_Tests {


	State::State(CString name) : name(name) {
	}

	const String State::GetName() const noexcept  {
		return this->name;
	}
	
	
	
	StateContext::StateContext(std::unique_ptr<IState> state): state(state.release()) {
	}

	void StateContext::Freeze() {
		std::cout << "Freezing " << state->GetName() << "..." << std::endl;
		this->state->Freeze(this->shared_from_this());
	}

	void StateContext::Heat() {
		std::cout << "Heating " << state->GetName() << "..." << std::endl;
		this->state->Heat(this->shared_from_this());
	}

	void StateContext::SetState(std::unique_ptr<IState> state) noexcept {
		std::cout << "Chaging state from " << this->state->GetName() << " to " << state->GetName() << "..." << std::endl;
		this->state.reset(state.release());
	}

	std::unique_ptr<IState> StateContext::GetState() noexcept {
		return std::move(this->state);
	}

	StateContext::~StateContext() {
		// delete this->state;
		std::cout << "Destroing stata " << this->state->GetName() << std::endl;
	}


	SolidState::SolidState() : State("Solid") {
	}

	void SolidState::Freeze(std::shared_ptr<StateContext> context) {
		std::cout << "Nothing happens" << std::endl;
	}

	void SolidState::Heat(std::shared_ptr<StateContext> context) {
		context->SetState(std::make_unique<LiquidState>());
	}


	
	
	LiquidState::LiquidState(): State("Liquid") {
	}

	void LiquidState::Freeze(std::shared_ptr<StateContext> context) {
		context->SetState(std::make_unique<SolidState>());
	}

	void LiquidState::Heat(std::shared_ptr<StateContext> context) {
		context->SetState(std::make_unique<GasState>());
	}

	

	GasState::GasState() : State("Gas")  {
	}

	void GasState::Freeze(std::shared_ptr<StateContext> context) {
		context->SetState(std::make_unique<LiquidState>());
	}

	void GasState::Heat(std::shared_ptr<StateContext> context) {
		std::cout << "Nothing happens" << std::endl;
	}
	

	void Test()
	{
		std::shared_ptr<StateContext> sc = std::make_shared<StateContext>(std::make_unique<SolidState>());
		sc->Heat();
		sc->Heat();
		sc->Heat();
		sc->Freeze();
		sc->Freeze();
		sc->Freeze();
	}
}

