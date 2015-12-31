//Golden Ration LED FLicker
//using the golden ratio in the flicker timing of an LED candle in hopes that it is extra beautiful

int flickerdepth = 6;
float repeatDelay = 100;
float flickerPattern[] = {10,5,12,20,11,8};
int flickerposition = 0; //position in flicker array
float highVal = 255;
float lowVal = 20;
float brightness = 0;    // how bright the LED is
float resilience = 1;    // how fast the candle regens its brighness

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(1, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  createWind();
  burnCandle();
  delay(repeatDelay);
}


void burnCandle() {
  if(brightness < highVal) {
    brightness = brightness + resilience;
  }
  analogWrite(1, brightness);
}

void createWind() {
  flickerposition++;
  if (flickerposition >= flickerdepth){
    flickerposition = 0;
    calucateFlickerPattern();
  }
  
  if(brightness > highVal/resilience){
    brightness = brightness - flickerPattern[flickerposition];
  }
}

void calucateFlickerPattern() {
  int seedval = random(1,5);
  int newPattern[flickerdepth];
  for(int j=0; j<flickerdepth; j++){
    //PHI = 1.6180339887498948482
    if (j <= 0){
      newPattern[j] = seedval;
    }else{
      newPattern[j] = newPattern[(j - 1)]*1.6180339887498948482;
    }
    flickerPattern[j] = newPattern[j];
  }
}
