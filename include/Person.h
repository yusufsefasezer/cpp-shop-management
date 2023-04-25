#ifndef PERSON_H
#define PERSON_H

#include "Address.h"
#include "User.h"

namespace SHOPManagement
{

    class Person : public User
    {
    private:
        std::string m_first_name;
        std::string m_last_name;
        std::string m_phone_number;

        void changeFirstName();
        void changeLastName();
        void changePhoneNumber();
        int getAddressIndex();

    public:
        std::vector<Address *> v_adress_list;
        Person() = default;
        Person(const std::string &t_user_name,
               const std::string &t_user_pass,
               const std::string &t_first_name,
               const std::string &t_last_name,
               const std::string &t_phone_number);

        void setFirstName(const std::string &t_first_name);
        std::string getFirstName() const;

        void setLastName(const std::string &t_last_name);
        std::string getLastName() const;

        void setPhoneNumber(const std::string &t_phone_number);
        std::string getPhoneNumber() const;

        // Address operation
        void listAddress();
        void addAddress();
        void editAddress();
        void deleteAddress();

        virtual void display();
        virtual void operationMenu(Shop *t_shop);
        virtual std::string className() const
        {
            return "Person";
        };
        virtual ~Person();
    };

}
#endif // PERSON_H
