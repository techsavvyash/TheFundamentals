
def minSteps(n):
    dp = [-1]*(n+1)
    dp[1] = 0 
    for i in [2, n]:
        op1 = 999999        
        op2 = 999999
        op3 = dp[i-1]
        if i%3 == 0:
            op1 = dp[i//3]
        if i%2 == 0 :
            op2 = dp[i//2]
        print(min(op1, min(op2, op3)))
        dp[i] = min(op1, min(op2, op3)) + 1

    return dp[n]


n = int(input("Enter the number: "))
ans = minSteps(n)
s = "ans: " + str(ans)
print(s)
