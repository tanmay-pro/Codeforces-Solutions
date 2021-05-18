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
    string str;
    stack<char> s;
    vl length;
    cin >> str;
    int c = 0;
    fo(i, str.length())
    {
        if (str[i] == '(')
        {
            s.push('(');
            c++;
        }
        else if (str[i] == ')' && !s.empty())
        {
            s.pop();
            c++;
            if (s.empty() == true && (i == str.length() - 1))
            {
                length.push_back(c);
            }
        }
        else if (str[i] == ')' && s.empty() == true)
        {
            if (c != 0)
            {
                length.push_back(c);
            }
            c = 0;
        }
    }
    if (length.size() == 0)
    {
        cout << "0 1";
        br;
    }
    else
    {
        sort(length.begin(), length.end());
        cout << length[length.size() - 1] << " " << length.size();
        br;
    }

    return 0;
}