# -*- coding: utf-8 -*-
"""
Created on Wed Nov  7 18:00:37 2018

@author: Sundhar
"""

from collections import defaultdict
from queue import PriorityQueue

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)
        self.h = [8,15,10,30,20,0]
    def addEdge(self, u, v, c):
        if u == v:
            self.graph[u].append([])
            return
        #single directional graph; also cost 1st dest next
        self.graph[u].append([c, v])
    def search(self):
        self.ucs(0, 5)
        self.astar(0, 4)
        self.bestfirst(0, 4)
        
    def ucs(self, start, end):
        pq = PriorityQueue()
        #save path as string
        pq.put((0, str(start)))
        while pq:
            t = pq.get()
            c = int(t[1][-1])
            if c == end:
                print("UCS")
                print("Cost: ", t[0])
                print("Path: ", *t[1], sep='-')
                return #dont forget return
            else:
                for i in self.graph[c]:
                    pq.put((t[0]+i[0], t[1]+str(i[1])))
    def astar(self, start, end):
        pq = PriorityQueue()
        pq.put((self.h[start], str(start)))
        while pq:
            t = pq.get()
            c = int(t[1][-1])
            if c == end:
                print("A*")
                print("Cost: ", t[0])
                print("Path: ", *t[1], sep='-')
                return #never forget the return
            else:
                for i, j in self.graph[c]:
                    pq.put((t[0]-self.h[c]+i+self.h[j], t[1]+str(j)))
    def bestfirst(self, start, end):
        pq = PriorityQueue()
        path = []
        v = [False]*(len(self.graph)+1) # +1- to add for 5th node
        pq.put((self.h[start], start))
        v[start] = True
        while pq:
            c = pq.get()[1] #getting current element
            path.append(c)
            if c == end:
                print("Best First")
                print("Path: ", *path, sep='-')
                return
            else:
                for t, i in self.graph[c]: #since 2 elements in obj
                    if not v[i]:
                        pq.put((self.h[i], i))
                        v[i] = True

                    
g = Graph()
g.addEdge(0, 1, 1)
g.addEdge(0, 5, 12)
g.addEdge(1, 2, 3)
g.addEdge(1, 3, 1)
g.addEdge(2, 4, 3)
g.addEdge(3, 4, 1)
g.addEdge(3, 5, 2)
g.addEdge(4, 5, 3)
#g.addEdge(5, 5, 0) - last node with no edges

g.search()