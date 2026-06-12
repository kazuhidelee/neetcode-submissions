class CountSquares {
public:
    unordered_map<int, unordered_map<int, int>> coords;
    CountSquares() {
    }
    
    void add(vector<int> point) {
        coords[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int point_x = point[0];
        int point_y = point[1];
        int total = 0;
        for(auto &[y, count]: coords[point_x]){
            if (y == point_y) continue;
            int curr = 1;
            int dist = point_y - y;
            curr *= coords[point_x][y];
            curr *= coords[point_x + dist][point_y];
            curr *= coords[point_x + dist][y];
            total += curr;

            curr = 1;
            curr *= coords[point_x][y];
            curr *= coords[point_x - dist][point_y];
            curr *= coords[point_x - dist][y];

            total += curr;
        }
        return total;
    }
};
