// Problem 3.6:
// Write a program to sort a stack in ascending order (with biggest items on top).
// You may use at most one additional stack to hold items, but you may not copy
// the elements into any other data structure (such as an array). The stack supports
// the following operations: push, pop, peek, and isEmpty.

// time 22.30 min

#include<iostream>
#include<stack>

using namespace std;

void print_stack(stack<int> s1){
	cout << "top | ";
	while(s1.size() > 0){
		cout << s1.top() << " | ";
		s1.pop();
	}
	cout << "base" << endl;
}


stack<int> * sort(stack<int> *s){
	stack<int> *sorted = new stack<int>;
	while(!s->empty()){
		int element = s->top();
		s->pop();
		if(sorted->empty()){
			// print_stack(*sorted);
			sorted->push(element);
		}
		else if(sorted->top() < element){
			// print_stack(*sorted);
			sorted->push(element);
		}else{
			// print_stack(*sorted);
			int count =0;
			while(!sorted->empty() && (sorted->top() > element)){
				count ++;
				s->push(sorted->top());
				sorted->pop();
			}
			sorted->push(element);
			while(count--){
				sorted->push(s->top());
				s->pop();
			}
		}
	}
	return sorted;
}


int main(){

	stack<int> source;
	stack<int> *sorted;
	source.push(1);
	source.push(5);
	source.push(3);
	source.push(7);
	source.push(2);
	source.push(8);
	source.push(4);
	source.push(9);
	source.push(6);

	cout << "original ";
	print_stack(source);
	sorted = sort(&source);
	cout << "sorted ";
	print_stack(*sorted);
	
	return 0;
}