#include <vector>
using namespace std;

// 摩尔投票算法
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int count = 0;
        int num = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (num == nums[i]) {
                ++count;
            } else {
                --count;
            }

            if (count == 0) {
                num = nums[i];
                count = 1;
            }
        }

        return checkMoerThanHalf(nums, num) ? num : 0;
    }

private:
    // 检查number的个数是否超过数组个数的一半
    bool checkMoerThanHalf(vector<int> nums, int number) {
        int count = 0;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            if (*it == number) {
                ++count;
            }
        }

        return count > nums.size() / 2 ? true : false;
    }
};