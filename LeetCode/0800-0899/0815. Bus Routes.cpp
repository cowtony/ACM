class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // Store the minimum bus needed for each stop, maximum 10^6 stops.
        vector<int> minBusTable(1000000, INT_MAX); 
        minBusTable[source] = 0;
        
        // Bellman-Ford algorithm
        bool updated = true;
        while(updated) {
            updated = false;
            for(const auto& route : routes) {
                int minBus = routes.size() + 1;
                // Find the minimum steps for all stops in this route:
                for(int stop : route) {
                    minBus = min(minBus, minBusTable[stop]);
                }
                // Update all stops to minBus + 1:
                for(int stop : route) {
                    if(minBusTable[stop] > minBus + 1) {
                        minBusTable[stop] = minBus + 1;
                        updated = true;
                    }
                }
            }
        }
        return minBusTable[target] > routes.size() ? -1 : minBusTable[target];
    }
};
