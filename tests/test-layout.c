#define main app_main
#include "baetacalc.c"
#undef main
#include <assert.h>
static void check(void){buildlayout();assert(keycount<=80);for(int i=0;i<keycount;i++){SDL_Rect a=layout[i].box;assert(a.x>=0&&a.y>=0&&a.w>0&&a.h>0&&a.x+a.w<=1024&&a.y+a.h<=768);for(int j=i+1;j<keycount;j++){SDL_Rect b=layout[j].box;assert(a.x+a.w<=b.x||b.x+b.w<=a.x||a.y+a.h<=b.y||b.y+b.h<=a.y);}}}
int main(void){for(int en=0;en<2;en++){english=en;homeScreen=1;check();homeScreen=0;for(int m=0;m<5;m++){mode=m;for(int edit=0;edit<2;edit++){editing=edit;settingsPanel=0;for(int panel=0;panel<3;panel++){mathPanel=panel;for(int sci=0;sci<2;sci++){scientific=sci;for(int kind=0;kind<4;kind++){solverKind=kind;polyDegree=6;solverN=3;solverChooser=0;check();if(mode==4&&!editing){solverChooser=1;check();}}}}}settingsPanel=1;editing=0;check();settingsPanel=0;}}mode=4;homeScreen=editing=settingsPanel=solverChooser=0;solverKind=1;solverStatus=8;realCount=16;check();puts("Todos os ambientes PT/EN: botões dentro do ecrã e sem sobreposição PASS");}
