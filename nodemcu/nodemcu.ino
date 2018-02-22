#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid ="Theex-HQ";
const char* password = "JuraganPeceLyeye";
const char* mqtt_server = "139.59.225.39";
int data = 0;
char msg[50];
//char msg2[50];
int value = 0;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte * payload, unsigned int length) {
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client", "admintes", "admin123")) {
      Serial.println("reconnected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      //delay(5000);
    }
  }
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }

  if (Serial.available() > 0) {
    data = Serial.parseFloat();
    Serial.println(data);

  }
  //Serial.println("serial tidak masuk");
  
   if (data > 24 && data < 35) {
      //cek suhu
      snprintf (msg, 75, "%ld", data);
      client.publish("peder/7H33X/data1", msg);
    } else {
      snprintf (msg, 75, "%ld", data);
      client.publish("peder/7H33X/data2", msg);
    } 
        
  delay(400);
}
