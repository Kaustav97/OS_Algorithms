#include <bits/stdc++.h>
using namespace std;

#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

int main(){
  cout<<"Number of items and Capacity: "<<endl;
  int n,cap; cin>>n>>cap;
  std::vector<int> wgt(n+1,0),prf(n+1,0);
  cout<<"W[i] and P[i] respectively: "<<endl;
  rep(n)cin>>wgt[i+1]>>prf[i+1];

  std::vector<std::vector<int> > dp(n+1,std::vector<int>(cap+1,0));

  for(int i=1;i<=n;i++){
    for(int j=1;j<=cap;j++){
      if(wgt[i]>j)dp[i][j]=dp[i-1][j];
      else{
        dp[i][j]=max(dp[i-1][j-wgt[i]]+prf[i], dp[i-1][j] );
      }
    }
  }

  // tr(dp){
  //   rep((*it).size())cout<<(*it)[i]<<"\t";
  //   cout<<endl;
  // }
  cout<<"Optimal Profit: "<<dp[n][cap]<<endl;
}
