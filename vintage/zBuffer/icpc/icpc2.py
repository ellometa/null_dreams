for _ in range(int(input())):
  n = int(input())
  l1 = sorted(list(map(int,input().split())))
  count = 0
  for i in range(n//2):
      count += abs(l1[i] - l1[n-i-1])
  print(count)