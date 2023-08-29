// Finite-State Machine (FSM) Operations in C++ Language
// Instructor: Dr. Shayan (Sean) Taheri

#include <iostream>
#include <utility>
#include <map>

typedef enum {
    Idle,
    Start,
    Stop,
    ChangeSpeed
}State;


class Engine
{
public:
    typedef enum {
        SetSpeed,
        Halt
    }Action;

    typedef void (Engine::*DoAction)(void);

    Engine() {
        std::cout << "Engine()" << std::endl;
    }
    void setSpeed() {
        std::cout << "Engine::setSpeed()" << std::endl;
    }
    void halt() {
        std::cout << "Engine::halt()" << std::endl;
    }
};

struct ActionCallback
{
    Engine::Action         action;
    Engine::DoAction       callback;
    ActionCallback(Engine::Action a, Engine::DoAction c):action(a), callback(c){}
};

struct StateAction {
    State state_;
    Engine::Action action_;
    StateAction(State state, Engine::Action action):state_(state), action_(action){}
    friend bool operator<(const StateAction& sta1, const StateAction& sta2) {
        return (sta1.state_ < sta2.state_) ||
        (sta1.state_ == sta2.state_ &&
         sta1.action_ < sta2.action_);
    }
};

class StateMachine {
public:
    typedef std::map<StateAction, State> StateDiagram;


    StateMachine(Engine &engine):engine_(engine) {
        stateDiag_[StateAction(Idle, Engine::SetSpeed)] = Start;
        stateDiag_[StateAction(Start, Engine::SetSpeed)] = ChangeSpeed;
        stateDiag_[StateAction(ChangeSpeed, Engine::SetSpeed)] = ChangeSpeed;
        stateDiag_[StateAction(ChangeSpeed, Engine::Halt)] = Stop;
        stateDiag_[StateAction(Start, Engine::Halt)] = Stop;
        //
        //  current state is initialized to Idle
        //
        currentState_ = Idle;
        std::cout << "State machine initial state: " << currentState_ << std::endl;
    }
    void performAction(ActionCallback actionCallback) {
        //
        //  The state machine "state" is: currentState
        //
        StateAction stateAction(currentState_, actionCallback.action);

        if (stateDiag_.find(stateAction) == stateDiag_.end()) {
            //
            //  Invalid state transition
            //
            std::cout << "You cannot perform action: "
            << actionCallback.action
            << " from state: "
            << currentState_
            << ", invalid transition!!!"
            << std::endl;
            return;
        }
        State oldState = currentState_;
        //
        //  Execute the action and update the state machine
        //
        (engine_.*actionCallback.callback)();
        currentState_ = stateDiag_[stateAction];

        std::cout << "State changed:\n\tOld state: " << oldState << "\n\tNew state: " << currentState_ << std::endl;
        //
        //  If current state is: Stop change state to: Idle
        //
        if (Stop == currentState_) {
            oldState = currentState_;
            currentState_ = Idle;
            std::cout << "State changed:\n\tOld state: " << oldState << "\n\tNew state: " << currentState_ << std::endl;
        }


    }
    State getInitialState() {
        return Idle;
    }

private:
    StateDiagram stateDiag_;
    State currentState_;
    Engine engine_;
};

// Driver Code
int main()
{
    // Task 1: Create an Engine in Your Finite-State Machine
	
	// Task 2: Show the Machine Current State
	
	// Task 3: Perform FSM Actions

    return 0;
}