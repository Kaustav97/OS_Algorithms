#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

struct point{
	int x,y;
	point(int a,int b): x(a),y(b){}
};

bool cmp(point a,point b){
	return a.y<b.y;
}

float dist(point p1,point p2){
	return sqrt( pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2) );
}

float distline(point p1,int x){
	return dist(p1,point(x,p1.y) );
}

void disp(point p1){
	cout<<"("<<p1.x<<","<<p1.y<<") ";
}

float ClosestPair(vector<point> v,int r=0){
	//tr(v)disp(*it);
	//if(r==3)return 0.0;
	
	if(v.size()<2)return INT_MAX;
	float sep=0;
	tr(v)sep+=it->x;
	sep /= (v.size()*1.0);
	//cout<<sep<<endl;
	
	vector<point> lft,rgt;
	
	tr(v)if(it->x<sep)lft.push_back(*it);
	tr(v)if(it->x>sep)rgt.push_back(*it);
	
	float m1,m2,del;
	m1=ClosestPair(lft,r+1);
	m2=ClosestPair(rgt,r+1);
	del= min( m1,m2 );
	
	tr(v){
		if(distline(*it,sep)>del ){
			v.erase(it);
			it--;
		}
	}
	sort(v.begin(),v.end(),cmp );	
	
	for(int i=1;i<v.size()-1;i++){
		int k=1;
		while( i+k <=v.size() && v[i+k].y< (v[i].y + del) ){
			del = min(del , dist(v[i],v[i+k]) );
			k++;
		}
	}
		
	return del;
}

int main(){
	vector<point> all;
	all.push_back(point(0,0));all.push_back(point(0,1));
	all.push_back(point(1,3));all.push_back(point(4,4));
	all.push_back(point(4,6));all.push_back(point(3,4));
	
	int len=all.size();
//	for(int i=0;i<len;i++){
//		for(int j=i+1;j<len;j++) cout<<dist(all[i],all[j])<<endl;
//	}
	
	cout<<ClosestPair(all)<<endl;
	
}
