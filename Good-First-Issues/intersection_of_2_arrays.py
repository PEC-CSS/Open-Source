nums1 = [4,9,5]
nums2 = [9,4,9,8,4]
nums2 = sorted(nums2)
intersecting_nums = []

# Returns index of x in arr if present, else -1
def binary_search(arr, low, high, x):
 
    # Check base case
    if high >= low:
 
        mid = (high + low) // 2
 
        # If element is present at the middle itself
        if arr[mid] == x:
            return mid
 
        # If element is smaller than mid, then it can only
        # be present in left subarray
        elif arr[mid] > x:
            return binary_search(arr, low, mid - 1, x)
 
        # Else the element can only be present in right subarray
        else:
            return binary_search(arr, mid + 1, high, x)
 
    else:
        # Element is not present in the array
        return -1

for elem in nums1:
    if binary_search(nums2,0,len(nums2)-1,elem) != -1 and binary_search(intersecting_nums,0,len(intersecting_nums)-1,elem) == -1:
        intersecting_nums.append(elem)
        
print(intersecting_nums)
