#include<iostream>
#include<regex>

int main(){
    //taking string input
    std::string input;
    std::cout<<"Enter the ab string: ";
    std::cin>>input;

    //regex expression is declared which is used to validate the entered input string
    std::regex input_validation("(^a)(ab{2}|a{2}b{2}|b{2}a{2}|b{2}a|a{2}|a)+");
    /*ans variable is set to either trur or false based on the output of 
    the regex_match Function*/
    std::string ans = regex_match(input,input_validation)?"true":"false";
    std::cout<<ans<<std::endl;    

    return 0;
}
