#include<bits/stdc++.h>
using namespace std;

#define vvi             vector<vector<int>>
#define ld              long double
#define mod             1000000007
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vpii            vector<pair<int,int>>
#define fr(i,a,b)       for(int i = a; i < b; i += 1)
#define all(x)          x.begin(),x.end()
#define sz(a)           (int)(a.size())
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define input(a)        for(auto it = a.begin(); it != a.end(); it++) { int value; cin >> value; *it = value;}
//#define print(a)        for(auto it = a.begin() ; it != a.end() ; it++){ cout << *it << " " ;}cout << '\n';
#define SS                      stringstream
#define db(...)                 __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int dirx[4] = {0, 0, -1, 1};
const int diry[4] = {-1, 1, 0, 0};

// 0 -> l, 1 - > r, 2 -> u , 3 -> down
void FASTIO()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int mxN = 1e6 + 10;
int n;
int dp[mxN][4];
// 0 -> none, 1-> 0 only, 2-> 9only, 3->0,9 only

void test_case()
{
	cin >> n;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j < 4; j++)
			dp[i][j] = 0;

	dp[1][0] = 8;
	dp[1][1] = 1;
	dp[1][2] = 1;
	dp[1][3] = 0;


	for(int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i-1][0] * 8;
		dp[i][1] = dp[i-1][0] + dp[i-1][1] * 9;
		dp[i][2] = dp[i-1][0] + dp[i-1][2] * 9;
		dp[i][3] = dp[i-1][1] + dp[i-1][2] + 10 * dp[i-1][3];

		for(int j = 0; j < 4; j++)
			dp[i][j] %= mod;
	}

	cout << dp[n][3];

}   


int32_t main()
{
    FASTIO();

    int t;
    t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++)
    {
        //cout << "Case #" << i << ": ";
        test_case();
    }
    return 0;
} 
