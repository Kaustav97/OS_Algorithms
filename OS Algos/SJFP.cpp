#include<bits/stdc++.h>
using namespace std;

#define rep(n) for(int i=0;i<n;i++)

int main(){
 int num; cin>>num;
 int arr[10000],brst[10000],b2[10000];
 int ta[10000];
 
 for(int i=0;i<num;i++){
  cin>>arr[i];
  cin>>brst[i];
  b2[i]=brst[i];
 }
 
 int time=0;
 while(true){
  int mn=INT_MAX,p=-1;
  
  rep(num)if(brst[i]<mn && brst[i]>0 && arr[i]<=time){mn=brst[i];p=i; }
  if(mn==INT_MAX)break;
  int nxt;
  rep(num)if(arr[i]>arr[p]){nxt=arr[i];break;}
  time+=min(mn,nxt);
  brst[p]-=min(mn,nxt);
  
  ta[p]=time;
 }
 cout<<"Arr\tBurst\tTA"<<endl;
 rep(num)cout<<arr[i]<<" \t "<<b2[i]<<" \t "<<ta[i]<<endl;
 int tot=0;
 cout<<"Average: ";
 rep(num)tot+=ta[i]-b2[i]-arr[i];
 cout<<tot/(num*1.0)<<endl;
  
}
