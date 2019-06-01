# -*- coding: utf-8 -*-
"""
Created on Sun Jan 21 12:10:21 2018

@author: Sundhar
"""

import matplotlib.pyplot as plt
#import numpy as np
#import matplotlib.animation as animation

xpoints, ypoints = [], []

def lineDDA(s1, s2, t1, t2):
    flag=0 # flag - 0 if m>0, 1 if m<0
    if s1<s2:#swap the coordinates such that x1 is smaller
        x1, x2, y1, y2 = s1, s2, t1, t2
    else:
        x1, x2, y1, y2 = s2, s1, t2, t1
        
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    
    if dx>=dy:
        steps = dx
    else:
        steps = dy
    
    xin = dx/steps
    yin = dy/steps
    
    x=x1
    y=y1
    s=steps+1
    
    if y1>y2:
        flag=1
    
    for i in range(s):
        xpoints.append(x)
        ypoints.append(y)
        x=round(x+xin, 2)
        if flag==0:
            y=round(y+yin, 2)
        else:
            y=round(y-yin, 2)
    return flag

def graphDDA(f):
    print("The points are: ")
    l = len(xpoints)
    #printing the points
    for i in range(l):
        print(str(i+1)+") x: "+str(xpoints[i])+", y: "+str(ypoints[i]))
    plt.figure()
    if f==0: #last points in the list have larger number to plot the axis
        plt.axis((0,xpoints[l-1]+1, 0, ypoints[l-1]+1))
    else: #1st point in the xpoints list have larger number, hence ypoints[0]
        plt.axis((0,xpoints[l-1]+1, 0, ypoints[0]+1))
    plt.margins(x=0)
    plt.title("Line Drawing using DDA Algorithm")
    plt.tick_params(left = 'off', bottom = 'off')
    plt.gca().spines['top'].set_visible(False)
    plt.gca().spines['right'].set_visible(False)
    plt.plot(xpoints, ypoints, color = 'blue', linewidth=3, marker="o")
    plt.xticks(alpha=0.7)
    plt.yticks(alpha=0.7)
    if f==0: #last point is largest
        for i in range(0, int(ypoints[l-1]+1), 1):
            plt.gca().axhline(y=i, color='grey', alpha=0.25)
    else: #first point in largest
        for i in range(0, int(ypoints[0]+1), 1):
            plt.gca().axhline(y=i, color='grey', alpha=0.25)
            
    for i in range(0, int(xpoints[l-1]+1), 1):
        plt.gca().axvline(x=i, color='grey', alpha=0.25)
        
    plt.show()

#x1=int(input("Enter x1: "))
#y1=int(input("Enter y1: "))
#x2=int(input("Enter x2: "))
#y2=int(input("Enter y2: "))

x1, y1, x2, y2 = 2, 1, 16, 14 #positive slope, left to right
#x1, y1, x2, y2= 26, 12, 3, 1 #positive slope, right to left
#x1, y1, x2, y2= 2, 10, 8, 1 #negative slope, left to right
#x1, y1, x2, y2= 20, 1, 2, 10 #negative slope,  right to left
#x1, y1, x2, y2 = 5, 1, 5, 4 #vertical line

fl=lineDDA(x1, x2, y1, y2)
graphDDA(fl)