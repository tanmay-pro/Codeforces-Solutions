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

int MOD = 1e9 + 7;

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vl a;
        ll x;
        fo(i, 4 * n)
        {
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        ll ans = a[0] * a[4 * n - 1];
        ll c = 0;
        fo(i, 2 * n)
        {
            if (a[i] * a[4 * n - i - 1] == ans)
            {
                if (i % 2 == 1 && (a[i] = a[i - 1]) && (a[4 * n - i - 1] == a[4 * n - i]))
                {
                    c++;
                }
                else if (i % 2 == 0)
                {
                    c++;
                }
            }
        }
        if (c == 2 * n)
        {
            cout << "YES";
            br;
        }
        else
        {
            cout << "NO";
            br;
        }
    }
    return 0;
}