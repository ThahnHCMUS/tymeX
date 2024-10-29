#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>

class Product
{
public:
    std::string name;
    double price;
    int quantity;

    Product(std::string name, double price, int quantity)
        : name(name), price(price), quantity(quantity) {}

    double getValue() const
    {
        return price * quantity;
    }
};

class ProductList
{
private:
    std::vector<Product> products;

public:
    void addProduct(const Product &product)
    {
        products.push_back(product);
    }

    double calculateTotalInventoryValue() const
    {
        double totalValue = 0.0;
        for (const auto &product : products)
        {
            totalValue += product.getValue();
        }
        return totalValue;
    }

    std::vector<std::string> findMostExpensiveProducts() const
    {
        std::vector<std::string> mostExpensiveProducts;

        if (products.empty())
        {
            mostExpensiveProducts.push_back("No products in inventory.");
            return mostExpensiveProducts;
        }

        double maxPrice = products[0].price;

        for (const auto &product : products)
        {
            if (product.price > maxPrice)
            {
                maxPrice = product.price;
                mostExpensiveProducts.clear(); // Clear the list if we find a new max price
                mostExpensiveProducts.push_back(product.name);
            }
            else if (product.price == maxPrice)
            {
                mostExpensiveProducts.push_back(product.name); // Add to the list if the price matches the max
            }
        }

        return mostExpensiveProducts;
    }

    bool isProductInStock(const std::string &productName) const
    {
        for (const auto &product : products)
        {
            if (product.name == productName)
            {
                return true;
            }
        }
        return false;
    }
    void sortProducts(const std::string sortBy, bool ascending)
    {
        if (sortBy == "price")
        {
            std::sort(products.begin(), products.end(), [ascending](const Product &a, const Product &b)
                      { return ascending ? a.price < b.price : a.price > b.price; });
        }
        else if (sortBy == "quantity")
        {
            std::sort(products.begin(), products.end(), [ascending](const Product &a, const Product &b)
                      { return ascending ? a.quantity < b.quantity : a.quantity > b.quantity; });
        }
    }
    void displayProducts() const
    {
        for (const auto &product : products)
        {
            std::cout << "Name: " << product.name << ", Price: $" << product.price
                      << ", Quantity: " << product.quantity << std::endl;
        }
    }
};

int main()
{
    ProductList inventory;
    // Adding products to the inventoryList inventory;
    inventory.addProduct(Product("Laptop", 999.99, 5));
    inventory.addProduct(Product("Smartphone", 499.99, 10));
    inventory.addProduct(Product("Tablet", 299.99, 0));
    inventory.addProduct(Product("Smartwatch", 199.99, 3));

    // Calculating total inventory value
    double totalValue = inventory.calculateTotalInventoryValue();
    // Displaying the total inventory value
    std::cout << std::setprecision(2);
    std::cout << std::fixed;
    std::cout << "Total Inventory Value: $" << totalValue << std::endl;
    //Displaying Most Expensive Product 
    std::vector<std::string> mostExpensiveProductNames = inventory.findMostExpensiveProducts();
    std::cout << "Most Expensive Product(s): ";
    for (const auto &name : mostExpensiveProductNames)
    {
        std::cout << name << " , ";
    }
    std::cout << std::endl;

    bool isHeadphonesInStock = inventory.isProductInStock("Headphones");
    std::cout << "Is 'Headphones' in stock? " << (isHeadphonesInStock ? "true" : "false") << std::endl;
    // Display unsorted list
    int sortOption, orderOption;
    bool ascending;
    std::string sortBy;

    // Displaying a simple menu to the user
    std::cout << "Choose a sorting option:" << std::endl;
    std::cout << "1. Sort by Price" << std::endl;
    std::cout << "2. Sort by Quantity" << std::endl;
    std::cout << "Enter option (1 or 2): ";
    std::cin >> sortOption;

    if (sortOption == 1)
    {
        sortBy = "price";
    }
    else if (sortOption == 2)
    {
        sortBy = "quantity";
    }
    else
    {
        std::cout << "Invalid option. Exiting program." << std::endl;
        return 1;
    }

    std::cout << "Choose order:" << std::endl;
    std::cout << "1. Ascending" << std::endl;
    std::cout << "2. Descending" << std::endl;
    std::cout << "Enter option (1 or 2): ";
    std::cin >> orderOption;

    if (orderOption == 1)
    {
        ascending = true;
    }
    else if (orderOption == 2)
    {
        ascending = false;
    }
    else
    {
        std::cout << "Invalid option. Exiting program." << std::endl;
        return 1;
    }

    // Sort products based on user input
    inventory.sortProducts(sortBy, ascending);

    // Display sorted products
    std::cout << "\nProducts Sorted by " << (sortBy == "price" ? "Price" : "Quantity")
              << (ascending ? " (Ascending):" : " (Descending):") << std::endl;
    inventory.displayProducts();

    return 0;
}
