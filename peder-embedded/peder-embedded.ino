//dht lewat nrf penerima
#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
const char payload_length = 32;
byte data[payload_length];

//fungsi nrf penerima (dht)
boolean terima() {
  if (!Mirf.isSending() && Mirf.dataReady())
  {
    Mirf.getData(data);
 //   Serial.println ("sensor berat = ");
    Serial.println ((char*)data);
    return true;
  }else {
   // Serial.println((char*)data);
   //Serial.println("tidak tersambung");
    //Serial.print ("terima");
    //Serial.write((char*)data);
    return false;  }
}

void setup() {
  Serial.begin(9600);
  //nrf penerima(dht)
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR((byte *)"serve");
  Mirf.payload = payload_length;
  Mirf.channel = 234;
  Mirf.config();

}

void loop() {
  //manggil fungsi nrf penerima (dht)
boolean statusNrf = terima();

    delay(500);

}
