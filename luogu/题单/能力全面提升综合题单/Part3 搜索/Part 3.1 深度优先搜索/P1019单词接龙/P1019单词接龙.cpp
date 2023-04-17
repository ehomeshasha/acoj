#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P1019d
 */
int N,ans=0,word_cnt[20];
string start, words[20];

void dfs(const string &s, int len)
{
    // 接龙游戏，找出所有解，然后求最大长度的
    // 从末尾1位到全部长度遍历作为匹配字符串，
    // 然后在查找出开头能够和匹配字符串相同的单词，
    // 继续以该单词作为入参继续进行查找，同时len增加
    // 对单词进行计数，用于判断每个单词不能使用超过2次
    // 结束条件为查不到符合条件的单词
    // 回溯算法去回溯计数
    // 最终结束条件那里找到max
    int slen=s.length();
    int end=slen==1?0:1;
    string match_s; // 匹配字符串
    bool find=false;
    for (int i=slen-1;i>=end;i--) {
        match_s=s.substr(i,slen-i); // 生成匹配字符串，从1~N-1
        for (int j=0;j<N;j++) { // 遍历所有单词
            if (slen!=1&&words[j].length()<=match_s.length()) continue; // 被匹配的单词长度<=待匹配字符串， 包含或者不足以匹配就继续下一次匹配
            if (word_cnt[j]>=2) continue; // 已经至少匹配2次了
            string match_s2=words[j].substr(0,slen-i);
            if (match_s==match_s2) { // 满足接龙要求
                // 增加单词使用计数
                find=true;
                word_cnt[j]++;
                int len3=words[j].length()-slen+i;
                string s3=words[j].substr(slen-i,len3);
                dfs(s+s3,len+len3);
                // 回溯计数
                word_cnt[j]--;
            }
        }
    }
    if (!find) { // 接龙停止
        ans=max(ans,len);
    }
}

int main()
{
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> words[i];
    }
    cin >> start;
    dfs(start,1L);
    cout << ans;
    return 0;
}
