class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int startSize = start.size();
        int endSize = end.size();
        
        // only one meeting, only one room
        if (startSize == 1)
            return 1;
            
        // map start time to end time in a vector of pair
        vector<pair<int, int>> mapping;
        
        for (int i = 0; i < startSize; i++)
            mapping.push_back({start[i], end[i]});
            
        // then sort the mapping array
        sort(mapping.begin(), mapping.end());
            
        // store the ending times in a min-heap
        // this will tell us how many meetings are running concurrently
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(mapping[0].second); // initialize to the ending of first meeting
            
        // count the max amount of rooms
        int count = 1, res = 1;
        
        // go through each meeting  
        for (int i = 1; i < start.size(); i++) {
            // if the current meeting starts before the previous meeting ends
            // this means that there is another meeting happening simultaneously
            if (mapping[i].first < pq.top()) {
                pq.push(mapping[i].second);
                count++;
            }
            else {
                pq.pop();
                pq.push(mapping[i].second);    
            }
            
            res = max(res, count);
        }
    
        return res;    
    }
};

