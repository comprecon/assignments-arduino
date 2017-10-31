//Roger Kim: "Shut Up"
//turn off an LED by making the loudest noise since the beginning of the program
//The LED grows less sensitive after each new loudest noise


int mic = A0; //microphone plugged in via 1/4" jack, one lead to ground and one lead to analog pin
int led = 11;
int brightness[5];
int brightnessAve;
int amplitude = 0;
int maxAmp = 5;
int i;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  i = 0;
}

void loop() {
  // amplitude - volume detected from the microphone
  amplitude = analogRead(mic);

  //auto calibrate, every new peak in amplitude is the new maximum amplitude possible
  if (maxAmp < amplitude) {
    maxAmp = amplitude;
    analogWrite(led, 0);
    Serial.print("new high:  ");
    Serial.println(maxAmp);
    delay(1000);
  }

//trying to smooth the data a bit by ignoring the amplitude when it is 0. the amplitude came in really unevenly though, and this didn't help much
  if (amplitude !=0) {
    if (i==5) i = 0; 
    brightness[i] = map(amplitude, 0, maxAmp, 255, 0);
    
      Serial.print(brightness[i]);
      Serial.print("       ");
    
    i++;
  }

  //even more data smoothing... 
  brightnessAve = 0;
  for (int j = 0; j < 5; j++) {
    brightnessAve = brightnessAve + brightness[j];
  }
  brightnessAve = brightnessAve / 5;
  Serial.print(brightnessAve);
    Serial.print("       ");
  analogWrite(led, brightnessAve);
  Serial.println(amplitude);
}

