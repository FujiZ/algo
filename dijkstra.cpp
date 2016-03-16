#include<iostream>
#include<climits>

using namespace std;

const int MAX=100;

int dist[MAX];
int prev[MAX];
int mat[MAX][MAX];

void dijkstra(int n,int v0){
	bool *S=new bool[n]();	//S集合代表已经求出最短路径的点
	//初始化dist,prev
	for(int i=0;i<n;++i){
		dist[i]=mat[v0][i];
		if(dist[i]==INT_MAX)
			prev[i]=-1;
		else
			prev[i]=v0;
	}
	dist[v0]=0;
	S[v0]=true;
	for(int i=0;i<n;++i){	//对点进行迭代，每次都会把一个点加入S集合
		int minDist=INT_MAX;
		int u=-1;
		//找出未使用点dist的最小值
		for(int j=0;j<n;++j){
			if(!S[j]&&dist[j]<minDist){
				u=j;
				minDist=dist[j];
			}
		}
		if(u<0) break;//剩下的都是不联通的点
		S[u]=true;	//加入S集合
		//用u更新dist,prev
		for(int j=0;j<n;++j){
			if(!S[j]&&mat[u][j]<INT_MAX){
				if(dist[u]+mat[u][j]<dist[j]){
					dist[j]=dist[u]+mat[u][j];
					prev[j]=u;
				}
			}
		}
	}
	delete[] S;
}

void print(int n){
	for(int i=0;i<n;++i){
		cout<<dist[i]<<": "<<i;
		for(int p=prev[i];p>=0;p=prev[p]){
			cout<<"<-"<<p;
		}
		cout<<endl;
	}
}

int main(void){
	int n,m,v0;
	cin>>n>>m>>v0;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			mat[i][j]=INT_MAX;
	for(int i=0;i<m;++i){
		int a,b,l;
		cin>>a>>b>>l;
		mat[a][b]=l;
	}
	dijkstra(n,v0);
	print(n);
	return 0;
}
