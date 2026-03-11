// declare constants for pins
const int xPin = A0;
const int yPin = A1;
const int swPin = 2; // this one (D2, wired the button function of the joy stick) is a digital signal because the button is either on, pressed, 
                     // ^ or off (released) as oppose to the other signals from the movement of the joystick that are represented more accurately with waves.
                     // ^ Those are called "analog" signals

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // activates a serial connection between the computer (I'm on Mac) and the arduino via USB cable
                      // this one is slower than that of the ultrasonic script because of the lower Baud rate (how many bits per second are transmitted over the connection)
                      // ^ this us usually based on how much information you need to send/how often you want your variables to update. 
                      // ^ This is a small script and we don't need crazy fast updates so we dont need much 
  pinMode(swPin, INPUT_PULLUP);
  // INPUT_PULLUP turns on a resistor inside the arduino that keeps it HIGH
  //^ when the joystick button is pressed, it goes to LOW, without this we get
  //^ a bunch of needless readings from the button

  // NOTICE: no pinMode for the analog pins, they default to input mode automatically
}

void loop() { // just output, with the actual drone we'd translate these into servo/thruster actions
  // put your main code here, to run repeatedly:
  int xVal = analogRead(xPin);
  int yVal = analogRead(yPin);
  int button = digitalRead(swPin);


  Serial.println();
  Serial.println("X: ");
  Serial.println(xVal);

  Serial.println();
  Serial.println("Y: ");
  Serial.println(yVal);

  Serial.println();
  Serial.println(" Button: ");
  Serial.println(button);

  delay(500); // 100 millisecond pause in between readings,
              //^ otherwise your human eyeballs wouldnt be able to keep up
}
