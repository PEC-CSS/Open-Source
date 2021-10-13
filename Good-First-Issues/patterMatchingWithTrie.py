'''
Title: Patter matching with Trie Data Structure
Author: Vishal Ambavade
Date: 2021-10-13
'''

from typing import Counter
class Trie(object):
    def __init__(self):
        self.child = {}

    ## Class to insert new elements in the Trie
    def insert(self, word):
        current = self.child
        for l in word:
            if l not in current:
                current[l] = {}
            current = current[l]
        current['#'] = 1
    
    ## Class to find the pattern in the tree
    def searchPattern(self, term):
        current = self.child
        for l in term:
            if l not in current:
                return False
            current = current[l]
        return True

obj = Trie()

n = int(input())
lst = [str(i) for i in input().split()][:n]
searchTerm = input()

output = []
for i in lst:
    obj.insert(i)
    output.append(obj.searchPattern(searchTerm))

print(any(output))
