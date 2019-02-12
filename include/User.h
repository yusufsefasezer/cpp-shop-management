#ifndef USER_H
#define USER_H

#include "Header.h"

namespace SHOPManagement
{

class Shop;

class User
{
private:
    int m_id;
    string m_user_name;
    string m_user_pass;
    void changePassword();

public:
    User() = default;
    User(const string &t_user_name,
         const string &t_user_pass);

    void setID(int t_id);
    int getID() const;

    void setUserName(const string &t_user_name);
    string getUserName() const;

    void setUserPass(const string &t_user_pass);
    string getUserPass() const;

    bool checkLogin(const string &t_user_name,
                    const string &t_user_pass);

    virtual void display();
    virtual void operationMenu(Shop *t_shop);
    virtual string className() const
    {
        return "User";
    };
    virtual ~User();
};

}
#endif // USER_H
