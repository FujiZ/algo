#include<iostream>
using namespace std;

void quickSort(int A[],int left,int right){
	int i=left,j=right;
	int pivot=A[left];
	while(i<=j){
		while(A[i]<pivot)
			++i;
		while(A[j]>pivot)
			--j;
		if(i<=j){
			swap(A[i],A[j]);
			i++;
			j--;
		}
	}

	if(left<j)
		quickSort(A,left,j);
	if(i<right)
		quickSort(A,i,right);

}

int main(void){
	int n;
	cin>>n;
	int *A=new int[n];
	for(int i=0;i<n;++i)
		cin>>A[i];
	quickSort(A,0,n-1);
	for(int i=0;i<n;++i)
		cout<<A[i]<<' ';
	cout<<endl;
	delete[] A;
	return 0;
}
