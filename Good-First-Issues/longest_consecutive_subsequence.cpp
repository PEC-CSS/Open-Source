#include <iostream>
#include <set>
using namespace std;

int findlongestconsqsubseq(int arr[], int n){
    set<int> st;
    int ans=0;
    //store elements in a set to eli11minate duplicates
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    for(int i=0;i<n;i++){
        if(st.find(arr[i]-1)==st.end()){
            int j = arr[i];
            while(st.find(j)!=st.end()){
                j++;
            }
            ans=max(ans, j-arr[i]);
        }
    }
    return ans;
}

int main(){
    int n;
    //number of elements
    cin>>n;
    int arr[n];
    //elements of array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findlongestconsqsubseq(arr, n)<<endl;
}

