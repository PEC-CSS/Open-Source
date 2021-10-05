#include <bits/stdc++.h>

using namespace std;

#define FOR(i,k,n) for ( int i=k; i<n; i++ )

int KMP(string s, string p)
{
    int lps[p.length()];
    lps[0]=0;

    FOR(i,1,p.length())
    {
        int ci = lps[i-1];

        while( ci>=1 && p[i]!=p[ci] )
            ci = lps[ci-1];
        
        if ( p[i]!=p[ci] )
            lps[i]=ci;
        else
            lps[i] = ci+1;
    }

    int ci=0;
    int ans=INT_MAX;

    FOR(i,0,s.length())
    {
        while( ci==p.length() || (ci>=1 && s[i]!=p[ci]) )
            ci = lps[ci-1];
        if ( s[i]==p[ci] )
            ci++;
        if (  ci==p.length())
            ans=min(ans,int(i-p.length()+1));
    }
    return (ans==INT_MAX?-1:ans);
}

int main(){
   
    string text,pattern;
    cin>>text>>pattern;

    cout<<KMP(text,pattern);

}
