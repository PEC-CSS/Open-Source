#include<iostream>
#include<string>

#define integer(c) (c-'0')  //makes char to int --> since c has a ascii value --> substract default
using namespace std;

string sumOfDigits(string &n){
    int ans = 0;

    for (int i = 0; i<n.length(); i++){
        ans += integer(n[i]);      
    }
    
    return to_string(ans);     //ofcouse int to string
}

int main(){
    string n; cin >> n;
    int spell = 0;

    while (n.length()>1){
        spell++;
        n = sumOfDigits(n);
    }

    cout << spell;
}