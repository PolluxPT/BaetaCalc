#ifndef MATH84_H
#define MATH84_H
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef struct {const char *p; double x,y,z,ans; int deg,error,depth; unsigned allowed;} Parser;
static void space(Parser *p){while(isspace((unsigned char)*p->p))p->p++;}
static double sum84(Parser*);
static double fact84(Parser*p,double a){if(a<0||a>170||floor(a)!=a){p->error=1;return NAN;}return tgamma(a+1);}
static double atom84(Parser*p){space(p);if(++p->depth>64){p->error=1;p->depth--;return NAN;}double a=NAN;
 if(*p->p=='('){p->p++;a=sum84(p);space(p);if(*p->p!=')')p->error=1;else p->p++;}
 else if(isdigit((unsigned char)*p->p)||*p->p=='.'){char*end;a=strtod(p->p,&end);if(end==p->p)p->error=1;p->p=end;}
 else if(isalpha((unsigned char)*p->p)){char name[24];int n=0;while(isalpha((unsigned char)*p->p)){if(n<23)name[n++]=tolower((unsigned char)*p->p);p->p++;}name[n]=0;
  if(!strcmp(name,"x")){a=p->x;if(!(p->allowed&1))p->error=1;}else if(!strcmp(name,"y")){a=p->y;if(!(p->allowed&2))p->error=1;}else if(!strcmp(name,"z")){a=p->z;if(!(p->allowed&4))p->error=1;}else if(!strcmp(name,"ans"))a=p->ans;else if(!strcmp(name,"pi"))a=3.14159265358979323846;else if(!strcmp(name,"e"))a=2.718281828459045;
  else {space(p);if(*p->p!='('){p->error=1;}else{p->p++;double v=sum84(p);space(p);if(*p->p!=')')p->error=1;else p->p++;double r=p->deg?3.14159265358979323846/180:1;
   if(!strcmp(name,"sin"))a=sin(v*r);else if(!strcmp(name,"cos"))a=cos(v*r);else if(!strcmp(name,"tan")){a=tan(v*r);if(fabs(cos(v*r))<1e-14)p->error=1;}
   else if(!strcmp(name,"asin"))a=asin(v)/r;else if(!strcmp(name,"acos"))a=acos(v)/r;else if(!strcmp(name,"atan"))a=atan(v)/r;
   else if(!strcmp(name,"log"))a=log10(v);else if(!strcmp(name,"ln"))a=log(v);else if(!strcmp(name,"sqrt"))a=sqrt(v);else if(!strcmp(name,"abs"))a=fabs(v);else if(!strcmp(name,"exp"))a=exp(v);else if(!strcmp(name,"sinh"))a=sinh(v);else if(!strcmp(name,"cosh"))a=cosh(v);else if(!strcmp(name,"tanh"))a=tanh(v);else if(!strcmp(name,"floor"))a=floor(v);else if(!strcmp(name,"ceil"))a=ceil(v);else if(!strcmp(name,"round"))a=round(v);else p->error=1;
  }}
 }else p->error=1;
 p->depth--;space(p);while(*p->p=='!'){p->p++;a=fact84(p,a);space(p);}return a;
}
static double unary84(Parser*);
static double power84(Parser*p){if(++p->depth>64){p->error=1;p->depth--;return NAN;}double a=atom84(p);space(p);if(*p->p=='^'){p->p++;a=pow(a,unary84(p));}p->depth--;return a;}
static double unary84(Parser*p){space(p);if(*p->p=='+'||*p->p=='-'){int neg=*p->p++=='-';if(++p->depth>64){p->error=1;p->depth--;return NAN;}double a=unary84(p);p->depth--;return neg?-a:a;}return power84(p);}
static double product84(Parser*p){double a=unary84(p);space(p);while(*p->p=='*'||*p->p=='/'||*p->p=='('||isalpha((unsigned char)*p->p)){int div=0;if(*p->p=='*'||*p->p=='/')div=*p->p++=='/';double b=unary84(p);if(div&&b==0)p->error=1;a=div?a/b:a*b;space(p);}return a;}
static double sum84(Parser*p){double a=product84(p);space(p);while(*p->p=='+'||*p->p=='-'){int sub=*p->p++=='-';double b=product84(p);a=sub?a-b:a+b;space(p);}return a;}
static int evaluateXYZ(const char*s,double x,double y,double z,double ans,int deg,unsigned allowed,double*out){Parser p={.p=s,.x=x,.y=y,.z=z,.ans=ans,.deg=deg,.allowed=allowed};double a=sum84(&p);space(&p);if(p.error||*p.p||!isfinite(a))return 0;*out=a;return 1;}
static int evaluate84(const char*s,double x,double ans,int deg,double*out){return evaluateXYZ(s,x,0,0,ans,deg,1,out);}
#endif
