#include <iostream>
using namespace std;

bool checkAB(char input[]) {
  if(input[0]=='a')
  {
      if(input[1]=='\0')
          return true;
      else if(input[1]=='a')
          return checkAB(input+1);
      else if(input[1]=='b'&&input[2]=='b')
      {
          if(input[3]=='\0')
              return true;
          else if(input[3]=='a')
              return checkAB(input+3);
          else
              return false;
      }
      else
          return false;
  }
    else
        return false;
}
     

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
