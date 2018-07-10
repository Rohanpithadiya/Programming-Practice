// problem 2.6
// Given a circular linked list, implement an algorithm which returns the node at
// the beginning of the loop.
// DEFINITION
// Circular linked list: A (corrupt) linked list in which a node's next pointer points
// to an earlier node, so as to make a loop in the linked list.
// EXAMPLE
// Input: A - > B - > C - > D - > E - > C [the same C as earlier]
// Output:C



#include<iostream>

using namespace std;

struct Node {
	int key;
	struct Node *next;
};

typedef struct Node node;


node * create_node(int value){
	node * new_node =  new node;
	new_node->key = value;
	new_node->next = nullptr;
	return new_node;
}

node * insert(node *head, int value){
	node * intrim_node = create_node(value);
	if (head == nullptr){
		head = intrim_node;
	}
	else{
		node* trav = head;
		while(trav->next){
			trav = trav->next;
		}
		trav->next = intrim_node;
	}
	return head;
}

void printll(node* head){
	node * trav = head;
	while(trav){
		cout << trav->key << ", ";
		trav = trav->next;
	}
	cout << endl;
}


int findloophead(node * head){

	if(!head)
		return -1;

	node * slow = head;
	node * fast = head;

	do{
		if(fast->next == nullptr || fast->next->next == nullptr){
			return -1;
		}
		slow = slow->next;
		fast = fast->next->next;
	}while(slow != fast);

	cout << "meeting point " << slow->key <<endl;
	slow = head;
	while(slow != fast){
		slow = slow->next;
		fast = fast->next;
	}
	return slow->key;
}

void set_loop(node* head, int x){
	node * last = head;
	node * xnode = head;
	while(last->next){
		if(x == last->key){xnode = last;}
		last = last->next;
	}
	if(x == last->key){xnode = last;}
	last->next = xnode;
}
int main(){
	node * list = nullptr;

	list = insert(list,1);
	list = insert(list,2);
	list = insert(list,3);
	list = insert(list,4);
	list = insert(list,5);
	list = insert(list,6);
	list = insert(list,7);
	list = insert(list,8);
	list = insert(list,9);
	list = insert(list,10);
	list = insert(list,11);
	list = insert(list,12);
	printll(list);
	set_loop(list,12);
	cout <<"loop start: "<< findloophead(list);
	return (0);
}