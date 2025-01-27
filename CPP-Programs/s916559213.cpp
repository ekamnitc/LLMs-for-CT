// #include <bits/stdc++.h>

// using namespace std;
// typedef long long ll;

// #define rep(i, n) for (int i = 0; i < (n); i++)
// #define rep2(i, a, b) for (int i = (a); i < (b); ++i)
// #define all(a) (a).begin(), (a).end()
// #define all2(a, b) (a).begin(), (a).begin() + (b)
// #define debug(vari) cerr << #vari << " = " << (vari) << endl;

// int main()
// {
//     int N;
//     cin >> N;

//     vector<int> vec(N);
//     rep(i, N) cin >> vec[i];

//     bool flag = true;
//     rep(i, N)
//     {
//         if (vec[i] % 2 == 0)
//         {
//             if (vec[i] % 3 != 0 || vec[i] % 5 != 0)
//             {
//                 flag = false;
//             }
//         }
//     }

//     cout << (flag ? "APPROVED" : "DENIED") << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    string s;
    cin >> s;

    vector<int> ck(26, 0);
    rep(i, s.size())
    {
        ck[s[i] - 'a']++;
    }

    rep(i, 26)
    {
        if (ck[i] == 0)
        {
            cout << char(i + 'a') << endl;
            return 0;
        }
    }
    cout << "None" << endl;

    return 0;
}