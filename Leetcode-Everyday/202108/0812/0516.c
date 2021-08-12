int longestPalindromeSubseq(char * s){
    int len = strlen(s);
    if (len == 0 || len == 1)
        return len;
    /* 初始化动态规划数组 */
    int **dp = (int **)malloc(len * sizeof(int *));
    for (int i = 0; i < len; i ++)
    {
        dp[i] = (int *)malloc(len * sizeof(int));
        memset(dp[i], 0x00, len * sizeof(int));
        dp[i][i] = 1;
    }
    /*  */
    for (int i = 1; i < len; i ++)
    {
        for (int j = i - 1; j >= 0; j --)
        {
            if (s[i] == s[j])
            {
                dp[j][i] = dp[j + 1][i - 1] + 2;
            }
            else
            {
                dp[j][i] = dp[j + 1][i] > dp[j][i - 1] ? dp[j + 1][i] : dp[j][i - 1];
            }
        }
    }
    int res = dp[0][len - 1];
    for (int i = 0; i < len; i ++)
    {
        free(dp[i]);
    }    
    free(dp);
    return res;
}