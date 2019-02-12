#include "Person.h"
#include "Shop.h"

namespace SHOPManagement
{

Person::Person(const string &t_user_name,
               const string &t_user_pass,
               const string &t_first_name,
               const string &t_last_name,
               const string &t_phone_number)
    : User(t_user_name, t_user_pass),
      m_first_name(t_first_name),
      m_last_name(t_last_name),
      m_phone_number(t_phone_number) {}

void Person::setFirstName(const string &t_first_name)
{
    this->m_first_name = t_first_name;
}

string Person::getFirstName() const
{
    return this->m_first_name;
}

void Person::setLastName(const string &t_last_name)
{
    this->m_last_name = t_last_name;
}

string Person::getLastName() const
{
    return this->m_last_name;
}

void Person::setPhoneNumber(const string &t_phone_number)
{
    this->m_phone_number = t_phone_number;
}

string Person::getPhoneNumber() const
{
    return this->m_phone_number ;
}

void Person::listAddress()
{
    for(auto current : this->v_adress_list)
    {
        current->display();
    }
}

int Person::getAddressIndex()
{
    int address_index = 0;
    vector<string> address_list;

    for(int i = 0, len = this->v_adress_list.size(); i < len; i++)
    {
        address_list.push_back(this->v_adress_list.at(i)->getName());
    }

    address_index = Helper::createMenu(address_list) - 1;

    return address_index;
}

void Person::addAddress()
{
    int address_pid = this->getID();
    string address_name = "";
    string address_country = "";
    string address_city = "";
    string address_street = "";

    cout << "Address Name: ";
    getline(cin, address_name);

    cout << "Country: ";
    getline(cin, address_country);

    cout << "City: ";
    getline(cin, address_city);

    cout << "Street: ";
    getline(cin, address_street);

    Address *pNew = new Address();
    pNew->setPid(address_pid);
    pNew->setName(address_name);
    pNew->setCountry(address_country);
    pNew->setCity(address_city);
    pNew->setStreet(address_street);

    this->v_adress_list.push_back(pNew);

    Helper::m_message = "Address was successfully added.";
}

void Person::editAddress()
{
    if(this->v_adress_list.size() < 1)
    {
        Helper::m_message = "Please add an address.";
        return;
    }

    int address_index = this->getAddressIndex();
    string address_name = "";
    string address_country = "";
    string address_city = "";
    string address_street = "";

    cout << "Address Name: ";
    getline(cin, address_name);

    cout << "Country: ";
    getline(cin, address_country);

    cout << "City: ";
    getline(cin, address_city);

    cout << "Street: ";
    getline(cin, address_street);

    Address *pEdit = this->v_adress_list.at(address_index);
    pEdit->setName(address_name);
    pEdit->setCountry(address_country);
    pEdit->setCity(address_city);
    pEdit->setStreet(address_street);

    Helper::m_message = "Address was successfully updated.";
}

void Person::deleteAddress()
{
    if(this->v_adress_list.size() < 1)
    {
        Helper::m_message = "Please add an address.";
        return;
    }

    if(this->v_adress_list.size() < 1)
    {
        return;
    }

    int address_index = this->getAddressIndex();
    this->v_adress_list.erase(this->v_adress_list.begin() + address_index);

    Helper::m_message = "Address was successfully deleted.";
}

void Person::changeFirstName()
{
    string new_value;
    cout << "First Name(" << this->getFirstName() << "): ";
    cin.ignore();
    getline(std::cin, new_value);

    if(!new_value.empty())
    {
        this->setFirstName(new_value);
        Helper::m_message = "First name has been changed successfully.";
    }
}

void Person::changeLastName()
{
    string new_value;
    cout << "Last name(" << this->getLastName() << "): ";
    cin.ignore();
    getline(std::cin, new_value);

    if(!new_value.empty())
    {
        this->setLastName(new_value);
        Helper::m_message = "Last name has been changed successfully.";
    }
}

void Person::changePhoneNumber()
{
    string new_value;
    cout << "Phone Number(" << this->getPhoneNumber() << "): ";
    cin.ignore();
    getline(std::cin, new_value);

    if(!new_value.empty())
    {
        this->setPhoneNumber(new_value);
        Helper::m_message = "Phone number has been changed successfully.";
    }
}

void Person::display()
{
    Helper::clearScreen();

    cout << "*** "<< this->className() << " Information ***" << endl;
    cout << "First Name: " << this->getFirstName() << endl;
    cout << "Last Name: " << this->getLastName() << endl;
    cout << "Phone Number: " << this->getPhoneNumber() << endl;

    for(int i = 0, len = this->v_adress_list.size(); i < len; i++)
        this->v_adress_list.at(i)->display();
}

void Person::operationMenu(Shop *t_shop)
{
    vector<string> menu_options
    {
        "Change First Name", "Change Last Name", "Change Phone Number",
        "List Address", "Add Address", "Edit Address", "Delete Address",
        "User Options", "Save & Exit", "Exit"};

    while(1)
    {
        int result = Helper::createMenu(menu_options);

        switch(result)
        {
        case 1:
            // Change First Name
            this->changeFirstName();
            Helper::clearScreen();
            Helper::showMessage();
            break;
        case 2:
            // Change Last Name
            this->changeLastName();
            Helper::clearScreen();
            Helper::showMessage();
            break;
        case 3:
            // Change Phone Number
            this->changePhoneNumber();
            Helper::clearScreen();
            Helper::showMessage();
            break;
        case 4:
            // List Address
            Helper::clearScreen();
            this->listAddress();
            break;
        case 5:
            // Add Address
            Helper::clearScreen();
            this->addAddress();
            Helper::showMessage();
            break;
        case 6:
            // Edit Address
            Helper::clearScreen();
            this->editAddress();
            Helper::showMessage();
            break;
        case 7:
            // Delete Address
            Helper::clearScreen();
            this->deleteAddress();
            Helper::showMessage();
            break;
        case 8:
            // User Options
            Helper::clearScreen();
            User::operationMenu(t_shop);
            break;
        case 9:
            // Save & Exit
            Helper::clearScreen();
            t_shop->save();
            Helper::showMessage();
            return;
            break;
        case 10:
            // Exit
            Helper::clearScreen();
            return;
            break;
        default:
            cout << "Please select correct option." << endl;
            break;
        }
    }
}

Person::~Person()
{
    for(int i = 0, len = this->v_adress_list.size(); i < len; i++)
    {
        delete this->v_adress_list.at(i);
    }
};

}
