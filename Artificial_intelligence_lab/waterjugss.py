# -*- coding: utf-8 -*-
"""
Created on Wed Nov  7 19:15:00 2018

@author: Sundhar
"""

s = set()

def wjss(jug1, jug2):
    max1, max2 = 5, 7
    print(jug1, '\t', jug2)
    
    if (jug1, 0) not in s:
        s.add((jug1, 0))
        wjss(jug1, 0)
    if (0, jug2) not in s:
        s.add((0, jug2))
        wjss(0, jug2)
    if (max1, jug2) not in s:
        s.add((max1, jug2))
        wjss(max1, jug2)
    if (jug1, max2) not in s:
        s.add((jug1, max2))
        wjss(jug1, max2)
    
    l = jug1+jug2
    r = 0
    if l>max1:
        l = max1
        r = max1 - jug1
    if (l, r) not in s:
        s.add((l, r))
        wjss(l, r)
    r = jug1+jug2
    l = 0
    if r>max2:
        r = max2
        l = max2-jug2
    if (l, r) not in s:
        s.add((l, r))
        wjss(l, r)
    
    return

wjss(0, 0)