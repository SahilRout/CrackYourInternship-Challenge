class Solution {
    private int[][][] dp;
    public int removeBoxes(int[] boxes) {
        int len = boxes.length;
        dp = new int[len][len][len];
        return dfs(boxes, 0, len - 1, 0);
    }
    private int dfs(int[] boxes, int i, int j, int k){
        if(i > j) return 0;
        if(dp[i][j][k] > 0) return dp[i][j][k];
        dp[i][j][k] = dfs(boxes, i, j - 1, 0) + (k + 1) * (k + 1);
        for(int p = i; p < j; p++){
            if(boxes[p] == boxes[j]){
                dp[i][j][k] = Math.max(dp[i][j][k], dfs(boxes, i, p, k + 1) + dfs(boxes, p + 1, j - 1, 0));
            }
        }
        return dp[i][j][k];
    }
}