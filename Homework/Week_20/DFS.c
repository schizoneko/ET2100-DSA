#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 7

typedef struct Student {
    long mssv;
    char name[50];
    float cpa;
    int visited;
} Student;

Student students[MAX];
int adj[MAX][MAX]; // Ma trận kề

void init_students() {
    for (int i = 0; i < MAX; i++) {
        students[i].mssv = 1000 + i;
        sprintf(students[i].name, "Sinh vien %d", i + 1);
        students[i].cpa = 2.5 + 0.1 * i;
        students[i].visited = 0;
    }
}

void init_graph() {
    memset(adj, 0, sizeof(adj));
    adj[0][1] = adj[0][2] = 1;       // 1 -> 2, 1 -> 3
    adj[1][3] = adj[1][4] = 1;       // 2 -> 4, 2 -> 5
    adj[2][4] = 1;                   // 3 -> 5
    adj[3][5] = 1;                   // 4 -> 6
    adj[4][5] = adj[4][6] = 1;       // 5 -> 6, 5 -> 7
    adj[5][6] = 1;                   // 6 -> 7
}

void reset_visited() {
    for (int i = 0; i < MAX; i++) {
        students[i].visited = 0;
    }
}

void DFS(int v) {
    students[v].visited = 1;
    printf("MSSV: %ld | Tên: %s | CPA: %.2f\n", students[v].mssv, students[v].name, students[v].cpa);
    for (int i = 0; i < MAX; i++) {
        if (adj[v][i] && !students[i].visited) {
            DFS(i);
        }
    }
}

float average_CPA_BFS(int start) {
    int queue[MAX];
    int front = 0, rear = 0;
    int count = 0;
    float total = 0.0;

    reset_visited();

    queue[rear++] = start;
    students[start].visited = 1;

    while (front < rear) {
        int v = queue[front++];
        total += students[v].cpa;
        count++;

        for (int i = 0; i < MAX; i++) {
            if (adj[v][i] && !students[i].visited) {
                queue[rear++] = i;
                students[i].visited = 1;
            }
        }
    }

    return (count == 0) ? 0 : total / count;
}

int main() {
    init_students();
    init_graph();

    printf("----- Duyệt đồ thị theo DFS -----\n");
    reset_visited();
    DFS(0);  // Bắt đầu từ đỉnh 0 (tức sinh viên số 1)

    printf("\n----- Tính điểm CPA trung bình bằng BFS -----\n");
    float avg_cpa = average_CPA_BFS(0);
    printf("CPA trung bình của tất cả sinh viên: %.2f\n", avg_cpa);

    return 0;
}
