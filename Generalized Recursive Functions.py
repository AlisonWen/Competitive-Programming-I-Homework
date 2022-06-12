import math
t = int(input())
while t >  0:
    arr1 = []
    arr2 = []
    dp = [[int(0)] * 105 for i in range(105)]
    #print(dp)
    var = [] #variables (x, y)
    cof = [] # coefficients(a, b)
    arr1 = list(map(int, input().split(' ')))
    arr2 = list(map(int, input().split(' ')))
    c = int(arr1[len(arr1) - 2])
    d = int(arr1[len(arr1) - 1])
    for i in range(0, len(arr1) - 2):
        if((i % 2) == 0):
            cof.append((int(arr1[i]), int(arr1[i + 1])))
    for i in range(0, len(arr2) - 1):
        if((i % 2) == 0):
            var.append((int(arr2[i]), int(arr2[i + 1])))
    for i in range(0, 100):
        dp[0][i] = dp[i][0] = d
    for i in range (1, 100):
        for j in range(1, 100):
            tmp = int(0)
            for Cof in cof:
                if i - Cof[0] >= 0 and j - Cof[1] >= 0 :
                    dp[i][j] =  dp[i][j] + int(dp[i - Cof[0]][j - Cof[1]])
                else :
                    dp[i][j] = dp[i][j] + int(d)
            dp[i][j] = dp[i][j] + int(c)
    for i in var:
        print(dp[i[0]][i[1]])
    t = t - 1
    if(t > 0):
        print("")
