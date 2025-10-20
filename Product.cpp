#include <string>
#include "Product.h"
using namespace std;

Product::Product(string t_name) {
	productName = t_name;
	productQuantity = 1; // all new products are unique, they can only have an initial quantity of 1
};
	
string Product::getProductName() const {
	return productName;
}

int Product::getProductQuantity() const {
	return productQuantity;
}

void Product::increaseQuantity() {
	productQuantity++;
}



