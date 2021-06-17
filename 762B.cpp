#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
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
	ll usb, ps2, both;
	cin >> usb >> ps2 >> both;
	ll m;
	cin >> m;
	vl musb, mps2;
	fo(i, m)
	{
		ll val;
		string str;
		cin >> val >> str;
		if(str == "USB")
		{
			musb.push_back(val);
		}
		else
		{
			mps2.push_back(val);
		}
	}
	sort(musb.begin(), musb.end());
	sort(mps2.begin(), mps2.end());
	ll cost = 0;
	int count = 0;
	int i = 0, j = 0;
	for(;i < musb.size(); i++)
	{
		if(usb > 0)
		{
			cost += musb[i];
			count++;
			usb--;
		}
		else
		{
			break;
		}
	}
	for(;j < mps2.size(); j++)
	{
		if(ps2 > 0)
		{
			cost += mps2[j];
			count++;
			ps2--;
		}
		else
		{
			break;
		}
	}
	vl array_net;
	while(true)
	{ 	if(i == musb.size() || j==mps2.size())
			break;
		if(musb[i] < mps2[j])
		{
			array_net.push_back(musb[i]);
			i++;
		}
		else
		{
			array_net.push_back(mps2[j]);
			j++;
		}
	}
	if(i != musb.size())
	{
		while(i != musb.size())
		{
			array_net.push_back(musb[i]);
			i++;
		}
	}
	if(j != mps2.size())
	{
		while(j != mps2.size())
		{
			array_net.push_back(mps2[j]);
			j++;
		}
	}
//	fo(i, array_net.size())
//	{
//		cout << "Element  = " << array_net[i];
//		br;
//	}
	fo(i, array_net.size())
	{
		if(both > 0)
		{
			count++;
			cost+=array_net[i];
			both--;
		}
		else
			break;
	}
	cout << count << " " << cost;
	br;
	return 0;
}