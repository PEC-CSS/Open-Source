#include<bits/stdc++.h>
using namespace std;

/*
Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.

Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".

Examples:

Input: s = "banana"
Output: "ana"

Input: s = "abcd"
Output: ""
Constraints:
2 <= s.length <= 3 * 104
s consists of lowercase English letters.

Solved using unordered multimap
*/

int p = INT_MAX / 26 / 26 * 26 - 1; // = 82595499
    // order of 26 mod 82595499 is 11799354 > 50000, so this choice should result in minimum collision
    string longestDupSubstring(string str) {
        int high = str.size(), low = 0, idx = 0;
        while (high - low > 1) {
            auto mid = (high + low) / 2;
            int pow = 1, h = 0;
            for (int i = mid - 1; i >= 0; --i) {
                h += (str[i] - 'a') * pow, h %= p;
                pow *= 26, pow %= p;
            }
            unordered_multimap<int,int> h2i = {{h,0}}; // hash to indices
            auto i = 0;
            for ( ; i + mid < str.size(); ++i) {
                h *= 26, h %= p;
                h += (str[i+mid] - 'a') - (str[i] - 'a') * pow, h %= p;
                h += p, h %= p;
                auto its = h2i.equal_range(h);
                auto it = its.first;
                for ( ; it != its.second; ++it) {
                    auto j = i+1, k = it->second;
                    for ( ; j < i + mid; ++j, ++k) {
                        if (str[j] != str[k]) break;
                    }
                    if (j == i + mid) break;
                }
                if (it != its.second) break;
                h2i.insert({h,i+1});
            }
            if (i + mid < str.size())
                low = mid, idx = i + 1;
            else high = mid;
        }
        return str.substr(idx,low);
    }

int main(){
	
	string str;
	cin>>str;
	
	cout<<longestDupSubstring(str);
	
}
