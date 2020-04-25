//Define array of RGB LED pins
int led[] = {D4, D3, D2};

//Define HIGH/LOW configurations for set colours
const bool RED[] = {HIGH, LOW, LOW};
const bool GREEN[] = {LOW, HIGH, LOW};
const bool BLUE[] = {LOW, LOW, HIGH};
const bool OFF[] = {LOW, LOW, LOW};

//Function prototypes
int remoteColour(String colour);
void setColour(const bool *colour);

void setup() {
    //Set all RGB pins to defined output pins
    for (int i = 0; i < 3; i++)
    {
        pinMode(led[i], OUTPUT);
    }
    
    //Define Particle.function() on the remoteColour() function to access function from cloud
    Particle.function("led", remoteColour);
    
    //Test all RGB LEDs
    setColour(RED);
    delay(1000);
    setColour(GREEN);
    delay(1000);
    setColour(BLUE);
    delay(1000);
    setColour(OFF);
}

void loop() {
    //This device only invoked via Particle.function()
}

//Takes String as parameter, if a valid input returns 1
//If invalid return 0
//This function can be invoked from the cloud
int remoteColour(String colour)
{
    if (colour == "red")
    {
        setColour(RED);
    }
    else if(colour == "green")
    {
        setColour(GREEN);
    }
    else if(colour == "blue")
    {
        setColour(BLUE);
    }
    else
    {
        return 0;
    }
    
    return 1;
}

//Uses the previously defined global arrays and sets the required RGB pins to HIGH/LOW
void setColour(const bool *colour)
{
    for (int i = 0; i < 3; i++)
    {
        digitalWrite(led[i], colour[i]);
    }
}
