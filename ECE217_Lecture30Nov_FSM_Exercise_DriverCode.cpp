// Finite-State Machine (FSM) Operations in C++ Language
// Instructor: Dr. Shayan (Sean) Taheri

// Driver Code
int main()
{
    // Task 1: Create an Engine in Your Finite-State Machine
	
	// Task 2: Show the Machine Current State
	
	// Task 3: Perform FSM Actions
	
	Engine engine;
    StateMachine stateMachine(engine);
    stateMachine.performAction(ActionCallback(Engine::SetSpeed, &Engine::setSpeed));
    stateMachine.performAction(ActionCallback(Engine::Halt, &Engine::halt));
    return 0;
}