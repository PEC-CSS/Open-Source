'''
You are a product manager and currently leading a team to develop a new product.
Unfortunately, the latest version of your product fails the quality check.
Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad.
Implement a function to find the first bad version
You should minimize the number of calls to the API.
'''

'''
Knowing that all versions after the first bad version will also be wrong
and the only possible state of version is "good" or "bad" (False or True
after running isBadVersion() function), we can compare this cenario to a
search in an ordered list.

Exemple:
    versions = [1, 2, 3, 4, 5], bad = 4

    The equivalent in an ordered list cenario is:
    [False, False, False, True, True]

The algorithim that make less calls to the API (aka has the lowest time
complexity) in this cenario (ordered list) is a binary search, which has a
time complexity of O(log_2(n)).
https://en.wikipedia.org/wiki/Binary_search_algorithm
'''

# Following coding style:
# "Use camelCase for variable and function names."


def getFirstBadVersion(n: int):
    firstBadVersion = 1
    while n != firstBadVersion:
        # because this isn't a list, calculate the
        # actual range of possible versions
        diff = n - firstBadVersion + 1

        half = diff // 2 if diff % 2 == 0 else diff // 2 + 1
        mid = (firstBadVersion - 1) + half
        if isBadVersion(mid):
            n = mid
        else:
            firstBadVersion = mid + 1

    return firstBadVersion