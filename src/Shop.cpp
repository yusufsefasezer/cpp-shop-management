#include "Shop.h"

namespace SHOPManagement
{

    Shop::Shop(std::string_view t_name,
               std::string_view t_description,
               std::shared_ptr<Address> t_address)
        : m_name(t_name),
          m_description(t_description),
          m_address(t_address) {}

    void Shop::run()
    {
        // Load necessary data
        this->loadData();

        // Show the shop menu
        this->menu();
    }

    void Shop::save()
    {
        this->saveUser();

        this->saveAddress();

        this->saveProduct();
    }

    void Shop::loadData()
    {
        // Load users
        this->loadUser();

        // Load addresses
        this->loadAddress();

        // Load products
        this->loadProduct();

        // Load orders
        // this->loadOrder();
    }

    void Shop::loadUser()
    {
        auto lines = Helper::loadFileByLine("data/USERS.dat");

        for (int i = 0, len = lines.size(); i < len; i++)
        {
            prepareUser(lines.at(i));
        }
    }

    void Shop::prepareUser(const std::string &t_data)
    {
        std::vector<std::string> data = Helper::split(t_data, '|');

        int id = atoi(data.at(0).c_str());
        std::string user_type = data.at(1).c_str();
        std::string user_name = data.at(2);
        std::string user_pass = data.at(3);
        std::string first_name = data.at(4);
        std::string last_name = data.at(5);
        std::string phone_number = data.at(6);

        if (user_type == "Manager")
        {
            Manager *pManager = new Manager();
            pManager->setID(id);
            pManager->setUserName(user_name);
            pManager->setUserPass(user_pass);
            pManager->setFirstName(first_name);
            pManager->setLastName(last_name);
            pManager->setPhoneNumber(phone_number);

            this->v_users.push_back(pManager);
        }
        else if (user_type == "Customer")
        {
            long double acc_balance = stod(data.at(7));

            Customer *pCustomer = new Customer();
            pCustomer->setID(id);
            pCustomer->setUserName(user_name);
            pCustomer->setUserPass(user_pass);
            pCustomer->setFirstName(first_name);
            pCustomer->setLastName(last_name);
            pCustomer->setPhoneNumber(phone_number);
            pCustomer->setBalance(acc_balance);

            this->v_users.push_back(pCustomer);
        }
        else
        {
            std::cerr << "Wrong Person Type" << std::endl;
        }
    }

    void Shop::saveUser()
    {
        std::vector<std::string> lines;
        std::stringstream ss;

        for (auto current : this->v_users)
        {
            if (current->className() == "Manager")
            {
                Manager *pManager = dynamic_cast<Manager *>(current);
                ss << pManager->getID() << "|";
                ss << pManager->className() << "|";
                ss << pManager->getUserName() << "|";
                ss << pManager->getUserPass() << "|";
                ss << pManager->getFirstName() << "|";
                ss << pManager->getLastName() << "|";
                ss << pManager->getPhoneNumber();
            }
            else if (current->className() == "Customer")
            {
                Customer *pCustomer = dynamic_cast<Customer *>(current);
                ss << pCustomer->getID() << "|";
                ss << pCustomer->className() << "|";
                ss << pCustomer->getUserName() << "|";
                ss << pCustomer->getUserPass() << "|";
                ss << pCustomer->getFirstName() << "|";
                ss << pCustomer->getLastName() << "|";
                ss << pCustomer->getPhoneNumber() << "|";
                ss << pCustomer->getBalance();
            }
            lines.push_back(ss.str());
            ss.str("");
        }

        Helper::saveFileByLine("data/USERS.dat", lines);
    }

    void Shop::loadAddress()
    {
        auto lines = Helper::loadFileByLine("data/ADDRESSES.dat");

        for (int i = 0, len = lines.size(); i < len; i++)
        {
            prepareAddress(lines.at(i));
        }
    }

    void Shop::prepareAddress(const std::string &t_data)
    {
        std::vector<std::string> data = Helper::split(t_data, '|');

        int id = atoi(data.at(0).c_str());
        std::string address_name = data.at(1);
        std::string address_country = data.at(2);
        std::string address_city = data.at(3);
        std::string address_street = data.at(4);
        Person *pCurrent = nullptr;

        for (int i = 0, len = this->v_users.size(); i < len; i++)
        {
            pCurrent = dynamic_cast<Person *>(this->v_users.at(i));

            if (pCurrent->getID() == id)
            {
                Address *pAddress = new Address();
                pAddress->setPid(id);
                pAddress->setName(address_name);
                pAddress->setCountry(address_country);
                pAddress->setCity(address_city);
                pAddress->setStreet(address_street);

                pCurrent->v_adress_list.push_back(pAddress);
            }
        }
    }

    void Shop::saveAddress()
    {
        std::vector<std::string> lines;
        std::stringstream ss;

        for (auto current : this->v_users)
        {
            Person *pPerson = dynamic_cast<Person *>(current);

            for (auto current_address : pPerson->v_adress_list)
            {
                ss << current_address->getPid() << "|";
                ss << current_address->getName() << "|";
                ss << current_address->getCountry() << "|";
                ss << current_address->getCity() << "|";
                ss << current_address->getStreet();
                lines.push_back(ss.str());
                ss.str("");
            }
        }

        Helper::saveFileByLine("data/ADDRESSES.dat", lines);
    }

    void Shop::loadProduct()
    {
        auto lines = Helper::loadFileByLine("data/PRODUCTS.dat");

        for (int i = 0, len = lines.size(); i < len; i++)
        {
            prepareProduct(lines.at(i));
        }
    }

    void Shop::prepareProduct(const std::string &t_data)
    {
        std::vector<std::string> data = Helper::split(t_data, '|');

        int id = atoi(data.at(0).c_str());
        std::string name = data.at(1);
        std::string description = data.at(2);
        long double price = std::stold(data.at(3).c_str());
        int quantity = atoi(data.at(4).c_str());

        Product *pProduct = new Product();
        pProduct->setID(id);
        pProduct->setName(name);
        pProduct->setDescription(description);
        pProduct->setPrice(price);
        pProduct->setQuantity(quantity);

        this->v_products.push_back(pProduct);
    }

    void Shop::saveProduct()
    {
        std::vector<std::string> lines;
        std::stringstream ss;

        for (auto current : this->v_products)
        {
            ss << current->getID() << "|";
            ss << current->getName() << "|";
            ss << current->getDescription() << "|";
            ss << current->getPrice() << "|";
            ss << current->getQuantity();
            lines.push_back(ss.str());
            ss.str("");
        }

        Helper::saveFileByLine("data/PRODUCTS.dat", lines);
    }

    std::vector<User *> Shop::getUsers() const
    {
        return this->v_users;
    }

    std::vector<Product *> Shop::getProduct() const
    {
        return this->v_products;
    }

    void Shop::listProduct()
    {
        for (auto current : this->v_products)
        {
            current->display();
        }
    }

    void Shop::addProduct()
    {
        int product_id = 1;
        std::string product_name = "";
        std::string product_description = "";
        long double product_price = 0.0;
        int product_quantity = 0;

        if (!this->v_products.empty())
        {
            product_id = this->v_products.back()->getID() + 1;
        }

        std::cout << "Product Name: ";
        std::getline(std::cin, product_name);

        std::cout << "Product Description: ";
        std::getline(std::cin, product_description);

        std::cout << "Product Price: ";
        std::cin >> product_price;

        std::cout << "Product Quantity: ";
        std::cin >> product_quantity;

        Product *pNew = new Product();
        pNew->setID(product_id);
        pNew->setName(product_name);
        pNew->setDescription(product_description);
        pNew->setPrice(product_price);
        pNew->setQuantity(product_quantity);

        this->v_products.push_back(pNew);

        Helper::m_message = "Product was successfully added.";
    }

    void Shop::editProduct()
    {
        if (this->v_products.size() < 1)
        {
            Helper::m_message = "Please add a Product.";
            return;
        }

        int product_id = -1;
        std::cout << "Product ID: ";
        std::cin >> product_id;
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        std::cin.sync();

        product_id = searchProductById(product_id);

        if (product_id != -1)
        {
            std::string product_name = "";
            std::string product_description = "";
            long double product_price = 0.0;
            int product_quantity = 0;

            std::cout << "Product Name: ";
            std::getline(std::cin, product_name);

            std::cout << "Product Description: ";
            std::getline(std::cin, product_description);

            std::cout << "Product Price: ";
            std::cin >> product_price;

            std::cout << "Product Quantity: ";
            std::cin >> product_quantity;

            Product *pEdit = this->v_products.at(product_id);
            pEdit->setName(product_name);
            pEdit->setDescription(product_description);
            pEdit->setPrice(product_price);
            pEdit->setQuantity(product_quantity);
            Helper::m_message = "Product was successfully updated.";
        }
        else
        {
            Helper::m_message = "Product was not found.";
        }
    }

    void Shop::deleteProduct()
    {
        if (this->v_products.size() < 1)
        {
            Helper::m_message = "Please add a Product.";
            return;
        }

        int product_id = -1;
        std::cout << "Product ID: ";
        std::cin >> product_id;
        std::cin.sync();

        product_id = searchProductById(product_id);

        if (product_id != -1)
        {
            this->v_products.erase(this->v_products.begin() + product_id);
            Helper::m_message = "Product was successfully deleted.";
        }
        else
        {
            Helper::m_message = "Product was not found.";
        }
    }

    void Shop::listUser()
    {
        for (auto current : this->v_users)
        {
            current->display();
        }
    }

    void Shop::addCustomer()
    {
        int user_id = 1;
        std::string user_name = "";
        std::string user_pass = "";
        std::string first_name = "";
        std::string last_name = "";
        std::string phone_number = "";

        if (!this->v_users.empty())
        {
            user_id = this->v_users.back()->getID() + 1;
        }

        std::cout << "User Name: ";
        std::getline(std::cin, user_name);

        std::cout << "User Pass: ";
        std::getline(std::cin, user_pass);

        std::cout << "First Name: ";
        std::getline(std::cin, first_name);

        std::cout << "Last Name: ";
        std::getline(std::cin, last_name);

        std::cout << "Phone Number: ";
        std::cin >> phone_number;

        Customer *pNew = new Customer();
        pNew->setID(user_id);
        pNew->setUserName(user_name);
        pNew->setUserPass(user_pass);
        pNew->setFirstName(first_name);
        pNew->setLastName(last_name);
        pNew->setPhoneNumber(phone_number);
        pNew->setBalance(0);

        this->v_users.push_back(pNew);

        Helper::m_message = "Customer was successfully added.";
    }

    void Shop::editCustomer()
    {
        int customer_id = -1;
        std::cout << "Customer ID: ";
        std::cin >> customer_id;
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        std::cin.sync();

        customer_id = searchProductById(customer_id);

        if (customer_id != -1)
        {
            std::string first_name;
            std::string last_name;
            std::string phone_number;

            std::cout << "First Name: ";
            std::getline(std::cin, first_name);

            std::cout << "Last Name: ";
            std::getline(std::cin, last_name);

            std::cout << "Phone Number: ";
            std::getline(std::cin, phone_number);

            Customer *pEdit = (Customer *)(this->v_users.at(customer_id));
            pEdit->setFirstName(first_name);
            pEdit->setLastName(last_name);
            pEdit->setPhoneNumber(phone_number);

            Helper::m_message = "Customer was successfully updated.";
        }
        else
        {
            Helper::m_message = "Customer was not found.";
        }
    }

    void Shop::deleteCustomer()
    {
        int customer_id = -1;
        bool search_result = false;
        std::cout << "Customer ID: ";
        std::cin >> customer_id;
        std::cin.sync();

        customer_id = searchUserById(customer_id);

        if (customer_id != -1)
        {
            User *pSelected = this->v_users.at(customer_id);
            search_result = Helper::findCaseInsensitive(pSelected->className(), "Manager");

            if (search_result == 0)
            {
                Helper::m_message = "Manager cannot be deleted.";
            }
            else
            {
                this->v_users.erase(this->v_users.begin() + customer_id);
                Helper::m_message = "Customer was successfully deleted.";
            }
        }
        else
        {
            Helper::m_message = "Customer was not found.";
        }
    }

    void Shop::searchProductByName()
    {
        std::string search_term;
        std::cout << "Product Name: ";
        std::getline(std::cin, search_term);

        for (int i = 0, len = this->v_products.size(); i < len; i++)
        {
            if (Helper::findCaseInsensitive(this->v_products.at(i)->getName(), search_term) == 0)
            {
                this->v_products.at(i)->display();
            }
        }

        Helper::m_message = "Product was not found.";
    }

    int Shop::searchProductById(const int &t_id)
    {
        for (int i = 0, len = this->v_products.size(); i < len; i++)
        {
            if (this->v_products.at(i)->getID() == t_id)
            {
                return i;
            }
        }

        return -1;
    }

    int Shop::searchUserById(const int &t_id)
    {
        for (int i = 0, len = this->v_users.size(); i < len; i++)
        {
            if (this->v_users.at(i)->getID() == t_id)
            {
                return i;
            }
        }

        return -1;
    }

    void Shop::buyProduct(Customer *pCustomer)
    {
        int product_id = -1;
        std::cout << "Product ID: ";
        std::cin >> product_id;

        product_id = searchProductById(product_id);

        if (product_id != -1)
        {
            Product *pProduct = this->v_products.at(product_id);

            if (pProduct->getQuantity() > 0)
            {
                int product_quantity;

                do
                {
                    std::cout << "Quantity: ";
                    std::cin >> product_quantity;
                } while (pProduct->getQuantity() < product_quantity || product_quantity < 1);

                int new_quantity = pProduct->getQuantity() - product_quantity;
                pProduct->setQuantity(new_quantity);
                long double new_balance = pCustomer->getBalance() + (pProduct->getPrice() * product_quantity);
                pCustomer->setBalance(new_balance);
            }
        }
        else
        {
            Helper::m_message = "Product was not found.";
        }
    }

    void Shop::menu()
    {
        std::vector<std::string> menu_options{"Shop Information", "Login", "Exit"};

        while (1)
        {
            int result = Helper::createMenu(menu_options);

            switch (result)
            {
            case 1:
                Helper::clearScreen();
                this->display();
                break;
            case 2:
                this->login();
                Helper::clearScreen();
                Helper::showMessage();
                if (this->pUser != nullptr)
                {
                    this->pUser->operationMenu(this);
                    this->pUser = nullptr;
                }
                break;
            case 3:
                return;
                break;
            default:
                std::cout << "Please select correct option." << std::endl;
                break;
            }
        }
    }

    bool Shop::login()
    {
        bool found = false;
        std::string user_name, user_pass;
        User *pCurrent = nullptr;
        std::cin.sync();

        std::cout << "User name: ";
        std::getline(std::cin, user_name);

        std::cout << "User pass: ";
        std::getline(std::cin, user_pass);

        for (int i = 0, len = this->v_users.size(); i < len; i++)
        {
            pCurrent = this->v_users.at(i);

            if (pCurrent->checkLogin(user_name, user_pass))
            {
                found = true;
                this->pUser = pCurrent;
                break;
            }
        }

        if (found == true)
        {
            Helper::m_message = "Login successfully.";
        }
        else
        {
            Helper::m_message = "User name or pass wrong";
        }

        return found;
    }

    void Shop::display()
    {
        std::cout << "*** Shop Information ***" << std::endl;
        std::cout << "Shop Name: " << this->m_name << std::endl;
        std::cout << "Description: " << this->m_description << std::endl;
        std::cout << "Product Count: " << this->v_products.size() << std::endl;

        this->m_address->display();
    }

    Shop::~Shop()
    {
        for (int i = 0, len = this->v_users.size(); i < len; i++)
        {
            delete this->v_users.at(i);
        }

        for (int i = 0, len = this->v_products.size(); i < len; i++)
        {
            delete this->v_products.at(i);
        }

        if (pUser != nullptr)
        {
            delete pUser;
        }
    }

}
