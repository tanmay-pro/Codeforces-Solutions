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
    ll n = 1;
    cin >> n;
    ll pos[n];
    fo(i, n)
    {
        ll x;
        cin >> x;
        pos[i] = x;
    }
    ll counter = 0;
    fo(i, n)
    {
        if (pos[n - i - 1] == 1)
        {
            bool set = true;
            ll temp = n - i - 1;
            pos[n - i - 1] = 2;
            while (pos[temp] != 0)
            {
                if (temp == n - 1)
                {
                    set = false;
                    break;
                }
                temp++;
            }
            if (set == true)
            {
                pos[temp] = 2;
                counter += temp - (n - i - 1);
                // fo(j, n)
                // {
                //     cout << pos[j] << " ";
                // }
                // br;
            }
            else
            {
                ll temp = n - i - 1;
                while (pos[temp] != 0)
                {
                    temp--;
                }
                pos[temp] = 2;
                counter += abs(temp - (n - i - 1));
                // fo(j, n)
                // {
                //     cout << pos[j] << " ";
                // }
                // br;
            }
        }
    }
    cout << counter;
    br;
    return 0;
}