#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    set<long long>st;
    
    for (int i = 0; i < N; i++) 
    {
        long long a;
        cin >> a;
        auto itr = st.find(a);
        if (itr != st.end()) {
            st.erase(a);
        }else{
            st.insert(a);
        }
    }
    cout << st.size() << endl;
}