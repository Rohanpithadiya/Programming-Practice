// Problem 3.5
// Implement a MyQueue class which implements a queue using two stacks.

#include<iostream>
#include <stack>

using namespace std;

class myQueue{
	private:
	stack<int> *s1;
	stack<int> *s2;
	public:
		myQueue();
		void push(int);
		void pop();
		int front();
		int back();
		int size();
		bool isEmpty();
};

myQueue::myQueue(){
	s1 = new stack<int>;
	s2 = new stack<int>;
}

void myQueue::push(int key){
	s1->push(key);
}

void shift_elements(stack<int> *source, stack<int> *dest){
	while(!source->empty()){
	dest->push(source->top());
	source->pop();
	}
}






void myQueue::pop(){
	if (this->size() > 0){
		if( s2->empty()){
			shift_elements(s1,s2);
		}
	s2->pop();
	}
}

int myQueue::front(){
	if (this->size() > 0){
			if( s2->empty()){
				shift_elements(s1,s2);
		}
		return s2->top();
	}
	return -1;
}

int myQueue::back(){
	if (this->size() > 0){
		if(s1->empty()){
			shift_elements(s2,s1);
			int key = s1->top();
			shift_elements(s1,s2);
			return key;	
		}
	}
	return -1;
}


int myQueue::size(){
	return (s1->size() + s2->size());
}

bool myQueue::isEmpty(){
	if ( this->size() > 0)
		return true;
	return false;
}

int main(){
	myQueue q_object;

	cout <<"front " << q_object.front() << endl;
	cout <<"back " << q_object.back() << endl;
	q_object.pop();
	q_object.push(1);
	q_object.push(2);
	q_object.push(3);
	cout <<"front " << q_object.front() << endl;
	cout <<"back " << q_object.back() << endl;
	q_object.pop();
	cout <<"back " << q_object.front() << endl;
	q_object.pop();
	q_object.pop();
	q_object.pop();
	q_object.pop();
	q_object.push(4);
	q_object.push(5);
	q_object.push(6);
	q_object.push(7);
	cout <<"front "<< q_object.front() << endl;
	cout <<"back "<< q_object.back() << endl;

	return 0;
}