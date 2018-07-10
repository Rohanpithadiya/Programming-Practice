// problem 2.1
// Write code to remove duplicates from an unsorted linked list.
// FOLLOW UP
// How would you solve this problem if a temporary buffer is not allowed?

#include<iostream>
#include<map>

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
node * remove_duplicate(node *head){
	map<int,int> hash_map;
	node *trav = head;
	node *prev = head;
	pair<map<int,int>::iterator,bool> ret;

	while(trav){
		ret = hash_map.insert(pair<int,int>(trav->key,1));
		if (!ret.second){
			if(trav == prev){
				node *temp = trav;
				head = trav->next;
				delete temp;
			}
			else{
				prev->next = trav->next;
				delete trav;
				trav = trav->next;
			}
		}
		else{
			prev = trav;
			trav = trav->next;
		}
	}
	return head;
}


int main(){

	node * head;
	head = insert(head,1);
	head = insert(head,1);
	head = insert(head,1);
	head = insert(head,1);
	head = insert(head,1);
	head = insert(head,1);
	head = insert(head,2);
	head = insert(head,3);
	head = insert(head,4);
	head = insert(head,3);
	head = insert(head,4);
	printll(head);
	head = remove_duplicate(head);

	printll(head);
	return 0;
}