#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.141592
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
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
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
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
        fo(i, n)
        {
            ll x;
            cin >> x;
            a.push_back(x);
        }
        vi count(n + 1, 0);
        Fo(i, 1, n + 1)
        {
            count[a[i-1]]++;
        }
        // fo(i, n + 1)
        // {
        //     cout << count[i] << endl;
        // }
        sort(count.begin(), count.end());

        cout << count[n] << endl;
    }
    return 0;
}