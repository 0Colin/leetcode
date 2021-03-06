# 118-杨辉三角

## 题目

leetcode：[118-杨辉三角](https://leetcode-cn.com/problems/pascals-triangle/)

## 思路

参考[LeetCode杨辉三角官方解答](https://leetcode-cn.com/problems/pascals-triangle/solution/)。

```c++
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if (numRows == 0) {
            return res;
        }

        res.push_back(vector<int>(1, 1));
        vector<int> temp(2, 1);
        vector<int>::iterator it;
        for (int i = 1; i < numRows; ++i) {
            for (it = res[i - 1].begin(); it != res[i - 1].end() && it + 1 != res[i - 1].end(); ++it) {
                temp.insert(temp.end() - 1, *it + *(it + 1));
            }
            res.push_back(temp);
            temp.erase(temp.begin() + 1, temp.end() - 1); // 只留下头尾的两个“1”，其他元素都删除
        }

        return res;
    }
};
```

