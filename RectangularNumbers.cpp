#include<bits/stdc++.h>
using namespace std;
#define max 100 //defining maximum limits
int main()
{
    int n,i,j,t;
    cin>>n; //input
    t= (2*n)-1; //size of matrix
    int arr[max][max]; //storing matrix
    int x = 0,y = t-1; //front limit and back limit for each iterative moving inside layer
    while (n != 0){
        for (i = x; i <=y; i++) {
            for (j = x; j <=y; j++) {
                if (i == x || i == y || j == x || j == y)
                    arr[i][j] = n;
            }
        }
        ++x;
        --y;
        --n;
    }
    for (i = 0; i < t; i++) {
        for (j = 0; j < t; j++) {
        cout << arr[i][j];//print
        }
        cout << endl;
    }
return 0;
}
/* logic explain: 
for example: n = 3
size of the matrix is twice the number (2n) with common middle element (-1) : 2n-1
then the matrix will be filled per iteration like:
in 1st loop  in 2nd loop  in 3rd loop 
33333
3   3         222
3   3 ---->   2 2 ---->   1
3   3         222
33333
and look like:
33333         33333       33333
3   3         32223       32223
3   3 ---->   32 23 ----> 32123
3   3         32223       32223
33333         33333       33333
thus Output:
33333
32223
32123
32223
33333
*/
