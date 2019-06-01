# -*- coding: utf-8 -*-
"""
Created on Wed Nov  7 16:54:28 2018

@author: Sundhar
"""

from collections import defaultdict
import timeit

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)
    def addEdge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)
    def bfs(self, start):
        queue = []
        path = []
        v = [False]*len(self.graph)
        queue.append(start)
        v[start]=True
        while queue:
            c = queue.pop(0)
            path.append(c)
            for child in self.graph[c]:
                if not v[child]:
                    queue.append(child)
                    v[child] = True
        print("BFS: ", *path, sep='-')
    def dfs(self, start):
        stack = []
        path = []
        v = [False]*len(self.graph)
        stack.append(start)
        v[start] = True
        while stack:
            c = stack.pop()
            path.append(c)
            for child in list(reversed(self.graph[c])):
                if not v[child]:
                    stack.append(child)
                    v[child] = True
        print("DFS: ", *path, sep='-')
    def ids(self, start, stop, depth):
        visited = []
        for cur_depth in range(depth):
            print("Level :", cur_depth)
            if cur_depth == 0:
                visited.append(start)
                print(start)
            else:
                new_g = {}
                new_v = []
                for j in visited:
                    new_g[j] = self.graph[j]
                    for k in self.graph[j]:
                        if k not in visited:
                            new_v.append(k)
                #dfs starts after appending dict and vertex
                self.new_dfs(start)
                for l in new_v:
                    visited.append(l)
    def new_dfs(self, start):
        stack = []
        path = []
        v = [False]*len(self.graph)
        stack.append(start)
        v[start] = True
        while stack:
            c = stack.pop()
            path.append(c)
            if self.graph.get(c): #new if statement
                for child in list(reversed(self.graph[c])):
                    if not v[child]:
                        stack.append(child)
                        v[child] = True
        print(*path, sep='-')
                        
    def search(self):
        start = timeit.default_timer()
        self.bfs(0)
        print("Time taken: ", timeit.default_timer()-start)
        start = timeit.default_timer()
        self.dfs(0)
        print("Time taken: ", timeit.default_timer()-start)
        start = timeit.default_timer()
        self.ids(0, 6, 3)
        print("Time taken: ", timeit.default_timer()-start)

g = Graph()

g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 3)
g.addEdge(1, 4)
g.addEdge(2, 5)
g.addEdge(2, 6)

g.search()