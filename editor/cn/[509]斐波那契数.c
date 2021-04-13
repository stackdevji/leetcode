//斐波那契数，通常用 F(n) 表示，形成的序列称为斐波那契数列。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是： 
//
// F(0) = 0,   F(1) = 1
//F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
// 
//
// 给定 N，计算 F(N)。 
//
// 
//
// 示例 1： 
//
// 输入：2
//输出：1
//解释：F(2) = F(1) + F(0) = 1 + 0 = 1.
// 
//
// 示例 2： 
//
// 输入：3
//输出：2
//解释：F(3) = F(2) + F(1) = 1 + 1 = 2.
// 
//
// 示例 3： 
//
// 输入：4
//输出：3
//解释：F(4) = F(3) + F(2) = 2 + 1 = 3.
// 
//
// 
//
// 提示： 
//
// 
// 0 ≤ N ≤ 30 
// 
// Related Topics 数组



//leetcode submit region begin(Prohibit modification and deletion)

// 普通的递归写法
// 缺点，随着N增大，就会发现重复计算的F(m)越来越多
// 时间复杂度会随着n成指数增加（可以看成是一棵树）效率大大降低
//int fib(int N){
//    if (N == 0) return 0;
//    if (N == 1) return 1;
//    return fib(N - 1) + fib(N - 2);
//}

// 迭代解法 记录已经计算过的f(m)数据 时间复杂度o(N)
int fib(int N){
    int simpleData[2] = {0, 1};
    if (N >= 0 && N < 2) return simpleData[N];

    int fibN_1 = 1; // f(n-1)
    int fibN_2 = 0; // f(n-2)
    int fibN = 0;
    for (int i = 2; i <= N; ++i) {
        fibN = fibN_1 + fibN_2;
        fibN_2 = fibN_1;
        fibN_1 = fibN;
    }
    return fibN;
}


//leetcode submit region end(Prohibit modification and deletion)
