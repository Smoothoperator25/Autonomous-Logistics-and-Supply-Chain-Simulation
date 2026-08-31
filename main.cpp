#include <iostream>
#include <vector>
using namespace std;

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

    void supplyProduct();
    void updateDetails();
};

void Supplier ::supplyProduct()
{
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