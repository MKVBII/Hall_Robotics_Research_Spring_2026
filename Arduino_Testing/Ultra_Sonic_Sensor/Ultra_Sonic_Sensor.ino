long duration; // declaring our variables
int distance;

const int trigPin = 10; // declaring where our inputs/outputs are coming in from
const int echoPin = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(trigPin, LOW); // turns the trigger pin off
  delayMicroseconds(2); // delay 2 micro-seconds

  digitalWrite(trigPin, HIGH); // sets the trigger pin to high (releases a sound pulse)
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); // waits 10 micro-seconds and turns it off again

  duration = pulseIn(echoPin, HIGH); // waits for the echo pin (the receiver) to trigger
                                     // when it receives a sound pulse

  distance = duration * 0.034/2; // distance calculation

  Serial.print("Distance: "); // output the results
  Serial.println(distance);
}
