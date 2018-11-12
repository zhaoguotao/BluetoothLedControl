/*
  SD card read/write
  This example shows how to read and write data to and from an SD card file
  The circuit:
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4
*/
int led0 = 23;
int led1 = 25;
int led2 = 27;
char comdata;

void setup()
{
  pinMode(led0, OUTPUT);
  digitalWrite(led0, HIGH);
  pinMode(led1, OUTPUT);
  digitalWrite(led1, HIGH);
  pinMode(led2, OUTPUT);
  digitalWrite(led2, HIGH);

  Serial.begin(115200); //串口0
  Serial1.begin(115200);
  Serial.println("initialization done.com0");
  Serial1.println("initialization done.com1");
}

void loop()
{
  while (Serial1.available() > 0)
  {
    comdata = char(Serial1.read());
    delay(2);//ms
  }
  led();
  comdata = ' ';
}
void led(void)
{
  switch (comdata)
  {
    case 'a':
      digitalWrite(led0, HIGH);//OFF
      Serial.println("led0 OFF");
      break;
    case 'A':
      digitalWrite(led0, LOW);//ON
      Serial.println("led0 ON");
      break;
    case 'b':
      digitalWrite(led1, HIGH);//OFF
      Serial.println("led1 OFF");
      break;
    case 'B':
      digitalWrite(led1, LOW);//ON
      Serial.println("led1 ON");
      break;
    case 'c':
      digitalWrite(led2, HIGH);//OFF
      Serial.println("led2 OFF");
      break;
    case 'C':
      digitalWrite(led2, LOW);//ON
      Serial.println("led2 ON");
      break;
    default:
      break;
  }


}


