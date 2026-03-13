// 17:00 -- 
#include <stdio.h>
#include <string.h>

#define MAXN 105

char maze[MAXN][MAXN];  // maze map
int visited[MAXN][MAXN][4]; // visited for each direction
typedef struct Node {
    int x, y;
    int direction;  // 面朝方向
    int turnCnt; // 转弯次数
} Node;
Node que[MAXN * MAXN * 40]; // bfs-queue
int front, tail;
// 上左下右
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

// maze and location
int m, n;
int k, x1, y_1, x2, y2;

void bfs() {
    front = tail = 0;
    memset(visited, 0x3f, sizeof(visited));
    Node src = {x1, y_1, 0, 0};
    for (int i = 0; i < 4; i++) {
        // 四个方向全入队
        src.direction = i;
        que[tail++] = src;
    }
    while(tail > front) {
        Node cur = que[front++];    // 出队
        for (int i = 0; i < 4; i++) {
            int x = cur.x + dx[i];
            int y = cur.y + dy[i];
            if (x < 0 || x >= m || y < 0 || y >= n || maze[x][y] == '*') {
                // 新点不能走
                continue;
            }
            Node next = cur;
            next.x = x, next.y = y;
            // if (i != next.direction) {
            //     // 转向了
            //     next.turnCnt++;
            //     // 转向次数太多了，不行
            //     if (next.turnCnt > k) continue;
            //     next.direction = i;
            // }
            if (i != cur.direction) {
                next.turnCnt++;
            }
            next.direction = i;
            if (next.turnCnt > k) continue;
            // 没有上一次来的好，也不行
            if (next.turnCnt >= visited[x][y][i]) continue;
            visited[x][y][i] = next.turnCnt;
            // 检查新点是终点吗
            if (x == x2 && y == y2) {
                printf("yes\n");
                return;
            }
            // 新点入队
            que[tail++] = next;
        }
    }
    printf("no\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        // input maze
        scanf("%d %d", &m, &n);
        for (int i = 0; i < m; i++) {
            scanf("%s", maze[i]);
        }
        scanf("%d %d %d %d %d", &k, &y_1, &x1, &y2, &x2);
        x1--, y_1--, x2--, y2--;
        if (maze[x1][y_1] == '*' || maze[x2][y2] == '*') {
            printf("no\n");
            continue;
        } else if (x1 == x2 && y_1 == y2) {
            printf("yes\n");
            continue;
        }
        bfs();
    }

    return 0;
}