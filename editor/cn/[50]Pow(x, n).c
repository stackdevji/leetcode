//实现 pow(x, n) ，即计算 x 的 n 次幂函数。 
//
// 示例 1: 
//
// 输入: 2.00000, 10
//输出: 1024.00000
// 
//
// 示例 2: 
//
// 输入: 2.10000, 3
//输出: 9.26100
// 
//
// 示例 3: 
//
// 输入: 2.00000, -2
//输出: 0.25000
//解释: 2^-2 = 1/2^2 = 1/4 = 0.25
//
// 说明: 
//
// 
// -100.0 < x < 100.0 
// n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。 
// 
// Related Topics 数学 二分查找

// 思想：
// 1. 注意边界问题
//      x为0.0的情况
//      unsigned int 和 int的取值范围 因为要算绝对值
// 2. 普通循环 res *= res效率不高
//      求x^32求解可拆分过程如下
//      x^32 = x^16 * x^16
//      x^16 = x^8 * x^8
//      x^8 = x^4 * x^14
//      x^4 = x^2 * x^2
//      x^2 = x * x
// 3. 除2操作可使用 n >> 1  判断奇偶可使用 n & 1 == 1(奇数)

//leetcode submit region begin(Prohibit modification and deletion)

double powByAbsN(double x, unsigned int absN) {
    if (absN == 0) return 1;
    if (absN == 1) return x;

    double res = powByAbsN(x, absN >> 1);
    res *= res;
    if (absN & 1) res *= x; // 奇数
    return res;
}


double myPow(double x, int n){
    // 防止x是0 当n < 0时 取到数时程序报错
    if (x == 0.0) return 0.0;

    // 计算n的绝对值 并且转成无符号的整数
    unsigned int absN = n;
    if (n < 0) absN = (unsigned int)(-absN);
    else absN = (unsigned int)n;

    double res = powByAbsN(x, absN);
    if (n < 0) return 1.0 / res;
    return res;
}


//leetcode submit region end(Prohibit modification and deletion)
