#include "math84.h"
#include <assert.h>
static void check(const char*s,int deg,double expected){double v;assert(evaluate84(s,2,7,deg,&v));assert(fabs(v-expected)<1e-9);}
int main(void){check("2+3*4",0,14);check("-2^2",0,-4);check("2^-2",0,.25);check("2^3^2",0,512);check("(2+3)*4",0,20);check("sin(30)",1,.5);check("cos(pi)",0,-1);check("asin(0.5)",1,30);check("sqrt(9)+log(100)+ln(e)",0,6);check("5!",0,120);check("x^2+Ans",0,11);check("1e-3",0,.001);double v;const char*bad[]={"","1/0","sqrt(-1)","2+","2q","sin(","171!","asin(2)","tan(90)","1..2"};for(int i=0;i<10;i++)assert(!evaluate84(bad[i],0,0,1,&v));puts("22 testes matemáticos: PASS");}
