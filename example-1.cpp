#include <stdio.h>
#include <iostream>
#include <windows.h>
using namespace std;

class Time
{
  private: // 私有访问权限（只能在Time类内访问）
    int hour, minute, second;

  public:
    Time(int hour, int minute, int second)
    {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
    void display()
    {
        cout << hour << ":" << minute << ":" << second << endl;
    }

    // 前置++
    Time operator++()
    {
        second++;
        if (second >= 60)
        {
            second = 0;
            minute++;
            if (minute >= 60)
            {
                minute = 0;
                hour++;
                if (hour >= 24)
                {
                    hour = 0;
                }
            }
        }

        return *(this);
    }

    // 后置++
    Time operator++(int)
    {
        Time temp = *this;

        second++;
        if (second >= 60)
        {
            second = 0;
            minute++;
            if (minute >= 60)
            {
                minute = 0;
                hour++;
                if (hour >= 24)
                {
                    hour = 0;
                }
            }
        }

        return temp;
    }
};

int main()
{
	float f = 1;
	int i = 2.2;

    system("pause");
    return 0;
}
