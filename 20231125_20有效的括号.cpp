#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

/*
 *  给你一个下标从 0 开始长度为 n 的整数数组 nums 和一个整数 target ，请你返回满足 0 <= i < j < n 且 nums[i] + nums[j] < target 的下标对 (i, j) 的数目。
 */
class Solution {
public:
    // 1. 暴力解 采用了栈结构
    bool isValid1(string s) {
        stack<char> st_char;
        for (const auto &item: s) {
            if (item == '(' || item == '[' || item == '{') {
                st_char.push(item);
            } else {
                if (!st_char.empty()) {
                    char temp = st_char.top();
                    st_char.pop();
                    if (!item) {
                        return false;
                    } else if (item == ')' && temp != '(') {
                        return false;
                    } else if (item == ']' && temp != '[') {
                        return false;
                    } else if (item == '}' && temp != '{') {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        if (st_char.empty()) {
            return true;
        } else {
            return false;
        }

    }

    //2.采用了哈希表存储对应关系
    bool isValid2(string s) {
        stack<char> parentheses;
        unordered_map<char, char> mapping = {{')', '('},
                                             {']', '['},
                                             {'}', '{'}};
        for (char c: s) {
            if (c == '(' || c == '[' || c == '{') {
                parentheses.push(c);
            } else {
                // 栈为空或者栈顶与当前括号不对应
                if (parentheses.empty() || parentheses.top() != mapping[c]) {
                    return false;
                }
                parentheses.pop();
            }
        }

        return parentheses.empty();

    }

    //2.采用了哈希表存储对应关系
    bool isValid(string s) {
        // 奇数直接截断
        if (s.length() % 2 == 1) {
            return false;
        }
        stack<char> parentheses;
        unordered_map<char, char> mapping = {{')', '('},
                                             {']', '['},
                                             {'}', '{'}};
        int leftSum = 0;
        for (char c: s) {
            // 左括号数量>总括号的一半 立即截断
            if (leftSum>(s.length()/2)){
                return false;
            }
            if (c == '(' || c == '[' || c == '{') {
                parentheses.push(c);leftSum++;
            } else {
                // 栈为空或者栈顶与当前括号不对应
                if (parentheses.empty() || parentheses.top() != mapping[c]) {
                    return false;
                }
                parentheses.pop();
            }
        }

        return parentheses.empty();

    }

};


int main() {
    Solution solution = *new Solution;
    bool res = solution.isValid("[{([[]");
    cout << res << endl;
    return -1;
}
