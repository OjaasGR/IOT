#include <WiFi.h>
#include <ThingSpeak.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ---------------- WIFI ----------------
const char* ssid = "hehehehehe";
const char* password = "hannah123";

// ------------- THINGSPEAK -------------
unsigned long channelID = 3278942;        // Replace with your Channel ID
const char* writeAPIKey = "
3D5PKVTDOTMEZXID"; // Replace with your Write API Key

WiFiClient client;

// ------------- SENSOR PINS -------------
#define MQ135_PIN 35
#define FLAME_PIN 34

// ------------- OLED SETUP -------------
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {

  Serial.begin(115200);

  pinMode(FLAME_PIN, INPUT);

  // I2C Pins for ESP32 (SDA = 21, SCL = 22)
  Wire.begin(21, 22);

  // OLED Initialization
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  // Connect WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");

  ThingSpeak.begin(client);
}

void loop() {

  // Read Sensors
  int gasValue = analogRead(MQ135_PIN);
  int flameStatus = digitalRead(FLAME_PIN);

  // Risk Logic
  String riskLevel = "LOW";

  if (gasValue > 400) {
    riskLevel = "HIGH";
  }
  else if (gasValue > 250) {
    riskLevel = "MEDIUM";
  }

  if (flameStatus == 0) {   // Flame detected
    riskLevel = "CRITICAL";
  }

  // -------- OLED DISPLAY --------
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Smart Fire System");
  display.println("------------------");

  display.print("Gas: ");
  display.println(gasValue);

  display.print("Flame: ");
  if (flameStatus == 0)
    display.println("YES");
  else
    display.println("NO");

  display.print("Risk: ");
  display.println(riskLevel);

  display.display();

  // -------- SERIAL MONITOR --------
  Serial.print("Gas: ");
  Serial.print(gasValue);
  Serial.print(" | Flame: ");
  Serial.print(flameStatus);
  Serial.print(" | Risk: ");
  Serial.println(riskLevel);

  // -------- SEND TO THINGSPEAK --------
  ThingSpeak.setField(1, gasValue);
  ThingSpeak.setField(2, flameStatus);

  int response = ThingSpeak.writeFields(channelID, writeAPIKey);

  if (response == 200) {
    Serial.println("Data uploaded successfully");
  } else {
    Serial.println("Upload failed");
  }

  delay(15000);  // ThingSpeak minimum delay
}

