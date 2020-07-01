class Solution(object):
    def arrangeCoins(self, n):
        """
        :type n: int
        :rtype: int
        """
        i=1
        count=0
        while n:
            n=n-i
            if n<0:
                break
            count=count+1
            i=i+1
        return count    
        
        
        
