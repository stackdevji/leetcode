//实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。 
//
// 
//
// 示例 1： 
//
// 
//输入：x = 2.00000, n = 10
//输出：1024.00000
// 
//
// 示例 2： 
//
// 
//输入：x = 2.10000, n = 3
//输出：9.26100 
//
// 示例 3： 
//
// 
//输入：x = 2.00000, n = -2
//输出：0.25000
//解释：2-2 = 1/22 = 1/4 = 0.25 
//
// 
//
// 提示： 
//
// 
// -100.0 < x < 100.0 
// -231 <= n <= 231-1 
// -104 <= xn <= 104 
// 
//
// 
//
// 注意：本题与主站 50 题相同：https://leetcode-cn.com/problems/powx-n/ 
// Related Topics 递归 
// 👍 149 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

// 偶数次幂只需要计算一次即可, 然后让结果 res *= res
// x^16 = x^8 * x^8
// x^8 = x^4 * x^4
// x^4 = x^2 * x^2
// x^2 = x * x

// 奇数
// x^5 = x^2 * x^2 * x
double absPow(double x, unsigned int absN) {
    if (absN == 0) return 1.0;
    if (absN == 1) return x;

    double res = absPow(x, absN >> 1);
    res *= res;

    if (absN & 1 == 1) res *= x;

    return res;
}

double myPow(double x, int n){
    if (x == 0.0) return 0.0;

    // 防止数组越界溢出
    unsigned int absN = n;
    absN = n < 0 ? (unsigned int)(-absN) : (unsigned int)n;

    double res = absPow(x, absN);
    if (n < 0) res = 1.0 / res;

    return res;
}


//leetcode submit region end(Prohibit modification and deletion)
