#include<iostream>
#include<climits>
#include<stack>

using namespace std;

const int MAX=100;

int mat[MAX][MAX];

void visit(int index){
	cout<<index<<endl;
}

void topo(int n){
	stack<int> nodeStack;
	int *indegree=new int[n]();
	//初始化入度
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(mat[i][j]<INT_MAX)
				++indegree[j];
	//将入度为0的节点入栈
	for(int i=0;i<n;++i)
		if(indegree[i]==0)
			nodeStack.push(i);
	while(!nodeStack.empty()){
		int node=nodeStack.top();
		visit(node);
		nodeStack.pop();
		for(int i=0;i<n;++i)
			if(mat[node][i]<INT_MAX){
				if(--indegree[i]==0)
					nodeStack.push(i);
			}
	}
}

int main(void){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			mat[i][j]=INT_MAX;
	for(int i=0;i<m;++i){
		int a,b,l;
		cin>>a>>b>>l;
		mat[a][b]=l;
	}
	topo(n);
	return 0;
}
