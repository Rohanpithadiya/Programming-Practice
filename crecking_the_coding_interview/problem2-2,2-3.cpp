// problem 2.2
// Implement an algorithm to find the kth to last element of a singly linked list.

// problem 2.3
// Implement an algorithm to delete a node in the middle of a singly linked list,
// given only access to that node.
// EXAMPLE
// Input: the node c from the linked list a - > b - > c - > d - > e
// Result: nothing is returned, but the new linked list looks like a- >b- >d->

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
	new_node->next = NULL;
	return new_node;
}

node * insert(node *head, int value){
	node * intrim_node = create_node(value);
	if (head == NULL){
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


node * getkthnode(node* head, int k){
	// return h;
	node *first = head;
	node *second = head;
	// cout << "here" << endl;
	while(k--){
		if(second->next){
			second = second->next;
		}
		else{
			cout << "k is larger than LL" << endl;
			return nullptr;
		}
	}
	while(second->next){
		second = second->next;
		first = first->next;
	}
	return first;
}


node * delete_middle(node* ptr){
	ptr->key = ptr->next->key;
	node *temp = ptr->next;
	ptr->next = ptr->next->next;
	delete temp;
}

int main(){
	int k = 2;
	node * head;
	node * kthnode = nullptr;
	head = insert(head,1);
	head = insert(head,2);
	head = insert(head,3);
	head = insert(head,4);
	head = insert(head,5);
	head = insert(head,6);
	head = insert(head,7);
	printll(head);
	kthnode = getkthnode(head,k);
	if(kthnode){
		cout << kthnode->key << endl;
	}
	delete_middle(kthnode);
	printll(head);
	return 0;
}