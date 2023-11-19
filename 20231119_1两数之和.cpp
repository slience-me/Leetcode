#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 *  给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
    你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
    你可以按任意顺序返回答案。
 */
class Solution {
public:

    // 1. 暴力解
    vector<int> twoSum1(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }

    // 2. 哈希表初次版本 3次循环
    vector<int> twoSum2(vector<int> &nums, int target) {
        // 分析 target=a+b ,
        unordered_map<int, int> myMap;
        for (int i = 0; i < nums.size(); ++i) {
            myMap[nums[i]] = i;
        }
        for (const auto &item: myMap){
            cout<<"key: "<<item.first<<"  value: "<<item.second<<endl;
        }
        for (int i = 0; i < nums.size(); ++i) {
            auto it = myMap.find(target-nums[i]);
            if (it != myMap.end()) {
                int j = it->second;
                if(i==j){ continue;}
                if(i<=j){
                    return {i,j};
                } else{
                    return {j,i};
                }

            };
        }

        return {};
    }

    // 3. 优化版本 1次循环
    vector<int> twoSum(vector<int> &nums, int target) {
        // 分析 target=a+b ,
        unordered_map<int, int> myMap;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (myMap.find(complement) != myMap.end()) {
                return { myMap[complement], i };
            }
            myMap[nums[i]] = i;
        }
        return {};
    }
};


int main1() {
    Solution solution = *new Solution;
    vector<int> myVector = {3, 2, 4};
    vector<int> res = solution.twoSum(myVector, 6);
    for (const auto &item: res) {
        cout << item << ", ";
    }
    return 0;
}
