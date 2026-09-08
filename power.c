#include <stdio.h>
int mul(int a,int b){
if(b==0){
 return 1;
 }
 else {
 return a*mul(a,b-1);
 }
}  
  
  
  
  
int main(){
  int a,b;
  printf("enter the number and power:");
  scanf("%d%d",&a,&b);
  printf("%d",mul(a,b));
    
  return 0;
}
