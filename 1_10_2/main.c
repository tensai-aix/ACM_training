#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �Զ���ȽϺ���
int compare(const void* a, const void* b) {
    // �������ַ���ƴ�Ӻ�Ƚϣ����� "3" �� "30"��ƴ�Ӻ�õ� "330" �� "303"
    char str1[40], str2[40];
    sprintf(str1, "%s%s", (char*)b, (char*)a);
    sprintf(str2, "%s%s", (char*)a, (char*)b);
    // �Ƚ�ƴ�Ӻ���ַ��������ֵ�������
    return strcmp(str1, str2);
}

int main() {
    int n;
    scanf("%d", &n);

    char nums[n][11]; // ʹ���ַ������鴢����������֣�ÿ����������� 10 λ���֣��������ź� \0 ��β����

    for (int i = 0; i < n; i++) {
        scanf("%s", nums[i]);
    }

    // ʹ���Զ���ȽϺ�����������
    qsort(nums, n, sizeof(nums[0]), compare);

    // ��������������
    char result[10000] = "";
    for (int i = 0; i < n; i++) {
        strcat(result, nums[i]);
    }

    // ����������
    printf("%s\n", result);

    return 0;
}
