//给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。 
//
// 示例 1: 
//
// 输入: 2
//输出: 1
//解释: 2 = 1 + 1, 1 × 1 = 1。 
//
// 示例 2: 
//
// 输入: 10
//输出: 36
//解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。 
//
// 说明: 你可以假设 n 不小于 2 且不大于 58。 
// Related Topics 数学 动态规划

// 动态规划思想
// f(n) = 将长度为n绳子分成若干段的最大乘积 第一次拆分可以从i = 1,2,3 ... n - 1处开始 f(n) = max(f(i) * f(n - i))
// 将f(n)最优解拆分为子问题的最优解 然后自底向上求解
// n <= 1 时输出0
// n = 2时 只有一种可能 1 + 1 输出  1
// n = 3时 1 * 2 > 1 + 1 + 1 输出 2
// n = 4 开始 最大乘积开始 = 本身
// n = 5 开始 最大乘积 6  已经 > 本身
// 我们需要定义一个存储f(n)最大乘积数组 maxProductArr i（0 <= i <= n）代表长度为i拆分最大乘积
// 但是 n <= 3时 乘积都小于本身，那么当拆分长度 n >= 4 的整数时，拆分的和可能有 f(1) * f(3) 或者 f(2) * f(2)
// 只要是使用f(2) 或者 f(3)时，用其乘积比自身长度小，算出的乘积结果不准，所以最大乘积数组(i <= 3)时元素值需定义为长度本身
// n >= 4 的时候 f(n) >= n 则可直接赋值给 maxProductArr 数组 供后续使用

// 注意： n 拆分和 时 会有重复 比如 3 拆分点i从1到2可分为 （1 2） 和 （2 1）所以判断时 只需判断 i <= n / 2 即可（即 1，2的乘积只计算一次）
// 动态规划，时间复杂度 o(n^2) 空间复杂度 o(n)
int integerBreak(int n){
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n == 3) return 2;

    // 定义f(n)数组 即n拆分整数和的最大乘积数组 长度为n + 1 包含下标0
    int *maxProductArr = malloc(sizeof(int) * (n + 1));
    // 由于 n <= 3 时，乘积都小于本身，所以此处元素值为本身
    maxProductArr[0] = 0;
    maxProductArr[1] = 1;
    maxProductArr[2] = 2;
    maxProductArr[3] = 3;

    int max = 0;
    for (int i = 4; i <= n; ++i) { // 第一个循环自小到大控制 4 ~ n 的乘积计算
        for (int j = 1; j <= i / 2; ++j) { // 第二个循环只控制乘积计算，但只需计算到 i / 2为止，过滤重复计算
            int product = maxProductArr[j] * maxProductArr[i - j];
            if (max < product) max = product;
        }
        maxProductArr[i] = max;
    }
    max = maxProductArr[n];
    free(maxProductArr); // 释放空间
    return max;
}

//leetcode submit region begin(Prohibit modification and deletion)

// 贪婪算法实现 空间和时间复杂度o(1)
// 1 2 3 是构成 n >= 4的基本组合 这里3的长度最大
// 所以我们尽可能将整数按照3拆分 这里我们定义 m = n / 3, x = n - 3m 其实也是余数(x = n % 3) 我们看下x的值情况如下
// 1. x == 0 product = 3^m * 1
// 2. x == 1 这种情况说明 (m - 1) * 3 + 4 = n 但是4不应该被分成1和3 应该分成 2 + 2 这里乘积 3^(m-1) * 2^2最大
// 3. x == 2 乘积为 3^m * 2
// 综上：我们最大乘积计算其实就是计算 3^m * 2^i 也就是说我们只需要3的指数个数和2的指数个数

int integerBreak(int n){
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n == 3) return 2;

    int cnt_3 = n / 3;
    int mod = n % 3;
    int cnt_2 = mod / 2;
    if (1 == mod) {
        cnt_3 -= 1;
        cnt_2 = 2; // 4/2
    }

    return pow(3,cnt_3) * pow(2, cnt_2);
}


//leetcode submit region end(Prohibit modification and deletion)
