class Robot {
public:
    int width, height, perimeter;
    int x, y, dir;
    
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    vector<string> dirs = {"East", "North", "West", "South"};

    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        this->perimeter = 2 * (width + height) - 4;
        
        x = 0;
        y = 0;
        dir = 0;
    }
    
    void step(int num) {
        num %= perimeter;
        
        if (num == 0) {
            num = perimeter;
        }

        while (num > 0) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= width || ny < 0 || ny >= height) {
                dir = (dir + 1) % 4;
                continue;
            }

            x = nx;
            y = ny;
            num--;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return dirs[dir];
    }
};