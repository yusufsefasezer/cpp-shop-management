#include "User.h"

namespace SHOPManagement
{

User::User(const string &t_user_name,
           const string &t_user_pass)
    : m_user_name(t_user_name),
      m_user_pass(t_user_pass)
{}

void User::setID(int t_id)
{
    this->m_id = t_id;
}

int User::getID() const
{
    return this->m_id;
}

void User::setUserName(const string &t_user_name)
{
    this->m_user_name = t_user_name;
}

string User::getUserName() const
{
    return this->m_user_name;
}

void User::setUserPass(const string &t_user_pass)
{
    this->m_user_pass = t_user_pass;
}

string User::getUserPass() const
{
    return this->m_user_pass;
}

bool User::checkLogin(const string &t_user_name,
                      const string &t_user_pass)
{
    return this->getUserName() == t_user_name && this->getUserPass() == t_user_pass;
}

void User::changePassword()
{
    string old_pass, new_pass;
    cout << "Old password: ";
    cin >> old_pass;

    if(this->getUserPass() == old_pass)
    {
        cout << "New password: ";
        cin >> new_pass;
        cin.ignore();
        this->setUserPass(new_pass);
        Helper::m_message = "password has been changed successfully.";
    }
    else
    {
        Helper::m_message = "Old password doesnt match!";
    }
}

void User::display()
{
    cout << this->getID() << " " << this->getUserName() << endl << endl;
}

void User::operationMenu(Shop *t_shop)
{
    vector<string> menu_options {"Change Password", "Show Information", "Exit"};

    while(1)
    {

        int result = Helper::createMenu(menu_options);

        switch(result)
        {
        case 1:
            this->changePassword();
            Helper::clearScreen();
            Helper::showMessage();
            break;
        case 2:
            Helper::clearScreen();
            this->display();
            break;
        case 3:
            Helper::clearScreen();
            return;
            break;
        default:
            cout << "Please select correct option." << endl;
            break;
        }

    }
}

User::~User() {}

}
