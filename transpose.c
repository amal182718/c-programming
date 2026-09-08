#include<stdio.h>
int main(){
  int row,col;
   printf("\n Enter the number of rows:");
  scanf("%d",&row);
  printf("\n Enter the number of columns:");
  scanf("%d",&col);
  int m1[row][col];
  int m2[row][col];
  
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      scanf("%d",&m1[i][j]);
    }
  }

  for(int i=0;i<col;i++){
    for(int j=0;j<row;j++){
      m2[j][i]=m1[i][j];
    }
  }
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      printf("%d\t",m2[i][j]);
    }
    printf("\n");
  }

