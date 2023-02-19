const int trigPin = 5;
const int echoPin = 18;

long duration;
float distanceCm;
float distanceInch;

void setup() {
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    distanceCm = (duration/2) / 27.6;
    distanceInch = distanceCm * CM_TO_INCH;

    Serial.print("duration: ");
    Serial.println(duration);
    Serial.print("Distance (cm): ");
    Serial.println(distanceCm);
    Serial.print("Distance (inch): ");
    Serial.println(distanceInch);
    delay(1000);
}
