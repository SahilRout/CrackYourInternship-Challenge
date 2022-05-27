class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         vector<vector<pair<int,int>>>adj(n);
        vector<int>cost(n,INT_MAX);
        vector<int>stop(n,INT_MAX);
        for(auto x:flights){
            adj[x[0]].push_back({x[1],x[2]});//attach nodes with their adjacent node
        }
        cost[src]=0;
        stop[src]=0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;// make min heap to store triplets and always show minimus on the top
        pq.push({0,src,0});//pq[0]->cost,pq[1]->curr node,pq[2]->number of stops
        while(!pq.empty()){
            auto[costs,currcity,stops]=pq.top();
            pq.pop();
            if(currcity==dst){// if we reach the destination
                return costs;
            }
            if(stops>k){//if we take stops more than k
                continue;//not gonna check further with this curr city
            }
            for(auto neighbors:adj[currcity]){//check for their adjacent node
                auto [node,price]=neighbors;
                if(costs+price<cost[node]||stops<stop[node]){//
                    pq.push({costs+price,node,stops+1});
                    cost[node]=costs+price;
                    stop[node]=stops;
                }
                
            }
        }
        return -1;
    }
};