#include<conio.h>
#include<iostream.h>
#include<time.h>
#include<stdlib.h>
#include<graphics.h>

static class Search
{
 public:
       static	long linear(long * , long ,long );
       static	long binary(long * , long ,long , long ,long & );
       static	long iBinary(long * ,long,long );
};

long  Search::linear(long * arr, long size, long key)
{
	long i,pixy=getmaxy()-51,flag=0;
	for(i=0;i<size;i++)
	{
		pixy--;
		if(arr[i]==key)
		{
			flag=1;
			break;
		}

	}
	putpixel(size+40,pixy,5);
	if(flag)
		return 1;
	else
		return 0;

}

long Search::binary(long * arr, long lb, long ub,long key,long & pixy)
{
	long mid=0;
	pixy--;
	if(lb<=ub)
	{
		mid=(lb+ub)/2;
		if(arr[mid]<key)
			return binary(arr,mid+1,ub,key,pixy);
		else if(arr[mid]>key)
			return binary(arr,lb,mid-1,key,pixy);
		else
			return 1;
	}
	return 0;
}

long Search::iBinary(long * arr,long size, long key)
{
	long mid,lb,ub,pixx=size,pixy=getmaxy()-51,flag=0;
	lb=0,ub=size-1;
	while(lb<=ub)
	{
		mid=(lb+ub)/2;
		if(arr[mid]==key)
		{
			flag=1;
			break;
		}
		else if(arr[mid]<key)
			lb=mid+1;
		else
			ub=mid-1;
			pixy--;
	}

	putpixel(pixx+40,pixy,14);
	if(flag)
		return 1;
	else
		return 0;
}

void initialize()
{
    int gd=DETECT, gm,i,j;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    setcolor(WHITE);
}

void drawAxis()
{

	settextstyle(0, VERT_DIR, 1);
	line(40,0,40,getmaxy());
	line(0,getmaxy()-50,getmaxx(),getmaxy()-50);
	outtextxy(25,220,"Run Time");
	settextstyle(0, 0, 1);
	outtextxy(30,435,"0");
	outtextxy(60,435,"100");
	outtextxy(120,435,"1000");
	outtextxy(190,435,"10000");
	outtextxy(320,435,"100000");
	outtextxy(560,435,"1000000");
	outtextxy(255,460,"# No of Inputs");
	outtextxy(400,80,"Linear = O\(N\)");
	outtextxy(400,400,"Binary = O\(log N\)");
	setcolor(YELLOW);
	outtextxy(50,40,"Comparison of differenct search Algorithms");


}

int main()
{
	long arr[10000],size=100,temp=getmaxy()-50,i;
	clrscr();
	initialize();
	srand(time(NULL));
	for(i=0;i<size;i++)
		arr[i]=rand();
	drawAxis();
	for(i=1;i<1000;i+=1)
	{
		Search::linear(arr,i,321);
		Search::iBinary(arr,i,321);
		Search::binary(arr,0,i-1,321,temp);
		putpixel(i+40,temp,1);
		temp=430;
	}
	getch();
	return 0;
}
