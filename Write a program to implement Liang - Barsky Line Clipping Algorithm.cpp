//AIM: Write a program to implement Liang - Barsky Line Clipping Algorithm

/*
input:

Enter the lower co-ordinates of window: 100 200
Enter the upper co-ordinates of window: 300 400
Enter x1: 100
Enter y1: 200
Enter x2: 300
Enter y2: 400
Line after clipping:
*/

#include<iostream>
#include<conio.h>
#include<graphics.h>
int main(){
 int gd=DETECT, gm;
 initgraph(&gd,& gm, "C:\\TURBOC3\\BGI");
 int x1, y1, x2, y2, xmax, xmin, ymax, ymin, xx1, yy1, xx2, yy2, dx, dy, i;
 float t1, t2, t[4];
 int p[4], q[4];
 printf("Enter the lower co-ordinates of window: ");
 scanf("%d%d", &xmin, &ymin);
 printf("Enter the upper co-ordinates of window: ");
 scanf("%d%d", &xmax, &ymax);
 setcolor(RED);
 rectangle(xmin, ymin, xmax, ymax);
 printf("Enter x1: ");
 scanf("%d", &x1);
 printf("Enter y1: ");
 scanf("%d", &y1);
 printf("Enter x2: ");
 scanf("%d", &x2);
 printf("Enter y2: ");
 scanf("%d", &y2);
 line(x1, y1, x2, y2);
 dx = x2 - x1;
 dy = y2 - y1;
 p[0] = -dx;
 p[1] = dx;
 p[2] = -dy;
 p[3] = dy;
 q[0] = x1 - xmin;
 q[1] = xmax - x1;
 q[2] = y1 - ymin;
 q[3] = ymax - y1;
 for(i = 0; i < 4; i++){
 if(p[i] != 0){
 t[i] = (float)q[i] / p[i];
 } else {
 if(p[i] == 0 && q[i] < 0)
 std::cout << "Line completely outside the window";
 else if(p[i] == 0 && q[i] >= 0)
 std::cout << "Line completely inside the window";
 else
 t[i] = 0;
 }
 }
 t1 = t[0];
 t2 = t[1];
 if (t[2] > t1){
 t1 = t[2];
 }
 if (t[3] < t2){
 t2 = t[3];
 }
 if (t1 < t2){
 xx1 = x1 + t1 * dx;
 xx2 = x1 + t2 * dx;
 yy1 = y1 + t1 * dy;
 yy2 = y1 + t2 * dy;
 printf("Line after clipping:");
 setcolor(WHITE);
 line(xx1, yy1, xx2, yy2);
 } else {
 printf("Line lies completely outside the window");
 }
 getch();
 closegraph();
 return 0;
}
