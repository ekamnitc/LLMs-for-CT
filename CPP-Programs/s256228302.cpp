#include <bits/stdc++.h>
    #include <math.h>
 
    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    # define M_PI  3.14159265358979323846
 
 
    const int M=1e9+7;
    long long mod(long long x){
        return ((x%M + M)%M);
    }
    long long add(long long a, long long b){
        return mod(mod(a)+mod(b));
    }
    long long mul(long long a, long long b){
        return mod(mod(a)*mod(b));
    }
 
    int fact[1000005];
    bool ok=false;
 
    void f(int x){
        if(ok==true)
            return;
        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                int a=i;
                int b=x/i;
                if(a==b){
                    a=i;
                    b=1;
                }
                if(a!=1){
                    if(fact[a]){
                        ok=true;
                        return;
                    }
                    fact[a]++;
                }
                if(b!=1){
                    if(fact[b]){
                        ok=true;
                        return;
                    }
                    fact[b]++;
                }
            }
        }
    }
 
    void solve(){  
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        int gcd=a[0];
        // cout<<"in "<<ok<<"\n";
        f(a[0]);
        // cout<<"in "<<ok<<"\n";
        for(int i=1;i<n;i++){
            f(a[i]);
            gcd=__gcd(gcd,a[i]);
            // cout<<"in "<<ok<<"\n";
        }
        if(!ok){
            cout<<"pairwise coprime";
        }
        else if(gcd==1){
            cout<<"setwise coprime";
        }
        else{
            cout<<"not coprime";
        }
    }
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cout<<fixed;
        cout<<setprecision(10);
//        freopen("timber_input.txt", "r", stdin);
//        freopen("timber_output.txt", "w", stdout);
        int t=1;
        // cin>>t;
        for(int i=1;i<=t;i++){
//            cout<<"Case #"<<i<<": ";
            solve();
        }
        return 0;
    }