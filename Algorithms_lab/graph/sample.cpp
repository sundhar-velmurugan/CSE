#include <stdio.h>
#include<time.h>
#include<graphics.h>
using namespace std;

void InitGraphics()
{

      int grd, grm;
      int gresult;
printf("Hello");      // Detect the graphics driver and mode
      detectgraph(&grd,&grm);
printf("Hello");      // initialize the graphics mode with initgraph
      initgraph(&grd, &grm, "C:\\TURBOC3\\BGI");

printf("Hello");
      gresult = graphresult();
      printf("Hello");
      if(gresult != grOk)
      {
            printf(grapherrormsg(gresult));
            getch();
            exit(0);
      }
printf("Hello");
      // set the background color
      setbkcolor(RED);
      // set the foreground color
      setcolor(WHITE);
      printf("Hello");
      // draw a white color border with rectangle
      rectangle(0,0,getmaxx(),getmaxy());
        printf("Hello");
      putpixel(1,1,1);
}

int main() {
    /*int i, j;
    clock_t tStart = clock();
    for(i=0; i<10; i++){
        for(j=0; j<5; j++){
            printf("%d-%d\n", i, j);
        }
    }
     printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
     */
    InitGraphics();

    return 0;
}
