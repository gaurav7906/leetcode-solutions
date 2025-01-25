class Solution:
    def countnum(self,tempo)->str:
        res = ""
        count = 1
        for i in range(1, len(tempo)):
            if tempo[i] == tempo[i - 1]: 
                count += 1
            else:
                
                res += str(count) + tempo[i - 1]
                count = 1  
        res += str(count) + tempo[-1]
        return res
    def countAndSay(self, n: int) -> str:
        if n==1:
            return "1"
        tempo=self.countAndSay(n-1)
        return self.countnum(tempo)

        