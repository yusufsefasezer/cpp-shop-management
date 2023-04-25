#ifndef PRODUCT_H
#define PRODUCT_H

#include "Header.h"

namespace SHOPManagement
{

    class Product
    {
    private:
        int m_id;
        std::string m_name;
        std::string m_description;
        long double m_price;
        int m_quantity;

    public:
        Product() = default;
        Product(const std::string &t_name,
                const std::string &t_description,
                const long double &t_price,
                const int &t_quantity);

        void setID(int t_id);
        int getID() const;

        void setName(const std::string &t_name);
        std::string getName() const;

        void setDescription(const std::string &t_description);
        std::string getDescription() const;

        void setPrice(const long double &t_price);
        long double getPrice() const;

        void setQuantity(const int &t_quantity);
        int getQuantity() const;

        virtual void display();
        virtual ~Product();
    };

}
#endif // PRODUCT_H
