#include<iostream>
#include<queue>
#include<string>
#include<sstream>

using namespace std;

struct Node{
	int value;
	int height;
	struct Node *parent;
	struct Node *left;
	struct Node *right;
};

typedef struct Node node;

enum Trav_Type{
	pre,in,post
}trav_type;

class AVL_tree{
private:
	node *root=NULL;
	void rec_insert(node *, node *);
	node * create_node(int);
	node * delete_node(node *, int);
	// node * rebalance(node *);
	void set_height(node *);
	void rebalance(node *);

public:
	void push(int);
	void pop(int);
	void find(int);
	void print();
	void travarsal(int);

};

node * AVL_tree::create_node(int value){
	node * temp_node = new node;
	temp_node->value = value;
	temp_node->height = 1;
	temp_node->parent = NULL;
	temp_node->left = NULL;
	temp_node->right = NULL;
	return temp_node;
}

int max(node *left, node *right){
	return ((left->height > right->height)?left->height:right->height);
}

void AVL_tree::set_height(node *root){
	if(!root)
		return;

	int left_height = 1;
	int right_height = 1;
	if(root->left)
		left_height = root->left->height;
	if (root->right)
		right_height = root->right->height;

	root->height = max(left_height, right_height) +1;
	this->set_height(root->parent);
}

void AVL_tree::rebalance(node *leaf){
	if(!root)
		return;
	
}

void AVL_tree::push(int value){
	node *temp_node = create_node(value);
	if (!root){
		root = temp_node;
		return;
	}
	node * trav = root;
	while(trav){
		if(trav->value > value){
			if(!trav->left){
				trav->left = temp_node;
				temp_node->parent = trav;
				break;
			}
			trav = trav->left;
		}else if(trav->value <= value){
			if(!trav->right){
				trav->right = temp_node;
				temp_node->parent = trav;
				break;
			}
			trav = trav->right;
		}
	}
	this->set_height(trav);
	// this->rebalance(trav);
}

void AVL_tree::pop(int value){

}

void AVL_tree::find(int value){
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


void AVL_tree::print(){
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

		cout << temp_node->value << "(" << temp_node->height << ")" << ", ";
		loQueue.pop();
	}	
	cout << endl;
}


void preoder_trav(node *root){
	if(!root)
		return;
	cout << root->value << ", ";
	preoder_trav(root->left);
	preoder_trav(root->right);
}

void inorder_trav(node *root){
	if (!root)
		return;
	inorder_trav(root->left);
	cout << root->value << ", ";
	inorder_trav(root->right);
}
void postorder_trav(node * root){
	if(!root)
		return;
	postorder_trav(root->left);
	postorder_trav(root->right);
	cout << root->value << ", ";
}

void AVL_tree::travarsal(int choice){
	switch(choice){
		case pre:
			preoder_trav(root);
		break;
		case in:
			inorder_trav(root);
		break;
		case post:
			postorder_trav(root);
		break;
		default:
			cout << "not a valid choice, use <pre, in, post>";
		
	}
	cout << endl;
}

int main(){
	AVL_tree myTree;

	myTree.push(1);
	myTree.push(2);
	myTree.push(3);
	myTree.push(4);
	myTree.push(5);
	myTree.push(6);
	myTree.push(7);

	myTree.print();

	return 0;
}