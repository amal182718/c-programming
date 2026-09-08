#include <stdio.h>
#include <stdlib.h>
struct Node{	
   int coefficient;
   int exponent;
   struct Node*next;
};
int main (){
   struct Node*poly1=NULL,*poly2=NULL,*result=NULL;
   struct Node*temp1,*temp2,*tempResult;
   int terms,coef,exp;
   printf ("Enter the number of terms in the first polynomial :");
   scanf("%d",&terms);
   printf("Enter each term in the format: coefficient : exponent:\n");
   
   for (int i=0; i<terms; i++){
   	printf("Term %d:", i+1);
   	scanf ("%d %d", &coef, &exp);
   
   	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   	newNode->coefficient = coef;
   	newNode->exponent = exp;
   	newNode->next = NULL;
   	
   	if (poly1 ==NULL){
   	    poly1 =newNode;
   	} else{
   	    temp1= poly1;
   	    while (temp1-> next!=NULL){
   	        temp1=temp1->next;
   	    }
   	    temp1->next=newNode;
   	}
   }
   printf ("\nEnter the number of terms in the second polynomial :");
   scanf("%d",&terms);
   printf("Enter each term in the format: coefficient : exponent:\n");
   
   for (int i=0; i<terms; i++){
   	printf("Term %d:", i+1);
   	scanf ("%d %d", &coef, &exp);
    
   	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   	newNode->coefficient = coef;
   	newNode->exponent = exp;
   	newNode->next = NULL;
   	
   	if (poly2 ==NULL){
   	    poly2 = newNode;
   	} else{
   	    temp2= poly2;
   	    while (temp2-> next!=NULL){
   	        temp2=temp2->next;
   	    }
   	    temp2->next=newNode;}}
   	temp1=poly1;
   	temp2=poly2;
   	while (temp1!=NULL || temp2!=NULL){
   	   int coef=0, exp=0;
   	   if (temp1==NULL){
   	      coef=temp2->coefficient;
   	      exp=temp2->exponent;
   	      temp2=temp2->next;
   	}else if (temp2==NULL){
   	      coef=temp1->coefficient;
   	      exp=temp1->exponent;
   	      temp1=temp1->next;
   	      
        }else if(temp1->exponent> temp2->exponent){
   	      coef=temp1->coefficient;
   	      exp=temp1->exponent;
   	      temp1=temp1->next;
   	         	      
        }else if(temp1->exponent< temp2->exponent){
   	      coef=temp2->coefficient;
   	      exp=temp2->exponent;       
   	      temp2=temp2->next;  	
   	      
   	}else{
	      coef=temp1->coefficient+temp2->coefficient;
   	      exp=temp1->exponent;
   	      temp1=temp1->next;
   	      temp2=temp2->next;  	
   	}
   	
   	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   	newNode->coefficient = coef;
   	newNode->exponent = exp;
   	newNode->next = NULL;  	
   	
   	if (result ==NULL){
   	    result= newNode;
   	} else{
   	    tempResult= result;
   	    while (tempResult-> next!=NULL){
   	        tempResult=tempResult->next;
   	    }
   	    tempResult->next=newNode; } }
   	    
   	    
   printf ("\nthe sum of the polynomials is :\n ");
   tempResult=result;
   	    while (tempResult!=NULL){
   	       if (tempResult->coefficient>=0 && tempResult!=result){
   	       printf("+");
   	    }  	
   	printf("%dx^%d",tempResult->coefficient,tempResult->exponent);
   	tempResult= tempResult ->next; }
   	printf("\n");
   return 0; }	
