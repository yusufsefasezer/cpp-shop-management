#include "Manager.h"

namespace SHOPManagement
{

Manager::Manager(const string &t_user_name,
                 const string &t_user_pass,
                 const string &t_first_name,
                 const string &t_last_name,
                 const string &t_phone_number)
    : Person(t_user_name, t_user_pass, t_first_name, t_last_name, t_phone_number) {}

void Manager::display()
{
    cout << "*** "<< this->className() << " Information ***" << endl;
    cout << "First Name: " << this->getFirstName() << endl;
    cout << "Last Name: " << this->getLastName() << endl;
    cout << "Phone Number: " << this->getPhoneNumber() << endl;

    for(int i = 0, len = this->v_adress_list.size(); i < len; i++)
    {
        this->v_adress_list.at(i)->display();
    }
}

void Manager::operationMenu(Shop *t_shop)
{
    vector<string> menu_options
    {
        "List Products", "Search Products", "Add Product", "Edit Product", "Delete Product",
        "List Users", "Add Customer", "Edit Customer", "Delete Customer",
        "Personal Options", "Save & Exit", "Exit"
    };

    while(1)
    {
        int result = Helper::createMenu(menu_options);

        switch(result)
        {
        case 1:
            // List Products
            Helper::clearScreen();
            t_shop->listProduct();
            break;
        case 2:
            // Search Products
            Helper::clearScreen();
            t_shop->searchProductByName();
            Helper::showMessage();
            break;
        case 3:
            // Add Product
            Helper::clearScreen();
            t_shop->addProduct();
            Helper::showMessage();
            break;
        case 4:
            // Edit Product
            Helper::clearScreen();
            t_shop->editProduct();
            Helper::showMessage();
            break;
        case 5:
            // Delete Product
            Helper::clearScreen();
            t_shop->deleteProduct();
            Helper::showMessage();
            break;
        case 6:
            // List Users
            Helper::clearScreen();
            t_shop->listUser();
            break;
        case 7:
            // Add Customer
            Helper::clearScreen();
            t_shop->addCustomer();
            Helper::showMessage();
            break;
        case 8:
            // Edit Customer
            Helper::clearScreen();
            t_shop->editCustomer();
            Helper::showMessage();
            break;
        case 9:
            // Delete Customer
            Helper::clearScreen();
            t_shop->deleteCustomer();
            Helper::showMessage();
            break;
        case 10:
            // Personal Options
            Helper::clearScreen();
            Person::operationMenu(t_shop);
            break;
        case 11:
            // Save & Exit
            Helper::clearScreen();
            t_shop->save();
            Helper::showMessage();
            return;
            break;
        case 12:
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

Manager::~Manager() {}

}
