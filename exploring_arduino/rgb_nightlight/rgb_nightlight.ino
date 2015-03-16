const int BLED = 9;
const int GLED = 10;
const int RLED = 11;
const int BUTTON = 2;

boolean lastButton = LOW;
boolean currentButton = LOW;
int ledMode = 0;

void setup(){
 pinMode(BLED, OUTPUT);
 pinMode(GLED, OUTPUT);
 pinMode(RLED, OUTPUT);
 pinMode(BUTTON, INPUT);
}

boolean debounce(boolean last){
    boolean current = digitalRead(BUTTON);

    if(last != current){
        delay(5);
        current = digitalRead(BUTTON);
    }

    return current;
}

void setMode(int mode){
//TODO
}

void loop(){
    currentButton = debounce(lastButton);

    if(lastButton == LOW && currentButton == HIGH){
        ledMode++;
    }

    lastButton = currentButton;

    //if options have been cycled through reset counter
    if(ledMode == 8) ledMode = 0;

    setMode(ledMode);
}