#include<iostream>

using namespace std;

struct Node {
	int key;
	struct Node *next;
};

typedef struct Node node;
class queue{
private:
	node * front;
	node * back;
	int size_t;
	node * create_node(int);
public:
	queue();
	void push(int);
	int pop();
	int peep();
	int size();
	void print_queue();
};

queue::queue(){
	front = nullptr;
	back = nullptr;
	size_t = 0;
}

node * queue::create_node(int key){
	node * new_node = new node;
	new_node->key = key;
	new_node->next = nullptr;
	return new_node;
}

void queue::push(int key){
	node* new_node = create_node(key);
	if(!back){
		front = new_node;
		back = new_node;
		size_t++;
	}else{
		back->next = new_node;
		back = back->next;
		size_t++;
	}
}

int queue::pop(){
	if(!front){
	cout << "empty queue !" << endl;
	return -1;
}
	int key = front->key;
	node * temp_node = front;
	front = front->next;
	delete temp_node;
	size_t--;
	return key;
}

void queue::print_queue(){
	node * trav = front;
	while(trav){
		cout << trav->key << "->";
		trav = trav->next;
	}
	cout << endl;
}

int queue::peep(){
	if(!front){
	cout << "empty queue !" << endl;
	return -1;
}
return front->key;
}

int queue::size(){
	return size_t;
}

int main(){
	queue queue_object;
	cout << queue_object. size() << endl;
	cout << queue_object. pop() << endl;
	queue_object. push(11);
	cout << queue_object. peep() << endl;
	queue_object. push(12);
	queue_object. push(13);
	queue_object. push(14);
	queue_object. push(15);
	cout << queue_object. size() << endl;
	cout << queue_object. peep() << endl;
	queue_object.print_queue();
	cout << queue_object. pop() << endl;
	cout << queue_object. size() << endl;
	cout << queue_object. peep() << endl;
	cout << queue_object. pop() << endl;
	cout << queue_object. size() << endl;
	cout << queue_object. peep() << endl;
	cout << queue_object. pop() << endl;
	cout << queue_object. peep() << endl;
	cout << queue_object. pop() << endl;
	cout << queue_object. peep() << endl;
	cout << queue_object. pop() << endl;
	cout << queue_object. peep() << endl;
	cout << queue_object. pop() << endl;
	cout << queue_object. peep() << endl;
	cout << queue_object. pop() << endl;
	cout << queue_object. peep() << endl;

	return 0;
}
