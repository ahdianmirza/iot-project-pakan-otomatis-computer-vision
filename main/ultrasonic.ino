void ultrasonic()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    distanceCm = (duration / 2) / 27.6;

    lcd.setCursor(0, 0);
    lcd.print("Jarak: ");

    lcd.setCursor(7, 0);
    lcd.print(distanceCm);

    if (distanceCm < 5)
    {
        lcd.setCursor(0, 1);
        lcd.print("Hampir Habis    ");
    }
    else
    {
        lcd.setCursor(0, 1);
        lcd.print("Pakan Aman      ");
    }
    delay(500);
}
