#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.1415926535897932384626
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define br printf("\n")
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define deba(i, a, n) \
    fo(i, n) { cout << a[i] << " "; }
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

int main()
{

    string s;
    cin >> s;
    if (s.at(0) == 'a' || s.at(0) == 'h')
    {
        if (s.at(1) == '1' || s.at(1) == '8')
        {
            cout << 3;
        }
        else
        {
            cout << 5;
        }
    }
    else 
    {
        if(s.at(1) == '1' || s.at(1) == '8')
        {
            cout << 5;
        } 
        else 
        {
            cout << 8;
        }
    }
    return 0;
}