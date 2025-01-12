class Solution:
    def getmaxprofit(self,index,prices,buy,dp):
        if index>=len(prices):
            return 0
        if dp[index][buy] !=-1:
            return dp[index][buy]
        if buy==0:
            opt1=0+self.getmaxprofit(index+1,prices,0,dp)
            opt2=-prices[index]+self.getmaxprofit(index+1,prices,1,dp)
            profit=max(opt1,opt2)
        if buy==1:
            opt1=0+self.getmaxprofit(index+1,prices,1,dp)
            opt2=prices[index]+self.getmaxprofit(index+2,prices,0,dp)
            profit=max(opt1,opt2)
        dp[index][buy]=profit
        return dp[index][buy]

    def maxProfit(self, prices: List[int]) -> int:
        n=len(prices)
        dp=[[-1]*2 for _ in range(n) ]
        ans=self.getmaxprofit(0,prices,0,dp)
        return ans 
        