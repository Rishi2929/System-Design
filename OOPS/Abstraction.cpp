#include<iostream>
#include<string>

using namespace std;

class Car{
    public:
        virtual void startEngine() = 0;
        virtual void shiftGear(int gear) = 0;
        virtual void accelerate() = 0;
        virtual void brake() = 0;
        virtual void stopEngine() = 0;
        virtual ~Car() {}
};

class SportsCar : public Car {
    public:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;

        SportsCar(string b ,string m){
            this -> brand = b;
            this -> model = m;
            this -> isEngineOn = false;
            this -> currentSpeed = 0;
            this -> currentGear = 0;
        }
        
        void startEngine(){
            isEngineOn = true;
            cout<<brand <<" " << model <<" : Engine starts with roar!"<<endl;
        }

        void shiftGear(int gear){
            if(!isEngineOn){
                cout<<brand <<" " << model <<" : Engine is off! Can't shift gear"<<endl;
                return;
            }
            currentGear = gear;
                cout<<brand <<" " << model <<" : shifted to gear"<< gear <<endl;
        }

        void accelerate(){
             if(!isEngineOn){
                cout<<brand <<" " << model <<" : Engine is off! Can't accelerate."<<endl;
                return;
            }
            currentSpeed += 20;
            cout<<brand <<" " << model <<" : Accelerating to "<< currentSpeed << " km/hr "<<endl;
        }

        void brake(){
            currentSpeed -= 20;
            if(currentSpeed < 0) currentSpeed = 0;
            cout<<brand <<" " << model <<" : Braking! Current Speed is now "<< currentSpeed << " km/hr "<<endl;
        }

        void stopEngine(){
            isEngineOn = false;
            currentGear = 0;
            currentSpeed = 0;
            cout<<brand <<" " << model <<" : Engine turned off"<<endl;

        }
};

int main(){
    Car * myCar = new SportsCar("Audi" , "Q6");
    
    myCar -> startEngine();
    myCar -> shiftGear(1);
    myCar -> accelerate();
    myCar -> brake();
    myCar -> stopEngine();

    delete myCar;

    return 0;

}