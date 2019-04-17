#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

int main(){
 //int n,cap; cin>>n>>cap;
 //vector<int> wgt(n),prf(n);
 //rep(n)cin>>wgt[i]>>prf[i];
 vector<int> wgt={5,7,2,10},prf={6,8,3,11};
 vector<float> dens(4);

 rep(wgt.size())dens[i] = prf[i]/(wgt[i]*1.0);
 tr(dens)cout<<*it<<" , ";
 cout<<endl;
 int cap=12,ans=0;
 while(cap>0){
 	int mx=0;
 	rep(dens.size()) if(dens[i]>dens[mx]) mx=i;
 	cap-= wgt[mx];
 	if(cap>=0){ans+=prf[mx]; cout<<"take "<<mx<<endl;  }
 	dens[mx]=-1;
 }
 cout<<ans<<endl;
}
