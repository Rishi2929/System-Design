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


        virtual void accelerate() = 0;
        virtual void accelerate(int speed) = 0;

        virtual void brake() = 0;
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

        //Overriding accelerate -> Dynamic Polymorphism
        void accelerate(){
            if(!isEngineOn){
                cout<<brand <<" " << model <<" : Engine is off! Can't accelerate."<<endl;
                return ;
            }
            currentSpeed += 20;
            cout<<brand <<" " << model <<" : Accelerating to "<< currentSpeed << " km/hr "<<endl;
        }

        //Overloading accelerate -> Static Polymorphism
         void accelerate(int speed){
            if(!isEngineOn){
                cout<<brand <<" " << model <<" : Engine is off! Can't accelerate."<<endl;
                return ;
            }
            currentSpeed += speed;
            cout<<brand <<" " << model <<" : Accelerating to "<< currentSpeed << " km/hr "<<endl;
        }

        //Overriding brake -> Dynamic Polymorphism
        void brake(){
            currentSpeed -= 20;
            if(currentSpeed < 0) currentSpeed = 0;
            cout<<brand <<" " << model <<" : Braking! Current Speed is now "<< currentSpeed << " km/hr "<<endl;
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

          //Overriding accelerate -> Dynamic Polymorphism
        void accelerate(){
            if(!isEngineOn){
                cout<<brand <<" " << model <<" : Engine is off! Can't accelerate."<<endl;
                return ;
            }
            if(batteryPercentage <= 0){
                cout<<brand <<" " << model <<" : Battery dead! Cannot Accelerate " << " km/hr "<<endl;
                return ;
            }

            batteryPercentage -= 10;
            currentSpeed += 15;
            cout<<brand <<" " << model <<" : Accelerating to "<< currentSpeed << " km/hr. Battery at "<<batteryPercentage<<endl;
        }

         void accelerate(int speed){
            if(!isEngineOn){
                cout<<brand <<" " << model <<" : Engine is off! Can't accelerate."<<endl;
                return ;
            }
            if(batteryPercentage <= 0){
                cout<<brand <<" " << model <<" : Battery dead! Cannot Accelerate " << " km/hr "<<endl;
                return ;
            }

            batteryPercentage -= 10;
            currentSpeed += speed;
            cout<<brand <<" " << model <<" : Accelerating to "<< currentSpeed << " km/hr. Battery at "<<batteryPercentage<<endl;
        }

        //Overriding brake -> Dynamic Polymorphism
        void brake(){
            currentSpeed -= 15;
            if(currentSpeed < 0) currentSpeed = 0;
            cout<<brand <<" " << model <<" : Regenerative Braking! Current Speed is now "<< currentSpeed << " km/hr. Battery at "<<batteryPercentage<<endl;
        }


};

int main(){
    
    ManualCar * myCar = new ManualCar("Audi","Q6");

    myCar ->startEngine();
    myCar ->accelerate();
    myCar ->shiftGear(1);
    myCar ->accelerate(40);

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


    return 0;

}