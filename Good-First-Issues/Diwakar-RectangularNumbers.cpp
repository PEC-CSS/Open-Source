#include<iostream>

int main(){
    int n;std::cin>>n;
    int size = n+n-1;
    int a[size][size];
  //start and end of the array are used in the loop 
    int start=0,end=size-1;
  
  //loop runs untill n becomes 1
    while(n!=0){
        for(int i=start;i<=end;i++){
            for(int j=start;j<=end;j++){
              //ring pattern condition
                if(i==start || j==start
                || i==end ||j==end){
                    a[i][j]=n;
                }
            }
        }
        start++;
        end--;
        n--;
    }

 //to print the pattern stored in the array
    for(int i=0;i<size;i++ ){
        for(int j=0;j<size;j++ ){
            std::cout<<a[i][j];
        }
        std::cout<<"\n";
    }

    return 0;
}
