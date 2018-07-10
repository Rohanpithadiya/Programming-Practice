#include<iostream>

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
	node * top;
	node * create_node(int);
public:
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
	size_t ++;
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

int main(){
	stack stack_object;
	
	cout << stack_object.size() << endl;
	cout << stack_object.pop() << endl;
	cout << stack_object.peep() << endl;
	stack_object.push(11);
	cout << stack_object.peep() << endl;
	stack_object.push(22);
	stack_object.push(33);
	stack_object.push(44);
	cout << stack_object.peep() << endl;
	cout << stack_object.size() << endl;
	cout << stack_object.pop() << endl;
	cout << stack_object.peep() << endl;
	cout << stack_object.size() << endl;
	cout << stack_object.pop() << endl;
	cout << stack_object.pop() << endl;
	cout << stack_object.pop() << endl;
	cout << stack_object.pop() << endl;
	cout << stack_object.pop() << endl;

	return 0;
}
