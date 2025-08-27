package cn.slienceme;

import java.util.HashMap;
import java.util.Map;

/**
 * <a href="https://leetcode.cn/problems/maximum-area-of-longest-diagonal-rectangle/description/">3000. 对角线最长的矩形的面积</a>
 */
public class Solution3000 {

    /**
     * 最终写法
     *
     * @param dimensions 矩形的长和宽
     * @return int
     */
    public int areaOfMaxDiagonal(int[][] dimensions) {
        int maxDiaSq = 0;
        int maxArea = 0;
        for (int[] dim : dimensions) {
            int l = dim[0];
            int w = dim[1];
            int diaSq = l * l + w * w;
            int area = l * w;
            if (diaSq > maxDiaSq) {
                maxDiaSq = diaSq;
                maxArea = area;
            } else if (diaSq == maxDiaSq) {
                maxArea = Math.max(maxArea, area);
            }
        }
        return maxArea;
    }

    /**
     * 我的写法草稿
     *
     * @param dimensions 矩形的长和宽
     * @return int
     */
    public int areaOfMaxDiagonalOld(int[][] dimensions) {
        double value = 0.0;
        int maxArea = 0;
        for (int i = 0; i < dimensions.length; i++) {
            int length = dimensions[i][0];
            int width = dimensions[i][1];
            double tmp = Math.sqrt(length * length + width * width);
            if (tmp > value) {
                value = tmp;
                maxArea = length * width;
            }
            if (tmp == value && length * width > maxArea){
                maxArea = length * width;
            }
        }
        return maxArea;
    }


    public static void main(String[] args) {
        Solution3000 solution = new Solution3000();
        int result = solution.areaOfMaxDiagonal(new int[][]{{4, 7}, {8, 9}, {5, 3}, {6, 10}, {2, 9}, {3, 10}, {2, 2}, {5, 8}, {5, 10}, {5, 6}, {8, 9}, {10, 7}, {8, 9}, {3, 7}, {2, 6}, {5, 1}, {7, 4}, {1, 10}, {1, 7}, {6, 9}, {3, 3}, {4, 6}, {8, 2}, {10, 6}, {7, 9}, {9, 2}, {1, 2}, {3, 8}, {10, 2}, {4, 1}, {9, 7}, {10, 3}, {6, 9}, {9, 8}, {7, 7}, {5, 7}, {5, 4}, {6, 5}, {1, 8}, {2, 3}, {7, 10}, {3, 9}, {5, 7}, {2, 4}, {5, 6}, {9, 5}, {8, 8}, {8, 10}, {6, 8}, {5, 1}, {10, 8}, {7, 4}, {2, 1}, {2, 7}, {10, 3}, {2, 5}, {7, 6}, {10, 5}, {10, 9}, {5, 7}, {10, 6}, {4, 3}, {10, 4}, {1, 5}, {8, 9}, {3, 1}, {2, 5}, {9, 10}, {6, 6}, {5, 10}, {10, 2}, {6, 10}, {1, 1}, {8, 6}, {1, 7}, {6, 3}, {9, 3}, {1, 4}, {1, 1}, {10, 4}, {7, 9}, {4, 5}, {2, 8}, {7, 9}, {7, 3}, {4, 9}, {2, 8}, {4, 6}, {9, 1}, {8, 4}, {2, 4}, {7, 8}, {3, 5}, {7, 6}, {8, 6}, {4, 7}, {25, 60}, {39, 52}, {16, 63}, {33, 56}});
        System.out.println(result);
    }
}
