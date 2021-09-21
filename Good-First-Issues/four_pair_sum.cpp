#include <iostream>
#include <unordered_map>
#include <random>
#include <chrono>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
signed main()
{

    FIO;
    int n;               //number of elements in the array
    cin >> n;            // assuming n goes till 1e4
    int *a = new int[n]; //array to hold the elements
    for (int i = 0; i < n; i++)
        cin >> a[i];

    unordered_map<int, pii, custom_hash> sum_of_pairs; // use custom hash to prevent O(n^2) blowing up on unordered-map
    sum_of_pairs.reserve(1 << 26);                     // increase the size of hash map
    sum_of_pairs.max_load_factor(0.25);

    bool found = false;
    for (int i = 0; i < n && !found; i++)
    {
        for (int j = i + 1; j < n && !found; j++)
        {
            int cur_sum = a[i] + a[j];
            if (sum_of_pairs.find(cur_sum) != sum_of_pairs.end())
            {
                found = true;
                cout << "Required elements are: "
                     << "{ " << a[i] << ", " << a[j] << " }"
                     << " & "
                     << "{ " << sum_of_pairs[cur_sum].ff << ", " << sum_of_pairs[cur_sum].ss << " }\n";
            }
            sum_of_pairs[cur_sum] = {min(a[i], a[j]), max(a[i], a[j])};
        }
    }
    if (!found)
        cout << "No such pairs found\n";
    return 0;
}