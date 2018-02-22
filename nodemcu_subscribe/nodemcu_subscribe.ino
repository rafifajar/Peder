#include <ESP8266WiFi.h>
#include <MQTTClient.h>
#include <Servo.h>

Servo myservo;
int pos = 0;

const char *ssid = "NeoPanduX";
const char *pass = "qwertyuiop";
WiFiClient net;
MQTTClient client;
String msg = "0";

unsigned long lastMillis = 0;

void connect(); // <- predefine connect() for setup()

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  client.begin("139.59.225.39", net);

  myservo.attach(D1);
  connect();
}

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect("arduino", "admintes", "admin123")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");

  client.subscribe("peder/7H33X/control");
  // client.unsubscribe("/example");
}

void loop() {
  client.loop();
  delay(10); // <- fixes some issues with WiFi stability

  if (!client.connected()) {
    connect();
  }

  client.subscribe("peder/7H33X/control");

    if (msg == "1") {
    for (pos = 20; pos < 40; pos += 1) // goes from 0 degrees to 180 degrees
    { // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }
    delay(1000);
    for (pos = 40; pos >= 20; pos -= 1) // goes from 180 degrees to 0 degrees
    {
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }
    msg = "0";
  }
  else if (msg == "2") {
    for (pos = 0; pos < 50; pos += 1) // goes from 0 degrees to 180 degrees
    { // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }
    delay(1000);
    for (pos = 50; pos >= 0; pos -= 1) // goes from 180 degrees to 0 degrees
    {
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }
    msg = "0";
  }
  else if (msg == "3") {
    for (pos = 0; pos < 60; pos += 1) // goes from 0 degrees to 180 degrees
    { // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }
    delay(1000);
    for (pos = 60; pos >= 0; pos -= 1) // goes from 180 degrees to 0 degrees
    {
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }
    msg = "0";
  }
  else if (msg == "4") {
    for (pos = 0; pos < 70; pos += 1) // goes from 0 degrees to 180 degrees
    { // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }
    delay(1000);
    for (pos = 70; pos >= 0; pos -= 1) // goes from 180 degrees to 0 degrees
    {
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }
    msg = "0";
  }
}

void messageReceived(String topic, String payload, char * bytes, unsigned int length) {
  Serial.println(payload);
  msg = payload;
  msg = payload;
}

