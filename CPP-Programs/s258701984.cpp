#include <bits/stdc++.h>
using namespace std;
int main(){
int N,A,B,C,D;
cin>>N>>A>>B>>C>>D;
string S; cin>>S;
int a1=0;
int a2=0;
if(D>C){
for(int i=A-1;i<D-3;i++){
if(S.at(i)==S.at(i+1)&&S.at(i)=='#'){
a1++;
break;}}}
else{
for(int i=A-1;i<C-3;i++){
if(S.at(i)==S.at(i+1)&&S.at(i)=='#'){
a1++;
break;}}}
if(a1==1){
cout<<"No"<<endl;}
else{
if(D>C){
cout<<"Yes"<<endl;}
else{
for(int i=B-2;i<=D-2;i++){
if(S.at(i)==S.at(i+1)&&S.at(i+1)==S.at(i+2)&&S.at(i)=='.'){
a2++;
break;}}
if(a2==1){
cout<<"Yes"<<endl;}
else{
cout<<"No"<<endl;}}}}
