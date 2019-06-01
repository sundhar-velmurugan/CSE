#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<iostream.h>

int draw(){  int gd = DETECT, gm;
    char a[]="C:/TC/BGI";
   initgraph(&gd, &gm, a);

   settextstyle(8,0,2);
   char b[]="H";
   outtextxy(320,0,b);

   setlinestyle(0,0,2);
   /* Draw X and Y Axis */   setcolor(3);
   line(90,410,90,50);
   line(90,410,590,410);
   line(85,60,90,50);
   line(95,60,90,50);
   line(585,405,590,410);
   line(585,415,590,410);             setcolor(13);
/*
   outtextxy(65,60,"Y");
   outtextxy(570,420,"X");
   outtextxy(70,415,"O");
   /* Draw bars on screen */
   setfillstyle(10, 13);
   bar3d(150,80,200,410,15,2);
   bar3d(225,100,275,410,15,2);
   bar3d(300,120,350,410,15,2);
   bar3d(375,170,425,410,15,2);

   closegraph();
   return 1;
}

int main(){
    draw();
    getch();
    return 0;
}
