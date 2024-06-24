#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m); // ����n��m��ֵ

    int counts[n]; // ������counts����¼ÿ�������ֵĴ���
    for (int i = 0; i < n; i++) {
        counts[i] = 0; // ��ʼ��counts����Ϊ0
    }

    for (int i = 0; i < m; i++) {
        int num;
        scanf("%d", &num); // ���뵱ǰ����num
        counts[num - 1]++; // ��Ӧ���ֵļ�����1
    }

    int min_count = m; // ����С������ʼ��Ϊ�����ָ���m
    for (int i = 0; i < n; i++) {
        if (counts[i] < min_count) {
            min_count = counts[i]; //������С����
        }
    }

    printf("%d\n", min_count); // ������ٴ���

    return 0;
}
