/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> timeline;
        
        for (const auto& interval : intervals) {
            timeline[interval.start] += 1;
            timeline[interval.end] -= 1;
        }
        
        int current_rooms = 0;
        int max_rooms = 0;
        
        for (const auto& event : timeline) {
            current_rooms += event.second;
            max_rooms = max(max_rooms, current_rooms);
        }
        
        return max_rooms;
    }
};
