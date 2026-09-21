for _ in range(int(input())):
  N, A, B, C, D, P, Q, Y = map(int,input().split())
  dist = list(map(int,input().split()))
  if abs(dist[A-1]-dist[C-1])*P <= Y:
      print(min(Y+abs(dist[C-1]-dist[D-1])*Q+abs(dist[D-1]-dist[B-1])*P,abs(dist[A-1]-dist[B-1])*P))
  else:
      print(abs(dist[A-1]-dist[B-1])*P)