#ifndef ADDRESS_H
#define ADDRESS_H

#include "Header.h"

namespace SHOPManagement
{

    class Address
    {
    private:
        int m_pid;
        std::string m_name;
        std::string m_country;
        std::string m_city;
        std::string m_street;

    public:
        Address() = default;
        Address(const std::string &t_name,
                const std::string &t_country,
                const std::string &t_city,
                const std::string &t_street);

        void setPid(int t_pid);
        int getPid();

        void setName(const std::string &t_name);
        std::string getName() const;

        void setCountry(const std::string &t_country);
        std::string getCountry() const;

        void setCity(const std::string &t_city);
        std::string getCity() const;

        void setStreet(const std::string &t_street);
        std::string getStreet() const;

        virtual void display();
        virtual ~Address();
    };

}
#endif // ADDRESS_H
