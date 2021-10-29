#include<iostream>
using namespace std;

int main(){
	// to find size of various data types :
	
	int size_char = sizeof(char);
	cout<<"Size of char datatype:"<<size_char<<" bytes"<<endl;
	
	int size_int = sizeof(int);
	cout<<"Size of int datatype:"<<size_int<<" bytes"<<endl;
	
	int size_short = sizeof(short);
	cout<<"Size of short datatype :"<<size_short<<" bytes"<<endl;
	
	int size_long = sizeof(long);
	cout<<"Size of long :"<<size_long<<" bytes"<<endl;
	
	int size_long_long = sizeof(long long);
	cout<<"Size of long long:"<<size_long_long<<" bytes"<<endl;
	
	int size_float = sizeof(float);
	cout<<"Size of float:"<<size_float<<" bytes"<<endl;
	
	int size_double = sizeof(double);
	cout<<"Size of double:"<<size_double<<" bytes"<<endl;
	
	int size_long_double = sizeof(long double);
	cout<<"Size of long double:"<<size_long_double<<" bytes"<<endl;
	
	int size_bool = sizeof(bool);
	cout<<"Size of bool:"<<size_bool<<" bytes"<<endl;

}
