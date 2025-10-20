#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product {
public:
	Product(string t_name = "empty");

	string getProductName() const;
	int getProductQuantity() const;
	void increaseQuantity();

private:
	string productName;
	int productQuantity;
};

#endif
