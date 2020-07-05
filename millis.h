/*
	Author: J. Zugna
	Date: 04/07/2019 [4 July 2019] 

	Version: v2.0

	Last update: 5/07/2020 8.05pm
*/

#ifndef millis_h
#define millis_h

class Millis {
	public:
	Millis(uint32_t t_delay = 500);
	~Millis(){};
	inline void setDelay(uint32_t t_delay); //change the delay value
	inline void setActive(bool start); //active, or not active, set to your function 
	inline bool isActive(void) const; //is active or not ? 
	inline uint32_t getDelay(void) const;
	void toCall(void (*func)(void)); //call your function	

	private:
	uint32_t interval; //dafault 500 ms
	uint32_t previousMillis;
	bool m_isActive; //default TRUE	
};


Millis::Millis(uint32_t t_delay) {
	this->interval = t_delay;
	this->m_isActive= true;
	this->previousMillis = 0;
}

void Millis::setDelay(uint32_t t_delay) {
	this->interval = t_delay;
}

void Millis::setActive(bool active) {
	this->m_isActive = active;
}

bool Millis::isActive(void) const {
	return this->m_isActive;
}

uint32_t Millis::getDelay(void) const {
	return this->interval;
}

void Millis::toCall(void (*func)(void)) {
	if(this->m_isActive) {
		uint32_t currentMillis = millis();
		if((currentMillis - this->previousMillis) >= this->interval) {
            this->previousMillis = currentMillis;
            func();	
		}
	}
}
#endif
