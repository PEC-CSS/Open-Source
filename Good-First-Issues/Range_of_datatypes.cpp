#include<iostream>
#include<math.h>
using namespace std;


void findRange(string s,int n){
	if(s == "signed"){
		int max = pow(2,n-1);
		int min = pow(2,n-1)-1;
		cout<<min*(-1)<<" to "<<max<<endl;
	}
	else{
		int r = pow(2,n)-1;
		cout<<0<<" to "<<r<<endl;
	}
}
int main(){
	// to find ranges of various data types :
	
	//signed
	
   cout<<"Signed:"<<endl;
   cout << "Range Signed char: ";
   findRange("signed", sizeof(char)*8); 
   
   cout << "Range Signed int: ";
   findRange("signed",sizeof(int)*8);
   
   cout << "Range Signed float: ";
   findRange("signed", sizeof(float)*8);
   
   cout << "Range Signed double: ";
   findRange("signed", sizeof(double)*8);
   
   cout << "Range Signed short: ";
   findRange("signed", sizeof(short)*8);
   
   cout << "Range Signed long: ";
   findRange("signed", sizeof(long)*8);
   
   cout << "Range Signed long long: ";
   findRange("signed", sizeof(long long)*8);
   
   cout << "Range Signed long double: ";
   findRange("signed", sizeof(long double)*8);
   
   //unsigned
   
   cout<<endl<<"Unsigned:"<<endl;
   
   cout << "Range Unsigned char: ";
   findRange("Unsigned", sizeof(char)*8);
	
   cout << "Range Unsigned int: ";
   findRange("unsigned", sizeof(unsigned int)*8);
   

   
   cout << "Range Unsigned short: ";
   findRange("unsigned", sizeof(unsigned short int)*8);
  
	cout << "Range Unigned long: ";
   findRange("Unsigned", sizeof(unsigned long)*8);
   
   cout << "Range Unsigned long long: ";
   findRange("Unsigned", sizeof(unsigned long long)*8);
   
//   cout << "Range Unsigned long double: ";
//   findRange("Unsigned", sizeof(unsigned long double)*8);
	

}
