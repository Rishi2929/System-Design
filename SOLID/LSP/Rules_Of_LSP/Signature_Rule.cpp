#include <iostream>
using namespace std;

class Parent{
    public:
        virtual void print (string msg){
            cout << " Parent: " <<msg<<endl;
    }
};

class Child : public Parent{
    public:
        void print(string msg) override{
            cout<<"Child: "<<msg<<endl;
        }
};

class Client{
    private:
        Parent*p;

    public:
        Client(Parent*p){
            this -> p = p;
        }
        void printMsg(){
            p -> print("hello");
        }
};

int main(){
    Parent* parent = new Parent();
    Child* child = new Child();

    Client* client = new Client(child);

    client ->printMsg();

}