#include "Product.h"

namespace SHOPManagement
{

Product::Product(const std::string &t_product_name,
                 const std::string &t_product_description,
                 const long double &t_product_price,
                 const int &t_product_quantity)
    : m_name(t_product_name),
      m_description(t_product_description),
      m_price(t_product_price),
      m_quantity(t_product_quantity)
{}

void Product::setID(int t_id)
{
    this->m_id = t_id;
}

int Product::getID() const
{
    return this->m_id;
}

void Product::setName(const std::string &t_name)
{
    this->m_name = t_name;
}

std::string Product::getName() const
{
    return this->m_name;
}

void Product::setDescription(const std::string &t_description)
{
    this->m_description = t_description;
}

std::string Product::getDescription() const
{
    return this->m_description;
}

void Product::setPrice(const long double &t_price)
{
    this->m_price = abs(t_price);
}

long double Product::getPrice() const
{
    return this->m_price;
}

void Product::setQuantity(const int &t_quantity)
{
    this->m_quantity = abs(t_quantity);
}

int Product::getQuantity() const
{
    return this->m_quantity;
}

void Product::display()
{
    std::cout << "Product ID: " << this->getID() << std::endl;
    std::cout << "Product Name: " << this->getName() << std::endl;
    std::cout << "Product Description: " << this->getDescription() << std::endl;
    std::cout << "Product Price: " << this->getPrice() << std::endl;
    std::cout << "Product Quantity: " << this->getQuantity() << std::endl;
}

Product::~Product() {}

}
