#include <bits/stdc++.h>
using namespace std;

#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

unordered_map<int,vector<pair<int,int> > >mp;
int num;

void addEdge(int fr,int to,int wt){
  mp[fr].push_back(make_pair(to,wt));
  mp[to].push_back(make_pair(fr,wt));
}

void disp(){
  tr(mp){
    cout<<it->first<<": ";
    rep(it->second.size())cout<<"("<<it->second[i].first<<","<<it->second[i].second<<") ";
    cout<<endl;
  }
}

void BFS(int st){
  queue<int> Q;
  bool visited[num+1]={0};
  int path[num+1];
  rep(num)path[i+1]=(i+1);

  visited[st]=1;
  cout<<st<<" ";
  Q.push(st);

  while(!Q.empty()){
    int cur=Q.front();

    rep( mp[cur].size() ){
      int adj=mp[cur][i].first;
      if( visited[adj]==0){
        Q.push(adj);
        cout<<adj<<" ";
        visited[adj]=1;
      }
    }
    Q.pop();
  }
  cout<<endl;
}

void DFS(int st,int *visited){
  cout<<st<<" ";
  visited[st]=1;
  rep( mp[st].size() ){
    int adj=mp[st][i].first;
    if(visited[adj]==0){
      visited[adj]=1;
      DFS(adj,visited);
    }
  }

}

int main(){
  num=6;
  mp=unordered_map<int,vector<pair<int,int> > >(num);

  // Initialize Graph
  addEdge(4,5,2);addEdge(4,3,1);addEdge(3,2,3);
  addEdge(1,2,10);addEdge(1,5,2);addEdge(5,2,6);
  addEdge(4,6,4);

  cout<<"Graph: "<<endl;
  disp();
  cout<<"\nBFS Traversal: "; BFS(1);
  cout<<"DFS Traversal: ";
  int visited[num+1]={0};
  DFS(1,visited);
  cout<<endl;

}
