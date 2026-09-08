#include <stdio.h>
#define PI 3.14159
#define area() (PI*r*r)
#define cyl() (PI*r*r*h)
int main(){
float r,h;
  printf("enter the raduis:");
  scanf("%f",&r);
  printf("%f",area());
  printf("enter the height:");
  scanf("%f",&h);
  printf("%f",cyl());
return 0;
}
