#include "Customer.h"

namespace SHOPManagement
{

Customer::Customer(const string &t_user_name,
                   const string &t_user_pass,
                   const string &t_first_name,
                   const string &t_last_name,
                   const string &t_phone_number,
                   const long double &t_balance)
    : Person(t_user_name, t_user_pass, t_first_name, t_last_name, t_phone_number),
      m_balance(t_balance) {}

void Customer::setBalance(long double t_balance)
{
    this->m_balance = t_balance;
}

long double Customer::getBalance() const
{
    return this->m_balance;
}

void Customer::payment()
{
    long double payment_amount = 0;

    this->display();
    do
    {
        cout << "Payment amount: ";
        cin >> payment_amount;
    }
    while(this->getBalance() < payment_amount || payment_amount < 0.0);

    long double new_balance = (double)this->getBalance() - (double)payment_amount;
    this->setBalance(new_balance);
    Helper::m_message = "Payment was made successfully.";
}

void Customer::display()
{
    cout << "*** Customer Information ***" << endl;
    cout << "First Name: " << this->getFirstName() << endl;
    cout << "Last Name: " << this->getLastName() << endl;
    cout << "Phone Number: " << this->getPhoneNumber() << endl;
    cout << "Account Balance: " << this->getBalance() << endl;

    for(int i = 0, len = this->v_adress_list.size(); i< len; i++)
        this->v_adress_list.at(i)->display();
}

void Customer::operationMenu(Shop *t_shop)
{
    vector<string> menu_options {"List Products", "Search Products", "Buy Product", "Payments", "Personal Options", "Exit"};

    while(1)
    {
        int result = Helper::createMenu(menu_options);

        switch(result)
        {
        case 1:
            Helper::clearScreen();
            t_shop->listProduct();
            break;
        case 2:
            Helper::clearScreen();
            t_shop->searchProductByName();
            break;
        case 3:
            Helper::clearScreen();
            t_shop->buyProduct(this);
            Helper::showMessage();
            break;
        case 4:
            Helper::clearScreen();
            this->payment();
            Helper::showMessage();
            break;
        case 5:
            Helper::clearScreen();
            Person::operationMenu(t_shop);
            break;
        case 6:
            Helper::clearScreen();
            return;
            break;
        default:
            cout << "Please select correct option." << endl;
            break;
        }
    }
}

Customer::~Customer() {}

}
