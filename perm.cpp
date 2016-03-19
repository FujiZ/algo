#include<iostream>

using namespace std;

int *list=NULL;
int total=0;

void perm(int k,int m){
	if(k>m){
		for(int i=0;i<=m;++i)
			cout<<list[i]<<' ';
		cout<<endl;
		++total;
	}
	else{
		for(int i=k;i<=m;++i){
			swap(list[k],list[i]);
			perm(k+1,m);
			swap(list[k],list[i]);
		}
	}
}

int main(void){
	int n;
	cin>>n;
	list=new int[n];
	for(int i=0;i<n;++i)
		list[i]=i;
	perm(0,n-1);
	cout<<"Total: "<<total<<endl;
	return 0;
}
