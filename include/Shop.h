#ifndef SHOP_H
#define SHOP_H

#include "Address.h"
#include "Customer.h"
#include "Helper.h"
#include "Manager.h"
#include "Product.h"
#include "User.h"

namespace SHOPManagement
{

class Customer;

class Shop
{
private:
    string m_name;
    string m_description;
    Address *m_address;
    vector<User*> v_users;
    vector<Product*> v_products;
    //vector<Order*> v_orders;
    User *pUser = nullptr;

    // Load data
    void loadData();

    // Load user
    void loadUser();
    void prepareUser(const string &t_data);
    void saveUser();

    // Load address
    void loadAddress();
    void prepareAddress(const string &t_data);
    void saveAddress();

    // Load product
    void loadProduct();
    void prepareProduct(const string &t_data);
    void saveProduct();

    // Shop functions
    void menu();
    bool login();

    int searchProductById(const int &t_id);
    int searchUserById(const int &t_id);

public:
    Shop() = default;
    Shop(const string &t_name,
         const string &t_description,
         Address *t_address);

    vector<User*> getUsers() const;
    vector<Product*> getProduct() const;

    void run();
    void save();

    // Product operation
    void listProduct();
    void addProduct();
    void editProduct();
    void deleteProduct();

    // Product operation
    void listUser();
    void addCustomer();
    void editCustomer();
    void deleteCustomer();

    void searchProductByName();
    void buyProduct(Customer *pCustomer);

    virtual void display();
    virtual ~Shop();
};

}
#endif // SHOP_H
