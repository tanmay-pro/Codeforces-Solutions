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

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        string ans;
        ll p_pow[str.length() + 1];
        p_pow[0] = 1;
        for (int i = 1; i < str.length() + 1; i++)
            p_pow[i] = (p_pow[i - 1] * p) % m;
        ll hp[str.length() + 1, 0];
        for (int i = 0; i < str.length(); i++)
            hp[i + 1] = (hp[i] + (str[i] - 'a' + 1) * p_pow[i]) % m;
        ll hs[str.length() + 1, 0];
        for (int i = 0; i < str.length(); i++)
            hs[i + 1] = (hs[i] + (str[str.length() - 1 - i] - 'a' + 1) * p_pow[i]) % m;
        int pos = -1;   
        fo(i, str.length())
        {
            if (hp[i] == hp[s])
                pos = i;
        }

    }
    return 0;
}