#
# longest common substring
# @param str1 string字符串 the string
# @param str2 string字符串 the string
# @return string字符串
#
class Solution:
    def LCS(self , str1 , str2 ):
        m, n = len(str1), len(str2)
        dp = [[0 for i in range(n)] for j in range(m)]
        length = 1
        res_pos = -1
        
        for i in range(m):
            if str1[i] == str2[0]:
                dp[i][0] = 1
        for i in range(n):
            if str1[0] == str2[i]:
                dp[0][i] = 1
        
        for i in range(1,m,1):
            for j in range(1,n,1):
                if str1[i] == str2[j]:
                    if str1[i-1] == str2[j-1]:
                        dp[i][j] = dp[i-1][j-1] + 1
                        if dp[i][j] > length:
                            length = dp[i][j]
                            res_pos = i
                    else:
                        dp[i][j] = 1
#                 else: //这个else操作必须去掉，不然超时
#                     dp[i][j] = max(dp[i-1][j], dp[i][j-1])
                    
        return str1[res_pos+1-length: res_pos+1]