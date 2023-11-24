#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

/*
 *  「HTML 实体解析器」 是一种特殊的解析器，它将 HTML 代码作为输入，并用字符本身替换掉所有这些特殊的字符实体。

    HTML 里这些特殊字符和它们对应的字符实体包括：

    双引号：字符实体为 &quot; ，对应的字符是 " 。
    单引号：字符实体为 &apos; ，对应的字符是 ' 。
    与符号：字符实体为 &amp; ，对应对的字符是 & 。
    大于号：字符实体为 &gt; ，对应的字符是 > 。
    小于号：字符实体为 &lt; ，对应的字符是 < 。
    斜线号：字符实体为 &frasl; ，对应的字符是 / 。
    给你输入字符串 text ，请你实现一个 HTML 实体解析器，返回解析器解析后的结果。
 */
class Solution {
public:
    // 1. 暴力解 历史最差代码没有之一
    string entityParser1(string text) {
        unordered_map<string, string> myMap = {{"&quot;",  "\""},
                                             {"&apos;",  "\'"},
                                             {"&amp;",   "&"},
                                             {"&gt;",    ">"},
                                             {"&lt;",    "<"},
                                             {"&frasl;", "/"}};
        for (const auto &map: myMap){
            string searchString = map.first;
            string replacementString = map.second;
            size_t pos = text.find(searchString); // 找到第一个匹配的位置
            // 循环替换所有匹配的内容
            while (pos != string::npos) {
                text.replace(pos, searchString.length(), replacementString); // 用替换字符串替换匹配字符串
                pos = text.find(searchString, pos + replacementString.length()); // 继续找下一个匹配的位置
            }

            cout << "Modified text: " << text << std::endl;
        }
        return text;
    }
    // 方法2 超时了
    string entityParser2(string text) {
        unordered_map<string, string> myMap = {{"&quot;",  "\""},
                                               {"&apos;",  "\'"},
                                               {"&amp;",   "&"},
                                               {"&gt;",    ">"},
                                               {"&lt;",    "<"},
                                               {"&frasl;", "/"}};
        for (int i = 0; i < text.length(); ++i){
            string temp="&";
            char a = text[i];
            if (text[i]=='&'){
                if (text[i+1]=='\0' || text[i+1]=='&'){
                    continue;
                }
                int indexj = i+1;
                while (text[indexj]!=';'){
                    if (indexj>=text.length()){
                        break;
                    }
                    temp += text[indexj];
                    indexj+=1;
                }
                if (indexj>=text.length()){
                    break;
                }
                temp += ';';
                size_t index = replaceStr(text, myMap, temp);
                if (index != -1){
                    i = index;
                }
            } else if(text[i]=='\0'){
                continue;
            }
        }
        return text;
    }

    size_t replaceStr(string &text, unordered_map<string, string> &myMap, const string &temp) const {
        if(myMap.find(temp) != myMap.end()){
            string searchString = myMap.find(temp)->first;
            string replacementString = myMap.find(temp)->second;
            size_t pos = text.find(searchString); // 找到第一个匹配的位置
            // 循环替换所有匹配的内容
            text.replace(pos, searchString.length(), replacementString); // 用替换字符串替换匹配字符串
            return pos+replacementString.length()-1;
        }
        return -1;
    }
    string entityParser(string text) {
        string result = "";
        int i = 0;
        int n = text.length();
        while (i < n) {
            if (text[i] == '&') {
                if (text.substr(i, 6) == "&quot;") {
                    result += "\"";
                    i += 6;
                } else if (text.substr(i, 6) == "&apos;") {
                    result += "'";
                    i += 6;
                } else if (text.substr(i, 5) == "&amp;") {
                    result += "&";
                    i += 5;
                } else if (text.substr(i, 4) == "&gt;") {
                    result += ">";
                    i += 4;
                } else if (text.substr(i, 4) == "&lt;") {
                    result += "<";
                    i += 4;
                } else if (text.substr(i, 7) == "&frasl;") {
                    result += "/";
                    i += 7;
                } else {
                    result += text[i];
                    i++;
                }
            } else {
                result += text[i];
                i++;
            }
        }
        return result;
    }
};


int main1410() {
    Solution solution = *new Solution;
    string res = solution.entityParser("&&&amp&&");
    cout << res << endl;
    return -1;
}
