#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.141592653589793238462
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define br printf("\n")
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
    // sl(t);
    while (t--)
    {
        ll n;
        sl(n);
        vl v;
        ll x;
        fo(i, n)
        {
            sl(x);
            v.push_back(x);
        }
        ll min = v[0];
        fo(i, n)
        {
            if (v[i] < min)
            {
                min = v[i];
            }
        }
        vl pos;
        fo(i, n)
        {
            if (v[i] == min)
            {
                pos.push_back(i);
            }
        }
        min = MOD;
        Fo(i, 1, pos.size())
        {
            if (pos[i] - pos[i - 1] < min)
            {
                min = pos[i] - pos[i - 1];
            }
        }
        cout << min << endl;
    }
    return 0;
}