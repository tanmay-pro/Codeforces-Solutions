#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
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

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        unordered_map<string, string> mp;
        string store;
        fo(i, n)
        {
            string str = "";
            char c;
            while ((c = getchar()) != '\n')
            {
                str += c;
            }
            string variable;
            char ch;
            int j = 0;
            while ((ch = str[j]) != ' ')
            {
                variable += ch;
                j++;
            }
            if (i == n - 1)
            {
                store = variable;
            }
            if (str[j + 1] == ':')
            {
                string temp = "";
                Fo(k, j + 4, str.length())
                {
                    temp += str[k];
                }
                mp[variable] = temp;
                // cout << "Stored variable = " << mp[variable];
                // br;
            }
            else
            {
                int k = j + 3;
                char ch;
                string var2 = "", var3 = "";
                while ((ch = str[k]) != ' ')
                {
                    var2 += ch;
                    k++;
                }
                // cout << "variable2 = " << var2;
                // br;
                k++;
                k++;
                k++;
                while (k != str.length())
                {
                    ch = str[k];
                    var3 += ch;
                    k++;
                }
                string temp = "";
                temp += mp[var2] + mp[var3];
                mp[variable] = temp;
                // cout << "Stored variable = " << mp[variable];
                // br;
            }
        }
        string checker = mp[store];
        ll count = 0;
        fo(i, checker.size() - 3)
        {
            if (checker[i] == 'h' && checker[i + 1] == 'a' && checker[i + 2] == 'h' && checker[i + 3] == 'a')
                count++;
        }
        cout << count;
        br;
    }
    return 0;
}