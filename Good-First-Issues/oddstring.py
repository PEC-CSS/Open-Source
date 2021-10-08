def oddstring(s):
    for i in range(len(s)-1,-1,-1):
        if int(s[i])%2!=0:
            return s[:i+1]
    return ""

print(oddstring("52")) #5
print(oddstring("4602")) # " "
print(oddstring("523589012344")) # 5235890123

print(oddstring(input()))