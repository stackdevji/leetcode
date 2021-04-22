//给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。
//请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18
//。 
//
// 示例 1： 
//
// 输入: 2
//输出: 1
//解释: 2 = 1 + 1, 1 × 1 = 1 
//
// 示例 2: 
//
// 输入: 10
//输出: 36
//解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36 
//
// 提示： 
//
// 
// 2 <= n <= 58 
// 
//
// 注意：本题与主站 343 题相同：https://leetcode-cn.com/problems/integer-break/ 
// Related Topics 数学 动态规划 
// 👍 217 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

// 贪婪算法实现 空间和时间复杂度o(1)
// 1 2 3 是构成 n >= 4的基本组合 这里3的长度最大
// 所以我们尽可能将整数按照3拆分 这里我们定义 m = n / 3, x = n - 3m 其实也是余数(x = n % 3) 我们看下x的值情况如下：
// 1. x == 0 product = 3^m * 1
// 2. x == 1 这种情况说明 (m - 1) * 3 + 4 = n 但是4不应该被分成1和3 应该分成 2 + 2 这里乘积 3^(m-1) * 2^2最大
// 3. x == 2 乘积为 3^m * 2
// 综上：我们最大乘积计算其实就是计算 3^m * 2^i 也就是说我们只需要3的指数个数和2的指数个数

int cuttingRope(int n){
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n == 3) return 2;

    // 按照3拆分
    int cnt_3 = n / 3;
    int mod = n % 3;

    // mod = 0, 1, 2
    int cnt_2 = mod / 2;
    if (mod == 1) {
        cnt_3 -= 1;
        cnt_2 = 2;
    }

    return pow(3, cnt_3) * pow(2, cnt_2);
}


//leetcode submit region end(Prohibit modification and deletion)
