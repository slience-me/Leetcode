package cn.slienceme;

import java.util.Arrays;

/**
 * <a href="https://leetcode.cn/problems/length-of-longest-v-shaped-diagonal-segment/">3459. 最长 V 形对角线段的长度</a>
 * 实在看不懂
 */
public class Solution3459 {

    /**
     * 官方答案
     */
    private static final int[][] DIRS = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    private int[][][][] memo;
    private int[][] grid;
    private int m, n;

    public int lenOfVDiagonal(int[][] grid) {
        this.grid = grid;
        this.m = grid.length;
        this.n = grid[0].length;
        this.memo = new int[m][n][4][2];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 4; k++) {
                    Arrays.fill(memo[i][j][k], -1);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int direction = 0; direction < 4; direction++) {
                        res = Math.max(res, dfs(i, j, direction, true, 2) + 1);
                    }
                }
            }
        }
        return res;
    }

    private int dfs(int cx, int cy, int direction, boolean turn, int target) {
        int nx = cx + DIRS[direction][0];
        int ny = cy + DIRS[direction][1];
        /* 如果超出边界或者下一个节点值不是目标值，则返回 */
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != target) {
            return 0;
        }

        int turnInt = turn ? 1 : 0;
        if (memo[nx][ny][direction][turnInt] != -1) {
            return memo[nx][ny][direction][turnInt];
        }

        /* 按照原来的方向继续行走 */
        int maxStep = dfs(nx, ny, direction, turn, 2 - target);
        if (turn) {
            /* 顺时针旋转 90 度转向 */
            maxStep = Math.max(maxStep, dfs(nx, ny, (direction + 1) % 4, false, 2 - target));
        }
        memo[nx][ny][direction][turnInt] = maxStep + 1;
        return maxStep + 1;
    }
    /*
    private static final int[][] DIRS = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

    public int lenOfVDiagonal(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        // 开太多维度影响效率，这里把 k 和 canTurn 压缩成一个 int
        int[][][] memo = new int[m][n][1 << 3];
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1) {
                    continue;
                }
                int[] maxs = {m - i, j + 1, i + 1, n - j}; // 理论最大值（走到底）
                for (int k = 0; k < 4; k++) { // 枚举起始方向
                    // 优化一：如果理论最大值没有超过 ans，那么不递归
                    if (maxs[k] > ans) {
                        ans = Math.max(ans, dfs(i, j, k, 1, 2, grid, memo) + 1);
                    }
                }
            }
        }
        return ans;
    }

    private int dfs(int i, int j, int k, int canTurn, int target, int[][] grid, int[][][] memo) {
        i += DIRS[k][0];
        j += DIRS[k][1];
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[i].length || grid[i][j] != target) {
            return 0;
        }
        int mask = k << 1 | canTurn;
        if (memo[i][j][mask] > 0) {
            return memo[i][j][mask];
        }
        int res = dfs(i, j, k, canTurn, 2 - target, grid, memo) + 1;
        if (canTurn == 1) {
            int[] maxs = {grid.length - i, j + 1, i + 1, grid[i].length - j}; // 理论最大值（走到底）
            k = (k + 1) % 4;
            // 优化二：如果理论最大值没有超过 res，那么不递归
            if (Math.min(maxs[k], maxs[(k + 3) % 4]) > res) {
                res = Math.max(res, dfs(i, j, k, 0, 2 - target, grid, memo) + 1);
            }
        }
        return memo[i][j][mask] = res;
    }
     */


    public static void main(String[] args) {
        Solution3459 solution = new Solution3459();
        int result = solution.lenOfVDiagonal(new int[][]{{2, 2, 1, 2, 2}, {2, 0, 2, 2, 0}, {2, 0, 1, 1, 0}, {1, 0, 2, 2, 2}, {2, 0, 0, 2, 2}});
        System.out.println(result);
    }
}
