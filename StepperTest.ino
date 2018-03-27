//Declare pin functions on Redboard
#define stp 2
#define dir 3
#define stp2 6
#define dir2 7


//Declare variables for functions
char user_input;
char user_input2;
int x;
int y;
int state;

void setup() {
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  ///pinMode(MS1, OUTPUT);
  ///pinMode(MS2, OUTPUT);
  ////pinMode(EN, OUTPUT);
  pinMode(stp2, OUTPUT);
  pinMode(dir2, OUTPUT);
  ///pinMode(MS12, OUTPUT);
  ////pinMode(MS22, OUTPUT);
  ////pinMode(EN2, OUTPUT);
  ///resetEDPins(); //Set step, direction, microstep and enable pins to default states
  Serial.begin(9600); //Open Serial connection for debugging
  Serial.println("Begin motor control");
  Serial.println();
  //Print function list for user selection
  Serial.println("Enter number for control option:");
  Serial.println("Press 2 to start");
}


void loop() {
while (Serial.available()) {
    user_input = Serial.read(); //Read user input and trigger appropriate function
    ///digitalWrite(EN, LOW); //Pull enable pin low to allow motor control
    ///digitalWrite(EN2, LOW);
    if (user_input == '2')
    {
       StepMode_Forward();
    }
    else
    {
      Serial.println("Invalid option entered.");
    }
    
  }
}

//Default microstep mode function
void StepMode_Forward()
{
  Serial.println("Moving forward at default step mode.");
  digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
  digitalWrite(dir2, LOW);
  ////digitalWrite(MS1, HIGH);
  ////digitalWrite(MS2, HIGH);
  
  ////digitalWrite(MS12,HIGH);
  ////digitalWrite(MS22, HIGH);
  Serial.println("press 1 to Turn A");
  Serial.println("press 3 to Turn B");
  while(Serial.available()==0) //Keeps Serial Port Open until Input
  {
  }
  user_input2 = Serial.read();
  Serial.println(user_input2);
  if (user_input2 == '1')
  {
    for (x = 1; x < 2000; x++) //Loop the forward stepping enough times for motion to be visible
    {
      digitalWrite(stp, LOW); //Trigger one step forward
      delay(1);
      digitalWrite(stp, HIGH);
      delay(1);
    }
    Serial.println("Enter new option");
    Serial.println();
  }
  else if (user_input2 == '3')
  {
    for (x = 1; x < 2000; x++) //Loop the forward stepping enough times for motion to be visible
    {
      digitalWrite(stp2, LOW); //Trigger one step forward
      delay(1);
      digitalWrite(stp2, HIGH);
      delay(1);
    }
    Serial.println("Enter new option");
    Serial.println();
  }
  else if (user_input2 == '0')
  {
    StepMode_Forward();
  }
  else
  {
    Serial.println("nope");
    resetEDPins();
  }
}

//Reset Easy Driver pins to default states
void resetEDPins()
{
  digitalWrite(stp, LOW);
  digitalWrite(dir, LOW);
  digitalWrite(stp2, LOW);
  digitalWrite(dir2, LOW);
  ///digitalWrite(MS1, LOW);
  ////digitalWrite(MS2, LOW);
  ////digitalWrite(EN, HIGH);
  ////digitalWrite(MS12, LOW);
  ////digitalWrite(MS22, LOW);
  ///digitalWrite(EN2, HIGH);
}


