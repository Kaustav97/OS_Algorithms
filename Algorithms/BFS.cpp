#include <bits/stdc++.h>
using namespace std;

#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

unordered_map<int,vector<int> >mp;
int *path;
int num;

void addEdge(int fr,int to){
  mp[fr].push_back(to);
  mp[to].push_back(fr);
}

void disp(){
  tr(mp){
    cout<<it->first<<": ";
    rep(it->second.size())cout<<it->second[i]<<",";
    cout<<endl;
  }
}

int* BFS(int st){
  queue<int> Q;
  bool visited[num+1]={0};
  path= new int[num+1];
  rep(num)path[i+1]=(i+1);
  visited[st]=1;
  // cout<<st<<" ";
  Q.push(st);

  while(!Q.empty()){
    int cur=Q.front();

    rep( mp[cur].size() ){
      int adj=mp[cur][i];
      if( visited[adj]==0){
        Q.push(adj);
        // cout<<adj<<" ";
        path[adj]=cur;
        visited[adj]=1;
      }
    }
    Q.pop();
  }
  return path;

}

void findPath(int fr,int to,int path[]){
  if(to==fr){cout<<fr<<"-> ";return;}
  findPath(fr,path[to],path);
  cout<<to<<" -> ";
}

int* DFS(int st,int *visited){
  // cout<<st<<" ";
  visited[st]=1;

  rep( mp[st].size() ){
    int adj=mp[st][i];
    if(visited[adj]==0){
      visited[adj]=1;
      path[adj]=st;
      DFS(adj,visited);
    }
  }
}


int main(){
  num=7;
  mp=unordered_map<int,vector<int > >(num);

  // Initialize Graph
  addEdge(4,5);addEdge(4,3);addEdge(3,2);
  addEdge(1,2);addEdge(1,5);addEdge(5,2);
  addEdge(4,6); addEdge(7,7);

  cout<<"Graph: "<<endl;
  disp();

  int fr,to;
  cin>>fr>>to;
  path=BFS(fr);
  cout<<"\nBFS Path: "<<endl;
  if(path[to]==to)cout<<"No Path";
  else if(path[to]==fr)cout<<fr<<" -> "<<to;
  else findPath(fr,to,path);
  cout<<endl;

  path=new int[num+1];
  rep(num)path[i+1]=(i+1);

  cout<<"DFS Path: "<<endl;
  int visited[num+1]={0};
  DFS(1,visited);
  // rep(num)cout<<path[i+1]<<" ";
  // cout<<endl;
  if(path[to]==to)cout<<"No Path";
  else findPath(fr,to,path);
  cout<<endl;


}
