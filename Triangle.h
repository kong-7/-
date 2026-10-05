#ifndef TRIANGLE_H
#define TRIANGLE_H

// ==================================================================
// 部分类：三角形题目类
//   数据成员：题目编号、三条边长、用户答案、正确答案
//   主要操作：初始化、修改、获取、输出显示、合法性验证、求周长面积、
//             判断三角形类型、判断用户答案是否正确
// ==================================================================
class Triangle
{
private:
    int    id;                  // 题目编号
    double sideA;               // 第 1 条边长
    double sideB;               // 第 2 条边长
    double sideC;               // 第 3 条边长
    char   userAnswer[24];      // 用户答案
    char   rightAnswer[24];     // 正确答案

public:
    // ---------- 构造函数与析构函数 ----------
    Triangle();                                          // 默认构造函数
    Triangle(int newId, double a, double b, double c);   // 重载构造函数
    ~Triangle();                                         // 析构函数

    // ---------- 初始化与修改 ----------
    void init(int newId, double a, double b, double c);  // 初始化
    void setSides(double a, double b, double c);         // 修改三条边长
    void setUserAnswer(const char *ans);                 // 修改用户答案
    bool isValid() const;                                // 合法性验证：三边能否构成三角形

    // ---------- 获取 ----------
    int         getId() const;
    double      getSideA() const;
    double      getSideB() const;
    double      getSideC() const;
    const char *getUserAnswer() const;
    const char *getRightAnswer() const;

    // ---------- 其他功能操作 ----------
    double perimeter() const;                            // 求周长
    double area() const;                                 // 求面积（海伦公式）
    void   calcRightAnswer();                            // 计算本题正确答案（三角形类型）
    bool   checkAnswer(const char *ans) const;           // 判断用户答案是否正确

    // ---------- 输出显示 ----------
    void show() const;
};

#endif
