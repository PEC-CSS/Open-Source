# -*- coding: utf-8 -*-
"""
Created on Sat Sep 11 16:12:56 2021

@author: gattsu997
"""

"""sudoku"""

# input the puzzle you want solved 

grid = [[5,4,0,0,7,0,0,0,0],
        [6,0,0,1,9,5,0,0,0],
        [0,9,8,0,0,0,0,6,0],
        [8,0,0,0,6,0,0,0,3],
        [4,0,0,8,0,3,0,0,1],
        [7,0,0,0,2,0,0,0,6],
        [0,6,0,0,0,0,2,8,0],
        [0,0,0,4,1,9,0,0,5],
        [0,0,0,0,8,0,0,7,9]]

import numpy as np
print(np.matrix(grid))

def possible(y,x,n):
    global grid
    for i in range (0,9):
        if grid[y][i]==n:
            return False
    for i in range (0,9):
        if grid[i][x]==n:
            return False;
    X=(x//3)*3
    Y=(y//3)*3
    for i in range (0,3):
        for j in range(0,3):
            if grid[X+i][Y+j]==n:
                return False
    return True

def solve():
    global grid
    for y in range (0,9):
        for x in range (0,9):
            if grid[y][y]==0:
                for n in range (1,10):
                    if possible (y,x,n):
                        grid[y][x]=n
                        solve()
                        grid[y][x]=0
            return
    print(np.matrix(grid))
solve()
