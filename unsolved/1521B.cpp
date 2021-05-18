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

vl change_i;
vl change_j;
vl final_x;
vl final_y;

ll minim(ll a, ll b)
{
    if (a < b)
        return a;
    else
        return b;
}

void select_number(ll n, vl &a, int index, ll exc1, ll exc2)
{
    ll i = 1;
    while (true)
    {
        if ((minim(i, a[exc1]) == minim(a[index], a[exc1])) && (__gcd(i, a[exc1]) == 1) && (minim(i, a[exc2]) == minim(a[index], a[exc2])) && (__gcd(i, a[exc2]) == 1))
        {
            a[index] = i;
            change_i.push_back(exc1 + 1);
            change_j.push_back(index + 1);
            final_x.push_back(a[exc1]);
            final_y.push_back(a[index]);
            change_i.push_back(index + 1);
            change_j.push_back(exc2 + 1);
            final_x.push_back(a[index]);
            final_y.push_back(a[exc2]);
            break;
        }
        else
        {
            i++;
        }
    }
}

void select_number1(ll n, vl &a, int index, ll exc1)
{
    ll i = 1;
    while (true)
    {
        if ((minim(i, a[exc1]) == minim(a[index], a[exc1])) && (__gcd(i, a[exc1]) == 1))
        {
            a[index] = i;
            change_i.push_back(exc1 + 1);
            change_j.push_back(index + 1);
            final_x.push_back(a[exc1]);
            final_y.push_back(a[index]);
            break;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;  
        cin >> n;
        vl array;
        fo(i, n)
        {
            ll x;
            cin >> x;
            array.push_back(x);
        }
        int count = 0;
        fo(i, n - 2)
        {
            if (__gcd(array[i], array[i + 1]) != 1)
            {
                if (__gcd(array[i + 1], array[i + 2]) != 1)
                {
                    //select lowest possible prime not equal to i or i +2 for i+1
                    // cout << " I reached here :)";
                    // br;
                    select_number(n, array, i + 1, i, i + 2);
                    count++;
                }
                else
                {
                    //select lowest possible prime not equal to i +1 for i
                    // cout << " I reached here";
                    // br;
                    select_number1(n, array, i, i + 1);
                    count++;
                }
            }
        }
        if (__gcd(array[n - 1], array[n - 2]) != 1)
        {
            select_number1(n, array, n - 1, n - 2);
            count++;
        }
        cout << count;
        br;
        fo(i, count)
        {
            cout << change_i[i] << " " << change_j[i] << " " << final_x[i] << " " << final_y[i];
            br;
        }
    }
    return 0;
}