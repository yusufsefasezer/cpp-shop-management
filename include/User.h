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
        std::string m_user_name;
        std::string m_user_pass;
        void changePassword();

    public:
        User() = default;
        User(const std::string &t_user_name,
             const std::string &t_user_pass);

        void setID(int t_id);
        int getID() const;

        void setUserName(const std::string &t_user_name);
        std::string getUserName() const;

        void setUserPass(const std::string &t_user_pass);
        std::string getUserPass() const;

        bool checkLogin(const std::string &t_user_name,
                        const std::string &t_user_pass);

        virtual void display();
        virtual void operationMenu(Shop *t_shop);
        virtual std::string className() const
        {
            return "User";
        };
        virtual ~User();
    };

}
#endif // USER_H
