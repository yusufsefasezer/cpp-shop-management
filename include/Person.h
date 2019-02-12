#ifndef PERSON_H
#define PERSON_H

#include "Address.h"
#include "User.h"

namespace SHOPManagement
{

class Person : public User
{
private:
    string m_first_name;
    string m_last_name;
    string m_phone_number;

    void changeFirstName();
    void changeLastName();
    void changePhoneNumber();
    int getAddressIndex();

public:
    vector<Address*> v_adress_list;
    Person() = default;
    Person(const string &t_user_name,
           const string &t_user_pass,
           const string &t_first_name,
           const string &t_last_name,
           const string &t_phone_number);

    void setFirstName(const string &t_first_name);
    string getFirstName() const;

    void setLastName(const string &t_last_name);
    string getLastName() const;

    void setPhoneNumber(const string &t_phone_number);
    string getPhoneNumber() const;

    // Address operation
    void listAddress();
    void addAddress();
    void editAddress();
    void deleteAddress();

    virtual void display();
    virtual void operationMenu(Shop *t_shop);
    virtual string className() const
    {
        return "Person";
    };
    virtual ~Person();
};

}
#endif // PERSON_H
