MODULO = 998244353

def count_unique_subsequences(S):
    n = len(S)
    dp = [0] * (n + 1)
    dp[0] = 1  
    
    last_occurrence = {}
    
    for i in range(1, n + 1):
        char = S[i - 1]
        
        
        dp[i] = (2 * dp[i - 1]) % MODULO
        
        
        if char in last_occurrence:
            dp[i] = (dp[i] - dp[last_occurrence[char] - 1] + MODULO) % MODULO
        
        
        last_occurrence[char] = i
    
    
    return (dp[n] - 1 + MODULO) % MODULO


S = input("Enter a string: ").strip()
result = count_unique_subsequences(S)
print(result)
