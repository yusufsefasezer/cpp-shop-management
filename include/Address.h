#ifndef ADDRESS_H
#define ADDRESS_H

#include "Header.h"

namespace SHOPManagement
{

class Address
{
private:
    int m_pid;
    string m_name;
    string m_country;
    string m_city;
    string m_street;

public:
    Address() = default;
    Address(const string &t_name,
            const string &t_country,
            const string &t_city,
            const string &t_street);

    void setPid(int t_pid);
    int getPid();

    void setName(const string &t_name);
    string getName();

    void setCountry(const string &t_country);
    string getCountry();

    void setCity(const string &t_city);
    string getCity();

    void setStreet(const string &t_street);
    string getStreet();

    virtual void display();
    virtual ~Address();
};

}
#endif // ADDRESS_H
