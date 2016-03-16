#include<iostream>
#include<climits>
const int MAX=100;

using namespace std;

int mat[MAX][MAX];

void floyd(int n){
	for(int k=0;k<n;++k)
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j){
				if(mat[i][k]==INT_MAX||mat[k][j]==INT_MAX)
					continue;
				if(mat[i][k]+mat[k][j]<mat[i][j])
					mat[i][j]=mat[i][k]+mat[k][j];
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
	for(int i=0;i<n;++i)
		mat[i][i]=0;
	floyd(n);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
