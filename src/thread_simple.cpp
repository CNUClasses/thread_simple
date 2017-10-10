//============================================================================
// Name        : thread_simple.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <string>
#include <iostream>
#include <thread>

using namespace std;

int global = 0;

void inc()
{
	global++;
}

int main()
{
	// constructs threads and runs it
	//it starts by executing function task_inc
	thread t1(inc);

	//Show dissasembly view (window->Show View->Other->debug->Disassembly
	//the following instruction = 3 assembly instructions
	//interrupt can happen after any of those, what happens if
	global++;

	// Makes the main thread wait for the new thread to finish execution,
	// therefore blocks its own execution.
	t1.join();
}
