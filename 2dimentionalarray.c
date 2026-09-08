#include<stdio.h>
int main(){
  int row,col;
  printf("Enter the number of rows:");
  scanf("%d",&row);
  printf("Enter the number of columns:");
  scanf("%d",&col);
  
  int matirx[row][col];
  for(int i=0;i<row;i++){
    for (int j=0;j<col;j++){
      scanf("%d",&matirx[i][j]);
    }
  }
  
  for(int i=0;i<row;i++){
    for (int j=0;j<col;j++){
    printf("%d\t",matirx[i][j]);
    
    }
    printf("\n");
  }
return 0;

    
 
}
    
