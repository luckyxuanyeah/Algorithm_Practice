class Solution {
public:
    map<string,multiset<string>> targets;
    vector<string> route;
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for(auto ticket:tickets)
            targets[ticket.first].insert(ticket.second);
        visit("JFK");
        return vector<string>(route.rbegin(),route.rend());
    }
    
    void visit(string airport)
    {
        while(targets[airport].size()) {
            string next=*targets[airport].begin();
            targets[airport].erase(targets[airport].begin());
            visit(next);
        }
        route.push_back(airport);
    }
};
//Runtime: 32 ms, faster than 67.44% of C++ online submissions for Reconstruct Itinerary.
//Memory Usage: 18.2 MB, less than 5.04% of C++ online submissions for Reconstruct Itinerary.
//Next challenges:Couples Holding Hands  All Nodes Distance K in Binary Tree   Minimize Malware Spread II
