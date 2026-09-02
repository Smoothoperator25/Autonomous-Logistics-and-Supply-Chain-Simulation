#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product
{
    int ProductID;
    int Quantaty;
    float Price;
    string ProductName;

public:
    Product()
    {
        ProductID = 0;
        Quantaty = 0;
        Price = 0.0;
        ProductName = "";
    }

    Product(int id, int q, float pri, string ProName)
    {
        ProductID = id;
        Quantaty = q;
        Price = pri;
        ProductName = ProName;
    }

    int GetProductID()
    {
        return ProductID;
    }

    string GetProductName()
    {
        return ProductName;
    }

    void DisplayProduct();
};

void Product ::DisplayProduct()
{
    cout << "Product ID   : " << ProductID << endl;
    cout << "Product Name : " << ProductName << endl;
    cout << "Price        : " << Price << "\n";
    cout << "Quantaty     : " << Quantaty << endl;
}

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
    void updateDetails(string name)
    {
        SupplierName = name;
    };

    int getSupplierID()
    {
        return SupplierID;
    }

    string getSupplierName()
    {
        return SupplierName;
    }

    void displaySupplier();
};

void Supplier ::supplyProduct(Product product)
{
    products.push_back(product);

    cout << "Successfull\n\n";
}

void Supplier ::displaySupplier()
{
    cout << "\nAll the products supply by " << getSupplierName() << " : \n";

    if (products.empty())
    {
        cout << "\nNo Product available \n";
        return;
    }

    for (int i = 0; i < products.size(); i++)
    {
        products[i].DisplayProduct();
        cout << endl;
    }

}

int main()
{
    system("cls");

    Supplier s1(1, "Kartik Bhand");

    Product p1(1000, 4, 4000, "Pan");
    Product p2(1001, 10, 2000, "Shirt");


    s1.supplyProduct(p1);
    s1.supplyProduct(p2);

    cout << "supplier : " << s1.getSupplierName() << endl;

    s1.displaySupplier();
    cout << endl;
    return 0;
}