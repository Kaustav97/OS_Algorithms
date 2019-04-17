#include <sys/wait.h>
#include <unistd.h>
#include <bits/stdc++.h>
#include <sys/types.h>

#define tr(cont) for(auto it=cont.begin();it!=cont.end();it++)

using namespace std;

int main(){
	vector<int> r1={1,23,4,5};
	tr(r1) cout<<*it<<" ";	
	cout<<endl;
	int pid= fork();

	if(pid==0){
	
		cout<<"Child ID - "<<getpid()<<"  Parent - "<<getppid()<<endl;
	}
	else{
		cout<<"Parent ID - "<<getpid()<<" Parent - "<<getppid()<<endl;
	}
}
