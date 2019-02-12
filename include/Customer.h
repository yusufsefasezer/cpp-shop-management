#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include "Shop.h"

namespace SHOPManagement
{

class Customer : public Person
{
private:
    long double m_balance;
    void payment();

public:
    Customer() = default;
    Customer(const string &t_user_name,
             const string &t_user_pass,
             const string &t_first_name,
             const string &t_last_name,
             const string &t_phone_number,
             const long double &t_balance);

    void setBalance(long double t_balance);
    long double getBalance() const;

    virtual void display();
    virtual void operationMenu(Shop *t_shop);
    virtual string className() const
    {
        return "Customer";
    };
    virtual ~Customer();
};

}
#endif // CUSTOMER_H
