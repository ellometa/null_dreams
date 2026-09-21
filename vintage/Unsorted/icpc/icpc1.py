n,m = map(int,input().split())
d1,d2,keys,count = dict(),dict(),set(),0
for _ in range(n):
    x,y = map(int,input().split())
    d1[x*y] = d1.get(x*y,0)+1
    keys.add(x*y)
for _ in range(m):
    x,y = map(int,input().split())
    d2[x*y] = d2.get(x*y,0)+1
    keys.add(x*y)
for x in keys:
    count += min(d1.get(x,0),d2.get(x,0))
print(count)
