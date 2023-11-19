#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:

    int maximumSum(vector<int> &nums) {
        int maxArray[120]={0}; //先给够
        int maxSum = -1; // 最大值
        // 先全部放入哈希表
        for (int num: nums) {
            int sum = getSumOfNum(num);
            if (maxArray[sum]) {
                maxSum = max(maxSum, maxArray[sum] + num);
                maxArray[sum] = max(maxArray[sum], num);
            } else {
                maxArray[sum] = num;
            }
        }

        return maxSum;

    }

    int maximumSum3(vector<int> &nums) {
        unordered_map<int, int> sumIndexMap; //存储数位和对应索引
        int maxSum = -1; // 最大值
        // 先全部放入哈希表
        for (int num: nums) {
            int sum = getSumOfNum(num);
            if (sumIndexMap.count(sum)) {
                maxSum = max(maxSum, sumIndexMap[sum] + num);
                sumIndexMap[sum] = max(sumIndexMap[sum], num);
            } else {
                sumIndexMap[sum] = num;
            }
        }

        return maxSum;

    }

    /*
     *  在给定的代码中，您的目标是找到满足数位和相等的两个数的和的最大值。目前的方法是使用两层嵌套的循环来检查所有数对，并找到它们的数位和相等的情况下的最大和。
        有一些地方可以进行优化来提高算法的效率：
        1. 使用哈希表存储数位和的索引： 可以使用哈希表（unordered_map）存储数位和及其对应的索引，这样可以在一次遍历中找到符合条件的数对。
        2. 不需要构建额外的向量存储数位和： 在遍历原始数组时，直接计算数位和并在哈希表中查找，而不需要额外的向量来存储数位和。
     */
    int maximumSum2(vector<int> &nums) {
        unordered_map<int, vector<int>> sumIndexMap; //存储数位和对应索引
        int maxSum = -1; // 最大值
        // 先全部放入哈希表
        for (int num: nums) {
            int sum = getSumOfNum(num);
            sumIndexMap[sum].push_back(num);
        }
        // vector排序倒序
        for (auto &pair: sumIndexMap) {
            if (pair.second.size() >= 2) {
                sort(pair.second.rbegin(), pair.second.rend());
                maxSum = max(maxSum, pair.second[0] + pair.second[1]);
            }
        }
        return maxSum;

    }

    // 第一版 暴力解
    int maximumSum1(vector<int> &nums) {
        vector<int> sumVector; // 创建一个空的整数向量，记录数位和
        int maxNum = -1;
        for (const auto &item: nums) {
            int num = getSumOfNum(item);
            sumVector.push_back(num);
        }
        for (int i = 0; i < sumVector.size(); i++) {
            for (int j = i + 1; j < sumVector.size(); j++) {
                if (sumVector[i] == sumVector[j]) {
                    if (nums[i] + nums[j] > maxNum) {
                        maxNum = nums[i] + nums[j];
                    }
                }
            }
        }
        return maxNum;

    }

    int getSumOfNum(int num) {

        if (num < 0) {
            return -1;
        }
        int sum = 0; // 12345
        while (num != 0) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
};


int main() {
    Solution solution = *new Solution;
    vector<int> myVector = {18, 43, 36, 13, 7};
    int max = solution.maximumSum(myVector);
    cout << max << endl;
    return 0;
}
