#include "QuestionBank.h"
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int SCORE_PER_QUESTION = 10;   // 每题满分

// ---------------- 默认构造函数 ----------------
QuestionBank::QuestionBank()
{
    strcpy(bankName, "未命名题库");
    count = 0;
    average = 0.0;
    for (int i = 0; i < MAX_NUM; i++)
        scores[i] = 0;
    // questions 数组中的 Triangle 对象由它们自己的默认构造函数自动初始化
}

// ---------------- 重载构造函数：用题库名称构造对象 ----------------
QuestionBank::QuestionBank(const char *name)
{
    strcpy(bankName, name);
    count = 0;
    average = 0.0;
    for (int i = 0; i < MAX_NUM; i++)
        scores[i] = 0;
}

// ---------------- 析构函数 ----------------
QuestionBank::~QuestionBank()
{
    cout << "[析构] 题库《" << bankName << "》被撤销，其中的 "
         << count << " 道题目对象也一并被撤销。" << endl;
}

// ---------------- 初始化与修改 ----------------
void QuestionBank::init(const char *name)
{
    strcpy(bankName, name);
    count = 0;
    average = 0.0;
    for (int i = 0; i < MAX_NUM; i++)
        scores[i] = 0;
}

void QuestionBank::setName(const char *name) { strcpy(bankName, name); }

// ---------------- 获取数据成员 ----------------
const char *QuestionBank::getName() const    { return bankName; }
int         QuestionBank::getCount() const   { return count; }
double      QuestionBank::getAverage() const { return average; }

// ---------------- 向题库中增加题目 ----------------
bool QuestionBank::addQuestion(const Triangle &t)
{
    if (count >= MAX_NUM)
    {
        cout << "  增加失败：题库已满！" << endl;
        return false;
    }
    if (!t.isValid())
    {
        cout << "  增加失败：三边不能构成三角形，非法题目不能入库！" << endl;
        return false;
    }

    questions[count] = t;        // 把题目对象存进题库（组合关系的使用）
    scores[count] = 0;
    count++;
    calcAverage();
    cout << "  增加成功：题目编号 " << t.getId() << " 已加入题库《"
         << bankName << "》。" << endl;
    return true;
}

// ---------------- 在题库中删除题目 ----------------
bool QuestionBank::deleteQuestion(int id)
{
    int pos = -1;
    for (int i = 0; i < count; i++)
        if (questions[i].getId() == id)
        {
            pos = i;
            break;
        }

    if (pos == -1)
    {
        cout << "  删除失败：题库中没有编号为 " << id << " 的题目！" << endl;
        return false;
    }

    for (int i = pos; i < count - 1; i++)     // 后面的题目整体前移
    {
        questions[i] = questions[i + 1];
        scores[i] = scores[i + 1];
    }
    count--;
    questions[count] = Triangle();    // 把移走的空位恢复成"空对象"（编号 0），避免残留旧题目
    scores[count] = 0;
    calcAverage();
    cout << "  删除成功：编号 " << id << " 的题目已从题库中删除。" << endl;
    return true;
}

// ---------------- 查询题库中的题目 ----------------
void QuestionBank::queryQuestion(int id) const
{
    for (int i = 0; i < count; i++)
    {
        if (questions[i].getId() == id)
        {
            cout << "  查询结果（第 " << i + 1 << " 题）：" << endl;
            questions[i].show();
            cout << "  本题成绩：" << scores[i] << " 分" << endl;
            return;
        }
    }
    cout << "  查询失败：题库中没有编号为 " << id << " 的题目！" << endl;
}

// ---------------- 输入用户答案并自动判分 ----------------
bool QuestionBank::answerQuestion(int id, const char *ans)
{
    for (int i = 0; i < count; i++)
    {
        if (questions[i].getId() == id)
        {
            questions[i].setUserAnswer(ans);            // 记录用户答案
            if (questions[i].checkAnswer(ans))          // 判分
                scores[i] = SCORE_PER_QUESTION;
            else
                scores[i] = 0;
            calcAverage();
            cout << "  第 " << i + 1 << " 题作答：" << ans << "，得分 "
                 << scores[i] << " 分。" << endl;
            return true;
        }
    }
    cout << "  作答失败：题库中没有编号为 " << id << " 的题目！" << endl;
    return false;
}

// ---------------- 计算平均分 ----------------
void QuestionBank::calcAverage()
{
    if (count == 0)
    {
        average = 0.0;
        return;
    }
    int sum = 0;
    for (int i = 0; i < count; i++)
        sum = sum + scores[i];
    average = (double)sum / count;
}

// ---------------- 输出显示 ----------------
void QuestionBank::show() const
{
    cout << fixed << setprecision(2);
    cout << "题库名称：" << bankName << "   题目数量：" << count << endl;
    if (count == 0)
        cout << "  （题库目前是空的）" << endl;

    for (int i = 0; i < count; i++)
    {
        cout << "----------------------------------------" << endl;
        questions[i].show();
        cout << "  本题成绩：" << scores[i] << " 分" << endl;
    }
    cout << "========================================" << endl;
    cout << "平均分：" << average << " 分" << endl;
}
