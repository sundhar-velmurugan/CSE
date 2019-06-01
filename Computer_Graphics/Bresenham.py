# -*- coding: utf-8 -*-
"""
Created on Sun Jan 21 13:09:51 2018

@author: Sundhar
"""
import matplotlib.pyplot as plt

xpts, ypts = [], []

def Bresenham(s1, t1, s2, t2):
    flag=0 # flag - 0 if m>0, 1 if m<0
    if s1<s2: #swap the coordinates such that x1 is smaller
        x1, x2, y1, y2 = s1, s2, t1, t2
    else:
        x1, x2, y1, y2 = s2, s1, t2, t1
    
    del_x = abs(x2-x1)
    del_y = abs(y2-y1)
        
    if y1>y2:
        flag=1
        
    if flag==0:
        y=y1
        p = (2*del_y)-del_x
        print("The points are: ")
        for x in range(x1, x2+1):
            print("x: "+str(x)+", y: "+str(y))
            xpts.append(x)
            ypts.append(y)
            p=p+(2*del_y)
            if p>=0:
                y=y+1
                p=p-(2*del_x)
    else:
        x=x1
        p = (2*del_x)-del_y
        print("The points are: ")
        for y in range(y1, y2-1, -1):
            print("x: "+str(x)+", y: "+str(y))
            xpts.append(x)
            ypts.append(y)
            p=p+(2*del_x)
            if p>=0:
                x=x+1
                p=p-(2*del_y)
    return flag
        
def graphBresenham(flag):
    l=len(xpts)
    plt.figure()
    if flag==0:
        plt.axis((0, xpts[l-1]+1, 0, ypts[l-1]+1))
    else:
        plt.axis((0, xpts[l-1]+1, 0, ypts[0]+1))
    plt.margins(x=0)
    plt.title("Line Generation using Bresenham's Algorithm")
    plt.tick_params(left = 'off', bottom = 'off')
    plt.gca().spines['top'].set_visible(False)
    plt.gca().spines['right'].set_visible(False)
    plt.plot(xpts, ypts, color = 'green', linewidth=3, marker="o")
    plt.xticks(alpha=0.7)
    plt.yticks(alpha=0.7)
    if flag==0: #last point is largest
        for i in range(0, int(ypts[l-1]+1), 1):
            plt.gca().axhline(y=i, color='grey', alpha=0.25)
    else: #first point in largest
        for i in range(0, int(ypts[0]+1), 1):
            plt.gca().axhline(y=i, color='grey', alpha=0.25)
    for i in range(0, int(xpts[l-1]+1), 1):
        plt.gca().axvline(x=i, color='grey', alpha=0.25)

#x1=int(input("Enter x1: "))
#y1=int(input("Enter y1: "))
#x2=int(input("Enter x2: "))
#y2=int(input("Enter y2: "))
        
x1, y1, x2, y2 = 3, 2, 25, 15 #positive slope, left to right
#x1, y1, x2, y2 = 35, 15, 10, 2 #positive slope, right to left
#x1, y1, x2, y2 = 2, 25, 20, 2 #negative slope, left to right
#x1, y1, x2, y2 = 10, 4, 2, 12 #negative slope,  right to left
#x1, y1, x2, y2 = 5, 1, 5, 4 #vertical line

f=Bresenham(x1, y1, x2, y2)
graphBresenham(f)