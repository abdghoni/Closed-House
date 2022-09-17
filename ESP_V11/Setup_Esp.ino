void setup_esp()
{
Serial.println(ssid);    
WiFi.begin(ssid, password);
      
while (WiFi.status() != WL_CONNECTED) {
    
Serial.print("Connecting to ");
Serial.println("Loading..");
delay(1000);
}
Serial.println("");
Serial.println("WiFi connected.");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
}
