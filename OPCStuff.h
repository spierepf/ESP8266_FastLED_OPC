WiFiServer opcServer(7890);
WiFiClient client;

void OPCStuff_setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  opcServer.begin();
}

void OPCStuff_loop() {
  if(!client) client = opcServer.available();

  digitalWrite(LED_BUILTIN, !client);

  if(client) {
    while (client.connected() && client.available() < 4) yield();
    int channel = client.read();
    int command = client.read();
    size_t length = (client.read() << 8) + client.read();
    while (client.connected() && client.available() < length) yield();
    if(client.connected() && (channel == 0 || channel == 1) && command == 0 && length <= NUM_LEDS * 3) {
      Serial.print(".");
      client.readBytes((uint8_t *)leds, length);
    } else {
      client.stop();
    }
  }
}
