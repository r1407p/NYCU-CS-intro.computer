#include<stdio.h>
int main(){
    float a;scanf("%f",&a);
    float sum ;
    if(a<121)sum =a*1.63;
    else if (a<331)sum =(a-120)*2.38+120*1.63;
    else if (a<501)sum =(a-330)*3.52+210*2.38+120*1.63;
    else if (a<701)sum =(a-500)*4.80+170*3.52+210*2.38+120*1.63;
    else if (a<1001)sum =(a-700)*5.66+200*4.80+170*3.52+210*2.38+120*1.63;
    else sum =(a-1000)*6.41+300*5.66+200*4.80+170*3.52+210*2.38+120*1.63; 
    printf("%.0f",round(sum));
}
