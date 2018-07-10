// problem 2.5
// Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is, 617 + 295.
// Output: 2 -> 1 -> 9.That is, 912

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

node * insert_node(node* slist, int digit){
	node * newnode = create_node(digit);
	node * list = slist;
	if(!slist)
		return newnode;
	else{
		while(slist->next){slist=slist->next;}
		slist->next = newnode;
	}
	return list;
}

node* sumlist(node * l1, node * l2){
	int l1_digit, l2_digit, sum, digit;
	int reminder = 0;
	node * slist = nullptr;

	while(l1 || l2){
		if(!l1){
			l1_digit = 0;
		}else{
			l1_digit = l1->key;
			l1 = l1->next;
		}
		if(!l2){
			l2_digit = 0;
		}else{
			l2_digit = l2->key;
			l2 = l2->next;
		}

		sum = l1_digit + l2_digit +reminder;
		digit = sum % 10;
		reminder = sum / 10;
		slist = insert_node(slist,digit);
	}
	if(reminder){
		slist = insert_node(slist,reminder);
	}
	return slist;
}



// node* rec_sumlist(node * l1, node * l2){
// 	int l1_digit, l2_digit, sum, digit;
// 	int reminder = 0;
// 	node * slist = nullptr;

// 	if(l1 || l2) {return};
// 	rec_sumlist(l1->next,l2->next)
// 	while(l1 || l2){
// 		if(!l1){
// 			l1_digit = 0;
// 		}else{
// 			l1_digit = l1->key;
// 			l1 = l1->next;
// 		}
// 		if(!l2){
// 			l2_digit = 0;
// 		}else{
// 			l2_digit = l2->key;
// 			l2 = l2->next;
// 		}

// 		sum = l1_digit + l2_digit +reminder;
// 		digit = sum % 10;
// 		reminder = sum / 10;
// 		// cout << l1_digit << ", "<< l2_digit <<", "<< sum <<", "<< reminder <<", "<< digit << endl;
// 		slist = insert_node(slist,digit);
// 		// printll(slist);
// 	}
// 	if(reminder){
// 		slist = insert_node(slist,reminder);
// 	}
// 	return slist;
// }


int main(){
	int x =40;
	node * list1 = nullptr;
	node * list2 = nullptr;
	node * newlist = nullptr;
	node * reclist = nullptr;
	list1 = insert(list1,6);
	list1 = insert(list1,1);
	list1 = insert(list1,7);
	list2 = insert(list2,2);
	list2 = insert(list2,9);
	list2 = insert(list2,5);
	list2 = insert(list2,9);
	list2 = insert(list2,9);
	head = insert(head,41);
	printll(list1);
	printll(list2);
	newlist = sumlist(list1,list2);
	printll(newlist);
	// reclist = sumlist(list1,list2);
	// printll(reclist);
	return 0;
}