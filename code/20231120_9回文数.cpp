#include <iostream>
#include <algorithm>

using namespace std;

/*
 *  给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
    回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
    例如，121 是回文，而 123 不是。
 */
class Solution {
public:

    // 1. 暴力解 计划用空间换时间
    bool isPalindrome1(int x) {
        // 直接截断一部分值
        if (x < 0) {
            return false;
        } else if (x == 0) {
            return true;
        }

        //x>0情况
        // 定义并初始化
        int a[12];
        for (int i = 0; i < 12; ++i) {
            a[i] = -1;
        }

        int len = 0;
        while (x > 0) {
            a[len] = x % 10;
            x /= 10;
            len++;
        }
        for (int j = 0, i = len - 1; j < len / 2 + 1;) {
            if (a[j] == a[i]) {
                j++;
                i--;
            } else {
                return false;
            }
        }
        for (int i = 0; i < 12; ++i) {
            cout << a[i] << endl;
        }
        return true;
    }

    // 2. 初次优化
    bool isPalindrome2(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            // 如果 x 是负数，或者 x 的最后一位是 0 但 x 不是 0，则不是回文数
            // 1230 2310
            return false;
        }

        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        // 12321>0,r=1,  x=1232;
        // 1232>1 ,r=12, x=123;
        // 123>12?

        // 1221>0,r=1, x=122
        // 122>0,r=12, x=12
        // 12>12?

        // 当数字长度为奇数时，通过 reversed / 10 去掉中间位
        return x == reversed || x == reversed / 10;
    }

    // 2. 初次优化
    bool isPalindrome(int x) {
        string target = to_string(x);

        string target_reverse = target;
        reverse(target_reverse.begin(), target_reverse.end());
        if (!target.compare(target_reverse)) {
            return true;
        }
        return false;
    }

};


int main9() {
    Solution solution = *new Solution;
    bool res = solution.isPalindrome(12321);
    if (res) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
