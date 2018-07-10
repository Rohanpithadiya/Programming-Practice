// Problem 3.3
// Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
// Therefore, in real life, we would likely start a new stack when the previous stack
// exceeds some threshold. Implement a data structure SetOf Stacks that mimics
// this. SetOf Stacks should be composed of several stacks and should create a
// new stack once the previous one exceeds capacity. SetOf Stacks. push() and
// SetOf Stacks. pop() should behave identically to a single stack (that is, popO
// should return the same values as it would if there were just a single stack).
// FOLLOW UP
// Implement a function popAt(int index) which performs a pop operation on
// a specific sub-stack.

// 25 min


#include<iostream>
#include<vector>

using namespace std;

struct Node {
int key;
struct Node *next;
struct Node* prev;
};

typedef struct Node node;

class stack{
private:
	int size_t;
	node * create_node(int);
public:
	node * top;
	stack();
	void push(int);
	int pop();
	int peep();
	int size();
};

stack::stack(){
	size_t = 0;
	top = nullptr;
}

node * stack::create_node(int key){
	node * new_node = new node;
	new_node->key = key;
	new_node->next = nullptr;
	new_node->prev = nullptr;
	return new_node;
}

void stack::push(int key){
	node * new_node = create_node(key);
	if(!top){
		top = new_node;
		size_t++;
		return;
	}
	top->next = new_node;
	new_node->prev = top;
	top = top->next;
	size_t++;
}

int stack::pop(){
	if(!top){
		cout << "stack underflow" << endl;
		return -1;
}
	int key = top->key;
	node * temp_node = top;
	top = top->prev;
	size_t--;
	delete temp_node;
	return key;
}

int stack::peep(){
	if(!top){
	cout << "stack is empty" << endl;
	return -1;
	}
	return top->key;
}

int stack::size(){
	return this->size_t;
}
///////////////////////////////////////////////////////////
class setofstack{
	private:
		int max_index = -1;
		vector<stack *> sofStack;
		int thresold = 4;
		vector<stack>::iterator it;
	public:
		void push(int);
		int pop();
		int popAt(int);
};





void setofstack::push(int key){
	cout << "push " << key << endl;
	if(max_index < 0){
		stack *temp_stack = new stack;
		max_index++;
		sofStack.push_back(temp_stack);
		temp_stack->push(key);
		cout << "stack Number " << max_index << endl;
	}
	else{
		stack *stack_ptr = sofStack[max_index];
		// cout << "stack size " << stack_ptr->size() << endl;
		if(!stack_ptr->top){
			stack_ptr->push(key);
		}
		else if(stack_ptr->size() == thresold){
			stack *temp_stack = new stack;
			max_index++;
			sofStack.push_back(temp_stack);
			temp_stack->push(key);
			cout << "stack Number " << max_index << endl;
		}else{
			stack_ptr->push(key);
		}
	}
}

int setofstack::pop(){
	int ret = -1;
	if(max_index < 0){
		cout <<"stack is empty" << endl;
		return ret;
	}
	stack *stack_ptr = sofStack[max_index];
	if(stack_ptr->size() == 0 && max_index == 0)
		cout <<"stack is empty" << endl;
	else if(stack_ptr->size() == 0){
	sofStack.pop_back();
	max_index --;
	stack_ptr = sofStack[max_index];
	ret = this->pop();
	}
	else{
		ret = stack_ptr->pop();
	}
	return ret;
}

int setofstack::popAt(int index){
	cout << "pop At " << index << max_index << endl;
	int ret = -1;
	if(index > max_index)
		return -1;
	stack *stack_ptr = sofStack[index];
	if(stack_ptr->size() == 0){
	cout <<"stack is empty" << endl;
	}
	else{
		ret = stack_ptr->pop();
	}
		return ret;
}


int main(){
	setofstack stack_object;
	
	// cout << stack_object.size() << endl;
	cout << stack_object.pop() << endl;
	// cout << stack_object.peep() << endl;
	stack_object.push(11);
	// cout << stack_object.peep() << endl;
	stack_object.push(22);
	stack_object.push(33);
	stack_object.push(44);
	stack_object.push(55);
	stack_object.push(66);
	stack_object.push(77);
	stack_object.push(88);
	stack_object.push(99);
	stack_object.push(111);
	stack_object.push(222);
	stack_object.push(333);
	stack_object.push(444);
	cout << stack_object.popAt(3) << endl;
	cout << stack_object.pop() << endl;
	cout << stack_object.pop() << endl;

	return 0;
}
