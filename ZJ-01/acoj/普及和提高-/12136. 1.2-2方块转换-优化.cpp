#include <bits/stdc++.h>


using namespace std;

/**
一块N x N（1<=N<=10）正方形的黑白瓦片的图案要被转换成新的正方形图案。写一个程序来找出将原始图案按照以下列转换方法转换成新图案的最小方式：
1：转90度：图案按顺时针转90度。
2：转180度：图案按顺时针转180度。
3：转270度：图案按顺时针转270度。
4：反射：图案在水平方向翻转（以中央铅垂线为中心形成原图案的镜像）。
5：组合：图案在水平方向翻转，然后再按照1到3之间的一种再次转换。
6：不改变：原图案不改变。
7：无效转换：无法用以上方法得到新图案。
如果有多种可用的转换方法，请选择序号最小的那个。
只使用1~7中的一个步骤来完成这次转换。
输入格式:
第一行： 单独的一个整数N。
第二行到第N+1行： N行每行N个字符（不是“@”就是“-”）；这是转换前的正方形。
第N+2行到第2*N+1行： N行每行N个字符（不是“@”就是“-”）；这是转换后的正方形。
输出格式:
单独的一行包括1到7之间的一个数字（在上文已描述）表明需要将转换前的正方形变为转换后的正方形的转换方法。
样例 1 :
输入:
1) 转90度
1,1 -> 1,3
1,2 -> 2,3
1,3 -> 3,3
2,1 -> 1,2
2,2 -> 2,2
2,3 -> 3,2
3,1 -> 1,1
3,2 -> 2,1
3,3 -> 3,1
res[j][N-i+1]=grid[i][j]
2) 转180度 就是2个转90度
3) 转270度 就是3个转90度
4) 反射
1,1 -> 1,3
1,2 -> 1,2
1,3 -> 1,1
2,1 -> 2,3
2,2 -> 2,2
2,3 -> 2,1
3,1 -> 3,3
3,2 -> 3,2
3,3 -> 3,1
res[i][N-j+1]=grid[i][j]

5) 组合
反射+旋转90*n
6) 不改变
7) 无效转换

3
@-@
---
@@-
@-@
@--
--@
输出:
1
 */
int N;

char** init_grid()
{
    char** res=new char*[N];
    for (int i=0;i<N;i++) {
        res[i]=new char[N];
    }
    return res;
}

char** turn90(char** grid)
{
    char** res=init_grid();
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            res[j][N-i-1]=grid[i][j];
        }
    }
    return res;
}

char** fanshe(char** grid)
{
    char** res=init_grid();
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            res[i][N-j-1]=grid[i][j];
        }
    }
    return res;
}

void mprint(char** g)
{
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            printf("%c ",g[i][j]);
        }
        printf("\n");
    }
}

bool mequal(char** g1, char** g2)
{
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            if (g1[i][j]!=g2[i][j]) return false;
        }
    }
    return true;
}

int main()
{
    // 思路， 提炼算子
    // 本题两个算子， 转90度， 反射
    scanf("%d\n",&N);
    char tc[4];
    char** sg=init_grid();
    char** eg=init_grid();
    // sg
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) sg[i][j]=getchar();
        gets(tc);
    }
    // eg
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) eg[i][j]=getchar();
        gets(tc);
    }
//    char** res=turn90(sg); // 转90度
//    char** res=fanshe(sg); // 反射
//    mprint(sg);
//    printf("\n");
//    mprint(res);
//    printf("\n");
    // 算子测试通过，开始编写逻辑
    char** res;
    res=turn90(sg);
    if(mequal(res,eg)) {printf("1");return 0;}
    for (int i=2;i<=3;i++) {
        res= turn90(res); // 转90度
        if(mequal(res,eg)) {printf("%d",i);return 0;}
    }
    // 反射
    res=fanshe(sg);
    if(mequal(res,eg)) {printf("4");return 0;}
    // 组合1 反射+转90、180、270
    for (int i=1;i<=3;i++) {
        res=turn90(res); // 转3次，每转1次就判断一下是否相等
        if(mequal(res,eg)) {printf("5");return 0;}
    }
    // 判断是否不用转
    if (mequal(eg,sg)) {printf("6");return 0;}
    printf("7");
    return 0;
}
