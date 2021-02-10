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
        ll n, m;
        cin >> n >> m;
        vl a;
        fo(i, n)
        {
            ll x;
            cin >> x;
            a.push_back(x);
        }
        vl b;
        fo(i, n)
        {
            ll x;
            cin >> x;
            b.push_back(x);
        }
        vl c;
        fo(i, m)
        {
            ll x;
            cin >> x;
            c.push_back(x);
        }
        int j = 0;
        fo(i, n)
        {
            if (a[i] != b[i])
            {
                a[i] = c[j];
                j++;
                if (c[j] != b[i])
                {
                    i--;
                }
                c[j] = i + 1;
            }
            if (j >= m)
                break;
        }
        ll count = 0;
        fo(i, n)
        {
            if (a[i] == b[i])
                count++;
        }
        if (count == n)
        {
            cout << "YES";
            br;
            fo(i, m)
            {
                cout << c[i] << " ";
            }
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