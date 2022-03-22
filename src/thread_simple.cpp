#include <string>
#include <iostream>
#include <thread>

using namespace std;

int balance = 0;

//start with a low number and run program, 
//final line below (~line 50) will always print 'balance=0'
//increase NUMB_TIMES, when it gets to 50000 or so final line
//will print a different result every time program is run
const int NUMB_TIMES=50000;

void inc1()
{
	for(int i=0;i<NUMB_TIMES;i++){
		balance = balance+1;
		balance++;
		
		//non threadsafe API below
//		cout<<"In inc1"<<"inc1"<<"inc1"<<"inc1"<<"inc1"<<"inc1"<<"inc1"<<endl;
	}
}

void dec1()
{
	for(int i=0;i<NUMB_TIMES;i++){
		balance = balance-1;
		balance--;
//		cout<<"In dec2"<<"dec2"<<"dec2"<<"dec2"<<"dec2"<<"dec2"<<"dec2"<<endl;
	}
}

int main()
{

	// constructs threads and runs them
	thread t1(dec1);	//thread t1 starts by executing func dec1
	thread t2(inc1);

	//Show dissasembly view (window->Show View->Other->debug->Disassembly
	//the following instruction = 3 assembly instructions
	//interrupt can happen after any of those, what happens if

	// Makes the main thread wait for the new thread to finish execution,
	// therefore blocks its own execution.
	t2.join();
	t1.join();

	cout<<"balance ="<<balance<<endl;
}
