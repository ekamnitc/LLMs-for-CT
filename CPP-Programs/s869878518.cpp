#include <iostream>
#include <algorithm>
using namespace std;

int cnt = 0;
int G[] = {1, 4, 13, 40, 121, 364, 1093, 3280, 9841, 29524, 88573, 265720, 797161};
int A[1000000];
int shellSort(int A[], int n);
void insertionSort(int A[], int n, int g);


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++) cin>>A[i];
    int m = shellSort(A, n);
    cout<<m<<'\n';
    for(int i=m-1; i>0; i--) cout<<G[i]<<' ';
    cout<<"1\n"<<cnt<<'\n';

    for(int i=0; i<n; i++) cout<<A[i]<<'\n';
    return 0;
}

int shellSort(int A[], int n)
{
    int m = 1;
    while(G[m]<n) m++;
    for(int i=m-1; i>=0; i--) insertionSort(A, n, G[i]);
    return m;
}

void insertionSort(int A[], int n, int g)
{
    for(int i=g; i<n; i++) {
        int v=A[i];
        int j=i-g;
        while(j>=0 && A[j]>v) {
            A[j+g] = A[j];
            j-=g;
            cnt++;
        }
        A[j+g]=v;
    }
}