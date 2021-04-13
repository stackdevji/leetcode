//给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。 
//
// 你可以返回满足此条件的任何数组作为答案。 
//
// 
//
// 示例： 
//
// 输入：[3,1,2,4]
//输出：[2,4,3,1]
//输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= A.length <= 5000 
// 0 <= A[i] <= 5000 
// 
// Related Topics 数组

// 是否是奇数
bool isEven(int n) {
    return n & 1;
}

/**
 * 基础解法双指针
 * @param A
 * @param ASize
 * @param func  函数指针 增加扩展性 比如我想让奇数在偶数前面  或者让负数在非负数前面
 */
void sortArrayByParity(int* A, int ASize, bool (*func)(int)){
    if (!A || ASize <= 0) return;

    int *left = A;
    int *right = A + ASize - 1;
    while (left < right) {
        while (left < right && func(*left)) left++;
        while (left < right && func(*right)) right--;
        if (left < right) {
            *left    = *left ^ *right;
            *right   = *left ^ *right;
            *left    = *left ^ *right;
        }
    }
}

//leetcode submit region begin(Prohibit modification and deletion)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    if (!A || ASize <= 0) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = 0;
    for (int i = 0; i < ASize; ++i) {
        (*returnSize)++;
    }
    int *res = malloc(sizeof(int) * (*returnSize));
    int *left = res;
    int *right = res + (*returnSize) - 1;
    for (int i = 0; i < ASize; ++i) {
        if ((A[i] & 1) == 1) {
            *right = A[i];
            right--;
        } else {
            *left = A[i];
            left++;
        }
    }
    return res;
}

//leetcode submit region end(Prohibit modification and deletion)
