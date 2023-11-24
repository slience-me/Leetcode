#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

/*
 *  给你一个下标从 0 开始长度为 n 的整数数组 nums 和一个整数 target ，请你返回满足 0 <= i < j < n 且 nums[i] + nums[j] < target 的下标对 (i, j) 的数目。
 */
class Solution {
public:
    // 1. 暴力解
    int countPairs1(vector<int>& nums, int target) {
        int sum=0;
        for (int i = 0; i < nums.size(); ++i){
            for (int j = i+1; j < nums.size(); ++j){
                if (i < j && nums[i]+nums[j]<target){
                    cout<<"("<<i<<", "<<j<<") , "<<i<<" < "<<j<<" and "<<"nums["<<i<<"] + nums["<<j<<"] = "<<nums[i] + nums[j]<< "  target: "<<target<<endl;
                    sum+=1;
                }
            }
        }
        return sum;
    }

    // 2. 采用了一个类似于快排的算法
    int countPairs(vector<int>& nums, int target) { //(0, 1) ，0 < 1 且 nums[0] + nums[1] = 0 < target
        // [-6,2,5,-2,-7,-1,3]
        sort(nums.begin(), nums.end());//先排序
        int ans = 0, left = 0, right = nums.size() - 1; //定义左索引,定义右索引
        while (left < right) { //快排常见的条件 左侧索引<右侧索引
            //  [-7,-6,-2,-1,2,3,5]
            // -7 + 5 = -2 < -2 right--
            // -7 + 3 = -4 < -2
            if (nums[left] + nums[right] < target) {
                ans += right - left; //增加全部满足条件的个数
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
};


int main() {
    Solution solution = *new Solution;
    vector<int> nums = {-6,2,5,-2,-7,-1,3};
    int res = solution.countPairs(nums, -2);
    cout << res << endl;
    return -1;
}
