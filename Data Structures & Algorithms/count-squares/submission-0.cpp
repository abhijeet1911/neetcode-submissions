class CountSquares {
public:
vector<pair<int, int>> points;
unordered_map<int, unordered_map<int, int>> freq;

    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        points.push_back({x, y});
        freq[x][y]++;
    }
    
    int count(vector<int> point) {
        int px = point[0];
        int py = point[1];
        int total_squares = 0;
        for (const auto& p : points) {
            int x = p.first;
            int y = p.second;
            if (abs(px - x) != 0 && abs(px - x) == abs(py - y)) {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
                total_squares += freq[x][py] * freq[px][y];
            }
        }
        
        return total_squares;
    }
};
