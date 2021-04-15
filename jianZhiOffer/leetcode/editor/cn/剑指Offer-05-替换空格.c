//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。 
//
// 
//
// 示例 1： 
//
// 输入：s = "We are happy."
//输出："We%20are%20happy." 
//
// 
//
// 限制： 
//
// 0 <= s 的长度 <= 10000 
// 👍 98 👎 0

// 思路：


//leetcode submit region begin(Prohibit modification and deletion)

char* replaceSpace(char* s){
    if (s == NULL) {
        return NULL;
    }

    // 计算空格数量
    int i = 0;
    int spaceLen = 0;
    while (s[i] != '\0')
    {
        if (s[i] == ' ')
        {
            spaceLen++;
        }
        i++;
    }

    // i此时指向'\0', 但是值是下标
    int newLen = i + 1 + spaceLen * 2;
    char* newStr = (char*)malloc(sizeof(char) * newLen);
    newLen--;

    while (i >= 0 && newLen >= i) {
        if (s[i] == ' ') {
            newStr[newLen--] = '0';
            newStr[newLen--] = '2';
            newStr[newLen--] = '%';
        } else {
            newStr[newLen--] = s[i];
        }
        i--;
    }

    return newStr;
}


//leetcode submit region end(Prohibit modification and deletion)
