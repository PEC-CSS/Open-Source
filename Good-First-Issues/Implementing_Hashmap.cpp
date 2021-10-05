// Assumptions:
// Key,Value are Non negative Integers
// The maximum (key,value) that can be inserted into HashMap is (1e6,1e6)

// Time Complexity:
// Push -> O(1)
// Remove -> O(1)
// Get/Search -> O(1)
// Count of Keys -> O(1)

//Space Complexity:
//O(1e6)

#include <bits/stdc++.h>
using namespace std;
class MyHashMap
{
    vector<int> mp;
    int siz;
    int cnt = 0;

public:
    MyHashMap()
    {
        siz = 1e6 + 1;
        mp.resize(siz);
        fill(mp.begin(), mp.end(), -1);
    }
    void push(int key, int value)
    {
        mp[key] = value;
        cout << "Key " << key << " assigned to value " << value << ".\n";
        cnt++;
    }
    void remove(int key)
    {
        mp[key] = -1;
        cout << "Key " << key << " removed from map.\n";
        cnt--;
    }
    int get(int key)
    {
        if (mp[key] == -1)
        {
            cout << "Key " << key << " not present in map.\n";
        }
        else
        {
            cout << "Value present at key " << key << " is " << mp[key] << ".\n";
        }
    }
    void count()
    {
        cout << "Count of Values in map is " << cnt << ".\n";
    }
};
int main()
{
    MyHashMap *obj = new MyHashMap();
    obj->push(1, 2);
    obj->push(3, 4);
    obj->push(5, 3);
    obj->push(9, 4);
    obj->push(6, 7);
    obj->count();
    obj->get(6);
    obj->remove(6);
    obj->get(6);
    obj->count();

    return 0;
}