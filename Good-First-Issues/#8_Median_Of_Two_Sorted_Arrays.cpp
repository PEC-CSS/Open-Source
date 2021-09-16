#include<bits/stdc++.h>
using namespace std;
double MedianOfSortedArrays(int a[],int m, int b[], int n){
    if (m<n){
          return MedianOfSortedArrays(b,n,a,m);
        }
    int start=0;
    int end=n;
    while (start<=end){
        int midb= (start+end)/2;
        int mida= (m+n+1)/2 - midb;
        int aLeftMax=(mida==0)?INT_MIN:a[mida-1];
        int aRightMin=(mida==m)?INT_MAX:a[mida];
        int bLeftMax=(midb==0)?INT_MIN:b[midb-1];
        int bRightMin=(midb==n)?INT_MAX:b[midb];
        if ((aLeftMax<=bRightMin) && (bLeftMax<=aRightMin)){
            if ((m+n)&1){
                return max(aLeftMax,bLeftMax);
            }
            else{
                return (max(aLeftMax,bLeftMax)+ min(aRightMin,bRightMin))/2.0;
            }
        }
        else if (aLeftMax>bRightMin){
            start=midb+1;
        }
        else{
            end=midb-1;
        }

    }
    return 0;

}
int main(){
    int m,n;
    cin>>m;
    int a[m];
    for (int i=0;i<m;i++){
        cin>>a[i];
    }
    cin>>n;
    int b[n];
    for (int i=0;i<n;i++){
        cin>>b[i];
    }
    cout<<MedianOfSortedArrays(a,m,b,n);
}
