#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int length = s.size();
        for (int i = 0; i < length; i += 2 * k) {
            int left = i;
            int right = min(length - 1, i + k - 1);
            while (left < right) {
                swap(s[left], s[right]);
                ++left;
                --right;
            }
        }

        return s;
    }
};
