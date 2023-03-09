#include <bits/stdc++.h>

/**
https://www.bilibili.com/video/BV1tC4y1H7Bx/?spm_id_from=333.337.search-card.all.click&vd_source=d942722ad3983de914a6eae0f9bc074c

 */

using namespace std;

#define int long long // 会爆int
int a[500005], N, tmp[500005], ans=0;

void mmerge(int l, int mid, int r)
{
    int i=l,j=mid+1,idx=l;
    while(i<=mid&&j<=r) {
        if (a[i]<=a[j]) tmp[idx++]=a[i++];
        else { // 发现逆序对
            ans+=mid-i+1;
            tmp[idx++]=a[j++];
        }
    }
    // 左半部分有剩余
    while (i<=mid) tmp[idx++]=a[i++];
    // 右半部分有剩余
    while (j<=r) tmp[idx++]=a[j++];
    // 拷贝
    while (l<=r) a[l]=tmp[l],l++;
}

void msort(int l, int r)
{
    if (l==r) return;
    int mid=l+(r-l)/2;
    // 左边切分
    msort(l,mid);
    // 右边切分
    msort(mid+1,r);
    // 原地merge
    mmerge(l,mid,r);
}

void merge_sort()
{
    msort(0,N-1);
}


#undef int
int main()
{
#define int long long
    scanf("%lld\n",&N);
    for (int i=0;i<N;i++) {
        scanf("%lld ",&a[i]);
    }
    // 归并排序求解
    merge_sort();
    cout << ans;
    return 0;
}
