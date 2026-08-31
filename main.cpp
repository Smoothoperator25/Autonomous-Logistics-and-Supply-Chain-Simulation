#include <iostream>
#include <vector>
using namespace std;

class Supplier
{
    int SupplierID;
    string SupplierName;
    vector<Product> products;

public:
    Supplier(){
        SupplierID = 0;
        SupplierName = "";
    }

    Supplier(){
        
    }
    void supplyProduct();
    void updateDetails();
};

void Supplier ::supplyProduct()
{

}

int main()
{
    system("cls");

    return 0;
}