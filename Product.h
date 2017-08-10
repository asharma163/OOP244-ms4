#ifndef SICT_PRODUCT_H_
#define SICT_PRODUCT_H_
#include "general.h"
#include"Streamable.h"
namespace sict {
	class Product:public Streamable {
	private:
		char sku_[MAX_SKU_LEN + 1];
		char* name_;
		double price_;
		bool  taxed_;
		int quantity_;
		int qtyNeeded_;

	public:
		Product();
		Product(const char*, const char*, bool tax = true, double = 0.0, int = 0);
		Product(const Product& Product);
		void m_copyConstructor(const Product&);
		Product& operator=(const Product& Product);
		virtual ~Product();
		void sku(const char* s);
		void price(double p);
		void name(const char* n);
		void taxed(int t);
		void quantity(int q);
		void qtyNeeded(int qn);
		const char* sku() const;
		double price() const;
		char* name() const;
		bool taxed() const;
		int quantity() const;
		int qtyNeeded() const;
		double cost() const;
		bool isEmpty() const;
		bool operator==(const char*);
		int operator+=(int);
		int operator-=(int);
	};
	double operator+=(double&, const Product&);
	std::ostream& operator<<(std::ostream& ostr, const Product& Product);
	std::istream& operator>> (std::istream& istr, Product& Product);

}
#endif


