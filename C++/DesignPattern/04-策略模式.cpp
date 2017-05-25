#include<iostream>
using namespace std;

class FlyBehavior{
	public:
		virtual void fly(){}
		virtual ~FlyBehavior(){}
};
class SubSonicFly:public FlyBehavior{
	public :
		SubSonicFly(){
			cout<<"SubSonicFly...����>>"<<endl;
		}
		void fly(){
			cout<<"SubSonicFly....."<<endl;
		}
		~SubSonicFly(){
			cout<<"~SubSonicFly..."<<endl;
		}
};
class SuperSonicFly:public FlyBehavior{
	public :
		SuperSonicFly(){
			cout<<"SuperSonicFly...����>>"<<endl;
		}
		void fly(){
			cout<<"SuperSonicFly....."<<endl;
		}
		~SuperSonicFly(){
			cout<<"~SuperSonicFly..."<<endl;
		}
};


class TakeOffBehavior{
	public:
		virtual void takeoff(){}
		virtual ~TakeOffBehavior(){}
};
class VerticalTakeOff:public TakeOffBehavior{
	public :
		VerticalTakeOff(){
			cout<<"VerticalTakeOff...����>>"<<endl;
		}
		void takeoff(){
			cout<<"Vertival Take Off....."<<endl;
		}
		~VerticalTakeOff(){
			cout<<"~VerticalTakeOff..."<<endl;
		}
};
class LongDistanceOff:public TakeOffBehavior{
	public:
		LongDistanceOff(){
			cout<<"LongDistanceOff...����>>"<<endl;
		}
		void takeoff(){
			cout<<"LongDistanceOff....."<<endl;
		}
		~LongDistanceOff(){
			cout<<"~LongDistanceOff..."<<endl;
		}
};

class AirCraft{
	private:
		FlyBehavior *flybe;
		TakeOffBehavior *offbe;
	public:
		AirCraft(FlyBehavior *flybe,TakeOffBehavior *offbe){
			this->flybe=flybe;
			this->offbe=offbe;
			cout<<"AirCraft...����>>"<<endl;
		}
		void takeoff(){
			offbe->takeoff();
		}
		void fly(){
			flybe->fly();
		}
		~AirCraft(){
			delete offbe;
			delete flybe;

			cout<<"~AirCraft..."<<endl;
		}
};

class Helicpter:public AirCraft{
	public:
		Helicpter(FlyBehavior *flybe,TakeOffBehavior *offbe):AirCraft(flybe,offbe){
			cout<<"Helicpter...����>>"<<endl;
		}
};

class Airplan : public AirCraft{
	public:
		Airplan(FlyBehavior *flybe,TakeOffBehavior *offbe):AirCraft(flybe,offbe){
			cout<<"Airplan...����>>"<<endl;
		}
};


int main(void){

	AirCraft *air=new Helicpter(new SubSonicFly(), new LongDistanceOff());
	air->fly();
	air->takeoff();
	delete air;
	cout<<endl;

	AirCraft *plan=new Airplan(new SuperSonicFly(), new VerticalTakeOff()) ;
	plan->fly();
	plan->takeoff();
	delete plan;


	return 0;
}
