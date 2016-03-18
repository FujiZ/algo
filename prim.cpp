#include<iostream>
#include<climits>

using namespace std;

const int MAX=100;

int mat[MAX][MAX];

void print(int n,int* closevertex){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	for(int i=0;i<n;++i)
		cout<<i<<','<<closevertex[i]<<':'<<mat[i][closevertex[i]]<<endl;
}

void prim(int n){
	bool *S=new bool[n]();	//S集合代表在当前生成树中的点
	int *lowcost=new int[n];	//S集合到顶点的最小cost
	int *closevertex=new int[n]();	//与顶点最近的S集合中的节点
	S[0]=true;
	for(int i=1;i<n;++i)
		lowcost[i]=mat[0][i];

	for(int i=1;i<n;++i){	//对点进行迭代，每次都会把一个点加入S集合
		int minDist=INT_MAX;
		int u=-1;
		//找出未使用点cost的最小值
		for(int j=0;j<n;++j){
			if(!S[j]&&S[closevertex[j]]&&lowcost[j]<minDist){
				u=j;
				minDist=lowcost[j];
			}
		}
		if(u<0) break;//剩下的都是不联通的点
		S[u]=true;	//加入S集合
		lowcost[u]=0;
		for(int j=0;j<n;++j){
			if(mat[u][j]<lowcost[j]){
				lowcost[j]=mat[u][j];
				closevertex[j]=u;
			}
		}
	}
	print(n,closevertex);
	delete[] S;
	delete[] lowcost;
	delete[] closevertex;
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
		mat[a][b]=mat[b][a]=l;
	}
	for(int i=0;i<n;++i)
		mat[i][i]=0;
	prim(n);
	return 0;
}
