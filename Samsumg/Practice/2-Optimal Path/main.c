// ConsoleApplication6.cpp: 定义控制台应用程序的入口点。
//

#include "stdio.h"

const int INF = 10000;
int graph[12][12] = { -1 };//表示两个点之间的距离
int node[24];
int x[12]; //存放当前节点 以及之前的节点

int ABS(int a, int b)
{
    int c = 0;
    if (a - b < 0)
        c = b - a;
    else
        c = a - b;
    return c;
}

int nextValue(int k)
{
    int m = 0;
    while (m < k)
    {
        if (x[k] == x[m])
            return 0;
        m += 1;
    }
    return 1;
}

int N;
int cl = 0, fl = INF;

void backtrack(int n)
{
    if (n == N)
    {
        for (int j = 1; j <= N; j++)
        {
            int g = x[n];
            x[n] = j;
            if (nextValue(n) == 1 && cl + graph[x[n - 1]][j] + graph[j][N + 1] < fl)
            {
                fl = cl + graph[x[n - 1]][x[n]] + graph[x[n]][N + 1];
                //x[n]=j;
            }
            x[n] = g;
        }
    }
    else
    {
        for (int j = 1; j <= N; j++)  //除去起点 一共是N个
        {
            //万一下面的if为false，也就是这个j走不通的话，，，那你不是应该再把x[n] = j清除吗   所以你应该写在if里面
            int g = x[n];
            x[n] = j; //代表路径中的点的标号 后面利用标号找距离
            //printf("%d ", x[n]);
            if (nextValue(n) == 1 && cl + graph[x[n - 1]][j] <= fl) // 选择了j 把j放在路径里面 就是路径中前一个加上现在选择了的j的长度嘛！！
            {
                //此路可行
                cl += graph[x[n - 1]][x[n]];
                //printf("%d\n", cl);
                backtrack(n + 1);
                cl -= graph[x[n - 1]][x[n]];
            }
            x[n] = g;
        }
    }
}
int main()
{
    scanf("%d", &N);
    //读入坐标
    scanf("%d%d", &node[0], &node[1]);
    int a, b;
    scanf("%d%d", &a, &b);
    node[2 * (N + 1)] = a;
    node[2 * (N + 1) + 1] = b;
    int i = 2;
    while (i < 2 * (N + 1))
    {
        int c, d;
        scanf("%d%d", &c, &d);
        node[i] = c;
        node[i + 1] = d;
        i += 2;
    }
    //矩阵赋值
    for (int j = 0; j < N + 2; j++)
    {
        for (int k = 0; k < N + 2; k++)
        {
            graph[j][k] = ABS(node[2 * j], node[2 * k]) + ABS(node[2 * j + 1], node[2 * k + 1]);
            graph[k][j] = graph[j][k];
        }
    }
    
     for (int j = 0; j < N + 2; j++)
     {
     for (int k = 0; k < N + 2; k++)
     {
     printf("%d ", graph[j][k]);
     }
     printf("\n");
     }
    
    int n = 1;
    x[0] = 0;
    backtrack(n);
    printf("%d\n", fl);
    return 0;
}
