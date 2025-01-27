#include<bits/stdc++.h>
using namespace std;

int main()
{
    int c,k;
    int sum = 0,money = 0;
    vector<int> summoney;

    cin >> c >> k;
    
    for (int i = 0; i < c; i++)
    {
        cin >> money;
        summoney.push_back(money);
    }

    sort(summoney.begin(),summoney.end());

    for (int j = 0; j < k; j++)
    {
        sum += summoney.at(j);
    }

    cout << sum << endl;
}