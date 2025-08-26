package cn.slienceme;

import java.util.HashMap;
import java.util.Map;

/**
 * <a href="https://leetcode.cn/problems/two-sum/description/">1. 两数之和</a>
 */
public class Solution0001 {

    /**
     * 我的写法
     * @param nums 数组
     * @param target 目标值
     * @return int[]
     */
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(target-nums[i])){
                return new int[]{map.get(target-nums[i]), i};
            }
            map.put(nums[i], i);
        }
        return null;
    }

    /**
     * 之前答案
     * @param nums 数组
     * @param target 目标值
     * @return int[]
     */
    public int[] twoSumFinal(int[] nums, int target) {
        Map<Integer, Integer> hash = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (hash.containsKey(target - nums[i])) {
                return new int[]{hash.get(target - nums[i]), i};
            }
            hash.put(nums[i], i);
        }
        return new int[0];
    }


    public static void main(String[] args) {
        Solution0001 solution0001 = new Solution0001();
        int[] ints = solution0001.twoSum(new int[]{2, 7, 11, 15}, 9);
        for (int anInt : ints) {
            System.out.println(anInt);
        }
    }
}
