// Problem 3.4:
// In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of
// different sizes which can slide onto any tower. The puzzle starts with disks sorted
// in ascending order of size from top to bottom (i.e., each disk sits on top of an
// even larger one). You have the following constraints:
// (1) Only one disk can be moved at a time.
// (2) A disk is slid off the top of one tower onto the next tower.
// (3) A disk can only be placed on top of a larger disk.
// Write a program to move the disks from the first tower to the last using stacks.

// time 16 min 

#include<iostream>
#include<stack>

using namespace std;

void towerOfHanoi(int n, stack<int> *source, stack<int> *buffer, stack<int> *dest){
	if(n <=0)
		return;
	towerOfHanoi(n-1, source, dest, buffer);
	dest->push( source->top() );
	source->pop();
	towerOfHanoi(n-1, buffer, source, dest);
}

void print_stack(stack<int> s1){
	cout << "top | ";
	while(s1.size() > 0){
		cout << s1.top() << " | ";
		s1.pop();
	}
	cout << "base" << endl;
}

int main(){

	stack<int> source;
	stack<int> buffer;
	stack<int> dest;
	
	source.push(9);
	source.push(8);
	source.push(7);
	source.push(6);
	source.push(5);
	source.push(4);
	source.push(3);
	source.push(2);
	source.push(1);

	cout << "source ";
	print_stack(source);
	cout << "buffer ";
	print_stack(buffer);
	cout << "dest   ";
	print_stack(dest);
	towerOfHanoi(source.size(), &source, &buffer, &dest);
	cout << "source ";
	print_stack(source);
	cout << "buffer ";
	print_stack(buffer);
	cout << "dest   ";
	print_stack(dest);
	
	return 0;
}