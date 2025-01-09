class Solution:
    def getmaxsub(self,index1,index2,word1,word2,dp):
        if index1<0 or index2<0:
            return 0
        if dp[index1][index2]!=-1:
            return dp[index1][index2]
        if word1[index1]==word2[index2]:
            dp[index1][index2]=1+self.getmaxsub(index1-1,index2-1,word1,word2,dp)
        else :
            dp[index1][index2]=max(self.getmaxsub(index1-1,index2,word1,word2,dp),self.getmaxsub(index1,index2-1,word1,word2,dp))
        return dp[index1][index2]

    def minDistance(self, word1: str, word2: str) -> int:
        n=len(word1)
        m=len(word2)
        dp = [[-1 for i in range(m + 1)] for j in range(n + 1)]
        res=self.getmaxsub(n-1,m-1,word1,word2,dp)
        return m+n-2*res
        