class Solution {
    pair<long long, int>fn(int node, int parent, unordered_map<int,int>&mp, int acc,
    vector<vector<int>>&g, int &seats)
    {
        int cars = 1; int pass = 1; 
        long long cost = 0;
        for(int i = 0; i< g[node].size(); i++)
        {
            if(g[node][i] == parent)
                continue;
            mp[g[node][i]] = acc;
            auto p = fn(g[node][i], node, mp, acc+1, g, seats);
            cost += p.first;
            if(p.second == seats)
                continue;
            cars++; pass += p.second;
        }
        if(node == 0)
            return {cost, 0};
        if(cars  == 1)
        {
            if(seats == 1)
                return {cost+mp[node], 1};
            return {cost+1, 1};
        }
        int fullCars = pass/seats;
        int rem = pass%seats;
        if(fullCars > 0)
            cost += (fullCars*mp[node]);
        if(rem > 0)
            return {cost+1, rem};
        return {cost, seats};
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {

        unordered_map<int,int>mp;
        int acc = 1;
        vector<vector<int>>g(roads.size()+2);
        for(int i = 0; i< roads.size(); i++)
        {
            int from = roads[i][0]; int to = roads[i][1];
            g[from].push_back(to);
            g[to].push_back(from);
        }
        return fn(0, -1, mp, acc, g, seats).first;
        
    }
};
