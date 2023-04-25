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
        std::string_view m_name;
        std::string_view m_description;
        std::shared_ptr<Address> m_address;
        std::vector<User *> v_users;
        std::vector<Product *> v_products;
        // std::vector <Order*> v_orders;
        User *pUser = nullptr;

        // Load data
        void loadData();

        // Load user
        void loadUser();
        void prepareUser(const std::string &t_data);
        void saveUser();

        // Load address
        void loadAddress();
        void prepareAddress(const std::string &t_data);
        void saveAddress();

        // Load product
        void loadProduct();
        void prepareProduct(const std::string &t_data);
        void saveProduct();

        // Shop functions
        void menu();
        bool login();

        int searchProductById(const int &t_id);
        int searchUserById(const int &t_id);

    public:
        Shop() = default;
        Shop(std::string_view t_name,
             std::string_view t_description,
             std::shared_ptr<Address> t_address);

        std::vector<User *> getUsers() const;
        std::vector<Product *> getProduct() const;

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
