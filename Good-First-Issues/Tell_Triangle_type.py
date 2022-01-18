def check_triangle(a,b,c):
    result = True
    # function to check whether given sides makes a triangle or not
    if a+b <= c or b+c <= a or c+a <= b :
        result = False
    return result

def type_side(a,b,c):
    # Function to determine whether a triangle is equilateral or isosceles or scalene
    if a == b == c :
        ans = "Equilateral"
    elif a==b or b==c or c==a:
        ans = "Isosceles"
    else:
        ans = "Scalene"
    return ans

def type_angle(p,q,r):
    # Function to determine whether a triangle is right or acute or obtuse angled 
    if p**2 + q**2 == r**2:
        ans = "Right Angled Triangle"
    elif p**2 + q**2 > r**2:
        ans = "Actue Angled Triangle"
    else:
        ans = "Obtuse Angled Triangle"
    return ans

#driver code
a,b,c = [int(i) for i in input().split()]
if check_triangle(a,b,c):
    aa = type_side(a,b,c)
    arr = [a,b,c]
    r = max(arr)
    p,q = [j for j in arr if j!=r]
    bb = type_angle(p,q,r)
    print(aa,",",bb)
else:
    print("Triangle not possible")
