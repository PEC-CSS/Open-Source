class Solution {
    
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int minSoFar = Integer.MAX_VALUE;
        int maxProfit = 0;
        for(int i=0;i< n;i++){
            if(minSoFar > prices[i])
                minSoFar = prices[i];
            else
                maxProfit = Math.max(prices[i] - minSoFar, maxProfit);
        }
        return maxProfit;
     }
}


// Time complexity of solution : O(n) and space complexity:O(1)
