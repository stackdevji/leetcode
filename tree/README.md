# 树相关算法

## 二叉树
刷题模板：[repo wiki](https://greyireland.gitbook.io/algorithm-pattern/shu-ju-jie-gou-pian/binary_tree)

### 二叉树的遍历（递归，迭代）

前序遍历：根->左->右

中序遍历：左->根->右

后序遍历：左->右->根

层序遍历：借助队列 BFS

递归：输出元素时机

迭代：借助栈，先把左节点入栈，出栈时机，后续遍历要记住上一次遍历的节点，要保证右节点出栈之后在出栈根节点

### 分治法
* 快速排序
* 归并排序
* 二叉树的相关操作

分治算法模板：
* 递归条件处理
* 分段处理
* 合并结果
```$go
func traversal(root *TreeNode) ResultType  {
    // nil or leaf
    if root == nil {
        // do something and return
    }

    // Divide
    ResultType left = traversal(root.Left)
    ResultType right = traversal(root.Right)

    // Conquer
    ResultType result = Merge from left and right

    return result
}
```



