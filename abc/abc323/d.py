N = int(input())
mp = {}
for i in range(N):
    S, C = map(int, input().split())
    while S % 2 == 0:
        S /= 2
        C *= 2
    if S in mp.keys():
        mp[S] += C
    else:
        mp[S] = C
ans = 0
for v in mp.values():
    for bit in range(60):
        if v & (1 << bit) != 0:
            ans += 1
print(ans)
