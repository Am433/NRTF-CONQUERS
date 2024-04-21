#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>

// Replace with your network credentials
const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFiPassword";

// Replace with your server or cloud service details
const char* serverAddress = "server_address";
const int serverPort = 80;

WiFiClient client;
Adafruit_BMP085 bmp;

const int triggerPin = 4; 
const int echoPin = 5;

float measureDistance() {
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    
    
    long duration = pulseIn(echoPin, HIGH);
    float distance = duration * 0.034 / 2; 
    
    return distance;
}

void setup() {
    Serial.begin(115200);
    pinMode(13, INPUT);
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);

    // Connect to WiFi network
    Serial.println();
    Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    // Initialize BMP180 sensor
    if (!bmp.begin()) {
        Serial.println("Could not find a valid BMP180 sensor, check wiring!");
        while (1);
    }
}

void loop() {
    float temp = digitalRead(13);

    delay(10);
    Serial.println(temp); // this speeds up the simulation
    float distance = measureDistance();
    Serial.print("Distance : ");
    Serial.print(distance);
    Serial.println(" cm");

    int sensorValue = analogRead(sensorPin); // Read analog value from sensor
    float voltage = sensorValue * (3.3 / 4095); // Convert analog value to voltage (assuming 12-bit ADC)
    
    // Convert voltage to current using sensor specifications (mV/A)
    float current = voltage / 185; // ACS712 sensitivity: 185 mV/A for ACS712-20A
   
    Serial.print("Current: ");
    Serial.print(current, 2); // Print current with two decimal places
    Serial.println(" A");

    // Send sensor data to server
    if (client.connect(serverAddress, serverPort)) {
        Serial.println("Sending data to server...");
        client.print("GET /update?temperature=");
        client.print(bmp.readTemperature());
        client.print("&pressure=");
        client.print(bmp.readPressure());
        client.print("&distance=");
        client.print(distance);
        client.print("&current=");
        client.print(current);
        client.println(" HTTP/1.1");
        client.print("Host: ");
        client.println(serverAddress);
        client.println("Connection: close");
        client.println();
        client.stop();
        Serial.println("Data sent");
    } else {
        Serial.println("Failed to connect to server");
    }

    delay(1000);
}
