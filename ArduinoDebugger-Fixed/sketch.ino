class Pinn{
	int pinnum;
	int delay;
	int state;
	
	public:
		void led();
		void setDelay(int delay);
		int getPinnum();
		int getDelay();
		
		Pinn();
		Pinn(int pinnum);
};
void Pinn::led(){
	digitalWrite(pinnum,state);
	state = !state;
}
Pinn::Pinn(){
	pinnum=13;
	delay=1000;
	state=0;
}
Pinn::Pinn(int pinnum){
	this->pinnum = pinnum;
	delay=1000;
	state=0;
}
int Pinn::getPinnum(){
	return pinnum;
}
void Pinn::setDelay(int delay){
	this->delay = delay;
}
int Pinn::getDelay(){
	return delay;
}

Pinn pinn(13);

void setup()
{
  pinMode (pinn.getPinnum(),OUTPUT);
  pinn.setDelay(1500);
}

unsigned long timeout = 0;

void loop()
{
  if (millis() > timeout)
  {
  	timeout = millis() + pinn.getDelay();
  	pinn.led();
  }
}
