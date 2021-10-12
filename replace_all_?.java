class Solution {
public:
    string modifyString(string s) 
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '?')
            {
                for(char j = 'a'; j <= 'c'; j++)
                {
                    if(i - 1 >= 0 && s[i - 1] == j) continue;
                    if(i + 1 < s.size() && s[i + 1] == j) continue;
                    s[i] = j;
                    break;
                }
            }
        }
        return s;
    }
};
