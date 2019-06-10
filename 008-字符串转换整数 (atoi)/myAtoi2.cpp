#include <string>
#include <climits>
#include <cctype>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if (str == "") {
            return 0;
        }

        int len = str.size();

        int i = 0;
        // 跳过开头的空格
        while (i < len && str[i] == ' ') {
            ++i;
        }
        
        // 是否为负数
        bool isNegative = false;
        if (str[i] == '-') {
            isNegative = true;
            ++i;
        } else if (str[i] == '+') {
            ++i;
        }

        // 转换为整型
        double sum = 0; // 取 double，为了处理溢出的情况
        while (i < len && isdigit(str[i])) {
            int n = charToNum(str[i]);

            // 每一次转成数字都检测一次是否溢出
            if (isNegative) {
                // 此处不能写成 -INT_MIN / 10，因为 -INT_MIN = INT_MAX + 1，溢出了
                if (sum > -(INT_MIN / 10) || (sum == -(INT_MIN / 10) && n >= -(INT_MIN % 10))) {
                    return INT_MIN;
                }
            } else {
                if (sum > INT_MAX / 10 || (sum == INT_MAX / 10 && n >= INT_MAX % 10)) {
                    return INT_MAX;
                }
            }

            sum = sum * 10 + n;
            ++i;
        }

        // 负数
        if (isNegative) {
            sum = -sum;
        }

        return sum;
    }

private:
    int charToNum(char c) {
        return c - '0';
    }
};
