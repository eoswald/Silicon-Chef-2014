#define TOP_LEFT 2
#define TOP_RIGHT 3
#define BOTTOM_LEFT 4
#define BOTTOM_RIGHT 5
#define PWM_PIN 6

#define NUM_BLOCKS 10
#define SPEED 100

#define BRICK_VAL 172
#define WOOD_VAL 280
#define ALUMINUM_VAL 200
#define STEEL_VAL 70

#define LIGHT_POWER 8
#define LIGHT_SENSOR A1
#define SAMPLES 50

int block_count = 10;
int blocks[10];
int nextBlockVal;

void setup() {
	pinMode(TOP_LEFT, OUTPUT);
	pinMode(TOP_RIGHT, OUTPUT);
	pinMode(BOTTOM_LEFT, OUTPUT);
	pinMode(BOTTOM_RIGHT, OUTPUT);
	pinMode(PWM_PIN, OUTPUT);
        pinMode(LIGHT_POWER, OUTPUT);
        Serial.begin(115200);
}

void loop() {
	/*while (block_count < NUM_BLOCKS) {
		forward(SPEED);
		while (not isBlock());
		block_count++;
		blocks[block_count] = blockVal();
	}
	calcNextBlock();*/
  forward(140);
//    delay(100);
//  brake();
//    delay(100);
    
//  Serial.println
int  v= blockVal();
while(v > 1023) { v = blockVal(); }
  //Serial.println(v);
  if ((v >= BRICK_VAL && v <= BRICK_VAL + 5) || v >= WOOD_VAL){
    
    Serial.println("DIGDIGDIGIDGG\n\n\n\n\n\n\n");
    brake();
    delay(1000);
    forward(140);
    //v=blockVal();
    while(v > 165){ v = blockVal(); }
         
  }
  //else if (v == 0) { brake(); while(1) {} }
  
  

}

// returns true if we are on top of a block
bool isBlock(int v) {
  return (v > BRICK_VAL);
}

// reads the optical measurement of block
int blockVal() {
	long temp = 0;
	unsigned int hi;
	for (unsigned int i = 0; i < SAMPLES; i++)
	{
		digitalWrite(LIGHT_POWER, HIGH);
		delay(1);
		hi = analogRead(LIGHT_SENSOR);
                //Serial.println(hi);
		digitalWrite(LIGHT_POWER, LOW);
		delay(1);
		temp += analogRead(LIGHT_SENSOR) - hi;
	}
	temp /= SAMPLES;
	return (int) temp;
}

void forward(int speed) {
	digitalWrite(TOP_LEFT, LOW);
	digitalWrite(TOP_RIGHT, HIGH);
	digitalWrite(BOTTOM_LEFT, LOW);
	digitalWrite(BOTTOM_RIGHT, HIGH);
	analogWrite(PWM_PIN, speed);
}

void reverse(int speed) {
	digitalWrite(TOP_LEFT, HIGH);
	digitalWrite(TOP_RIGHT, LOW);
	digitalWrite(BOTTOM_LEFT, HIGH);
	digitalWrite(BOTTOM_RIGHT, LOW);
	analogWrite(PWM_PIN, speed);
}

void brake() {
	digitalWrite(TOP_LEFT, LOW);
	digitalWrite(TOP_RIGHT, LOW);
	digitalWrite(BOTTOM_LEFT, HIGH);
	digitalWrite(BOTTOM_RIGHT, HIGH);
}
