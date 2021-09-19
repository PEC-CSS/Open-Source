#include <iostream>
using namespace std;

int calculateWays(int x , int& ways){
    if(x==0){
        return ways++;
    }else{
        if(x>=1){
            calculateWays(x-1,ways);
        }
        if(x>=2){
            calculateWays(x-2,ways);
        }
        if(x>=3){
            calculateWays(x-3,ways);
        }
    }
    return ways;   
}   

//assuming input can be any positive integer , ways caluclation has been bifurcated into 3 parts, if input is assumed to be greater than 3 always, u can just do it with one single statement calculateways(n-1)+calculateways(n-2)+calculatewaus(n-3)


int main(){
    int n;
    cin>>n;
    int W=0;
    cout<<calculateWays(n,W);
}
