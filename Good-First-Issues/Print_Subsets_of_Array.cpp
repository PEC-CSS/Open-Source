#include<iostream>
#include<math.h>
using namespace std;



void PrintAllSubsets(int *arr, int n){    
    int snum = 0;
    while(snum<pow(2,n)){
        for(int i=0;i<n;++i){
            if((snum&(1<<i))!=0){
                cout<<arr[i]<<' ';
            }
        }
        cout<<endl;
        ++snum;
    }
            
}
int main()
{
    int n;
	cin>>n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}


    PrintAllSubsets(arr,n);
	return 0; 
}  