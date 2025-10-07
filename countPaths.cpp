class Solution {
public:

    #define ll long long int
    
    int countPaths(int n, vector<vector<int>>& roads) {

        ll mod=1e9+7;

        vector<vector<pair<int,int>>>g(n);


        for(auto r : roads)
        {
            int u=r[0],v=r[1],w=r[2];
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }

        vector<ll>ways(n,0);
        vector<ll>dist(n,1e18);

        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;

        dist[0]=0;
        pq.push({0,0});
        ways[0]=1;

        while(!pq.empty())
        {
            auto [d,node]=pq.top();
            pq.pop();


            if(dist[node]<d) continue;

            for(auto [nbr,wt] : g[node])
            {
               

                if(dist[node]+wt<dist[nbr])
                {
                    dist[nbr]=dist[node]+wt;
                    ways[nbr]=ways[node]%mod;
                    // cout<<nbr<<" "<<dist[nbr]<<endl;
                    pq.push({dist[nbr],nbr});
                }
                else if(dist[node]+wt==dist[nbr])
                {
                   
                    ways[nbr]=(ways[nbr]%mod+ways[node]%mod)%mod;  
                    //  cout<<nbr<<"ways "<<ways[nbr]<<" "<<node<<endl;
                }
            }
    
        }

        return ways[n-1]%mod;

        
    }
};
