#include <iostream>
using namespace std;

class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1)
        : _year(year), _month(month), _day(day)
    {
    }

    int GetMonthDay(int year, int month) const
    {
        int hashm[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (year % 400 == 0 || (year % 4 == 0) && (year % 100 != 0))
            hashm[2] += 1;
        return hashm[month];
    }

    bool IsValid() const
    {
        if (_year <= 0)
            return false;
        else if (_month <= 0 || _month > 12)
            return false;
        else if (_day <= 0 || _day > GetMonthDay(_year, _month))
            return false;
        else
            return true;
    }

    void Print() const
    {
        std::cout << _year << "-" << _month << "-" << _day << std::endl;
    }

    bool operator==(const Date &d) const
    {
        return _year == d._year && _month == d._month && _day == d._day;
    }
    bool operator!=(const Date &d) const
    {
        return !(*this == d);
    }

    bool operator<(const Date &d) const
    {
        if (_year != d._year)
            return _year < d._year;
        if (_month != d._month)
            return _month < d._month;

        return _day < d._day;
    }
    bool operator<=(const Date &d) const
    {
        return operator<(d) || operator==(d);
    }

    bool operator>(const Date &d) const
    {
        return d < *this;
    }
    bool operator>=(const Date &d) const
    {
        return !operator<(d);
    }

    Date &operator+=(int day)
    {
        _day += day;
        while (_day > GetMonthDay(_year, _month))
        {
            _day -= GetMonthDay(_year, _month);
            _month++;
            if (_month > 12)
            {
                _year++;
                _month = 1;
            }
        }
        return *this;
    }
    Date operator+(int day) const
    {
        Date tmp = *this;
        tmp += day;
        return tmp;
    }

    Date &operator-=(int day)
    {
        _day -= day;
        while (_day <= 0)
        {
            --_month;
            if (_month <= 0)
            {
                _year--;
                _month = 12;
            }
            _day += GetMonthDay(_year, _month);
        }
        return *this;
    }
    Date operator-(int day) const
    {
        Date tmp = *this;
        tmp -= day;
        return tmp;
    }

    int operator-(const Date &d) const
    {
        Date max = *this;
        Date min = d;
        int tmp = 1;
        if (max < min)
        {
            max = d;
            min = *this;
            tmp = -1;
        }
        int count = 0;
        while (max > min)
        {
            min++;
            count++;
        }

        return count * tmp;
    }

    Date &operator++()
    {
        *this += 1;
        return *this;
    }
    Date operator++(int)
    {
        Date tmp = *this;
        *this += 1;
        return tmp;
    }

    friend ostream &operator<<(ostream &out, const Date &d);
    friend istream &operator>>(istream &in, Date &d);

private:
    int _year;
    int _month;
    int _day;
};

ostream &operator<<(ostream &out, const Date &d)
{
    out << d._year << "-" << d._month << "-" << d._day;
    return out;
}

istream &operator>>(istream &in, Date &d)
{
    in >> d._year >> d._month >> d._day;
}

int main()
{

    return 0;
}