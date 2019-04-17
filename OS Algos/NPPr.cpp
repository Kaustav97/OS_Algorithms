#include<bits/stdc++.h>
using namespace std;

#define rep(n) for(int i=0;i<n;i++)

int main(){
 int num; cin>>num;
 int arr[10000],brst[10000],b2[10000];
 int ta[10000],prt[10000];
 
 for(int i=0;i<num;i++){
  cin>>arr[i]>>brst[i]>>prt[i];
  b2[i]=brst[i];
 }
 int time=0;
 while(true){
  int hp=INT_MAX,p=-1,mn=INT_MAX;
  rep(num)if(prt[i]<hp && arr[i]<=time){mn=brst[i];p=i;hp=prt[i]; }
  if(mn==INT_MAX)break;
  brst[p]=INT_MAX;
  time+=mn;
  ta[p]=time;
 }
 
 rep(num)cout<<arr[i]<<" - "<<b2[i]<<" - "<<ta[i]<<endl;
 int tot=0;
 cout<<"Average: ";
 rep(num)tot+=ta[i]-b2[i]-arr[i];
 cout<<tot/(num*1.0)<<endl;
  
}
