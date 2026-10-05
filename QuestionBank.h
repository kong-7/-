#ifndef QUESTIONBANK_H
#define QUESTIONBANK_H

#include "Triangle.h"

const int MAX_NUM = 50;         // 题库最多能容纳的题目数量

// ==================================================================
// 整体类：三角形题库类（与 Triangle 是【组合关系】）
//   组合关系：题库对象内部直接包含 Triangle 对象数组，
//             题库对象被撤销时，里面的题目对象也一起被撤销。
//   数据成员：题库名称、题目数量、包含的所有题目、所做题目的成绩、平均分
// ==================================================================
class QuestionBank
{
private:
    char     bankName[30];           // 题库名称
    int      count;                  // 题目数量
    Triangle questions[MAX_NUM];     // 包含的所有题目（组合关系的体现）
    int      scores[MAX_NUM];        // 所做题目的成绩（每题 10 分）
    double   average;                // 平均分

public:
    // ---------- 构造函数与析构函数 ----------
    QuestionBank();                              // 默认构造函数
    QuestionBank(const char *name);              // 重载构造函数
    ~QuestionBank();                             // 析构函数

    // ---------- 初始化、修改、获取 ----------
    void        init(const char *name);
    void        setName(const char *name);
    const char *getName() const;
    int         getCount() const;
    double      getAverage() const;

    // ---------- 其他功能操作 ----------
    bool addQuestion(const Triangle &t);                 // 向题库中增加题目
    bool deleteQuestion(int id);                         // 在题库中删除题目
    void queryQuestion(int id) const;                    // 查询题库中的题目
    bool answerQuestion(int id, const char *ans);        // 输入答案并自动判分
    void calcAverage();                                  // 计算平均分
    void show() const;                                   // 输出显示题库信息
};

#endif
