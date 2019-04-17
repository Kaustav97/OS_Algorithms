#include<bits/stdc++.h>
using namespace std;

#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)

int main(){
 int num; cin>>num;
 int arr[10000],brst[10000];
 int qnt=3;
 int ta[10000];
 
 for(int i=0;i<num;i++){
  cin>>arr[i];
  cin>>brst[i];
 }
 vector<pair<int,int> > rdy={make_pair(arr[0],brst[0] )};
 int time=0;
 
 while(rdy.size()!=0){ 
  cout<<time<<"-"<<"P"<<rdy[0].first<<":"<<rdy[0].second<<endl;
  
  //tr(rdy)cout<<"("<<it->first<<":"<<it->second<<") ";
  //cout<<endl;

  
  pair<int,int> prc=rdy[0];
  rdy.erase(rdy.begin());
  time+=min(qnt,prc.second);
  for(int i=0;i<num;i++)if(arr[i]<=time && arr[i]>time-qnt) rdy.push_back(make_pair(arr[i],brst[i])); 
  prc.second-=qnt;
  
  if(prc.second<=0){
   for(int i=0;i<num;i++)if(arr[i]==prc.first)ta[i]=time; 
  }
  
  else rdy.push_back(prc); 
 }
 
 cout<<"DONE - "<<time<<endl;
 
 for(int i=0;i<num;i++) cout<<arr[i]<<"- "<<brst[i]<<" TA:" <<ta[i]<<endl;
 cout<<"Average Wait :";
 int tot=0;
 for(int i=0;i<num;i++)tot+=ta[i]-brst[i]-arr[i];
 cout<<(tot)/(num*1.0)<<endl;
 
  
}

