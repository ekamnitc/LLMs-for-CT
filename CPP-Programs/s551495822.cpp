 #include<bits/stdc++.h>
 // #include <ext/pb_ds/tree_policy.hpp>
 // #include <ext/pb_ds/assoc_container.hpp>
 #include<chrono>
  using namespace std;
   using namespace std::chrono;      
  // using namespace __gnu_pbds; 
 #define fastio     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 #define fi         first
 #define se         second
 #define int         long long 
 #define pb         push_back
 #define emp        emplace_back
 #define vv(x)      vector<x>
 #define mp(x,y)    map<x,y>
 #define dq(x)      deque<x>
 #define pql(x)     priority_queue<x>
 #define pqs(x)     priority_queue<x,vv(x),greater<x> >
 //#define M          1000000007
 #define forf(i,a,b) for(int i=a;i<b;i++)
 #define it(x)      x::iterator
 #define ll         long long 
 #define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
 #define time__(d)  for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
 #define vii        vector<int>
 #define big        1e12
 #define sm         -2e18
 #define mkr        make_pair
 #define vpi        vector<pair<int,int> >
 #define pii        pair<int,int>
 #define rng        500005
 #define sz(x)      (int)x.size()
 #define rv(x)      reverse(x.begin(),x.end())
 #define out(x)     cout<<x.fi<<" "<<x.se<<endl;
#define MEM(x,val) memset(x,val,sizeof(x))

 // typedef tree<pii, null_type, less<pii>, rb_tree_tag,  
 //            tree_order_statistics_node_update>  odst; 


void pr_init()
{
   
    #ifndef ONLINE_JUDGE
    freopen("gin.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
   
    #endif
}


const int Mxn = 3e5+1;
int cols[Mxn] , seg[4*Mxn+4];
map<int,vii> row;  
void build(int s,int e,int i)
{
  if(s==e)
  {
    seg[i] = cols[s];
    return ;
  }
  int md = (s+e)/2;
  build(s,md,2*i+1);
  build(md+1,e,2*i+2);
  seg[i] = max(seg[2*i+1],seg[2*i+2]);
}

int qr(int qs,int qe,int s,int e,int i)
{
   if(s<=qs && e>=qe)
   {
    return seg[i];
   }
   if(s>qe || e<qs)
   {
     return 0;
   }

   int md = (qe+qs)/2;
   return max(qr(qs,md,s,e,2*i+1),qr(md+1,qe,s,e,2*i+2));
}

map<int,map<int,int> > mn;
void solve()
{
  int h,w,m;
  cin >> h >> w >> m; 
  

  forf(i,0,m)
  {
    int x,y;
    cin >> x >> y;
    mn[x][y] -- ;
    cols[y]++;
    row[x].pb(y);
  }
 
   build(0,Mxn,0);
   int an = 0;
   for(auto x:row)
   {
    vii cur = x.se;
    int num = sz(cur);
    cur.pb(w);
    cur.pb(0);
    sort(cur.begin(),cur.end());
    
    for(int i=1;i<(int)cur.size();i++)
    {
       an = max(an , num + cols[cur[i]] + mn[x.fi][cur[i]]);
       if(cur[i-1]+2<=cur[i])
       {
         an = max(an,qr(0,Mxn,cur[i-1]+1,cur[i]-1,0)+num);
       }
    }

   }

   cout<<an;
}

int32_t main()
{
  pr_init();
  fastio;
  auto start = high_resolution_clock::now(); 
  solve(); 
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start); 
  
    // cout << "Time taken by function: "
    //      << duration.count() << " microseconds" << endl; 

  return 0;
}