a,b=input().split(" ")
a=int(a)
b=int(b)
res=1
m=a
a= a*(a+1)//2
a%=m

while (b > 0):    
    res = res * a % m
    a = a * a % m
    b >>= 1
print(res)
