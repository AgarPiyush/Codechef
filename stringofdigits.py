s=""
for i in range(1000000000):
    s=s+str(i)
k=len(s)
print(k)
l=int(input())
while l>0:
    k=input()
    if k in a:
        print("YES")
    else:
        print("NO")
    l=l-1
