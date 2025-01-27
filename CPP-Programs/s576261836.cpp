                    #include <iostream>
                    #include<cmath>
                    #include<string>
                    using namespace std;
                    int main()
                    {
                       long long int n,k,x,y;
                      cin>>n>>k>>x>>y;
                      if(n>k)
                      {  long long int h=n-k;
                      long long int u=(k*x)+(h*y);
                      cout<<u;
                      }
                      else
                        cout<<x*n;
                        
                    }