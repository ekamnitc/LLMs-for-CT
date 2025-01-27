#include <bits/stdc++.h>
using namespace std;
int main()
{
    int64_t N;
    cin >> N;
    vector<int64_t> A(N);
    vector<int64_t> B(N);
    for(int i=0; i<N; i++)
    {
        cin >> A.at(i) >> B.at(i);
    } 
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    reverse(A.begin(),A.end());
    cout << B.at(0)+A.at(0) << endl;

}
