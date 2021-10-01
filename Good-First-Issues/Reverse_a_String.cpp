#include <iostream>
#include <string>
using namespace std;

void reverseWord(string& strg)
{

    int strLen = strg.length() - 1;
    int index = 0;
    
    while(index < strLen - index){

        char temp = strg[index];
        strg[index] = strg[strLen - index];
        strg[strLen - index] = temp;
        
        ++index;
    }

}

int main(int args, char *argv[])
{   
    string str = "PEC-CSS/Opensource";
    reverseWord(str);
    cout << str << endl;
    
    return 0;
}
