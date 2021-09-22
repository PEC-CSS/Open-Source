#include<bits/stdc++.h>
using namespace std;
void swap(int a[], int idx1, int idx2){
	int temp=a[idx1];
	a[idx1]=a[idx2];
	a[idx2]=temp;
}

void rearrage(int arr[], int n){

	int ptr1=0;
	int ptr2=0;
	for(ptr1;ptr1<n;ptr1++){
		if(arr[ptr1]!=0 && arr[ptr2]==0){
			swap(arr,ptr1,ptr2);
		}

		if (arr[ptr2]!=0){
			ptr2++;
		}	
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int main()
{	cout<<"enter no. of elements"<<endl;
	int n;cin>>n;

	int arr[n]{0};
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"resultant array: ";
	rearrage(arr,11);
    cout<<endl;
    return 0;
}