/*
 * Editor: Jörn Seybold, Max Bier
 * 
 * Date: 24.04.16
 * 
 * Desc: All Sensor Readings merged in one File
 */

#define distPin A6

/*
 * Init 
 */
void setup() {
  Serial.begin(9600);
  pinMode(distPin, INPUT);

}

void loop () 
{
  range = distanceSensor_test();
}


/*
 * functions for sharp distance sensor
 */

uint16_t distanceSensor_test()
{
  uint16_t value = analogRead (pin);
  uint16_t range //= get_gp2d12 (value);
  if (value < 10) range = 10;
  else range = value;
  range  = ((67870.0 / (range - 3.0)) - 40.0)
// unneccesary range returns for serial monitor
//  Serial.println (value);
//  Serial.print (range);
//  Serial.println (" mm");
//  Serial.println ();
  delay (500);
  return range;
}
