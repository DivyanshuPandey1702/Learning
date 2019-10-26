#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;

int main(){

    system("cls");

   char SnakePosition[100][100],ch=0;
   int DirX,DirY,Dir=68,FoodLocationX,FoodLocationY,Score=0;
   DirX=rand()%20;
   DirY=rand()%40;
   FoodLocationX=rand()%20;
   FoodLocationY=rand()%40;

 while(1){

   for(int i=0;i<20;i++){
      for(int j=0;j<40;j++){
	         SnakePosition[i][j]=' ';
      }
   }
  // for(int i=0;i<=Score;i++){
     SnakePosition[DirX][DirY]='S';
  // }
   SnakePosition[FoodLocationX][FoodLocationY]='F';

   if(DirX==FoodLocationX  && DirY==FoodLocationY){
     Score++;
     FoodLocationX=rand()%20;
     FoodLocationY=rand()%40;
   }

  if(!_kbhit()){

    cout<<"*****************************************";

    for(int i=0;i<20;i++){
      cout<<"*";
       for(int j=0;j<40;j++){
	  cout<<SnakePosition[i][j];
       }
       cout<<"*"<<endl;
    }

    cout<<"******************************************"<<endl;

    switch(Dir){
	case 100:
	case 68: Dir=68;
		DirY++;
		break;
	case 97:
	case 65: Dir=65;
		DirY--;
		break;
	case 119:
	case 87: Dir=87;
		DirX--;
		break;
	case 115:
	case 83: Dir=83;
		DirX++;
		break;
    }
    if(DirY==40 && Dir==68){
      DirY=0;
    }
    if(DirX==20 && Dir==83){
      DirX=0;
    }
    if(DirY==0 && Dir==65){
      DirY=40;
    }
    if(DirX==0 && Dir==87){
      DirX=20;
    }
  }
  else{
     ch=_getch();
     if(ch==27){
       break;
     }
     Dir=int(ch);
  }

  cout<<"Score: "<<Score;

  Sleep(100);
  system("cls");
 }
 return 0;
}
