# -*- coding: utf-8 -*-
"""
Created on Wed Nov  7 17:44:45 2018

@author: Sundhar
"""

from collections import defaultdict

class Node:
    def __init__(self):
        self.parentset = set() #set() - set; {} - list
        self.childlist = list()
        self.value = None
        self.parent = None

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)
    def addEdge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)
    def searchtree(self, start):
        queue = []
        s = Node()
        s.value = start
        for i in self.graph[s.value]: #s.value - node name; s - obj
            s.childlist.append(i)
        queue.append(s)
        while queue:
            c = queue.pop(0)
            print(c.parent,"\t", c.value)
            for n in c.childlist:
                node = Node()
                node.value = n
                node.parent = c.value #just the value, not entire obj
                for j in c.parentset:
                    node.parentset.add(j)
                node.parentset.add(c.value)
                for j in self.graph[n]:
                    if j not in node.parentset:
                        node.childlist.append(j)
                queue.append(node)
                
g = Graph()

g.addEdge(1, 2)
g.addEdge(1, 3)
g.addEdge(2, 3)
g.addEdge(2, 4)
g.addEdge(2, 5)
g.addEdge(3, 4)
g.addEdge(4, 5)
#sv = int(input("Enter the starting vertex: "))
print("Parent\tChild")
g.searchtree(1)