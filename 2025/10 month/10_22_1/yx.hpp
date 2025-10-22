#pragma once
#include <iostream>
using namespace std;

class Info
{
public:
    Info() {}
    string getAwards() { return awards; }
    string getAwardsClase() { return awardsClase; }
    void setAwards(string s_awareds) { awards = s_awareds; }
    void setAwardsClase(string s_awardsclase) { awardsClase = s_awardsclase; }

    Info *Clone()
    {
        Info *info = new Info();
        *info = *this;
        return info;
    }

private:
    string awards;
    string awardsClase;
};

class Certificate
{
public:
    Certificate() {}
    virtual void Display() = 0;
    virtual void SetInfo(string name, string sex, string college) = 0;
    virtual void SetAwardsInfo(string data, string class_) = 0;
    virtual Certificate *Clone() = 0;

protected:
    string name;
    string sex;
    string college;
};

class Citation : public Certificate
{
public:
    Citation() = default;
    void SetInfo(string name, string sex, string college)
    {
        this->name = name;
        this->sex = sex;
        this->college = college;
    }

    void SetAwardsInfo(string data, string class_)
    {
        _info->setAwards(data);
        _info->setAwardsClase(class_);
    }

    void Display()
    {
        cout << name << " " << sex << " " << college << "\n";
        cout << _info->getAwards() << " " << _info->getAwardsClase() << endl;
    }

    Certificate *Clone() override
    {
        Citation *clonecitation = new Citation(_info);
        clonecitation->name = this->name;
        clonecitation->sex = this->sex;
        clonecitation->college = college;

        return clonecitation;
    }

private:
    Info *_info = new Info();
    explicit Citation(Info *info) : _info((Info *)info->Clone()) {}
};
