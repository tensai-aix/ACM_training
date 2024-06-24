#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 自定义比较函数
int compare(const void* a, const void* b) {
    // 将两个字符串拼接后比较，比如 "3" 和 "30"，拼接后得到 "330" 和 "303"
    char str1[40], str2[40];
    sprintf(str1, "%s%s", (char*)b, (char*)a);
    sprintf(str2, "%s%s", (char*)a, (char*)b);
    // 比较拼接后的字符，按照字典序排序
    return strcmp(str1, str2);
}

int main() {
    int n;
    scanf("%d", &n);

    char nums[n][11]; // 使用字符串数组储存输入的数字，每个数字最多有 10 位数字（包括负号和 \0 结尾符）

    for (int i = 0; i < n; i++) {
        scanf("%s", nums[i]);
    }

    // 使用自定义比较函数进行排序
    qsort(nums, n, sizeof(nums[0]), compare);

    // 连接排序后的整数
    char result[10000] = "";
    for (int i = 0; i < n; i++) {
        strcat(result, nums[i]);
    }

    // 输出最大整数
    printf("%s\n", result);

    return 0;
}
