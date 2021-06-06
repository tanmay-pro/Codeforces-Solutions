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
ll MOD = 1e9 + 7;
int p = 31;

ll maxim(ll a, ll b, ll c)
{
    ll max_val = max(a, b);
    return max(max_val, c);
}

ll minim(ll a, ll b, ll c)
{
    ll min_val = min(a, b);
    return min(min_val, c);
}

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, l;
        cin >> n >> l;
        ll a[n];
        fo(i, n)
        {
            cin >> a[i];
        }
        double time1[n];
        double time2[n];
        double vel1 = 1.0;
        time1[0] = a[0] / vel1;
        vel1++;
        Fo(i, 1, n)
        {
            time1[i] = time1[i - 1] + (a[i] - a[i - 1]) / vel1;
            vel1++;
        }
        double vel2 = 1.0;
        time2[n - 1] = (l - a[n - 1]) / vel2;
        vel2++;
        Fo(i, 1, n)
        {
            time2[n - i - 1] = time2[n - i] + (a[n - i] - a[n - i - 1]) / vel2;
            vel2++;
        }
        // fo(i, n)
        // {
        //     cout << time1[i] << " ";
        // }
        // br;
        // fo(i, n)
        // {
        //     cout << time2[i] << " ";
        // }
        // br;
        double ans = 0;
        fo(i, n)
        {
            if (time1[i] > time2[i])
            {
                vel1 = 1 + i;
                vel2 = n - i + 1;
                ll c = vel1 * (time1[i] - time1[i - 1]);
                ans = c / (vel1 + vel2) + vel2 * (time2[i] - time1[i - 1]) / (vel1 + vel2);
                ans += time1[i - 1];
                break;
            }
        }
        cout << ans;
        br;
    }
    return 0;
}