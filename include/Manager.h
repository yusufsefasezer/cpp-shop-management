#ifndef MANAGER_H
#define MANAGER_H

#include "Person.h"
#include "Shop.h"

namespace SHOPManagement
{

    class Manager : public Person
    {
    public:
        Manager() = default;
        Manager(const std::string &t_user_name,
                const std::string &t_user_pass,
                const std::string &t_first_name,
                const std::string &t_last_name,
                const std::string &t_phone_number);

        virtual void display();
        virtual void operationMenu(Shop *t_shop);
        virtual std::string className() const
        {
            return "Manager";
        };
        virtual ~Manager();
    };

}
#endif // MANAGER_H
