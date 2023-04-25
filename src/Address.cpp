#include "Address.h"

namespace SHOPManagement
{

    Address::Address(const std::string &t_name,
                     const std::string &t_country,
                     const std::string &t_city,
                     const std::string &t_street)
        : m_name(t_name),
          m_country(t_country),
          m_city(t_city),
          m_street(t_street) {}

    void Address::setPid(int t_pid)
    {
        this->m_pid = t_pid;
    }

    int Address::getPid()
    {
        return this->m_pid;
    }

    void Address::setName(const std::string &t_name)
    {
        this->m_name = t_name;
    }

    std::string Address::getName() const
    {
        return this->m_name;
    }

    void Address::setCountry(const std::string &t_country)
    {
        this->m_country = t_country;
    }

    std::string Address::getCountry() const
    {
        return this->m_country;
    }

    void Address::setCity(const std::string &t_city)
    {
        this->m_city = t_city;
    }

    std::string Address::getCity() const
    {
        return this->m_city;
    }

    void Address::setStreet(const std::string &t_street)
    {
        this->m_street = t_street;
    }

    std::string Address::getStreet() const
    {
        return this->m_street;
    }

    void Address::display()
    {
        std::cout << this->getName() << std::endl;
        std::cout << "Country: " << this->getCountry() << std::endl;
        std::cout << "City: " << this->getCity() << std::endl;
        std::cout << "Street: " << this->getStreet() << std::endl;
    }

    Address::~Address() {}

}
