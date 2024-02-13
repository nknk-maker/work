n = int(input())
C = [[] for _ in range(n)]
for i in range(n):
    a = int(input())
    C[i] = list(map(int, input().split()))
score = [0] * n
x = int(input())
for i in range(n):
    if x in C[i]:
        score[i] += 1
score.sort()
print(*score)

