#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ff first
#define ss second
#define pb push_back
#define file_read                     \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
int m = 1e9 + 7;
int p = 31;

bool func(ll h[], ll p_pow[], ll n, int j)
{
    int counts = 0;
    ll S = j + 1;
    ll T = n;
    for (int i = 1; i + S - 1 < T; i++)
    {
        ll cur_h = (h[i + S - 1] + m - h[i - 1]) % m;
        if (cur_h == h[j] * p_pow[i] % m)
            counts++;
    }
    if (counts >= 2)
        return true;
    else
        return false;
}

int main()
{
    amazing;
    string str;
    cin >> str;
    ll power[str.length() + 2];
    power[0] = 1;   
    for (int i = 1; i < str.length() + 2; i++)
        power[i] = (power[i - 1] * p) % m;
    ll n = str.length();
    ll hash_val_start[n];
    hash_val_start[0] = (str[0] - 'a' + 1) * power[0];
    Fo(i, 1, n)
    {
        hash_val_start[i] = (hash_val_start[i - 1] + (str[i] - 'a' + 1) * power[i]) % m;
    }
    ll hash_val_end[n];
    hash_val_end[0] = (str[str.length() - 1] - 'a' + 1) * power[str.length() - 1];
    Fo(i, 1, n)
    {
        hash_val_end[i] = (hash_val_end[i - 1] + (str[str.length() - 1 - i] - 'a' + 1) * power[str.length() - 1 - i]) % m;
    }
    ll index = -1;
    fo(i, n - 1)
    {
        if (((hash_val_start[i] * power[str.length() - i - 1]) % m == hash_val_end[i]) && func(hash_val_start, power, n, i) == true)
        {
            index = i;
        }
    }
    if (index != -1)
    {
        fo(i, index + 1)
        {
            cout << str[i];
        }
    }
    else
    {
        cout << "Just a legend";
    }
    br;
    return 0;
}