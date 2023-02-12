#include <bits/stdc++.h>


using namespace std;

/**
由于高传染性的牛传染病爆发，Farmer John 非常担忧他的奶牛们的健康。
为了限制疾病的传播，Farmer John 的 N 头奶牛（2≤N≤100000）决定践行“社交距离”，分散到农场的各处。
农场的形状如一维数轴，上有 M 个互不相交的区间（1≤M≤100000），其中有可用来放牧的青草。
奶牛们想要使她们位于不同的整数位置，每个位置上均有草，并且最大化 D 的值，其中 D 为最近的两头奶牛之间的距离。
请帮助奶牛们求出 D 的最大可能值。
输入格式:
输入的第一行包含 N 和 M。以下 M 行每行用两个整数 a 和 b 描述一个区间，其中 0≤a≤b≤10^18。
没有两个区间有重合部分或在端点处相交。位于一个区间的端点上的奶牛视为在草上。
输出格式:
输出 D 的最大可能值，使得所有奶牛之间的距离均不小于 D 单位。保证存在 D>0 的解。
提示:
测试点 2-3 满足 b≤10^5。
测试点 4-10 没有额外限制。
限制:
0≤a≤b≤10^18。
样例 1 :
输入:
5 3
0 2
4 7
9 9
输出:
2
说明:
取到 D=2 的一种方式是令奶牛们处在位置 0、2、4、6 和 9。
 */
struct Search {
    long long low;
    long long high;
    int s_idx;
    int e_idx;
};
long long sr[100005],er[100005];
vector<Search> searchs;
vector<Search> tmp;
int cnt=0,N,M;
void binary_search()
{
    if (cnt==N-2) return;
    tmp.clear();
    for (int k=0;k<searchs.size();k++) {
        Search search1=searchs[k];
        long long low=search1.low,high=search1.high;
        int s_idx=search1.s_idx,e_idx=search1.e_idx;
        long long middle=(low+high)/2,cha_min=999999999999999999,best_middle;
        if (low==middle) return;
        int s1_idx,e1_idx,s2_idx,e2_idx;
        // 可以查找到
        for (int i=s_idx;i<e_idx;i++) {
            long long s_cha=middle-sr[i];
            long long e_cha=er[i]-middle;
            if (s_cha>=0&&e_cha>=0) { // 正好落在中间
                // 距离最近的是s还是r，距离是d, middle不变
                best_middle=middle;
                s1_idx=s_idx;
                e1_idx=i+1;
                s2_idx=i;
                e2_idx=e_idx;
                break;
            } else if (e_cha<0) { // 取距离最近的
                if (-e_cha<cha_min) {
                    best_middle=er[i];
                    cha_min=-e_cha;
                    s1_idx=s_idx;
                    e1_idx=i+1;
                    s2_idx=i;
                    e2_idx=e_idx;
                }
            } else if (s_cha<0) { // 取距离最近的
                if (-s_cha<cha_min) {
                    best_middle=sr[i];
                    cha_min=-s_cha;
                    s1_idx=s_idx;
                    e1_idx=i+1;
                    s2_idx=i;
                    e2_idx=e_idx;
                    break;
                } else {
                    break;
                }
            }
        }
        tmp.push_back(Search{low,best_middle,s1_idx,e1_idx});
        tmp.push_back(Search{best_middle+1,high,s2_idx,e2_idx});
        cnt++;
        if (cnt==N-2) {
            cout << min(best_middle-low,high-best_middle);
            return;
        }
    }
    searchs.clear();
    for (int i=0;i<tmp.size();i++) searchs.push_back(tmp[i]);
    binary_search();
}


int main()
{
    cin >> N >> M;
    for (int i=0;i<M;i++) {
        cin >> sr[i] >> er[i];
    }
    // 先升序排序
    sort(sr,sr+M);
    sort(er,er+M);
    searchs.push_back(Search{sr[0],er[M-1],0,M});
    binary_search();
//    while(cnt<N-2) {
//        binary_search();
//    }
    return 0;
}
