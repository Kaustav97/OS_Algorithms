#include <bits/stdc++.h>
using namespace std;

#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

int main(){
  // int n; cin>>n;

  int n=6;
  std::vector<int> r={30,35,15,5,10,20,25};
  std::vector<std::vector<int> > dp(n,std::vector<int>(n,-1));

  rep(n){

    for(int i=0;i<n;i++){
      for(int j=i;j<n;j++){
        if(i==j)dp[i][j]=0;
        if(j==i+1)dp[i][j]=r[i]*r[j]*r[j+1];
        if(dp[i][j-1]>0 && dp[i+1][j]>0)
        dp[i][j]= min(dp[i][j-1] + r[i]*r[j]*r[j+1] , dp[i+1][j]+r[i]*r[i+1]*r[j+1] );
      }
    }

  }

  tr(dp){
    rep((*it).size())cout<<(*it)[i]<<"\t";
    cout<<endl;
  }


}
