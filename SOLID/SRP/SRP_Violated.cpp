#include <iostream>
#include <vector>
using namespace std;

class Product{

public:
    string name;
    double price;

    Product(string name , double price){
        this -> name = name;
        this -> price = price;
    }
};

//SRP Violated

class ShoppingCart{
    
    private:
        vector<Product*> products;

    public:
        void addProduct(Product* p){
            products.push_back(p);
        }

        const vector<Product*>& getProducts(){
            return products;
        }

        double calculateTotal(){
            double total = 0;
            for(auto p : products){
                total = total + p -> price;
            }
            return total;
        }

        void printInvoice(){
            cout<< "Shopping Cart Invoice:\n";
            for(auto p : products){
                cout << p -> name << " -  $" << p -> price << endl;
            }
            cout << "Total: $" << calculateTotal()<< endl;
        }

        void saveToDatabase(){
            cout << "Saving to Database"<<endl;
        }
};

int main(){

    ShoppingCart * cart = new ShoppingCart();

    cart -> addProduct(new Product("Laptop", 1500));
    cart -> addProduct(new Product("Iphone",1000));

    cart -> printInvoice();
    cart -> saveToDatabase();

    return 0;
}