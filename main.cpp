#include <iostream>
#include <vector>
#include<string>
using namespace std;


class Product;
class Supplier
{
    int SupplierID;
    string SupplierName;
    vector<Product> products;

public:
    Supplier()
    {
        SupplierID = 0;
        SupplierName = "";
    }

    Supplier(int id, string name)
    {
        SupplierID = id;
        SupplierName = name;
    }

    void supplyProduct(Product product);
    void updateDetails(string name){
        SupplierName = name;
    };

    int getSupplierID(){
        return SupplierID;
    }

    string getSupplierName()
    {
        return SupplierName;
    }

    vector<Product>
};

void Supplier ::supplyProduct(Product product)
{README.md
    string proName;

    cout << "Enter the product name : ";
    getline(cin, proName);

    products.push_back(proName);

    cout << "Successfull\n\n";
}

int main()
{
    system("cls");

    return 0;
}