#include<iostream>
#include<cstring>

using namespace std;

void sieve(int n){
	bool* a=new bool[n];
	memset(a,true,n*sizeof(bool));
	for(int i=2;i*i<n;++i){
		if(a[i]){
			for(int j=2;i*j<n;++j)
				a[i*j]=false;
		}
	}
	for(int i=2;i<n;++i){
		if(a[i]) cout<<i<<endl;
	}
	delete[] a;
	
}

int main(void){
	sieve(100);
	return 0;
}
