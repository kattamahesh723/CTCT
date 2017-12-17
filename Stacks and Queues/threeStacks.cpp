/*
	Q.	Implement three stacks using single array. 
*/

/*
	Solution: Two ways to solve this problem 
		1. Divide the array into three equal parts
		2. Use space efficiently, because one stack can have more elements than others. Will store information of the previous
		   element in the current top element along with the information of stack.
*/

#include<iostream>
#define MAX_SIZE 20

using namespace std;

struct Data{
	int data;				// Stores the value of the stack element		
	int stack_number;		// Has the information about the stack
};

struct Index{
	int current_index;		// Stores at which index the current element is stored
	int prev_index;			// Stores at which index the previous element is stored
}

Data Stack[MAX_SIZE];		// Declared as global variable
Index top[3];				// Stores current and prev indices of top elements
int index;					// Global index of Stack array

// data is the value need to be pushed, stack has the value into which stack the operation is done
void initialize();
void push(int data, int stack_number);		
void pop(int stack_number);
int peek(int stack_number);
bool isEmpty(int stack_number);

int main()
{
	
}

void initialize(){
	top[0] = {-1,-1};
	top[1] = {-1,-1};
	top[2] = {-1,-1};
}

bool isEmpty(int stack_number){
	return top[stack_number].current_index == -1;
}

void push(int data, int stack_number){
	if(isEmpty(stack_number)){
		index++;
		Stack[index].data = data;
		Stack[index].stack_number = stack_number;
		top[stack_number].current_index = index;
	}
	else{
		index++;
		Stack[index].data = data;
		Stack[index].stack_number = stack_number;
		top[stack_number].prev_index = current_index;
		top[stack_number].current_index = index;
	}
}

void pop(int stack_number){
	if(isEmpty(stack_number)){
		cout<<"Stack is empty, Pop operation is not valid"<<endl;
	}
	else{
		
	}
}