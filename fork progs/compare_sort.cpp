#include <sys/wait.h>
#include <unistd.h>
#include <bits/stdc++.h>
#include <sys/types.h>

using namespace std;

int main(int argc, char** argv ){
	string arr[100];
	int n; cin>>n;
	for (int i = 0; i < n; ++i) cin>>arr[i];

	if(fork()>0){

		if(fork()>0){
			cout<<"Parent done "<<endl;

		}
		else{
			// SELECTIONSORT
			for(int i=0; i<n;i++ ){				
				int mn=i;
				for(int j=i+1;j<n;j++){
					if ( arr[j]<arr[i] ) mn=j;
				}
				string tmp=arr[i];
				arr[i]=arr[mn];
				arr[mn]=tmp;
			}
			for (int i = 0; i < n; ++i)cout<<arr[i]<<" ";

			cout<<" - child 2 done"<<getpid()<<endl;
		}
	}
	else{
		// BUBBLESORT
		for(int i=0; i<n; i++){
			for(int j=0; j<n-1;j++ )
				if(arr[j]>arr[j+1]){
					string tmp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=tmp;
				}
		}

		for (int i = 0; i < n; ++i)cout<<arr[i]<<" ";

		cout<<" - child 1 done"<<getpid()<<endl;
	}
}