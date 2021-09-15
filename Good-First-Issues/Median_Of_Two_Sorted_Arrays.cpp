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
        int aleftmax=(mida==0)?INT_MIN:a[mida-1];
        int arightmin=(mida==m)?INT_MAX:a[mida];
        int bleftmax=(midb==0)?INT_MIN:b[midb-1];
        int brightmin=(midb==n)?INT_MAX:b[midb];
        if ((aleftmax<=brightmin) && (bleftmax<=arightmin)){
            if ((m+n)&1){
                return max(aleftmax,bleftmax);
            }
            else{
                return (max(aleftmax,bleftmax)+ min(arightmin,brightmin))/2.0;
            }
        }
        else if (aleftmax>brightmin){
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
