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
        ll max_consec = 0;
        ll temp = 1;
        ll starting_pos = 0;
        ll starting_pos_temp = 0;
        Fo(i, 1, n)
        {
            if (str[i - 1] == '*' && str[i] == '*')
            {
                temp++;
                if (i == n - 1)
                {
                    if (max_consec < temp)
                    {
                        max_consec = temp;
                        starting_pos = starting_pos_temp;
                    }
                    temp = 1;
                }
            }
            else if (str[i] == '*' && str[i - 1] == '.')
                starting_pos_temp = i;
            else
            {
                if (max_consec < temp)
                {
                    max_consec = temp;
                    starting_pos = starting_pos_temp;
                }
                temp = 1;
            }
        }
        ll ending_pos = starting_pos + max_consec - 1;
        ll sum = 0;
        ll check = 1;
        Fo(i, starting_pos - 1, -1)
        {
            if (str[i] == '*')
            {
                sum += starting_pos - check - i;
                check++;
            }
        }
        check = 1;
        Fo(i, ending_pos + 1, n)
        {
            if (str[i] == '*')
            {
                sum += i - ending_pos - check;
                check++;
            }
        }
        cout << sum;
        br;
    }
    return 0;
}