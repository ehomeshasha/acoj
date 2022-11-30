#include <iostream>

using namespace std;

/**
 * 某校的惯例是在每学期的期末考试之后发放奖学金。发放的奖学金共有五种，获取的条件各自不同：

1.院士奖学金，每人8000元，期末平均成绩高于80分（>80），并且在本学期内发表1篇或1篇以上论文的学生均可获得；
2.五四奖学金，每人4000元，期末平均成绩高于85分（>85），并且班级评议成绩高于80分（>80）的学生均可获得；
3.成绩优秀奖，每人2000元，期末平均成绩高于90分（>90）的学生均可获得；
4.西部奖学金，每人1000元，期末平均成绩高于85分（>85）的西部省份学生均可获得；
5.班级贡献奖，每人850元，班级评议成绩高于80分（>80）的学生干部均可获得；
只要符合条件就可以得奖，每项奖学金的获奖人数没有限制，每名学生也可以同时获得多项奖学金。例如姚林的期末平均成绩是87分，班级评议成绩82分，同时他还是一位学生干部，那么他可以同时获得五四奖学金和班级贡献奖，奖金总数是4850元。
现在给出若干学生的相关数据，请计算哪些同学获得的奖金总数最高（假设总有同学能满足获得奖学金的条件）。
 */


struct Result {
    string name;
    int reward;
};

Result calReward() {
    int qm_score, py_score, lw_cnt;
    char is_gb, is_west;
    char xm[100];
    // 从左向右依次是姓名，期末平均成绩，班级评议成绩，是否是学生干部，是否是西部省份学生，以及发表的论文数。
    scanf("%s %d %d %c %c %d", xm, &qm_score, &py_score, &is_gb, &is_west, &lw_cnt);
    Result res {};
    res.name = xm;

    int reward = 0;
    // 1.院士奖学金，每人8000元，期末平均成绩高于80分（>80），并且在本学期内发表1篇或1篇以上论文的学生均可获得；
    if (qm_score > 80 && lw_cnt >= 1) {
        reward += 8000;
    }
    // 2.五四奖学金，每人4000元，期末平均成绩高于85分（>85），并且班级评议成绩高于80分（>80）的学生均可获得；
    if (qm_score > 85 && py_score > 80) {
        reward += 4000;
    }
    // 3.成绩优秀奖，每人2000元，期末平均成绩高于90分（>90）的学生均可获得；
    if (qm_score > 90) {
        reward += 2000;
    }
    // 4.西部奖学金，每人1000元，期末平均成绩高于85分（>85）的西部省份学生均可获得；
    if (qm_score > 85 && is_west == 'Y') {
        reward += 1000;
    }
    // 5.班级贡献奖，每人850元，班级评议成绩高于80分（>80）的学生干部均可获得；
    if (py_score > 80 && is_gb == 'Y') {
        reward += 850;
    }
    res.reward = reward;
    return res;
}


int main()
{
    int N;
    cin >> N;
    int total_reward = 0;
    Result highestResult {"xxx", -1};
    for (int i = 0; i < N; i++) {
        Result result = calReward();
        if (result.reward > highestResult.reward) {
            highestResult = result;
        }
        total_reward += result.reward;
    }

    cout << highestResult.name << endl;
    cout << highestResult.reward << endl;
    cout << total_reward << endl;



    return 0;
}
