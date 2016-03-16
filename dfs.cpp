#include<iostream>
#include<queue>
#include<stack>
using namespace std;

template<typename T>
struct Node{
	Node(const T& val);
	T val;
	Node<T>* left;
	Node<T>* right;
	bool visited;
};

template<typename T>
Node<T>::Node(const T& val){
	this->val=val;
	this->left=NULL;
	this->right=NULL;
	this->visited=false;
}

Node<int>* init(int n){
	Node<int>* root=new Node<int>(0);
	queue<Node<int>*> nodeQueue;
	nodeQueue.push(root);
	for(int i=1;i<n;++i){
		Node<int>* pNode=new Node<int>(i);
		Node<int>* parent=nodeQueue.front();
		if(!parent->left)
			parent->left=pNode;
		else{
			parent->right=pNode;
			nodeQueue.pop();
		}
		nodeQueue.push(pNode);
	}
	return root;
}

template<typename T>
void dfs(Node<T>* root, void (*visit)(Node<T>*)){
	stack<Node<T>*> nodeStack;
	nodeStack.push(root);
	while(!nodeStack.empty()){
		Node<int>* current=nodeStack.top();
		nodeStack.pop();
		if(!current->visited){
			if(current->right&&!current->right->visited)
				nodeStack.push(current->right);
			if(current->left&&!current->left->visited)
				nodeStack.push(current->left);
			visit(current);
			current->visited=true;
		}
	}
}

void visit(Node<int>* node){
	cout<<node->val<<endl;
}

int main(void){
	int n=10;
	Node<int>* root=init(n);
	dfs(root,visit);
	return 0;
}
