n = int(input())
s = [int(input()) for _ in range(n)]
dp = [0] * n

if n == 1:
    print(s[0])
elif n == 2:
    print(s[0] + s[1])
else:
    dp[0] = s[0]
    dp[1] = s[0] + s[1]
    
    for i in range(2, n):
        dp[i] = max(dp[i-3] + s[i-1] + s[i], dp[i-2] + s[i])

    print(dp[-1])
