void servo()
{
  for (pos = 0; pos <= 180; pos++)
  {
    myServo.write(pos);
    delay(15);
  }

  for (pos = 180; pos >= 0; pos--)
  {
    myServo.write(pos);
    delay(15);
  }
}
