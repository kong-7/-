#include <iostream>
#include "QuestionBank.h"
using namespace std;

int main()
{
    cout << "========== 一、三角形题目类（部分类）的基本操作 ==========" << endl;

    Triangle t1(101, 3, 4, 5);
    cout << "题目 101 的信息：" << endl;
    t1.show();

    cout << endl << "---------- 合法性验证：非法三边 ----------" << endl;
    Triangle t2;
    t2.init(102, 1, 2, 10);
    cout << "题目 102 的信息：" << endl;
    t2.show();
    t2.setSides(6, 6, 6);
    cout << "把题目 102 的三边改成 6, 6, 6 之后：" << endl;
    t2.show();

    cout << endl << "---------- 获取数据成员 ----------" << endl;
    cout << "题目编号：" << t1.getId()
         << "，第 1 条边：" << t1.getSideA()
         << "，正确答案：" << t1.getRightAnswer() << endl;

    cout << endl << "========== 二、用默认构造函数创建题库（组合关系） ==========" << endl;
    QuestionBank bank1;
    bank1.show();

    cout << endl << "========== 三、用重载构造函数创建题库并管理题目 ==========" << endl;
    QuestionBank bank2("三角形判断题库");

    Triangle t3(103, 6, 6, 6);
    Triangle t4(104, 5, 5, 8);
    Triangle t5(105, 1, 2, 10);

    cout << "---------- 向题库中增加题目 ----------" << endl;
    bank2.addQuestion(t1);
    bank2.addQuestion(t3);
    bank2.addQuestion(t4);
    bank2.addQuestion(t5);

    cout << endl << "---------- 输出显示题库内容 ----------" << endl;
    bank2.show();

    cout << endl << "---------- 做题：输入答案并自动判分 ----------" << endl;
    bank2.answerQuestion(101, "直角三角形");
    bank2.answerQuestion(103, "等腰三角形");
    bank2.answerQuestion(104, "等腰三角形");
    bank2.answerQuestion(999, "一般三角形");

    cout << endl << "---------- 查询题目 ----------" << endl;
    bank2.queryQuestion(103);
    bank2.queryQuestion(999);

    cout << endl << "---------- 查看判分后的题库 ----------" << endl;
    bank2.show();

    cout << endl << "---------- 在题库中删除题目 ----------" << endl;
    bank2.deleteQuestion(103);
    bank2.show();

    cout << endl << "========== 四、程序结束，对象开始析构 ==========" << endl;
    return 0;
}
