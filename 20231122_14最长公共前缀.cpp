#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

/*
 *  编写一个函数来查找字符串数组中的最长公共前缀。

    如果不存在公共前缀，返回空字符串 ""。
 */
class Solution {
public:
    // 1. 暴力解 历史最差代码没有之一
    string longestCommonPrefix1(vector<string> &strs) {
        if (strs[0] == "") {
            return "";
        }
        int maxsize = -1;
        for (const auto &item: strs) {
            maxsize = max(maxsize, static_cast<int>(item.size()));
        }
        string res;
        for (int i = 0; i < maxsize; ++i) {
            char temp = strs[0][i];
            string tmp;
            for (int j = 0; j < strs.size(); ++j) {
                if (temp == strs[j][i]) {
                    cout << "temp: " << temp << "   strs[j][i]: " << strs[j][i] << "  i: " << i << " j: " << j << endl;
                    tmp = strs[j][i];
                } else {
                    tmp = "";
                    goto outerLoop; // 跳到外层循环的标签位置
                }
            }
            res.append(tmp);
        }
        outerLoop:
        return res;
    }

    // 2. 尝试去优化
    string longestCommonPrefix2(vector<string> &strs) {
        string res;
        // 先每个单词，再总体
        for (int i = 0; i < 200; ++i) {
            if (i > strs[0].length())
                return res; //处理空情况
            char tmp = strs[0][i];
            for (const auto &s: strs) {
                if (i >= s.length())
                    return res;// 超出了，则说明当前字符串长度不够 flower flow  i=5 >= 4
                if (s[i] != tmp)
                    return res;
            }
            res += tmp;
        }
        return res;
    }

    // 3. 尝试去优化
    string longestCommonPrefix(vector<string> &strs) {
        string ans = "";
        // 用第一个单词的字符一次遍历全部字符串
        for (int i = 0; i < strs[0].size(); ++i) {
            bool flag = true;
            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[j][i] != strs[0][i]) {
                    flag = false; // 合二为一
                    break; // 退出里循环
                }
            }
            if (flag) {
                ans += strs[0][i];
            } else {
                break; // 退出外循环
            }
        }
        return ans;
    }
};


int main14() {
    Solution solution = *new Solution;
    vector<string> strVector = {"flower", "flower", "flower", "flower"};
    string res = solution.longestCommonPrefix(strVector);
    cout << res << endl;
    return 0;
}
