#include<iostream>

int gcd(int m,int n){
	int r;
	do{
		r=m%n;
		m=n;
		n=r;
	}while(r);
	return m;
}

int main(void){
	std::cout<<gcd(30,18)<<std::endl;
	return 0;
}
