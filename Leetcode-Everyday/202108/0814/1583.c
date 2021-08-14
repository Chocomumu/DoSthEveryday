int unhappyFriends(int n, int** preferences, int preferencesSize, int* preferencesColSize, int** pairs, int pairsSize, int* pairsColSize){
    if (n <= 2)
    {
        return 0;
    }
    int count = 0;
    /* 记录x中y在preferences中的ID */
    int **preferID = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        preferID[i] = (int *)malloc(n * sizeof(int));
    }
    /* 初始化preferID内容 */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < preferencesColSize[i]; j++)
        {
            preferID[i][preferences[i][j]] = j;
        }
        preferID[i][i] = -1;        /* 无实际意义，写着玩 */
    }
    /* 记录pair的位置 */
    int *pairID = (int *)malloc((n) * sizeof(int));
    for (int i = 0; i < pairsSize; i++)
    {
        pairID[pairs[i][0]] = i;
        pairID[pairs[i][1]] = i;
    }
    for (int i = 0; i < n; i ++)
    {
        int mate = pairs[pairID[i]][0] == i ? pairs[pairID[i]][1] : pairs[pairID[i]][0];
        for (int j = preferID[i][mate] - 1; j >= 0; j--)
        {
            int prefer_mate = preferences[i][j];
            int prefer_mate_mate = pairs[pairID[prefer_mate]][0] == prefer_mate ? pairs[pairID[prefer_mate]][1] :pairs[pairID[prefer_mate]][0];
            if (preferID[prefer_mate][i] < preferID[prefer_mate][prefer_mate_mate])
            {
                count ++;
                break;
            }
        }
    }
    /* 释放preferID空间 */
    for (int i = 0; i < n; i++)
    {
        free(preferID[i]);
    }
    free(preferID);
    return count;
}