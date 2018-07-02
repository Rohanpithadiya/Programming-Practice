#include<iostream>

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
	cout << "done creating" << endl;
	size_t ++;
	if(!root){
		root = intrim_node;
		return;
	}

	this->rec_insert(root,intrim_node);
}

void BSTree::pop(int value){}

void BSTree::find(int value){}

void BSTree::print(){

}

int BSTree::size(){return size_t;}

int main()
{
	BSTree myBSTree;

	myBSTree.push(3);
	myBSTree.push(2);
	myBSTree.push(1);
	myBSTree.push(4);
	myBSTree.push(6);
	cout << myBSTree.size() << endl;
	myBSTree.print();

	myBSTree.find(5);
	myBSTree.find(6);

	myBSTree.pop(3);
	myBSTree.pop(3);
	cout << myBSTree.size() << endl;
	myBSTree.print();

	return 0;
}