#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m); // 输入n和m的值

    int counts[n]; // 用数组counts来记录每个数出现的次数
    for (int i = 0; i < n; i++) {
        counts[i] = 0; // 初始化counts数组为0
    }

    for (int i = 0; i < m; i++) {
        int num;
        scanf("%d", &num); // 输入当前数字num
        counts[num - 1]++; // 对应数字的计数加1
    }

    int min_count = m; // 将最小次数初始化为总数字个数m
    for (int i = 0; i < n; i++) {
        if (counts[i] < min_count) {
            min_count = counts[i]; //更新最小次数
        }
    }

    printf("%d\n", min_count); // 输出最少次数

    return 0;
}
