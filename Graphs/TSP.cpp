#include <bits/stdc++.h>
using namespace std;

#define tr(cont)  for(auto it=cont.begin();it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

struct edge{
  int to,wt;
  edge(int t,int w): to(t),wt(w){}
};

std::vector<vector<edge>> grp;

void add_edge(int fr,int to,int wt){
  grp[to].push_back(edge(fr,wt));
  grp[fr].push_back(edge(to,wt));
}

void disp(){
  int p=1;
  for(auto it=grp.begin()+1;it!=grp.end();it++){
    cout<<p<<" : ";p++;
    rep((*it).size())cout<<"("<<(*it)[i].to<<","<<(*it)[i].wt<<") ";
    cout<<endl;
  }
}

int opt=INT_MAX,itr=0;
void dfs(int pos=1,int curr=0,std::set<int> vis=std::set<int>() ){
  itr++;
  cout<<pos<<" , "<<curr<<" , "<<opt<<endl;
  vis.insert(pos);
  int flg=1;
  tr(grp[pos]){
    if(vis.find(it->to)==vis.end()){
      if(curr+it->wt>=opt)return;
      else flg=0,dfs(it->to,curr+it->wt,vis);
    }
  }
  if(flg){
    int bck=0;
    tr(grp[pos])if(it->to==1){bck=it->wt;break;}
    opt=min(opt,curr+bck);
    return;
  }
}

int main(){
   int n,e;
   cout<<"No. of nodes and edges: "<<endl;
   cin>>n>>e;
   grp=std::vector<std::vector<edge>>(n+1);
   cout<<"From To Cost:"<<endl;
   rep(e){
     int f,t,w;
     cin>>f>>t>>w;
     add_edge(f,t,w);
   }
/*
  int n=4,e=6;
  grp=std::vector<std::vector<edge> >(n+1);
  add_edge(1,2,10);add_edge(1,3,15);add_edge(1,4,20);
  add_edge(2,4,25);add_edge(2,3,35);add_edge(3,4,30);
*/
  disp();
  dfs();

  cout<<"\nOptimal : "<<opt<<" - "<<itr<<" iterations"<<endl;
}
