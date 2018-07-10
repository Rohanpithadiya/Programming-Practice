// problem 3.2
// How would you design a stack which, in addition to push and pop, also has a
// function min which returns the minimum element? Push, pop and min should
// all operate in O(1) time.
// 19 min

#include<iostream>

using namespace std;

struct Node {
	int key;
	int min;
	struct Node* next;
	struct Node* prev;
};

typedef Node node;

class stack{
	private:
		node* top;
	public:
		stack();
		void push(int);
		int pop();
		int min();
};

stack::stack(){
	top = nullptr;
}
node * create_node(int key){
	node * new_node = new node;
	new_node->key = key;
	new_node->min = key;
	new_node->next = nullptr;
	new_node->prev = nullptr;
	return new_node;
}

void stack::push(int key){
	node * new_node = create_node(key);
	if(!top){
		top = new_node;
	}
	top->next = new_node;
	new_node->prev = top;
	if(top->min < new_node->key){
		new_node->min = top->min;
	}
	top = new_node;
}

int stack::pop(){
	if(!top){
		cout << "empty stack !" << endl;
		return -1;
	}
	int key = top->key;
	node * temp = top;
	top = top->prev;
	delete temp;
	return key;
}

int stack::min(){
	if(!top){
		cout << "empty stack !"<< endl;
		return -1;
	}
	return (top->min);
}

int main(){

	stack s1;
	cout << s1.min() << endl;
	cout << s1.pop() << endl;

	s1.push(8);
	cout << s1.min() << endl;
	s1.push(10);
	cout << s1.min() << endl;
	s1.push(5);
	cout << s1.min() << endl;
	s1.push(6);
	cout << s1.min() << endl;
	s1.push(9);
	cout << s1.min() << endl;
	s1.push(2);
	cout << s1.min() << endl;
	s1.push(1);
	cout << s1.min() << endl;
	s1.push(21);
	cout << s1.min() << endl;

	cout << s1.pop() << endl;
	cout << s1.pop() << endl;
	cout << s1.min() << endl;

	return 0;	
}