#ifndef BAETA_FRACTIONS_H
#define BAETA_FRACTIONS_H
#include <stdint.h>
#include <float.h>
/* Display reconstruction only. Never feed displayed text back into arithmetic. */
static int fractionValue(double value,int64_t*num,int64_t*den){if(!isfinite(value)||fabs(value)>9e12)return 0;double whole=floor(fabs(value)),f=fabs(value)-whole;if(f==0){*num=(int64_t)value;*den=1;return 1;}int64_t p0=0,p1=1,q0=1,q1=0;double z=f;for(int k=0;k<64;k++){double ad=floor(z);if(ad>1000000)break;int64_t a=(int64_t)ad;if(p1&&a>(INT64_MAX-p0)/p1)break;if(q1&&a>(1000000-q0)/q1)break;int64_t p=a*p1+p0,q=a*q1+q0;if(q<=0||q>1000000)break;if(p>0&&p<q&&fabs((double)p/q-f)<=16*DBL_EPSILON){long double total=(long double)whole*q+p;if(total>INT64_MAX)return 0;*num=(int64_t)total*(value<0?-1:1);*den=q;return 1;}p0=p1;p1=p;q0=q1;q1=q;double rem=z-ad;if(rem<DBL_EPSILON)break;z=1/rem;}return 0;}
static void numberText(double value,char*out,size_t size){int64_t a,b;if(fractionView&&fractionValue(value,&a,&b)&&(b&(b-1))==0&&(long double)a/b==(long double)value){if(b==1)snprintf(out,size,"%lld",(long long)a);else snprintf(out,size,"%lld/%lld",(long long)a,(long long)b);}else snprintf(out,size,"%.17g",value);}
#endif
