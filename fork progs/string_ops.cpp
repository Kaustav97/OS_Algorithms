#include<unistd.h>
#include<sys/wait.h>
#include<bits/stdc++.h>

using namespace std;
int main(int argc,char** argv ){
 
 int p=fork();
 
 if(p>0){
  wait(NULL);
  for(int i=0;i<argc;i++)cout<<argv[i]<<" ";
  cout<<endl;
 }
 
 else{
   for(int i=1;i<argc;i++){
    for(int j=2;j<argc;j++){
     if( strcmp(argv[j],argv[j-1])<0 ){
      char tmp[100];
      strcpy(tmp,argv[j]);
      strcpy(argv[j],argv[j-1] );
      strcpy(argv[j],tmp );
     }     
    }
   }
   for(int i=0;i<argc;i++)cout<<argv[i]<<" ";
   cout<<"Child done "<<endl;
 } 
}
