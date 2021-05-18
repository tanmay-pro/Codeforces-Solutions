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

void heapify(vl &array, ll n, int i, vl &array2) // Forming Max Heap
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && array[l] < array[largest])
        largest = l;
    if (r < n && array[r] < array[largest])
        largest = r;
    if (largest != i)
    {
        ll temp = array[largest];
        array[largest] = array[i];
        array[i] = temp;
        ll temp2 = array2[largest];
        array2[largest] = array2[i];
        array2[i] = temp2;
        heapify(array, n, largest, array2);
    }
}

void heapSort(vl &arr, ll n, vl &arr2)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, arr2);
    for (int i = n - 1; i > 0; i--)
    {
        ll temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        ll temp2 = arr2[0];
        arr2[0] = arr2[i];
        arr2[i] = temp2;
        heapify(arr, i, 0, arr2);
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
        ll sum = 0;
        vl u;
        vvl array(n + 1);
        fo(i, n)
        {
            ll x;
            cin >> x;
            u.push_back(x);
        }
        vl s;
        fo(i, n)
        {
            ll x;
            cin >> x;
            s.push_back(x);
        }
        heapSort(s, s.size(), u);
        fo(i, n)
        {
            sum += s[i];
            array[u[i]].push_back(s[i]);
        }
        Fo(k, 1, n + 1)
        {
            ll sum2 = sum;
            bool set[n + 1];
            fo(i, n + 1)
            {
                set[i] = false;
            }
            fo(i, n)
            {
                if (array[u[i]].size() % k != 0 && set[u[i]] == false)
                {
                    //cout << "For University " << u[i] << " The size is " << array[u[i]].size() << " and k = " << k;
                    //br;
                    set[u[i]] = true;
                    ll constant;
                    if (array[u[i]].size() >= k)
                    {
                        constant = array[u[i]].size() % k;
                    }
                    else
                    {
                        constant = array[u[i]].size();
                    }
                    //cout << "Constant = " << constant;
                    //br;
                    fo(r, constant)
                    {
                        sum2 -= array[u[i]][array[u[i]].size() - 1 - r];
                        if (sum2 < 0)
                        {
                            sum2 = 0;
                            break;
                        }
                    }
                }
            }
            cout << sum2 << " ";
        }
        br;
    }
    return 0;
}