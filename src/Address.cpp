#include "Address.h"

namespace SHOPManagement
{

Address::Address(const string &t_name,
                 const string &t_country,
                 const string &t_city,
                 const string &t_street)
    : m_name(t_name),
      m_country(t_country),
      m_city(t_city),
      m_street(t_street)
{}

void Address::setPid(int t_pid)
{
    this->m_pid = t_pid;
}

int Address::getPid()
{
    return this->m_pid;
}

void Address::setName(const string &t_name)
{
    this->m_name = t_name;
}

string Address::getName()
{
    return this->m_name;
}

void Address::setCountry(const string &t_country)
{
    this->m_country = t_country;
}

string Address::getCountry()
{
    return this->m_country;
}

void Address::setCity(const string &t_city)
{
    this->m_city = t_city;
}

string Address::getCity()
{
    return this->m_city;
}

void Address::setStreet(const string &t_street)
{
    this->m_street = t_street;
}

string Address::getStreet()
{
    return this->m_street;
}

void Address::display()
{
    cout << this->getName() << endl;
    cout << "Country: " << this->getCountry() << endl;
    cout << "City: " << this->getCity() << endl;
    cout << "Street: " << this->getStreet() << endl;
}

Address::~Address() {}

}
