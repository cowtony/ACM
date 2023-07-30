#include <iostream>
#include <vector>

using namespace std;

class Cart {
public:
    void add_item (const string name, const float cost) {
        shoppingCart.push_back(item{name, cost});
    }
    void print_receipt () {
        cout << "Here is your receipt!" << endl;
        cout << "Item\t\tCost" << endl;
        for (item i : shoppingCart) {
            cout << i.item_name << "\t\t" << i.item_cost << endl;
        }
    }
    void clear_cart () {
        shoppingCart.clear();
    }
    void remove_item (const string name) {
        int temp = 0;
        for (item i : shoppingCart) {
            if (name == i.item_name) {
                // It gave me an error when I did
                // shoppingCart.erase(i);
                // so I did this instead
                shoppingCart.erase(shoppingCart.begin() + temp);
            }
            temp++;
        }
    }
    
private:
    struct item {
        string item_name = "undefined";
        float item_cost = 999;
    };
    
    vector<item> shoppingCart;
};

int main()
{
    Cart myCart;
   
    string command;
    string item_of_interest;
    float item_of_interest_cost;
   
    cout << "Welcome to Christan's Shopping Cart!" << endl;
    cout << "What would you like to do today? "
            "Commands: \"add\" (add item), \"checkout\", \"clear\" (clear cart), "
            "\"remove\" (remove a specific item), \"end\" (stop shopping)." << endl;
    cin >> command;
   
    while (true) {
        if (command == "add") {
            cout << "What is the item called?" << endl;
            cin >> item_of_interest;
            cout << "What is the price of the item? Don't lie!" << endl;
            cin >> item_of_interest_cost;
            myCart.add_item(item_of_interest, item_of_interest_cost);
            command = "undefined";
        } else if (command == "checkout") {
            myCart.print_receipt();
            command = "undefined";
        } else if (command == "clear") {
            myCart.clear_cart();
            command = "undefined";
        } else if (command == "remove") {
            cout << "What is the item you want to remove called?" << endl;
            cin >> item_of_interest;
            myCart.remove_item(item_of_interest);
            command = "undefined";
        } else if (command == "stop") {
            return 0;
        }
        cout << "What would you like to do today?" << endl;
        cin >> command;
    }
}