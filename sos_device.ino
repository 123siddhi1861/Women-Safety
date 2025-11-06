#define MODEM_RX 20
#define MODEM_TX 21

#define BUTTON_FIRE 2
#define BUTTON_HEALTH 3

#include <HardwareSerial.h>

HardwareSerial sim800(1);  // Serial1

void setup() {
  Serial.begin(115200);
  sim800.begin(9600, SERIAL_8N1, MODEM_RX, MODEM_TX);

  pinMode(BUTTON_FIRE, INPUT_PULLUP);
  pinMode(BUTTON_HEALTH, INPUT_PULLUP);

  Serial.println("System Ready. Waiting for button press...");

  sim800.println("AT");
  delay(500);
  printResponse();
}

void loop() {
  if (digitalRead(BUTTON_FIRE) == LOW) {
    Serial.println("Injury button pressed.");
    sendSMS("8788390936", "Emergency: fire detected. Please respond immediately.");
    delay(3000);
  }

  if (digitalRead(BUTTON_HEALTH) == LOW) {
    Serial.println("Health issue button pressed.");
    sendSMS("your no", "Emergency: Health issue detected. Immediate attention needed.");
    delay(3000);
  }
}

void sendSMS(const char* number, const char* message) {
  sim800.println("AT+CMGF=1");  // Set SMS mode to text
  delay(500);
  printResponse();

  sim800.print("AT+CMGS=\"");
  sim800.print(number);
  sim800.println("\"");
  delay(1000);  // Wait for > prompt
  waitForPrompt();

  sim800.print(message);
  delay(500);
  sim800.write(26);  // Ctrl+Z
  Serial.println("Message sent. Waiting for confirmation...");
  delay(5000);
  printResponse();
}

void printResponse() {
  long timeout = millis() + 5000;
  while (millis() < timeout) {
    while (sim800.available()) {
      Serial.write(sim800.read());
    }
  }
}

void waitForPrompt() {
  long timeout = millis() + 5000;
  while (millis() < timeout) {
    if (sim800.available()) {
      char c = sim800.read();
      Serial.write(c);
      if (c == '>') return;  // Prompt received
    }
  }
  Serial.println("Didn't get '>' prompt.");
}
