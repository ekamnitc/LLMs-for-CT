#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void merge(int l,int mid,int r,vector<pair<int,int>> &array){
    int n = mid - l;
    int m = r - mid;
    vector<pair<int,int>> left_array(n),right_array(m);
    for(int i=0;i<n;i++){
        left_array.at(i) = array.at(l+i);
    }
    for(int i=0;i<m;i++){
        right_array.at(i) = array.at(mid+i);
    }
    pair<int,int> a = make_pair(1000000,1000000);
    left_array.push_back(a);
    right_array.push_back(a);
    int li=0,ri=0;
    for(int i=0;i<r-l;i++){
        if(left_array.at(li).first < right_array.at(ri).first){
            array.at(l+i) = left_array.at(li);
            li++;
        }else{
            array.at(l+i) = right_array.at(ri);
            ri++;
        }
    }

}

void mergesort(int l, int r, vector<pair<int,int>> &array){
    if(l+1 < r){
        int mid = (l+r)/2;
        mergesort(l,mid,array);
        mergesort(mid,r,array);
        merge(l,mid,r,array);
    }

}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> array(n);
    for(int i=0;i<n;i++){
        cin >> array.at(i).first;
        array.at(i).second = i+1;
    }
    mergesort(0,n,array);
    for(int i=0;i<n;i++){
        cout << array.at(i).second << " ";
    }
    cout << endl;
}