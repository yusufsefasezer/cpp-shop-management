#include "Product.h"

namespace SHOPManagement
{

Product::Product(const string &t_product_name,
                 const string &t_product_description,
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

void Product::setName(const string &t_name)
{
    this->m_name = t_name;
}

string Product::getName() const
{
    return this->m_name;
}

void Product::setDescription(const string &t_description)
{
    this->m_description = t_description;
}

string Product::getDescription() const
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
    cout << "Product ID: " << this->getID() << endl;
    cout << "Product Name: " << this->getName() << endl;
    cout << "Product Description: " << this->getDescription() << endl;
    cout << "Product Price: " << this->getPrice() << endl;
    cout << "Product Quantity: " << this->getQuantity() << endl;
}

Product::~Product() {}

}
