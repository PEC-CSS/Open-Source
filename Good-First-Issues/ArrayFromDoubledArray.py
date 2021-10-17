'''
ALGORITHM EXPLANATION

The array is first sorted.

The 0th element of the array now holds the smallest value.
So half of this value cannot be in the array.
Therefore the 0th element is one of the original elements.
We remove it and add it to the originals.
We also remove its double.

We keep doing this until the array size reaches 0.
At this point, we have gone through all of the elements.
Therefore we can return the array of original elements.
'''

def arrayFromDoubledArray(arr):
    arr.sort()
    original = []
    while (len(arr) > 0):
        n = arr.pop(0)
        arr.remove(n*2)
        original.append(n)
    return original

# Test cases
print("Test case 1:", arrayFromDoubledArray([4, 1, 18, 2, 9, 8]))
print("Test case 2:", arrayFromDoubledArray([4, 1, 2, 2, 8, 2, 4, 4]))