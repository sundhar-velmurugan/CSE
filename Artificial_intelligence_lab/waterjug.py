# -*- coding: utf-8 -*-
"""
Created on Wed Nov  7 19:04:07 2018

@author: Sundhar
"""

def pour(jug1, jug2):
    max1, max2, fill = 5, 7, 4
    print(jug1,'\t', jug2)
    
    if jug2 is fill:
        return
    elif jug2 is max2:
        pour(0, jug1)
    elif jug1!=0 and jug2==0:
        pour(0, jug1)
    elif jug1 is fill:
        pour(jug1, 0)
    elif jug1 < max1:
        pour(max1, jug2)
    elif jug1 < (max2-jug2):
        pour(0, jug1+jug2)
    else:
        pour(jug1-(max2-jug2), jug2+(max2-jug2))
    return

print("Jug1\tJug2")
pour(0, 0)