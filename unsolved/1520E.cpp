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
        ll n;
        cin >> n;
        string str;
        cin >> str;
        ll no_of_sheep = 0;
        fo(i, n)
        {
            if (str[i] == '*')
                no_of_sheep++;
        }
        vl diff_array;
        stack<int> s;
        ll count = 0;
        fo(i, n)
        {
            if (str[i] == '*' && s.empty())
            {
                s.push_back(1);
                count = 0;
            }
            else if (str[i] == '*' && !s.empty())
            {
                s.pop();
                diff_array.push_back(count);
                count = 0;
            }
            else
            {
                count++;
            }
        }
    }
    return 0;
}