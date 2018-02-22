#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

const char payload_length = 32;
byte data[payload_length];

boolean kirim(String sensor){

  Serial.println("Kirim");
  Serial.print(",\t");
  String sensora=String(sensor);
  char data[32];
  sensora.toCharArray(data,32);
  Mirf.send((byte*) data);
//  while(Mirf.isSending())
//  {
//
//  }
}

void setup(){
  Serial.begin(9600);
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setTADDR((byte *)"serve");
  Mirf.payload = payload_length;
  Mirf.channel = 234;
  Mirf.config();
 }

void loop(){
 int databerat = random(1000,2000);
 String dataBerat = String (databerat);
 Serial.println(dataBerat);
 kirim(dataBerat);
 delay(50);
}
