//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。 
//
// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？ 
//
// 注意：给定 n 是一个正整数。 
//
// 示例 1： 
//
// 输入： 2
//输出： 2
//解释： 有两种方法可以爬到楼顶。
//1.  1 阶 + 1 阶
//2.  2 阶 
//
// 示例 2： 
//
// 输入： 3
//输出： 3
//解释： 有三种方法可以爬到楼顶。
//1.  1 阶 + 1 阶 + 1 阶
//2.  1 阶 + 2 阶
//3.  2 阶 + 1 阶
// 
// Related Topics 动态规划

// 思想
// n = 1    1种
// n = 2    2种
// n > 2    第一次爬一层 = 后面f(n-1)的爬法 第一次爬两层 = 后面f(n-2)的爬法
// 由此可见就是斐波那契数列 只是初始值不一样

// 相似题 1次可以爬一层 也可以爬2层 还可以爬n层
// 1        1                   1种
// 2        1 + 2               2种
// 3        1 + 2 + 3           3种
// 4        1 + 2 + 3 + 4
// n        1 + f(1) + f(2) + f(3) + ... + f(n-2) + f(n-1) = f(n)
//

//leetcode submit region begin(Prohibit modification and deletion)


int climbStairs(int n){
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    int fibN_1 = 2; // f(n-1) f(2)
    int fibN_2 = 1; // f(n-2) f(1)
    int fibN = 0;
    for (int i = 3; i <= n; ++i) {
        fibN = fibN_1 + fibN_2;
        fibN_2 = fibN_1;
        fibN_1 = fibN;
    }
    return fibN;
}


//leetcode submit region end(Prohibit modification and deletion)
