#include<iostream>
#include<queue>
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
void bfs(Node<T>* root, void (*visit)(Node<T>*)){
	queue<Node<T>*> nodeQueue;
	nodeQueue.push(root);
	while(!nodeQueue.empty()){
		Node<int>* current=nodeQueue.front();
		nodeQueue.pop();
		if(!current->visited){
			if(current->left&&!current->left->visited)
				nodeQueue.push(current->left);
			if(current->right&&!current->right->visited)
				nodeQueue.push(current->right);
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
	bfs(root,visit);
	return 0;
}
