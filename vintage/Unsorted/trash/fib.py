# lol this is shauyra's code on aayush's laptop with giant font
n1,n2 = 1,1
lst: list = []
while n2<4_000_000:
    n1, n2 = n2, n1+n2
    lst.append(n1)

evens = filter(lambda x: x%2==0, lst)
print(sum(evens))