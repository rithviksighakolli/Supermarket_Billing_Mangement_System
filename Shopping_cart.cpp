#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <omp.h> // Include OpenMP header

int total_bill = 0;

class Shop {
public:
    Shop(const std::string& name) : name(name) {}
    virtual ~Shop() {}

    double calculatePrice(int price) {}

    std::string getName() const {
        return name;
    }

protected:
    std::string name;
    void print_bill(){
        std::cout<<name;
        std::cout << "Total Bill: $" << total_bill << std::endl;
    }
};

class Groceries : public Shop {
public:
    Groceries(const std::string& name) : Shop(name) {}
};

class Fashion : public Shop {
public:
    Fashion(const std::string& name) : Shop(name) {}
};

class Electronics : public Shop {
public:
    Electronics(const std::string& name) : Shop(name) {}
};

class Staples : public Groceries {
public:
    Staples(const std::string& name) : Groceries(name) {}
    double calculatePrice(int price){
        total_bill+=price;
    }
};

class SnacksAndBeverages : public Groceries {
public:
    SnacksAndBeverages(const std::string& name) : Groceries(name) {}
    double calculatePrice(int price){
        total_bill+=price;
    }
};

class Household : public Groceries {
public:
    Household(const std::string& name) : Groceries(name) {}
    double calculatePrice(int price){
        total_bill+=price;
    }
    void print_bill(){
        std::cout << "Total Bill: $" << total_bill << std::endl;
    }
};

class Menclothing : public Fashion {
public:
    Menclothing(const std::string& name) : Fashion(name) {}
    double calculatePrice(int price){
        total_bill+=price;
    }
};

class Womenclothing : public Fashion {
public:
    Womenclothing(const std::string& name) : Fashion(name) {}
    double calculatePrice(int price){
        total_bill+=price;
    }
};

class TravelAndAccessories : public Fashion {
public:
    TravelAndAccessories(const std::string& name) : Fashion(name) {}
    double calculatePrice(int price){
        total_bill+=price;
    }
};

class MobilesAndAccessories : public Electronics {
public:
    MobilesAndAccessories(const std::string& name) : Electronics(name) {}
    double calculatePrice(int price){
        total_bill+=price;
    }
};

class LaptopsAndAccessories : public Electronics {
public:
    LaptopsAndAccessories(const std::string& name) : Electronics(name) {}
    double calculatePrice(int price){
        total_bill+=price;
    }
};

class HomeAppliances : public Electronics {
public:
    HomeAppliances(const std::string& name) : Electronics(name) {}
    double calculatePrice(int price){
        total_bill+=price;
    }
};


int main() {
    int choice;
    std::vector<Shop*> shops;
    std::map<int, std::string> menu;

    menu[1] = "Groceries";
    menu[2] = "Fashion";
    menu[3] = "Electronics";
    menu[4] = "Exit";

    std::vector<std::pair<std::string, double>> cart; // Store purchased items

    while (true) {
        std::cout << "Menu:" << std::endl;
        for (const auto& item : menu) {
            std::cout << item.first << ". " << item.second << std::endl;
        }

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 4) {
            // Exit
            break;
        }

        if (menu.find(choice) == menu.end()) {
            std::cout << "Invalid choice. Please try again." << std::endl;
            continue;
        }

        // Handle different shop types based on the user's choice
        switch (choice) {
            case 1: {
                // Groceries
                int subChoice;
                std::map<int, std::string> groceryMenu;

                groceryMenu[1] = "Staples";
                groceryMenu[2] = "SnacksAndBeverages";
                groceryMenu[3] = "Household";
                groceryMenu[4] = "Back";

                while (true) {
                    std::cout << "Groceries Menu:" << std::endl;
                    for (const auto& item : groceryMenu) {
                        std::cout << item.first << ". " << item.second << std::endl;
                    }
                    std::cout << "Enter your choice: ";
                    std::cin >> subChoice;

                    if (subChoice == 4) {
                        // Back
                        break;
                    }

                    if (groceryMenu.find(subChoice) == groceryMenu.end()) {
                        std::cout << "Invalid choice. Please try again." << std::endl;
                        continue;
                    }

                    if (subChoice >= 1 && subChoice <= 3) {
                        std::string itemName;
                        double itemPrice;
                        std::cout << "Enter the name of the item: ";
                        std::cin >> itemName;
                        std::cout << "Enter the price of the item: ";
                        std::cin >> itemPrice;

                        // Create a dynamic object of the selected class
                        Shop* newItem = nullptr;
                        if (subChoice == 1) {
                            newItem = new Staples(itemName);
                            newItem->calculatePrice(itemPrice);
                        } else if (subChoice == 2) {
                            newItem = new SnacksAndBeverages(itemName);
                            newItem->calculatePrice(itemPrice);
                        } else if (subChoice == 3) {
                            newItem = new Household(itemName);
                            newItem->calculatePrice(itemPrice);
                        }

                        // Add the item to the cart
                        cart.push_back(std::make_pair(itemName, itemPrice));

                        std::cout << "Item added to the cart." << std::endl;
                    }
                }
                break;
            }
            case 2: {
                // Fashion
                int subChoice;
                std::map<int, std::string> fashionMenu;

                fashionMenu[1] = "Men's Clothing";
                fashionMenu[2] = "Women's Clothing";
                fashionMenu[3] = "Travel and Accessories";
                fashionMenu[4] = "Back";

                while (true) {
                    std::cout << "Fashion Menu:" << std::endl;
                    for (const auto& item : fashionMenu) {
                        std::cout << item.first << ". " << item.second << std::endl;
                    }   
                    std::cout << "Enter your choice: ";
                    std::cin >> subChoice;

                    if (subChoice == 4) {
                        // Back
                        break;
                    }

                    if (fashionMenu.find(subChoice) == fashionMenu.end()) {
                        std::cout << "Invalid choice. Please try again." << std::endl;
                        continue;
                    }

                    if (subChoice >= 1 && subChoice <= 3) {
                        std::string itemName;
                        double itemPrice;
                        std::cout << "Enter the name of the item: ";
                        std::cin >> itemName;
                        std::cout << "Enter the price of the item: ";
                        std::cin >> itemPrice;

                        // Create a dynamic object of the selected class
                        Shop* newItem = nullptr;
                        if (subChoice == 1) {
                            newItem = new Menclothing(itemName);
                            newItem->calculatePrice(itemPrice);
                        } else if (subChoice == 2) {
                            newItem = new Womenclothing(itemName);
                            newItem->calculatePrice(itemPrice);
                        } else if (subChoice == 3) {
                            newItem = new TravelAndAccessories(itemName);
                            newItem->calculatePrice(itemPrice);
                        }

                        // Add the item to the cart
                        cart.push_back(std::make_pair(itemName, itemPrice));

                        std::cout << "Item added to the cart." << std::endl;
                    }
                }
                break;
            }

            case 3: {
                // Electronics
                int subChoice;
                std::map<int, std::string> electronicsMenu;

                electronicsMenu[1] = "Mobiles and Accessories";
                electronicsMenu[2] = "Laptops and Accessories";
                electronicsMenu[3] = "Home Appliances";
                electronicsMenu[4] = "Back";

                while (true) {
                    std::cout << "Electronics Menu:" << std::endl;
                    for (const auto& item : electronicsMenu) {
                        std::cout << item.first << ". " << item.second << std::endl;
                    }
                    std::cout << "Enter your choice: ";
                    std::cin >> subChoice;

                    if (subChoice == 4) {
                        // Back
                        break;
                    }
                    if (electronicsMenu.find(subChoice) == electronicsMenu.end()) {
                        std::cout << "Invalid choice. Please try again." << std::endl;
                        continue;
                    }
                    if (subChoice >= 1 && subChoice <= 3) {
                        std::string itemName;
                        double itemPrice;
                        std::cout << "Enter the name of the item: ";
                        std::cin >> itemName;
                        std::cout << "Enter the price of the item: ";
                        std::cin >> itemPrice;

                        // Create a dynamic object of the selected class
                        Shop* newItem = nullptr;
                        if (subChoice == 1) {
                            newItem = new MobilesAndAccessories(itemName);
                            newItem->calculatePrice(itemPrice);
                        } else if (subChoice == 2) {
                            newItem = new LaptopsAndAccessories(itemName);
                            newItem->calculatePrice(itemPrice);
                        } else if (subChoice == 3) {
                            newItem = new HomeAppliances(itemName);
                            newItem->calculatePrice(itemPrice);
                        }

                        // Add the item to the cart
                        cart.push_back(std::make_pair(itemName, itemPrice));

                        std::cout << "Item added to the cart." << std::endl;
                    }
                }
                break;
            }
        }
    }

    // Calculate the total bill and display purchased items
    std::cout << "Items Purchased:" << std::endl;
    #pragma omp parallel for reduction(+:totalBill)
    for (int i = 0; i < cart.size(); ++i) {
        const auto& item = cart[i];
        #pragma omp critical
        {
            std::cout << item.first << " - Price: $" << item.second << std::endl;
            total_bill+=item.second;
        }
    }
    std::cout << "Total Bill: $" << total_bill << std::endl;
}