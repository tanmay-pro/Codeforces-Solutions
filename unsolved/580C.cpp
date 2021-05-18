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

ll global = 0;

void dfs(vvl &adj, int v, vector<bool> &visited, int cats, vl &a, ll mr, ll p[])
{
    visited[v] = true;
    if (p[v] == -1)
    {
        if (a[v] == 1)
            cats++;
    }
    else
    {
        if (a[v] == 1 && a[p[v]] == 1)
        {
            cats++;
            // cout << "I reached at this pin";
            // br;
        }
        else if (a[v] == 1 && a[p[v]] == 0)
        {
            cats = 1;
            // cout << "I re at this pin";
            // br;
        }
    }
    if (adj[v].size() == 0 && cats <= mr)
    {
        global++;
        // cout << "The number of vertex is = " << v;
        // br;
    }
    else
    {
        // cout << "The number of vertex is =  " << v << "And I failed";
        // br;
    }
    for (int i = 0; i < adj[v].size(); i++)
    {
        if (!visited[adj[v][i]])
            dfs(adj, adj[v][i], visited, cats, a, mr, p);
    }
}

int main()
{
    amazing;
    ll n;
    ll mr;
    cin >> n >> mr;
    vl a;
    ll p[n];
    fo(i, n)
    {
        ll x;
        cin >> x;
        a.push_back(x);
        p[i] = -1;
    }
    vector<pair<ll, ll>> edges;
    fo(i, n - 1)
    {
        ll x, y;
        cin >> x >> y;
        edges.push_back(make_pair(x - 1, y - 1));
    }
    vvl adj(n);
    fo(i, n - 1)
    {
        adj[edges[i].first].push_back(edges[i].second);
        p[edges[i].second] = edges[i].first;
    }
    // fo(i, n)
    // {
    //     cout << "The vertex is: " << i;
    //     br;
    //     fo(j, adj[i].size())
    //     {
    //         cout << adj[i][j];
    //         br;
    //     }
    // }
    vector<bool> visited(n);
    int cats = 0;
    dfs(adj, 0, visited, cats, a, mr, p);
    cout << global;
    br;
    return 0;
}