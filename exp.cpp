    #include <iostream>
    #include <stdio.h>
    #include <stdint.h>
    #include <vector>
    #include <list>
    #include <set>
    #include <map>
    #include <queue>
    #include <utility>
    #include <algorithm>
    #include <math.h>
    #include <stdlib.h>
    #include <string>
    #include <assert.h>
     
    using namespace::std;
     
    int M = 100000;
    int cand[] = {1, 4, 27, 256, 3125, 46656};
     
    main()
    {
    vector<int> nim(1 + M, -1);
    nim[0] = 0;
     
    for (int i = 1; i <= M; i++)
    {
    set<int> p = set<int>();
    for (int j = 0; j < 6; j++)
    {
    if (i < cand[j])
    break;
     
    p.insert(nim[i - cand[j]]);
    }
     
    for (int j = 0; j < 10; j++)
    {
    if (p.find(j) == p.end())
    {
    nim[i] = j;
    break;
    }
    }
    }
     
    int T;
    scanf("%d", &T);
     
    for (int t = 0; t < T; t++)
    {
    int N;
    scanf("%d", &N);
     
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
    int x;
    scanf("%d", &x);
     
    ans ^= nim[x];
    }
     
    if (ans == 0)
    printf("Head Chef\n");
    else
    printf("Little Chef\n");
    }
    }

