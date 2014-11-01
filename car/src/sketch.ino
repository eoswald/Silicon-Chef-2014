#define TOP_LEFT 2
#define TOP_RIGHT 3
#define BOTTOM_LEFT 4
#define BOTTOM_RIGHT 5
#define PWM_PIN 6

#define NUM_BLOCKS 10
#define SPEED 100

#define BRICK_VAL
#define WOOD_VAL
#define ALUMINUM_VAL
#define STEEL_VAL

int block_count = 10;
int blocks[10];
int nextBlockVal;

void setup() {
	pinMode(TOP_LEFT, OUTPUT);
	pinMode(TOP_RIGHT, OUTPUT);
	pinMode(BOTTOM_LEFT, OUTPUT);
	pinMode(BOTTOM_RIGHT, OUTPUT);
	pinMode(PWM_PIN, OUTPUT);
}

void loop() {
	while (block_count < NUM_BLOCKS) {
		forward(SPEED);
		while (not isBlock());
		block_count++;
		blocks[block_count] = blockVal();
	}
	calcNextBlock();
}

void calcNextBlock(){
	for (int i = 0; i < 10; ++i)
		if (blocks[i] >= BRICK_VAL) {
			nextBlockVal = BRICK_VAL;
			return;
		}
	}
	for (int i = 0; i < 10; ++i)
		if (blocks[i] >= WOOD_VAL) {
			nextBlockVal = WOOD_VAL;
			return;
		}
	}
	for (int i = 0; i < 10; ++i)
		if (blocks[i] >= ALUMINUM_VAL) {
			nextBlockVal = ALUMINUM_VAL;
			return;
		}
	}
	for (int i = 0; i < 10; ++i)
		if (blocks[i] >= STEEL_VAL) {
			nextBlockVal = STEEL_VAL;
			return;
		}
	}
}

// returns true if we are on top of a block
bool isBlock() {
}

// reads the optical measurement of block
int blockVal() {
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
