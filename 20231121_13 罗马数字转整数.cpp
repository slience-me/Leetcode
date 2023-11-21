#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
 *  罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

    字符          数值
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
    例如， 罗马数字 2 写做 II ，即为两个并列的 1 。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

    通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
    I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
    X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
    C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
    给定一个罗马数字，将其转换成整数。
 */
class Solution {
public:
    // 1. 暴力解 字符串翻转后 使用了两个值记录前后关系
    int romanToInt1(string s) {
        unordered_map<char, int> myMap = {{'I', 1},
                                          {'V', 5},
                                          {'X', 10},
                                          {'L', 50},
                                          {'C', 100},
                                          {'D', 500},
                                          {'M', 1000}};
        int sum = 0;
        reverse(s.begin(), s.end());
        char this_char = 0;
        char last_char = 0;
        for (int i = 0; i < s.length(); ++i) {
            this_char = s[i];
            if (this_char == 'I' && last_char == 'V') {
                sum -= 1;  // 4 = 5-1
            } else if (this_char == 'I' && last_char == 'X') {
                sum -= 1;  // 9 = 10-1
            } else if (this_char == 'X' && last_char == 'L') {
                sum -= 10; // 40 = 50-10
            } else if (this_char == 'X' && last_char == 'C') {
                sum -= 10; // 90 = 100-10
            } else if (this_char == 'C' && last_char == 'D') {
                sum -= 100; // 400 = 500-100
            } else if (this_char == 'C' && last_char == 'M') {
                sum -= 100; // 900 = 1000-100
            } else {
                sum += myMap[s[i]];
            }
            last_char = this_char;
        }
        return sum;

    }

    int romanToInt2(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'M') {
                sum += 1000;
            } else if (s[i] == 'D') {
                sum += 500;
            } else if (s[i] == 'C') {
                if (s[i + 1] == 'M' || s[i + 1] == 'D') {
                    sum -= 100;
                } else {
                    sum += 100;
                }
            } else if (s[i] == 'L') {
                sum += 50;
            } else if (s[i] == 'X') {
                if (s[i + 1] == 'L' || s[i + 1] == 'C') {
                    sum -= 10;
                } else {
                    sum += 10;
                }
            } else if (s[i] == 'V') {
                sum += 5;
            } else if (s[i] == 'I') {
                if (s[i + 1] == 'X' || s[i + 1] == 'V') {
                    sum -= 1;
                } else {
                    sum += 1;
                }
            }
        }
        return sum;
    }

    int romanToInt(string s) {
        unordered_map<char, int> romanMap = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
        };

        int result = 0;

        for (int i = 0; i < s.length(); ++i) {
            // 如果当前字符代表的值小于下一个字符代表的值，则减去当前值
            if (i + 1 < s.length() && romanMap[s[i]] < romanMap[s[i + 1]]) {
                result -= romanMap[s[i]];
            } else {
                result += romanMap[s[i]];
            }
        }

        return result;
    }

};


int main13() {
    Solution solution = *new Solution;
    int res = solution.romanToInt("IX");
    cout << res << endl;
    return 0;
}
