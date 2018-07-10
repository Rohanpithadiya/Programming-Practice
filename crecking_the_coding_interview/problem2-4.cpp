// problem 2.4
// Write code to partition a linked list around a value x, such that all nodes less than
// x come before all nodes greater than or equal to x.

#include <iostream>

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


node * dividebyx(node *list, int x){
	node * smallerlist = nullptr;
	node * largerlist = nullptr;
	node * newnode = nullptr;
	node * trav = nullptr;

	// cout << list->next->key << endl;

	while(list){
		newnode = list;
		list = list->next;
		newnode->next = nullptr;
		// cout << newnode->key << endl;
		if(newnode->key < x){
			if(!smallerlist){
				smallerlist = newnode;
			}
			else{
				newnode->next = smallerlist;
				smallerlist = newnode;
			}
		}else{
			if(largerlist){
				newnode->next = largerlist;
			}
			largerlist = newnode;
		}
	}
	if(!smallerlist){
		return largerlist;
	}else{
		trav = smallerlist;
		while(trav->next){
			trav = trav->next;
		}
		trav->next = largerlist;
		return smallerlist;
	}
}



int main(){
	int x =40;
	node * head = nullptr;
	node * newlist = nullptr;
	head = insert(head,78);
	head = insert(head,26);
	head = insert(head,35);
	head = insert(head,42);
	head = insert(head,36);
	head = insert(head,21);
	head = insert(head,41);
	printll(head);
	newlist = dividebyx(head,x);
	printll(newlist);
	return 0;
}