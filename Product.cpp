#define _CRT_SECURE_NO_WARNINGS  
#include <iostream>
#include <cstring>
#include "Product.h"
#include "general.h"
#include "Streamable.h"


using namespace std;
namespace sict
{
	Product::Product()
	{
		sku_[0] = '\0';
		name_ = nullptr;
		price_ = 0;
		quantity_ = 0;
		qtyNeeded_ = 0;
	}
	Product::Product(const char* sku, const char* name, bool tax, double price, int quantity)
	{
		strncpy(sku_, sku, MAX_SKU_LEN);
		int length = strlen(name);
		name_ = new char[length + 1];
		strcpy(name_, name);
		quantity_ = 0;
		price_ = price;
		qtyNeeded_ = quantity;
		taxed_ = tax;
	}
	void Product::m_copyConstructor(const Product& item)
	{
		strncpy(sku_, item.sku_, MAX_SKU_LEN);
		int length = strlen(item.name_);
		name_ = new char[length + 1];
		strncpy(name_, item.name_, length + 1);
		price_ = item.price_;
		taxed_ = item.taxed_;
		quantity_ = item.quantity_;
		qtyNeeded_ = item.qtyNeeded_;
	}
	Product::Product(const Product& item)
	{
		m_copyConstructor(item);
	}
	Product::~Product()
	{
		delete[] name_;
	}
	Product& Product::operator=(const Product& item)
	{
		if (this != &item && !item.isEmpty())
		{
			m_copyConstructor(item);
		}
		return *this;
	}
	void Product::sku(const char* s)
	{
		strncpy(sku_, s, MAX_SKU_LEN);
	}
	void Product::price(const double p)
	{
		price_ = p;
	}
	void Product::name(const char* name)
	{
		int length = strlen(name);
		delete[] name_;
		name_ = new char[length + 1];
		strcpy(name_, name);
	}
	void Product::taxed(int t)
	{
		taxed_ = t;
	}
	void Product::quantity(const int q)
	{
		quantity_ = q;
	}
	void Product::qtyNeeded(const int qn)
	{
		qtyNeeded_ = qn;
	}
	const char* Product::sku() const
	{
		return (const char*)sku_;
	}
	double Product::price() const
	{
		return price_;
	}
	char* Product::name() const
	{
		return (char*)name_;
	}
	bool Product::taxed() const
	{
		return taxed_;
	}
	int Product::quantity() const
	{
		return quantity_;
	}
	int Product::qtyNeeded() const
	{
		return qtyNeeded_;
	}
	double Product::cost() const
	{
		if (taxed_)
		{
			return price_ + (price_ * TAX);
		}
		else
		{
			return price_;
		}
	}
	bool Product::isEmpty() const
	{
		if (sku_[0] == '\0' && name_ == nullptr && price_ == 0 && quantity_ == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Product::operator==(const char* sku)
	{
		if (strcmp(sku_, sku) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int Product::operator+=(const int quantity)
	{
		return quantity_ += quantity;
	}
	int Product::operator-=(const int quantity)
	{
		 quantity_ -= quantity;
		 return quantity_;
	}
	double operator+=(double& d, const Product& I)
	{
		 d += I.quantity() * I.cost();
		return d;
	}
	std::ostream& operator<<(std::ostream& ostr, const Product& p)
	{
		p.write(ostr, 1);
		return ostr;
	}
	std::istream& operator >> (std::istream& istr, Product& m)
	{
		m.read(istr);
		return istr;
	}
}