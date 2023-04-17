#include <bits/stdc++.h>
using namespace std;

/**
https://www.luogu.com.cn/problem/P5440
 */
const int MAXN=100000005;
int N,ans,monthday[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};
int pm[MAXN+5],flag[MAXN+5];
string input_str;
int pm_idx=0;


void init_pm()
{
    // 埃氏筛
//    for (int i=2;i<=sqrt(MAXN);i++) {
//        if (pm[i]==0) {
//            for (int j=i*i;j<=MAXN;j+=i) pm[j]=1;
//        }
//    }
    // 欧氏筛
    int n=MAXN;
    for (int i=2;i<=n;i++) {
        if (flag[i]==0) {
            pm[pm_idx++]=i;
        }
        for (int j=0;j<pm_idx&&i*pm[j]<=n;j++) {
            flag[i*pm[j]]=1; // 素数数组里面每个元素都乘以i标记一次
            if (i%pm[j]==0) break; // 表示i*pm[j+1]不是他的最小质因子分解
        }
    }
}

bool is_runnian(int year)
{
    // 能被4整除但不能被100整除
    // 能被400整除是闰年
    return year%4==0&&year%100!=0||year%400==0;
}

bool is_prime(int n)
{
    if (n==1) return false;
    return flag[n]==0;
//    int t=sqrt(n);
//    for (int i=2;i<=t;i++) {
//        if (n%i==0) return false;
//    }
//    return true;
}

bool check()
{
    int year=stoi(input_str.substr(0,4));
    int month=stoi(input_str.substr(4,2));
    int day=stoi(input_str.substr(6,2));
    if (year<1||year>9999) return false;
    if (month<1||month>12) return false;
    monthday[2]=is_runnian(year)?29:28; // 2月份闰年最大天为29，非闰年为28
    if (day<1||day>monthday[month]) return false;
    if (!is_prime(day)||!is_prime(month*100+day)||!is_prime(year*10000+month*100+day)) return false; // 不是质数
    return true;
}

void dfs(int i)
{
    if (i==8) {
        if (check()) ans++;
        return;
    }
    if (input_str[i]!='-') {
        dfs(i+1);
        return;
    }
    for (int j=0;j<=9;j++) {
        if (i==4&&j>1) break; // 第4个位置(月份第一个)不能大于等于2
        if (i==5&&input_str[4]=='1'&&j>2) break; // 第5个位置在第4个位置等于1的时候不能大于2
        if (i==5&&input_str[4]=='0'&&j==0) continue; // 第5个位置在第4个位置等于1的时候不能大于2
        if (i==6&&j>3) break; // 第6个位置（日期第一个）不能大于等于3
        if (i==7&&j%2==0) continue; // 第7个位置（最后一位）不能是偶数
        input_str[i]=j+'0';
        dfs(i+1);
        input_str[i]='-'; //回溯
    }
}


int main()
{
    init_pm();
    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> input_str;
        dfs(0);
        cout << ans << "\n";
        ans=0;
    }
    return 0;
}
