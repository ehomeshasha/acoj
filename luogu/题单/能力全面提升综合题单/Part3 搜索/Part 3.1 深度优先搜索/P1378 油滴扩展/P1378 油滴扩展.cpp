#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1378
 */
//6*5*4*3*2*1=720种可能性, 可能性较少，可以直接爆深搜
//直接进行坐标平移 [-1000,1000] 平移成 [0,2000]
//构建平移后的坐标系
struct Pos {
    int x,y;
} POS[10];
int N,X1,Y1,X2,Y2,PATH[7],VIS[7];
double RI[7],max_mj=0;
void print_path()
{
    for (int i=1;i<=N;i++) {
        printf("%d ",PATH[i]);
    }
    printf("\n");
}

// 计算第i个油滴和边框的距离，选择最小的 minR1
// 计算第i个油滴和path里面其他油滴的距离，选择最小的 minR2
double find_maxr(int i, int k)
{
    Pos cur=POS[i];
    int x=cur.x,y=cur.y;
    int minX=min(abs(x-X1),abs(x-X2));
    int minY=min(abs(y-Y1),abs(y-Y2));
    double minR=min(minX,minY);
    for (int j=1;j<=N;j++) {
        if (i!=j&&VIS[j]) {
            int xj=POS[j].x,yj=POS[j].y;
            double rj=RI[j];
            double r=sqrt((xj-x)*(xj-x)+(yj-y)*(yj-y))-rj;
            if (r<=0) return 0; // 如果小于等于0，说明在某个油滴内部，因此该点能够扩展的距离就是0
            minR=min(minR,r);
        }
    }
    return minR;
    //    mj_sum+=r*r*M_PI;
}

void dfs(int k, double sum) // k代表第几个油滴，一共最多N个，程序到到N+1结束
{
    if (k==N+1) {
        // 油滴全部滴完
//        print_path();
//        printf("%lf",mj_sum);
        max_mj=max(sum,max_mj);
        return;
    }
    // 当前油滴选择:可选为1到6，已选择的需要剔除
    for (int i=1;i<=N;i++) {
        if (VIS[i]==0) {
            VIS[i]=1;
            PATH[k]=i;
            // 当前油滴扩展
            // 计算油滴和其他油滴的曼哈顿距离，既两个圆心之间的距离
            // 要使油滴不相交，那么该距离应该等于r1+r2，最大的r2可以求得即为边界
            RI[i]=find_maxr(i,k);
            dfs(k+1,sum+M_PI*RI[i]*RI[i]);
            VIS[i]=0;
            PATH[k]=0;
        }
    }



}

int main()
{
    cin >> N;
    cin >> X1 >> Y1 >> X2 >> Y2;
    for (int i=1;i<=N;i++) {
        cin >> POS[i].x >> POS[i].y;
        POS[i].x+=1000,POS[i].y+=1000; // 平移坐标
    }
    // 平移坐标
    X1+=1000,Y1+=1000,X2+=1000,Y2+=1000;
    // 初始化结束，开始dfs
    dfs(1,0.0);
    double mj_all=abs(X1-X2)*abs(Y1-Y2);
    double ans=mj_all-max_mj;
    printf("%.lf",ans);
    return 0;
}
