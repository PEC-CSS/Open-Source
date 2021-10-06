#include<bits/stdc++.h>

using namespace std;
/*
 Time Complexity  O(N*W)
 Space Complexity O(N*W) 
*/
int knapSack(int i,int w,int wt[],int val[],int n,int dp[][10000]){
  if(w==0)
     return 0; //If the knapsack weight becomes zero
  if(i>=n)     
      return 0; //If we go out of bounds
  if(dp[i][w]!=-1)
     return dp[i][w];//Returning the saved value
  if(wt[i]<=w){
      int take=val[i]+knapSack(i+1,w-val[i],wt,val,n,dp);//In this call we are adding the current weight to knapsack
      int notake=knapSack(i+1,w,wt,val,n,dp);//In this we are  skipping the current weight
      return dp[i][w]=max(take,notake);//taking max as we want the maximum of both of them
  }else{
      return dp[i][w]=knapSack(i+1,w,wt,val,n,dp);//In this the current weight is more than knapsacks weight
  }   
}


int main(){
    int n,w;
    //Input of  required and  no of weights
    cin>>n>>w;
    int val[n],wt[n];
    int dp[n][w];
    memset(dp,-1,sizeof dp);//Intializing the dp with -1;
    //Input of values
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    //Input of respective weights of the values
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    cout<<knapSack(0,w,wt,val,n,dp);
}