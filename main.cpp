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
    int GetQuantaty()
    {
        return Quantaty;
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

class Warehouse
{
    int WarehouseID;
    string WarehouseLocation;
    int Capacity;
    int used;
    vector<Product> products;

public:
    Warehouse()
    {
        WarehouseID = 0;
        WarehouseLocation = "";
        Capacity = 0;
        used = 0;
    }

    Warehouse(int wareID, string Location, int cap)
    {
        WarehouseID = wareID;
        WarehouseLocation = Location;
        Capacity = cap;
        used = 0;
    }
    void reciveProduct(Product product);
    void storeProduct(Product protect);
    int GetUsedSpace()
    {
        return used;
    }
    void dispachedProduct(int proID, int quan);
    void displayWarehouse();
};

void Warehouse ::reciveProduct(Product product)
{
    if ((used + product.GetQuantaty()) > Capacity)
    {
        cout << "Greater than Warehouse capicity\n";
        return;
    }
    cout << "\nProduct recived at Warehouse\n";
    storeProduct(product);
}

void Warehouse ::storeProduct(Product product)
{
    products.push_back(product);

    used += product.GetQuantaty();

    cout << "\nProduct stored in Warehouse successfully\n\n";
}

void Warehouse ::dispachedProduct(int proID, int quan)
{
    for (int i = 0; i < products.size(); i++)
    {
        if (products[i].GetProductID() == proID)
        {
            if (quan > products[i].GetQuantaty())
            {
                cout << "\nEnough quantaty is not available\n";
                return;
            }

            cout << "\nProduct Dispached Successfully\n";
            cout << "Product ID : " << proID << endl;
            cout << "Quantity   : " << quan << endl;

            used -= quan; // This is to reduce the space of warehouse
            return;
        }
    }

    cout << "\nProduct Not Found In The Warehouse!!\n";
}

void Warehouse ::displayWarehouse()
{
    cout << "\n======== Warehouse Info =========\n";

    cout << "Warehouse ID    : " << WarehouseID << endl;
    cout << "Location        : " << WarehouseLocation << endl;
    cout << "Capicity(Space) : " << Capacity << endl;
    cout << "Used Space      : " << used << endl;
    cout << "Available Space : " << Capacity - used << endl;

    cout << "\nStored Products\n";

    if (products.empty())
    {
        cout << "No products available" << endl;
        return;
    }

    for (int i = 0; i < products.size(); i++)
    {
        if (products[i].GetUsedSpace != 0)
        {
            products[i].DisplayProduct();
            cout << endl;
        }
    }
}

vector<Warehouse> createWarehouses() // For creating warehouse
{
    vector<Warehouse> AllWarehouses;
    AllWarehouses.push_back(Warehouse(10, "Pune", 30));
    AllWarehouses.push_back(Warehouse(11, "Mumbai", 40));
    AllWarehouses.push_back(Warehouse(12, "Delhi", 20));

    cout << "All the warehouses are LIVE\n\n";
    return AllWarehouses;
}

int main()
{
    system("cls");
    vector<Warehouse> AllWarehouses = createWarehouses(); // We had already created warehouses

    Supplier s1(1, "Kartik Bhand");

    Product p1(1000, 4, 4000, "Pan");
    Product p2(1001, 10, 2000, "Shirt");

    s1.supplyProduct(p1);
    s1.supplyProduct(p2);

    cout << "supplier : " << s1.getSupplierName() << endl;

    s1.displaySupplier();
    cout << endl;

    AllWarehouses[0].reciveProduct(p1);
    AllWarehouses[1].reciveProduct(p2);

    AllWarehouses[1].displayWarehouse();

    AllWarehouses[1].dispachedProduct(1001, 10);

    AllWarehouses[1].displayWarehouse();

    return 0;
}