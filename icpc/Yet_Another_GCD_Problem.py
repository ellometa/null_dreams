# cook your dish here
def FindPrimes(n,l1):
    num = 3
    count = 0
    while count != n:
        if isPrime(num,l1):
            l1.append(num)
            count += 1
        num += 1
    return(l1)
            
    
def isPrime(num,l1):
    for x in l1:
        if num%x == 0:
            return(False)
    return(True)
    
l2 = [2]
for _ in range(int(input())):
    size,k = map(int,input().split())
    n = 1
    flag = False
    while True:
        if n == size:
            flag = True
            print(-1)
            break
        if ((k-((n*(n-1))>>1))/n)%1 == 0 and ((k-((n*(n-1))>>1))//n)+n <= size:
            req = (((k-((n*(n-1))>>1))//n)*2)+1
            break
        n+=1
    if flag == True:
        continue
    l1 = [x for x in range(4,req,2)]
    l2 = FindPrimes(n,l2)
    print(str(l1+l2).replace(',','')[1:-1])