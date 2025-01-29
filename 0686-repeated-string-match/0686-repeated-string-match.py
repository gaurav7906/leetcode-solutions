class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:
        # the cases where we can find substrinds can be :
        # minimum repeation=len(b)/len(a)
        # prefix+(n*a)+suffix -> n+2
        # prefix+(n*a) -> n+1
        # (n*a)suffix ->n+1
        # (n*a) -> n 
        # whre n is the minimum number of repetion 
        minrep=len(b)//len(a)
        n=minrep
        na=""
        while minrep:
            na=na+a
            minrep-=1
        if b in na :
            return n
        na=na+a
        if b in na :
            return n+1
        na=na+a
        if b in na :
            return n+2 
        return -1