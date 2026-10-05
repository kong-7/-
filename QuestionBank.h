#ifndef QUESTIONBANK_H
#define QUESTIONBANK_H

#include "Triangle.h"

const int MAX_NUM = 50;

class QuestionBank
{
private:
    char     bankName[30];
    int      count;
    Triangle questions[MAX_NUM];
    int      scores[MAX_NUM];
    double   average;

public:
    QuestionBank();
    QuestionBank(const char *name);
    ~QuestionBank();

    void        init(const char *name);
    void        setName(const char *name);
    const char *getName() const;
    int         getCount() const;
    double      getAverage() const;

    bool addQuestion(const Triangle &t);
    bool deleteQuestion(int id);
    void queryQuestion(int id) const;
    bool answerQuestion(int id, const char *ans);
    void calcAverage();
    void show() const;
};

#endif
