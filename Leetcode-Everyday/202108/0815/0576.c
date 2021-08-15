/* 
* 本题动态规划的维度为移动的步数  
* 求出小于等于maxMove步数时，出界的路径总数，相加即可得到结果。 
* 
* 而每个数量的步数的出界情况必为前一步中，路径终点为边界网格的情况。  
* 对于网格中的每个格子，第i步足球能到达该格子的路径数量为第i-1步到达相邻格子（上下左右中存在的）的路径数量的和。   
* 
* 使用两个动态规划数组，分别放置第i步和第i-1步的结果  
* 初始化第0步状态：足球所在网格为1，其它为0    
*/
#define MOD_BASE 1000000007
int findPaths(int m, int n, int maxMove, int startRow, int startColumn){
    int count = 0;
    int **dp[2];
    dp[0] = (int **)malloc(m * sizeof(int *));
    dp[1] = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i ++)
    {
        dp[0][i] = (int *)malloc(n * sizeof(int));
        dp[1][i] = (int *)malloc(n * sizeof(int));
        memset(dp[0][i], 0x00, n * sizeof(int));
        memset(dp[1][i], 0x00, n * sizeof(int));
    }
    int pre_dp_id = 0;
    int cur_dp_id = 1;
    dp[cur_dp_id][startRow][startColumn] = 1;
    for (int k = 1; k <= maxMove; k ++)
    {
        /* 通过第k-1步的网格的路径情况，计算第k步的出界路径数 */
        /* 加上向上和向下出界的路径数 */
        for (int j = 0; j < n; j++)
        {
            count = (count + dp[cur_dp_id][0][j]) % MOD_BASE;
            count = (count + dp[cur_dp_id][m - 1][j]) % MOD_BASE;
        }
        /* 加上向左和向右出界的路径数 */
        for (int j = 0; j < m; j++)
        {
            count = (count + dp[cur_dp_id][j][0]) % MOD_BASE;
            count = (count + dp[cur_dp_id][j][n - 1]) % MOD_BASE;
        }
        pre_dp_id = (pre_dp_id + 1) % 2;
        cur_dp_id = (cur_dp_id + 1) % 2;   
        if (maxMove != k){
            for (int i = 0; i < m; i ++)
            {
                for (int j = 0; j < n; j ++)
                {
                                
                    dp[cur_dp_id][i][j] = 0;
                    dp[cur_dp_id][i][j] = (dp[cur_dp_id][i][j] + (i == 0 ? 0 : dp[pre_dp_id][i - 1][j]))     % MOD_BASE;
                    dp[cur_dp_id][i][j] = (dp[cur_dp_id][i][j] + (i == m - 1 ? 0 : dp[pre_dp_id][i + 1][j])) % MOD_BASE;
                    dp[cur_dp_id][i][j] = (dp[cur_dp_id][i][j] + (j == 0 ? 0 : dp[pre_dp_id][i][j - 1]))     % MOD_BASE;
                    dp[cur_dp_id][i][j] = (dp[cur_dp_id][i][j] + (j == n - 1 ? 0 : dp[pre_dp_id][i][j + 1])) % MOD_BASE;
                }
            }
        }     
    }
    for (int i = 0; i < m; i ++)
    {
        free(dp[1][i]);
        free(dp[0][i]);
    }
    free(dp[1]);
    free(dp[0]);
    return count;
}