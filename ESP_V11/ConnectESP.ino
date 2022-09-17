
void kirim_data_ke_web(){
    if (!client.connect(host, 80)) {
    Serial.println("connection failed");
  }

//http://iot.reinutech.site/data/input/%.2f/%.2f/%.2f/%.2f/%.2f/%.2f/%.2f/%.2f/%.2f/%.2f/%.2f

//http://iot.mediageometri.com/index.php/sendkp/input?suhu=28&kelembaban=63&amonia=8&hari=1&sett=28&fan1=0.0&fan2=1&fan3=0.0&mode=1&heater=1&eva=0.0&sync=1
  
  sprintf(buff_datasend,"/data/input/%.2f/%.2f/%.2f/%.2f/%.2f/%.2f/%.2f/%.2f/%.2f/%.2f/%.2f",
           average_suhu,  average_humadity,  average_ppm, hariF, setpoint_suhu,kipas1F_state, kipas2F_state, kipas3F_state, modeF_state, heaterF_state, colpadF_state);
  client.print(String("GET ") + buff_datasend + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
               


  while(client.available()){
    String line = client.readStringUntil('\r');

  }
  delay(100); 
  Serial.println("terkirim");    
}


void terima_data_dari_web(){
    if (!client.connect(host, 80)) {
    Serial.println("connection failed");
  }
  HTTPClient http;
  
    http.begin("http://iot.reinutech.site/data/control");
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
   
    int httpResponseCode = http.POST("id=" + key); 
    delay(100);

    if (httpResponseCode > 0) {
      String response = http.getString();
      char json[500];
      response.toCharArray(json, 500);
      StaticJsonDocument<200> doc;
      deserializeJson(doc, json);
      
      web_setpoint = doc["temp_setpoint"];
      web_mode= doc["mode"];
      web_sync=doc["sync"];
      web_kipas1= doc["exhaust1"];
      web_kipas2=doc["exhaust2"];
      web_kipas3=doc["exhaust3"];
      web_heater =doc["heater"];
      web_colpad =doc["evaporative"];
      
      web_setpoint*=10;
        

    } 
    http.end();  
  
  }


  void olah_data(){
    
      if(count_kirim2==15&&web_sync==0&&sync_state_arduino==0)
      {
        terima_ard();
        sinkron_arduino();
        kirim_data_ke_web();
        count_kirim2=0;

       }
     }
  
