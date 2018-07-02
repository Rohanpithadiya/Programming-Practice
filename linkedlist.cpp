// linkedList implementation

#include <iostream>

using namespace std;

struct node {
	int value;
	struct node *next;
};

typedef struct node Node;

class linkedList{

 	private:
 		struct node * head = NULL;
 		struct node * tail = NULL;
 		struct node * create_node(int);
 	public:

 		void insert(int);
 		void insert_reverse(int);
 		void del(int);
 		void find(int);
 		void at(int);
 		void sort();
 		void reverse();
 		void print();
 		// void ptr_print(struct node *);
 		void reverse_print();
 		int  size();
 		struct node * ptr_insert(int,struct node * );
};


struct node * linkedList::create_node(int value){
	struct node * new_node =  new node;
	new_node->value = value;
	new_node->next = NULL;
	return new_node;
}

void linkedList::insert(int value){
	struct node * intrim_node = create_node(value);
	if (head == NULL)
		head = tail = intrim_node;

	tail->next = intrim_node;
	tail = intrim_node;
}

struct node * linkedList::ptr_insert(int value, struct node * head){
	struct node * intrim_node = create_node(value);
	if (head == NULL)
		head = tail = intrim_node;

	tail->next = intrim_node;
	tail = intrim_node;
	return head;
}


void linkedList::print(){
	struct node *trav = head;
	while(trav!=NULL){
		cout << trav->value << " -> ";
		trav = trav->next;
	}
	cout << "NULL" << endl;
}

// void linkedList::ptr_print(struct node *head){
// 	struct node *trav = head;
// 	while(trav!=NULL){
// 		cout << trav->value << " -> ";
// 		trav = trav->next;
// 	}
// 	cout << "NULL" << endl;
// }


// todo: tail management reamining
void linkedList::del(int element){
	struct node *trav =  head;
	struct node *prev = trav;

	if(trav == NULL){
		cout << "linked list is empty";
		return;
	}
	if(trav->value == element){
		head = trav->next;
		delete trav;
	}
	else{
		trav = prev->next;
		while (trav){
			if(trav->value == element){
				prev->next = trav->next;
				delete trav;
			}
			prev = trav;
			trav=trav->next;
		}	
	}
	
}

void linkedList::find(int element){
	struct node *trav = head;
	int counter = 0;

	while(trav!=NULL){
		if (trav->value == element){
			cout << "found "<< element <<" at location "<< counter << endl;
			return;
		}
		trav = trav->next;
		counter++;
	}
	cout << "Not found element " << element << endl;
}

void linkedList::at(int location){
	struct node *trav = head;
	int counter = location;
	while(trav && counter){
		trav = trav->next;
		counter --;
	}
	if(counter == 0)
		cout << "at location "<< location <<" found element "<< trav->value << endl;
	else
		cout << "location out of range" << endl;
}

int  linkedList::size(){
	struct node *trav = head;
	int counter = 0;
	while(trav){
		counter ++;
		trav = trav->next;
	}
	cout << "size of Linked list " << counter << endl;
	return counter;
}

void linkedList::insert_reverse(int value){
	struct node * intrim_node = create_node(value);
	if(!head)
		head = tail = intrim_node;
	else{
		intrim_node->next = head;
		head = intrim_node;
	}

}

void linkedList::sort(){
	struct node *trav = head;
	struct node *sorted = NULL;
	int ll_size = this->size();

	for (int i=0; i< ll_size;i++){

		trav = head;
		int min = trav->value;
		for(int j=0; j <ll_size -i; j++){
			if (min > trav->value){
					min = trav->value;
			}
			trav = trav->next;
		}
		this->del(min);
		sorted = this->ptr_insert(min,sorted);
	}
	head = sorted;
}


void linkedList::reverse(){}

void rec_trav(struct node *trav){
	if(!trav){
		cout << "NULL -> ";
		return;
	}
	rec_trav(trav->next);
	cout << trav->value << " -> ";
}

void linkedList::reverse_print(){
	struct node *trav = head;
	rec_trav(trav);
	cout << "head" << endl;
}


int main()
{
	linkedList mylist;
	struct node* sorted_ll;

	mylist.size();
	
	mylist.insert(1);
	mylist.insert(2);
	mylist.insert(3);
	mylist.insert(4);
	mylist.insert(5);

	mylist.size();
	
	mylist.print();
	mylist.reverse_print();
	mylist.del(3);
	mylist.print();
	mylist.reverse_print();
	
	mylist.size();

	mylist.find(1);
	mylist.find(3);
	mylist.find(5);

	mylist.at(0);
	mylist.at(5);
	mylist.at(-7);
	mylist.at(7);

	linkedList my_revlist;
	my_revlist.size();
	my_revlist.insert_reverse(2);
	my_revlist.insert_reverse(4);
	my_revlist.insert_reverse(5);
	my_revlist.insert_reverse(1);
	my_revlist.insert_reverse(3);
	my_revlist.size();
	my_revlist.print();
	my_revlist.reverse_print();
	
	cout << "sorted Test" << endl;
	my_revlist.sort();
	my_revlist.print();
	return 0;
}
