#include<stdio.h>
#include<math.h>

#define rep(n) for(int i=0;i<n;i++)

int main(){
 int num; scanf("%d",&num);
 int arr[10000],brst[10000],b2[10000];
 int ta[10000];
 
 for(int i=0;i<num;i++){
  scanf("%d%d",arr[i],brst[i]);
  b2[i]=brst[i];
 }
 
 int time=0;
 while(1){
  int mn=INT_MAX,p=-1;
  
  rep(num)if(brst[i]<mn && brst[i]>0 && arr[i]<=time){mn=brst[i];p=i; }
  if(mn==INT_MAX)break;
  int nxt;
  rep(num)if(arr[i]>arr[p]){nxt=arr[i];break;}
  time+=min(mn,nxt);
  brst[p]-=min(mn,nxt);
  
  ta[p]=time;
 }
 printf("Arr\tBurst\tTA\n");
 rep(num)printf("%d\t%d\t%d",arr[i],b2[i],ta[i]);
 int tot=0;
 cout<<"Average: ";
 rep(num)tot+=ta[i]-b2[i]-arr[i];
 printf("%f\n",tot/(num*1.0) );
  
}
