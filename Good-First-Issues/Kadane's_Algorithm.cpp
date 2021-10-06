#include<iostream>
using namespace std;
int kadanes(int array[],int length) {
   int highestMax = 0;
   int currentElementMax = 0;
   for(int i = 0; i < length; i++){
      currentElementMax =max(array[i],currentElementMax + array[i]) ;
      highestMax = max(highestMax,currentElementMax);
   }
   return highestMax;
}


int main() {

   int n;
   cin >> n;
   int arr[n];
   
   for (int i = 0; i < n; i++) {
      cin >> arr[i];
   }
   cout <<kadanes(arr,n) << endl;
   return 0;
}