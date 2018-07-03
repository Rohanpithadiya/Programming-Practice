#include<iostream>
#include<queue>
#include<string>
#include<sstream>

using namespace std;

struct Node{
	int value;
	struct Node *left;
	struct Node *right;
};

typedef struct Node node;

class BSTree{
private:
	node *root=NULL;
	int size_t;
	void rec_insert(node*,node*);
	node * create_node(int);
	node * delete_node(node*,int);

public:
	BSTree();
	void push(int);
	void pop(int);
	void find(int);
	int size();
	void print();

};
BSTree::BSTree(){
	root = NULL;
	size_t = 0;
}

node * BSTree::create_node(int value){
	node *temp_node = new node;
	temp_node->value = value;
	temp_node->left = NULL;
	temp_node->right = NULL;
	return temp_node;
}

void BSTree::rec_insert(node *root, node *intrim_node){
	if(root->value > intrim_node->value){
		if(root->left){
			this->rec_insert(root->left, intrim_node);		
		}
		else{
			root->left = intrim_node;
		}
	}
	else{
		if(root->right){
			this->rec_insert(root->right, intrim_node);
		}
		else{
			root->right = intrim_node;
		}

	}

}

void BSTree::push(int value){
	node * intrim_node = this->create_node(value);
	size_t ++;
	if(!root){
		root = intrim_node;
		return;
	}

	this->rec_insert(root,intrim_node);
}
node * inoder_successor(node * root)
{
	node *trav = root;
	while (trav->left != NULL){
		trav = trav->left;
	}
	return trav;
}
node* BSTree::delete_node(node* head,int value){
	if (!head){
		return head;
	}
	if (head->value > value){
		head->left = delete_node(head->left,value);
	}
	else if(head->value < value){
		head->right = delete_node(head->right,value);
	}
	else{
		if (head->left == NULL){
			node *temp = head->right;
			delete(head);
			size_t --;
			return head->right;
		}
		else if(head->right == NULL){
			node *temp = head->left;
			delete(head);
			size_t --;
			return head->left;	
		}
		else{
				node * ino_succ = inoder_successor(head->right);
				head->value = ino_succ->value;
				head->right = delete_node(head->right,ino_succ->value);	
		}
	}
	return head;
}

void BSTree::pop(int value){
	if (!root){
		cout << "element not found" << endl;
		return;
	}
	root = delete_node(root,value);
}

void BSTree::find(int value){
	node *trav = root;
	string path_str = "path: ";
	while(trav){
		ostringstream temp_str;
		temp_str << trav->value;
		path_str += temp_str.str() + "->";
		if (trav->value == value){
			cout << "found element " << value << endl << path_str << endl;
			return;
		}
		else if (trav->value > value){
			trav = trav->left;
		}
		else{
			trav = trav->right;
		}
	}
	cout << "Not able to find element " << value << endl;
}

void BSTree::print(){
	if(!root){
		cout << "Tree is empty !" << endl;
		return;
	}
	
	node *trav = root;
	queue<node *> loQueue;

	loQueue.push(root);
	while(!loQueue.empty()){
		node *temp_node = loQueue.front();
		if(temp_node->left)
			loQueue.push(temp_node->left);
		if(temp_node->right)
			loQueue.push(temp_node->right);

		cout << temp_node->value << ", ";
		loQueue.pop();
	}	
	cout << endl;
}

int BSTree::size(){return size_t;}

int main()
{
	BSTree myBSTree;

	myBSTree.push(5);
	myBSTree.push(3);
	myBSTree.push(1);
	myBSTree.push(4);
	myBSTree.push(8);
	myBSTree.push(6);
	myBSTree.push(9);
	myBSTree.push(2);
	cout << myBSTree.size() << endl;
	myBSTree.print();

	myBSTree.find(2);
	myBSTree.find(7);

	myBSTree.pop(5);
	cout << myBSTree.size() << endl;
	myBSTree.print();

	return 0;
}