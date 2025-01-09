class Solution:
    def countsum(self,index,coins,target,dp)->int:
        if index==0:
            if target%coins[0]==0:
                return 1
            else:
                return 0
        if dp[index][target]!=-1:
            return dp[index][target]
        nottake=0+self.countsum(index-1,coins,target,dp)
        take=0
        if coins[index]<=target:
            take=self.countsum(index,coins,target-coins[index],dp)
        dp[index][target]=take+nottake
        return dp[index][target]

    def change(self, amount: int, coins: List[int]) -> int:
        n=len(coins)
        dp=[[-1]*(amount+1) for _ in range(n)]
        result=self.countsum(n-1,coins,amount,dp)
        return result if result!=int(1e9) else 0