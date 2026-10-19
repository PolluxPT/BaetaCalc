#define main app_main
#include "baetacalc.c"
#undef main
#include <assert.h>
int main(void){running=1;strcpy(expr,"123");ans=123;action(5);assert(running&&exitDialog&&exitChoice==0);action(42);assert(!strcmp(expr,"123"));requestExit();assert(exitChoice==0);assert(exitClick(180,430));assert(running&&!exitDialog);action(5);SDL_Event e={0};e.type=0x603;e.bytes[12]=1;exitEvent(&e);assert(running&&!exitDialog&&ans==123);action(5);e.bytes[12]=0;exitEvent(&e);assert(running&&!exitDialog);action(5);e.type=0x602;e.bytes[13]=2;exitEvent(&e);assert(exitChoice==1);e.type=0x603;e.bytes[12]=0;exitEvent(&e);assert(!running&&!exitDialog);running=1;action(5);exitClick(700,440);assert(!running);puts("Confirmation sortie: annulation par défaut, B, D-pad + A et toucher PASS");}
