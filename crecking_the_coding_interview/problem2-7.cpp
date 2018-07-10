// problem 2.7
// Implement a function to check if a linked list is a palindrome.
// 11 min



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

node * reverseList(node* head){
	node * rev = nullptr;
	node * trav = head;

	while(trav){
		node * temp = create_node(trav->key);
		if(!rev){
			rev = temp;
		}
		else{
			temp->next = rev;
			rev = temp;
		}
		trav = trav->next;
	}
	return rev;
}

bool is_palindrom(node * head){
	bool result = false;

	node * trav = head;
	node * rev = reverseList(head);

	while(rev && trav){
		if(rev->key != trav->key){
			break;
		}
		rev = rev->next;
		trav = trav->next;
	}
	if(rev == nullptr && trav == nullptr)
		result = true;
	return result;
}

int main()
{
	node* mylist;

	mylist = insert(mylist,11);
	mylist = insert(mylist,21);
	mylist = insert(mylist,12);
	mylist = insert(mylist,22);
	mylist = insert(mylist,22);
	mylist = insert(mylist,12);
	mylist = insert(mylist,21);
	mylist = insert(mylist,11);


	printf("%s",is_palindrom(mylist)?"palindrome":"Not a palindrome");

	return 0;
}