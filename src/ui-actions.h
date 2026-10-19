static void cursorMove(int dx,int dy){evaluated=0;cursor+=dx;if(dy)cursor=dy<0?0:strlen(active());if(cursor<0)cursor=0;if(cursor>(int)strlen(active()))cursor=strlen(active());}
static int commitEdit(void){if(setting>=0){enter();if(setting>=0)return 0;}else save();editing=0;focusId=settingsPanel?230:mode==4?220+solverField:106;return 1;}
static void action(int k){if(exitDialog)return;
 if(k==82){save();homeScreen=1;editing=solverChooser=settingsPanel=0;setting=-1;selected=1;focusId=-1;return;}
 if(k==59){toggleLanguage();return;}if(k==5){requestExit();return;}
 if(k==0||k==1||k==78){homeScreen=0;editing=settingsPanel=0;setting=-1;mathPanel=0;selected=0;if(k==78){coreAction(k);solverChooser=1;focusId=200;}else{coreAction(k);solverChooser=0;focusId=k==0?36:100+target;}return;}
 if(homeScreen)return;
 if(k==63){if(mode==0)coreAction(41);else if(editing&&mode==4&&solverKind!=0&&setting<0)append("=");else if(editing)commitEdit();return;}
 if(k==40&&!editing&&mode!=0){if(settingsPanel){settingsPanel=0;return;}if(mode==2||mode==3){action(205);return;}if(mode==4&&!solverChooser){solverChooser=1;selected=0;return;}action(82);return;}
 if(k==92){fractionView=!fractionView;clearMessage();return;}
 if(k==90||k==91||k==93){mathPanel=k==93?2:k==91;selected=0;return;}
 if(k==84){commitEdit();return;}
 if(k==85){int field=solverField,slot=target,window=setting;if(!commitEdit())return;if(window>=0){setting=(window+1)%5;double v[]={xmin,xmax,ymin,ymax,tableStep};snprintf(winexpr,512,"%.12g",v[setting]);}else if(mode==4)solverField=(field+1)%fieldCount();else if(mode==1)target=(slot+1)%6;editing=1;cursor=strlen(active());return;}
 if(k==204){solverChooser=1;editing=0;selected=0;focusId=200;return;}
 if(k>=200&&k<=203){solverKind=k-200;solverField=solverStatus=resultPage=0;solverChooser=0;editing=0;mathPanel=0;focusId=220;save();return;}
 if(k>=220&&k<227){solverField=k-220;if(solverField<fieldCount()){editing=1;mathPanel=0;focusId=36;cursor=strlen(active());selected=0;}return;}
 if(k>=100&&k<=105){target=k-100;cursor=strlen(active());return;}
 if(k==106){editing=1;mathPanel=0;focusId=36;cursor=strlen(active());selected=0;return;}
 if(k==210||k==211){int type=k-210;if(curveType[target]!=type)coreAction(60);cursor=strlen(active());return;}
 if(k>=212&&k<=214){activeShade()[target]=k==212?0:k==213?-1:1;if(!solverPlot)save();return;}
 if(k==47){settingsPanel=1;editing=0;setting=-1;selected=0;return;}
 if(k>=230&&k<=234){setting=k-230;double v[]={xmin,xmax,ymin,ymax,tableStep};snprintf(winexpr,512,"%.12g",v[setting]);editing=1;mathPanel=0;cursor=strlen(active());return;}
 if(k==206){settingsPanel=0;editing=0;setting=-1;return;}
 if(k==205){settingsPanel=editing=0;setting=-1;if(solverPlot){mode=4;solverChooser=0;}else{mode=1;solverPlot=0;}return;}
 if(k>=260&&k<=263){pan84(k==260?-1:k==263?1:0,k==261?-1:k==262?1:0);return;}
 if(k==2||k==3){editing=settingsPanel=solverChooser=0;setting=-1;coreAction(k);return;}
 if(k==73){coreAction(k);editing=solverChooser=0;return;}
 if(k==74){coreAction(k);editing=settingsPanel=0;return;}
 if(k==75){coreAction(k);editing=0;return;}
 if(k==76){coreAction(k);return;}
 if((k==50||k==51||k==52||k==53)&&(editing||mode==0)){cursorMove(k==50?-1:k==53?1:0,k==51?-1:k==52?1:0);return;}
 if(k==41&&editing){if(setting<0&&mode==4&&solverKind!=0){append("=");return;}commitEdit();return;}
 coreAction(k);}
