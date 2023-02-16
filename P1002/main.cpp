#include <iostream>
using namespace std;

struct pos {
    int x, y;
};

pos target, obstacle;
long long map[21][21];

void setObstacle() {
    // C
    map[obstacle.x][obstacle.y] = -1;
    // P1
    if (obstacle.x + 2 <= target.x && obstacle.y + 1 <= target.y)
        map[obstacle.x + 2][obstacle.y + 1] = -1;
    // P2
    if (obstacle.x + 1 <= target.x && obstacle.y + 2 <= target.y)
        map[obstacle.x + 1][obstacle.y + 2] = -1;
    // P3
    if (obstacle.x - 1 >= 0 && obstacle.y + 2 <= target.y)
        map[obstacle.x - 1][obstacle.y + 2] = -1;
    // P4
    if (obstacle.x - 2 >= 0 && obstacle.y + 1 <= target.y)
        map[obstacle.x - 2][obstacle.y + 1] = -1;
    // P5
    if (obstacle.x - 2 >= 0 && obstacle.y - 1 >= 0)
        map[obstacle.x - 2][obstacle.y - 1] = -1;
    // P6
    if (obstacle.x - 1 >= 0 && obstacle.y - 2 >= 0)
        map[obstacle.x - 1][obstacle.y - 2] = -1;
    // P7
    if (obstacle.x + 1 <= target.x && obstacle.y - 2 >= 0)
        map[obstacle.x + 1][obstacle.y - 2] = -1;
    // P8
    if (obstacle.x + 2 <= target.x && obstacle.y - 1 >= 0)
        map[obstacle.x + 2][obstacle.y - 1] = -1;
}

void derive (pos p) {
    // cout << "derive: " << p.x << " " << p.y << endl;
    if (map[p.x][p.y] != -1) {            
        // map[p.x][p.y] = 0;
        if (p.x - 1 >= 0 && map[p.x - 1][p.y] != -1)
            map[p.x][p.y] += map[p.x - 1][p.y];
        if (p.y - 1 >= 0 && map[p.x][p.y - 1] != -1)
            map[p.x][p.y] += map[p.x][p.y - 1];
    }
}

int main() {
    cin >> target.x >> target.y >> obstacle.x >> obstacle.y;
    setObstacle();

    map[0][0] = 1;

    // for (int i = 0; i <= target.x; i++) {
    //     for (int j = 0; j <= target.y; j++) {
    //         if (map[i][j] != -1) 
    //             cout << " ";
    //         cout << " " << map[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    int nx = 1, ny = 1;
    bool nxdone = false, nydone = false;
    while (true) {
        int sx = 0, sy = 0;
        // cout << "derive sq " << nx << " " << ny << endl;
        while(true) {
            pos p;
            if ((sx == nx || nydone) && (sy == ny || nxdone)) {
                p = {nx, ny};
                derive(p);
                break;
            }
            // map[nx][sy]
            if (!nxdone) {
                p = {nx, sy};
                derive(p);
            }
            // map[sx][ny]
            if (!nydone) {
                p = {sx, ny};
                derive(p);
            }

            if (sx + 1 <= nx)
                sx += 1;
            if (sy + 1 <= ny)
                sy += 1;
        }
        if (nx == target.x)
            nxdone = true;
        if (ny == target.y)
            nydone = true;
        if (nx == target.x && ny == target.y)
            break;
        if (nx + 1 <= target.x)
            nx += 1;
        if (ny + 1 <= target.y)
            ny += 1;
    }
    // for (int i = 0; i <= target.x; i++) {
    //     for (int j = 0; j <= target.y; j++) {
    //         if (map[i][j] != -1) 
    //             cout << " ";
    //         cout << " " << map[i][j];
    //     }
    //     cout << endl;
    // }
    cout << map[target.x][target.y];
    return 0;
}