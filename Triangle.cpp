#include "Triangle.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;

const double EPS = 1e-6;

Triangle::Triangle()
{
    id = 0;
    sideA = 0.0;
    sideB = 0.0;
    sideC = 0.0;
    strcpy(userAnswer, "未作答");
    strcpy(rightAnswer, "非三角形");
}

Triangle::Triangle(int newId, double a, double b, double c)
{
    id = newId;
    sideA = 0.0;
    sideB = 0.0;
    sideC = 0.0;
    strcpy(userAnswer, "未作答");
    strcpy(rightAnswer, "非三角形");
    setSides(a, b, c);
}

Triangle::~Triangle()
{
    if (id > 0)
        cout << "  [析构] 三角形题目对象（编号 " << id << "）被撤销。" << endl;
}

void Triangle::init(int newId, double a, double b, double c)
{
    id = newId;
    strcpy(userAnswer, "未作答");
    setSides(a, b, c);
}

void Triangle::setSides(double a, double b, double c)
{
    double oldA = sideA, oldB = sideB, oldC = sideC;

    sideA = a;
    sideB = b;
    sideC = c;
    if (!isValid())
    {
        cout << "  警告：三边 " << a << ", " << b << ", " << c
             << " 不能构成三角形，本次修改无效！" << endl;
        sideA = oldA;
        sideB = oldB;
        sideC = oldC;
        return;
    }
    calcRightAnswer();
}

void Triangle::setUserAnswer(const char *ans)
{
    strcpy(userAnswer, ans);
}

bool Triangle::isValid() const
{
    if (sideA <= 0 || sideB <= 0 || sideC <= 0)
        return false;
    if (sideA + sideB <= sideC)
        return false;
    if (sideA + sideC <= sideB)
        return false;
    if (sideB + sideC <= sideA)
        return false;
    return true;
}

int    Triangle::getId() const         { return id; }
double Triangle::getSideA() const      { return sideA; }
double Triangle::getSideB() const      { return sideB; }
double Triangle::getSideC() const      { return sideC; }
const char *Triangle::getUserAnswer() const  { return userAnswer; }
const char *Triangle::getRightAnswer() const { return rightAnswer; }

double Triangle::perimeter() const
{
    if (!isValid())
        return 0.0;
    return sideA + sideB + sideC;
}

double Triangle::area() const
{
    if (!isValid())
        return 0.0;
    double p = perimeter() / 2.0;
    return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
}

void Triangle::calcRightAnswer()
{
    if (!isValid())
    {
        strcpy(rightAnswer, "非三角形");
        return;
    }

    if (sideA == sideB && sideB == sideC)
    {
        strcpy(rightAnswer, "等边三角形");
    }
    else if (fabs(sideA * sideA + sideB * sideB - sideC * sideC) < EPS ||
             fabs(sideA * sideA + sideC * sideC - sideB * sideB) < EPS ||
             fabs(sideB * sideB + sideC * sideC - sideA * sideA) < EPS)
    {
        strcpy(rightAnswer, "直角三角形");
    }
    else if (sideA == sideB || sideB == sideC || sideA == sideC)
    {
        strcpy(rightAnswer, "等腰三角形");
    }
    else
    {
        strcpy(rightAnswer, "一般三角形");
    }
}

bool Triangle::checkAnswer(const char *ans) const
{
    return strcmp(ans, rightAnswer) == 0;
}

void Triangle::show() const
{
    cout << fixed << setprecision(2);
    cout << "  题目编号：" << id
         << "   三边：" << sideA << ", " << sideB << ", " << sideC << endl;
    if (isValid())
        cout << "  周长：" << perimeter() << "   面积：" << area() << endl;
    else
        cout << "  周长：无法计算   面积：无法计算" << endl;
    cout << "  正确答案：" << rightAnswer
         << "   用户答案：" << userAnswer << endl;
}
