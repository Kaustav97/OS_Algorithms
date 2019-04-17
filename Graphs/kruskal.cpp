#include<bits/stdc++.h>
using namespace std;

#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)


struct edge{
 int fr,to,wt;
 edge(int f,int t,int w): fr(f),to(t),wt(w){}
};

class Mycomp{
 public: bool operator()(edge a,edge b){
  return a.wt>b.wt;
 }
};

unordered_map <int,vector<edge > > mp;
priority_queue<edge,vector<edge>, Mycomp > Q;
vector<edge> mst;
unordered_set<int> tree;

void addEdge(int fr,int to,int wt){
 edge e1(fr,to,wt);
 Q.push(e1);
 mp[fr].push_back(e1);
}

void graphdisp(){
 tr(mp){
  cout<<it->first<<" : ";
  rep(it->second.size()){
   edge tmp= it->second[i];
   cout<<"("<<tmp.to<<","<<tmp.wt<<") ";
  }
  cout<<endl;
 }
}

bool noCycle(edge tst){
 if(tree.find(tst.fr)!=tree.end() && tree.find(tst.to)!=tree.end() )
  return false;
 else return true; 
}

int main(){
 int num=6;
 
 //tree= unordered_set(num);
 mp= unordered_map <int,vector<edge> >(num);
 
 addEdge(4,5,5);addEdge(4,3,1);addEdge(3,2,3);
 addEdge(1,2,10);addEdge(1,5,2);addEdge(5,2,6);
 addEdge(4,6,4);
  
 while( mst.size()<=num ){
  edge nw=Q.top(); Q.pop();
  if(noCycle(nw)){
   mst.push_back(nw);
   tree.insert(nw.fr);
   tree.insert(nw.to);
  }
 }

 //tr(tree)cout<<*it<<" "; cout<<endl; 
 tr(mst){
  cout<<it->fr<<" - "<<it->to<<endl;
 }
   
}




























