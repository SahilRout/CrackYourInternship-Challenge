bool isJumpPossible(int n,unordered_map<int,int>& mp,int value,int index,int k,vector<int>& stones,vector<vector<int>>& dp){
    
    if(index == n-1)   return dp[index][k] = true;
    
    if(dp[index][k] != -1){
        if(dp[index][k] == 1)   return true;
        return false;
    }
    
    if(value != stones[index]) return dp[index][k] = false;
    
    bool opt1 = false;
    bool opt2 = false;
    bool opt3 = false;
    
    if(k-1 > 0 && mp.find(value+k-1) != mp.end()){
        opt1 = isJumpPossible(n,mp,value+k-1,mp[value+k-1],k-1,stones,dp);
    }
    
    if(mp.find(value+k) != mp.end()){
        opt2 = isJumpPossible(n,mp,value+k,mp[value+k],k,stones,dp);
    }
    
    if(mp.find(value+k+1) != mp.end()){
        opt3 = isJumpPossible(n,mp,value+k+1,mp[value+k+1],k+1,stones,dp);
    }
    
    if(opt1 || opt2 || opt3)    return dp[index][k] = true;
    return dp[index][k] = false;
    
}

class Solution {
public:
    bool canCross(vector<int>& stones) {
        
        int n = stones.size();
        if(n < 2) return false;
        if(1 + stones[0] < stones[1])   return false;
        
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[stones[i]] = i;
        }
        vector<vector<int>> dp(n,vector<int>(1000,-1));
        return isJumpPossible(n,mp,stones[1],1,1,stones,dp);
        
    }
};