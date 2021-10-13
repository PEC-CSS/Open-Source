
/*-------1st Approch ---------*/
#include <iostream>
using namespace std;
 
int countWays(int n){
    int res[n + 1];
    res[0] = 1;
    res[1] = 1;
    res[2] = 2;
    for (int i = 3; i <= n; i++)
        res[i] = res[i - 1] + res[i - 2] + res[i - 3];
 
    return res[n];
}
 
int main(){
    int n;
    cin>>n;
    cout << countWays(n);
    return 0;
}

//TC : O(n) SC: O(n)

/*-------2nd Approch ---------*/
#include <iostream>
using namespace std;
 
int countWays(int n){
    int a = 1, b = 2, c = 4; // declaring three variables
                             // and holding the ways
                             // for first three stairs
    int d = 0; // fourth variable
    if (n == 0 || n == 1 || n == 2)
        return n;
    if (n == 3)
        return c;
 
    for (int i = 4; i <= n; i++) { // starting from 4 as
        d = c + b + a; // already counted for 3 stairs
        a = b;
        b = c;
        c = d;
    }
    return d;
}
 
int main(){
    int n;
    cin>>n;
    cout << countWays(n);
    return 0;
}

//TC : O(n) SC: O(1)
