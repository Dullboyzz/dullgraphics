/*
AIM: Program to create a house like figure and perform the following operations.
i. Scaling about the origin followed by translation.
ii. Scaling with reference to an arbitrary point.
iii. Reflect about the line y = mx + c.

inpust: 

1.Scaling about the origin.
2.Scaling about an arbitrary point.
3.Reflection about the line y=mx+c.
4.Exit
Enter the choice:1
Enter the x- and y-scaling factors:10 20

1.Scaling about the origin.
2.Scaling about an arbitrary point.
3.Reflection about the line y=mx+c.
4.Exit
Enter the choice:2
Enter the x- and y-scaling factors:80 50
Enter the x- and y-co-ordinate of the point:60 50

*/

//Code:-

#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
void reset(int h[][2])
{
 int val[9][2]={
 {50,50},{75,50},{75,75},{100,75},{100,50},
 {125,50},{125,100},{87,125},{50,100}
 };
 int i;
 for(i=0;i<9;i++)
 {
 h[i][0]=val[i][0]-50;
 h[i][1]=val[i][1]-50;
 }
}
void draw(int h[][2])
{
 int i;
 setlinestyle(DOTTED_LINE,0,1);
 line(320,0,320,480);
 line(0,240,640,240);
 setlinestyle(SOLID_LINE,0,1);
 for(i=0;i<8;i++)
 line(320+h[i][0],240-h[i][1],320+h[i+1][0],240-h[i+1][1]);
 line(320+h[0][0],240-h[0][1],320+h[8][0],240-h[8][1]);
}
void rotate(int h[][2],float angle)
{
 int i;
 for(i=0;i<9;i++)
 {
 int xnew,ynew;
 xnew=h[i][0]*cos(angle)-h[i][1]*sin(angle);
 ynew=h[i][0]*sin(angle)+h[i][1]*cos(angle);
 h[i][0]=xnew;h[i][1]=ynew;
 }
}
void scale(int h[][2],int sx,int sy)
{
 int i;
 for(i=0;i<9;i++)
 {
 h[i][0]*=sx;
 h[i][1]*=sy;
 }
}
void translate(int h[][2],int dx,int dy)
{
 int i;
 for(i=0;i<9;i++)
 {
 h[i][0]+=dx;
 h[i][1]+=dy;
 }
}
void reflect(int h[][2],int m,int c)
{
 int i;
 float angle;
 for(i=0;i<9;i++);
 h[i][1]-=c;
 angle=M_PI/2-atan(m);
 rotate(h,angle);
 for(i=0;i<9;i++)
 h[i][0]=-h[i][0];
 angle=-angle;
 rotate(h,angle);
 for(i=0;i<9;i++)
 h[i][1]+=c;
}
void ini()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
}
void dini()
{
 getch();
 closegraph();
}
int main()
{
 int h[9][2],sx,sy,x,y,m,c,choice;
 do{
 printf("1.Scaling about the origin.\n");
 printf("2.Scaling about an arbitrary point.\n");
 printf("3.Reflection about the line y=mx+c.\n");
 printf("4.Exit\n");
 printf("Enter the choice:");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:printf("Enter the x- and y-scaling factors:");
 scanf("%d%d",&sx,&sy);
 ini();
 reset(h);
 draw(h);getch();
 cleardevice();
 draw(h);
 dini();
 break;
 case 2:printf("Enter the x- and y-scaling factors:");
 scanf("%d%d,&sx,&sy");
 printf("Enter the x- and y-co-ordinate of the point:");
 scanf("%d%d",&x,&y);
 ini();
 reset(h);
 translate(h,x,y);
 draw(h);getch();
 cleardevice();
 translate(h,-x,-y);
 draw(h);
 getch();
 cleardevice();
 scale(h,sx,sy);
 draw(h);
 getch();
 translate(h,x,y);
 cleardevice();
 draw(h);
 putpixel(320+x,240-y,WHITE);
 dini();
 break;
 case 3:printf("Enter the values of m and c:");
 scanf("%d%d",&m,&c);
 ini();
 reset(h);
 draw(h);getch();
 reflect(h,m,c);
 cleardevice();
 draw(h);
 dini();
 break;
 case 4:exit(0);
 }
 }while(choice!=4);
}
