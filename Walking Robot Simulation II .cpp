class Robot {
public:
    int x = 0, y = 0;
    int w, h;
    int dir = 0;
    int per;

    Robot(int width, int height) {
        w = width;
        h = height;
        per = 2 * (w + h) - 4;
    }
 
    void step(int num) {

        if (per == 0)
            return;
        num %= per;

        if (num == 0 && x == 0 && y == 0) {
            dir = 3;
            return;
        }

        while (num > 0) {

            if (dir == 0) {
                int move = min(num, w - x - 1);
                x += move;
                num -= move;
                if (num > 0)
                    dir = 1;
            }

            else if (dir == 1) {
                int move = min(num, h - y - 1);
                y += move;
                num -= move;
                if (num > 0)
                    dir = 2;
            } else if (dir == 2) {
                int move = min(num, x);
                x -= move;
                num -= move;
                if (num > 0)
                    dir = 3;
            } else {
                int move = min(num, y);
                y -= move;
                num -= move;
                if (num > 0)
                    dir = 0;
            }
        }
    }

    vector<int> getPos() { return {x, y}; }

    string getDir() {
        if (dir == 1)
            return "North";
        if (dir == 0)
            return "East";
        if (dir == 2)
            return "West";

            return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
