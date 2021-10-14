#include<bits/stdc++.h>
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int column){
    
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
  int** storage = new int*[row];
  for(int i = 0; i<row; i++)
    storage[i] = new int[column];
  
  for(int i = 0; i<row; i++)
      storage[i][0] = arr[i][0];
 
  
  for(int i = 0; i<column; i++)
      storage[0][i] = arr[0][i];
 
  
  int j, max = INT_MIN;
  
  for(int i = 1; i<row; i++)
  {
      for(j = 1; j<column; j++)
      { if(arr[i][j] == 0)
           storage[i][j] = 1 +  min(storage[i-1][j-1],min(storage[i-1][j],storage[i][j-1]));
       else
          storage[i][j] = 0;
      }
     
  }
  
  int max_of_s = storage[0][0]; int max_i = 0; int max_j = 0;
  for(int i = 0; i < row; i++)
  {
    for(j = 0; j < column; j++)
    {
      if(max_of_s < storage[i][j])
      {
         max_of_s = storage[i][j];
         max_i = i; 
         max_j = j;
      }        
    }             
  }
  return max_of_s;
    
}
