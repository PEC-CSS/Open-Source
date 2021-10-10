#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> incrementBinary(std::vector<int> in){
    int count=in.size()-1;
    in[count]+=1;
    while(count >=0){
        if(in[count]>1){
            in[count]=0;
            in[count-1]+=1;
        }
        count--;
    }
    return in;
}

std::vector<int> extendBinary(std::vector<int> ans,bool isNegative){
//checks if answer is negative and performs 2's compliment
    if(isNegative){
        for(int i=0;i<ans.size();i++){
            if(ans[i] == 0)
                ans[i]=1;
            else
                ans[i]=0;
        }
        if(ans[ans.size()-1]==0){
            ans[ans.size()-1]=1;
        }
        else{
            ans = incrementBinary(ans);
        }
    }

    int size=(sizeof(int)*8)-ans.size();
    std::vector<int> extended;
    int temp=0;
    if(isNegative)
        temp =1;
    while(size>0){
        extended.push_back(temp);
        size--;
    }
    for(auto p:ans){
        extended.push_back(p);
    }
    return extended;
}

int countSetBits(std::vector<int> a){
    int setBitCount=0;
    for(auto i:a){
        if(i==1){
            setBitCount++;
        }
    }
    return setBitCount;
}

int setBitCounter(int a){
    bool isNegative=false;
    if(a<0){
        isNegative = true;
    }
    std::vector<int>ans;
    while(a!=0){
        ans.push_back(a%2);
        a=a/2;        
    }
    std::reverse(ans.begin(),ans.end()); 
    //extendeds the binary to 32 bits based on positive or negative
    ans = extendBinary(ans,isNegative);

    return countSetBits(ans);
}

void print(std::vector<int> a){
    for(auto i:a){
        std::cout<<i;
    }
}

int main(){
    std::cout<<"enter a number\n";
    int s;std::cin>>s;
    std::cout<<"Output: "<<setBitCounter(s);
    return 0;
}
