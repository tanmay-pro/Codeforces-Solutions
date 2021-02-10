#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define f first
#define s second
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

int MOD = 1e9 + 7;

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vl h;
        ll x;
        fo(i, n)
        {
            cin >> x;
            h.push_back(x);
        }
        ll pos = 0;
        ll count = 0;
        fo(i, k)
        {
            if (pos < n - 1)
            {
                if (h[pos] >= h[pos + 1])
                {
                    pos++;
                    i--;
                }
                else
                {
                    h[pos]++;
                    if (i != k - 1)
                    {
                        pos = 0;
                    }
                }
            }
            else
            {
                pos = -1;
                count++;
                if (count == 2)
                {
                    break;
                }
            }
        }
        if (pos == -1)
        {
            cout << -1;
            br;
        }
        else
        {
            cout << (pos + 1);
            br;
        }
    }
    return 0;
}