#include<iostream>
#include<string>

using namespace std;

class Car  {
    protected:
        //Characters
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;

    public:
        Car(string b ,string m){
            this -> brand = b;
            this -> model = m;
            this -> isEngineOn = false;
            this -> currentSpeed = 0;

        }

        int getCurrentSpeed(){
            return this -> currentSpeed;
        }


        //Behaviour or methods
        void startEngine(){
            isEngineOn = true;
            cout<<brand <<" " << model <<" : Engine starts with roar!"<<endl;
        }
        
          void stopEngine(){
            isEngineOn = false;
            currentSpeed = 0;
            cout<<brand <<" " << model <<" : Engine turned off"<<endl;
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
        virtual ~Car(){}
      
};

class ManualCar : public Car{
    private:
        int currentGear;
    
    public:
        ManualCar(string b , string m ) : Car(b , m){
            currentGear = 0;
        }

        void shiftGear(int gear){
            currentGear = gear;
            cout << brand << " " << model << " : shifted to gear " << currentGear << endl;
        }
};

class ElectricCar : public Car{
    private:
        int batteryPercentage;

    public:
        ElectricCar(string b , string m) : Car(b , m){
            batteryPercentage = 10;
        }

        int getBatteryPercentage() {
         return batteryPercentage;
        }

        void chargeBattery(){
            batteryPercentage = 100;
            cout << brand << " " << model << " : Fully Charged "  << endl;

        }


};

int main(){
    
    ManualCar * myCar = new ManualCar("Audi","Q6");

    myCar ->startEngine();
    myCar ->accelerate();
    myCar ->shiftGear(1);
    myCar ->brake();
    myCar ->stopEngine();
    cout << myCar->getCurrentSpeed()<<endl;
    delete myCar;



    ElectricCar * myCar2 = new ElectricCar("BYD" , "Q1");
    myCar2 -> chargeBattery();
    myCar2 ->startEngine();
    myCar2 ->accelerate();
    myCar2 ->accelerate();
    myCar2 ->brake();
    myCar2 ->stopEngine();
    // cout << myCar2 -> batteryPercentage <<endl;








    return 0;

}