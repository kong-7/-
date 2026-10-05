#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle
{
private:
    int    id;
    double sideA;
    double sideB;
    double sideC;
    char   userAnswer[24];
    char   rightAnswer[24];

public:
    Triangle();
    Triangle(int newId, double a, double b, double c);
    ~Triangle();

    void init(int newId, double a, double b, double c);
    void setSides(double a, double b, double c);
    void setUserAnswer(const char *ans);
    bool isValid() const;

    int         getId() const;
    double      getSideA() const;
    double      getSideB() const;
    double      getSideC() const;
    const char *getUserAnswer() const;
    const char *getRightAnswer() const;

    double perimeter() const;
    double area() const;
    void   calcRightAnswer();
    bool   checkAnswer(const char *ans) const;

    void show() const;
};

#endif
