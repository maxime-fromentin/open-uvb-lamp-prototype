// XIAO RP2040 relay smoke test.
// Hardware: D2/GPIO28 -> 1k -> 2N3904 base -> relay coil driver.

constexpr uint8_t RELAY_PIN = D2;
constexpr unsigned long RUN_MS = 5000;
constexpr unsigned long AUTO_START_DELAY_MS = 3000;
constexpr bool AUTO_START_ON_BOOT = false;

bool relayOn = false;
unsigned long relayUntil = 0;
String line;

void setRelay(bool on) {
  relayOn = on;
  digitalWrite(RELAY_PIN, on ? HIGH : LOW);
  if (!on) {
    relayUntil = 0;
  }
  Serial.println(on ? "RELAY_ON" : "RELAY_OFF");
}

void handleCommand(String cmd) {
  cmd.trim();
  cmd.toLowerCase();

  if (cmd == "on") {
    setRelay(true);
    relayUntil = millis() + RUN_MS;
    Serial.println("TIMER_5S_STARTED");
  } else if (cmd == "off") {
    setRelay(false);
  } else if (cmd == "pulse") {
    setRelay(true);
    relayUntil = millis() + RUN_MS;
    Serial.println("TIMER_5S_STARTED");
  } else if (cmd == "status") {
    Serial.println(relayOn ? "STATUS_ON" : "STATUS_OFF");
  } else if (cmd.length() > 0) {
    Serial.println("Commands: on, off, pulse, status");
  }
}

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  Serial.begin(115200);
  delay(1500);
  Serial.println("XIAO_RP2040_RELAY_TEST_READY");
  Serial.println("Commands: on, off, pulse, status");

  if (AUTO_START_ON_BOOT) {
    Serial.println("AUTO_START_WAIT_3S");
    delay(AUTO_START_DELAY_MS);
    setRelay(true);
    relayUntil = millis() + RUN_MS;
    Serial.println("AUTO_START_TIMER_5S_STARTED");
  }
}

void loop() {
  while (Serial.available() > 0) {
    char c = static_cast<char>(Serial.read());
    if (c == '\n' || c == '\r') {
      handleCommand(line);
      line = "";
    } else {
      line += c;
    }
  }

  if (relayUntil != 0 && static_cast<long>(millis() - relayUntil) >= 0) {
    setRelay(false);
    Serial.println("TIMER_DONE");
  }
}
