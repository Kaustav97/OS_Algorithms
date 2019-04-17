#include <bits/stdc++.h>
using namespace std;

#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

int opt=0,sum=0;
int n,cap;
std::vector<int> wgt,prf;

int itr=0;

void select(int pos,int cap,int curr=0){
	itr++;
	if(pos==wgt.size()){
		if(curr>opt)opt=curr;
		return;
	}

	if(wgt[pos]>cap){
		select(pos+1,cap,curr);
	}
	else{
		//take
		select(pos+1,cap-wgt[pos],curr+prf[pos]);

		//leave
		if(sum-curr-prf[pos]<=opt)return;
		select(pos+1,cap,curr);
	}
}

int main(){
	cout<<"Number of items and Capacity: "<<endl;
	int n,cap;
	cin>>n>>cap;

	wgt=std::vector<int>(n+1,0);
	prf= vector<int>(n+1,0);
	cout<<"W[i] and P[i] respectively: "<<endl;
	rep(n)cin>>wgt[i+1]>>prf[i+1];

	tr(prf)sum+=(*it);

	select(0,cap);
	cout<<opt<<" - "<<itr<<" iterations"<<endl;
}
