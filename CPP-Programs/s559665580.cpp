#include <bits/stdc++.h>
using namespace std;

int N;
int A[100010];
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    bool increase = true;
    bool updated = true;
    int cnt = 0;
    for (int i = 0; i < N ; i++)
    {   
        while(i+1 < N && A[i] == A[i+1]) i++;
        
        if (i+1 < N && A[i] < A[i + 1])
        {
            while(A[i]<=A[i+1]){
                i++;
            } 
            
        }
        else if (i+1 < N && A[i] > A[i + 1])
        {
            while(A[i] >= A[i+1]) i++;
        }

        cnt++;
    }

    cout << cnt << endl;

    return 0;
}
