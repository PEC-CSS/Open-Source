#include<bits/stdc++.h>

using namespace std;
int kadanes(int array[],int length) {

   int max_temp=INT_MIN;
   int highestMax = 0;
   int currentElementMax = INT_MIN;

   for(int i = 0; i < length; i++){


     highestMax=max(highestMax+array[i],0);
     max_temp=max(highestMax,max_temp);
     currentElementMax=max(currentElementMax,array[i]);

      if(max_temp==0){
         max_temp=currentElementMax;
      }
   }


   return max_temp;
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
