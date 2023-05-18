#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MenuItem {
public:
    string name;
    string type;
    double price;


    MenuItem(string name, string type, double price) {
        this->name = name;
        this->type = type;
        this->price = price;
    }
};

class CoffeeShop {
private:
    string name;
    vector<MenuItem> menu;
    vector<string> orders;


public:
    CoffeeShop(string name, vector<MenuItem> menu) {
        this->name = name;
        this->menu = menu;
    }

    string addOrder(string itemName) {
        bool found = false;
        for (MenuItem item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                found = true;
                return "Order added successfully.";
            }
        }
        if (!found) {
            return "This item is currently unavailable.";
        }
    }

    string fulfillOrder() {
        if (orders.size() > 0) {
            orders.erase(orders.begin());
            return "The order is ready.";
        }
        else {
            return "All orders have been fulfilled.";
        }
    }

    vector<string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0.0;
        for (string order : orders) {
            for (MenuItem item : menu) {
                if (item.name == order) {
                    total += item.price;
                }
            }
        }
        return total;
    }

    MenuItem cheapestItem() {
        MenuItem cheapest = menu[0];
        for (MenuItem item : menu) {
            if (item.price < cheapest.price) {
                cheapest = item;
            }
        }
        return cheapest;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (MenuItem item : menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> food;
        for (MenuItem item : menu) {
            if (item.type == "food") {
                food.push_back(item.name);
            }
        }
        return food;
    }
};

int main() {
    vector<MenuItem> menu = { MenuItem("iced Coffee", "drink", 2.5), MenuItem("lemonde", "drink", 2.0), MenuItem("cinnamon roll", "food", 3.0), MenuItem("Muffin", "food", 2.5), MenuItem("orange jucie","drink",3.0), MenuItem("tuna sandwitch", "food" , 3.0) };
    CoffeeShop shop("My Coffee Shop", menu);
    cout << shop.addOrder("Hot Cocoa") << endl;
    cout << shop.addOrder("Iced tea") << endl;
    cout << shop.addOrder("cinnamon roll") << endl;
    cout << shop.addOrder("iced Coffee") << endl;
    vector<string>  listOrders = shop.listOrders();
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << "Due Amount: $" << shop.dueAmount() << endl;
    MenuItem cheapest = shop.cheapestItem();
    cout << "Cheapest Item: " << cheapest.name << " ($" << cheapest.price << ")" << endl;
    cout << "-----------------" << endl;
    vector<string> drinks = shop.drinksOnly();
    cout << "Drinks Only:" << endl;
    for (string item : drinks) {
        cout << item << endl;
    }
    cout << "-----------------" << endl;
    vector<string> food = shop.foodOnly();
    cout << "Food Only:" << endl;
    for (string item : food) {
        cout << item << endl;
    }
    return 0;
}