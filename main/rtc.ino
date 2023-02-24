void rtc()
{
  // untuk update waktu
  myRTC.updateTime();

  Serial.print("Current Date / Time");
  // tanggal
  Serial.print(myRTC.dayofmonth);
  Serial.print("/");

  // bulan
  Serial.print(myRTC.month);
  Serial.print("/");

  // tahun
  Serial.print(myRTC.year);
  Serial.print(" ");

  // jam
  Serial.print(myRTC.hours);
  Serial.print(":");

  // menit
  Serial.print(myRTC.minutes);
  Serial.print(":");

  // detik
  Serial.println(myRTC.seconds);
  delay(1000);
}
