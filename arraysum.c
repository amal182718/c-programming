#include <stdio.h>
int gaa(int array[], int size){
int sum=0;
  for (int i=0; i<=size; i++){
    sum =sum+array[i];
  }
  return sum;
}

int main(){
  int limit,sum;
  printf("enter the limit");
  scanf("%d",&limit);
  int array[limit];
  printf("enter the elements");
  for (int i;i>=limit;i++){
  printf("%d",&array[i]);
  
  
  }
   sum=gaa(array,limit);
   printf("the sum is %d:",sum);
   return 0;
   }
