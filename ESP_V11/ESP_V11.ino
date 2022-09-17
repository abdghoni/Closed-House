#include <WiFi.h>
#include <EasyTransfer.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
String key = "12345";

#include <esp_task_wdt.h>

#define WDT_TIMEOUT 8


WiFiClient client;

const int httpPort = 80;
char buff_datasend[200];
unsigned long timeout;
const char* ssid     = "BOLT-D3D7";
const char* password = "12345678";

const char* host="iot.reinutech.site";


uint16_t state_kirim_data_web_manual, state_kirim_data_web_auto,
          state_kirim_data_arduino_manual, state_kirim_data_arduino_auto,  
          count_kirim1=0, count_kirim2=0;
     
#define REPORTING_PERIOD_MS     1000
uint32_t tsLastReport = 0;

float  average_suhu,  average_humadity,  average_ppm, hariF, setpoint_suhu,modeF_state, kipas1F_state, kipas2F_state, kipas3F_state, 
        heaterF_state, colpadF_state, sync_state;

float   setpoint_suhu_arduino,modeF_state_arduino, kipas1F_state_arduino, kipas2F_state_arduino, kipas3F_state_arduino, 
        heaterF_state_arduino, colpadF_state_arduino, sync_state_arduino;

int web_kipas1, web_kipas2, web_kipas3, web_colpad, web_heater, web_mode, web_hooper, web_line, web_sync, web_pompa;        

float web_setpoint; 

EasyTransfer data_masuk, data_keluar;

struct struktur_data{
  
  uint16_t data_suhu;
  uint16_t data_kelembaban;
  uint16_t data_amoniak;
  uint16_t data_setpoint;
  uint16_t data_hari;
  
  uint16_t data_mode;
  
  uint16_t data_sync;
  
  uint16_t data_kipas1;
  uint16_t data_kipas2;
  uint16_t data_kipas3;
  uint16_t data_heater;
  uint16_t data_colpad;

};


struct struktur_data2{
  
  uint16_t esp_setpoint;
  uint16_t esp_mode;
  uint16_t esp_sync;
  uint16_t esp_kipas1;
  uint16_t esp_kipas2;
  uint16_t esp_kipas3;
  
  uint16_t esp_heater;
  uint16_t esp_colpad;

};

struktur_data data_in;
struktur_data2 data_out;

void setup() {
  
Serial.begin(9600);
Serial2.begin(115200);


data_masuk.begin(details(data_in), &Serial2);
data_keluar.begin(details(data_out), &Serial2);

setup_esp();
setpoint_suhu=30;
kirim_data_ke_web();
esp_task_wdt_init(WDT_TIMEOUT, true);
esp_task_wdt_add(NULL);

}

void loop() 
{

   if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
   count_kirim1+=1;
   tsLastReport = millis();
   esp_task_wdt_reset();
   }
  
  terima_ard();
  sinkron_arduino();
  tampil_arduino();
  if(count_kirim1==300)
  {
  //kirim_data_ke_web();
  count_kirim1=0;
  }

  
  
}


void tampil_arduino(){
  
 Serial.print("suhu=");
 Serial.print(average_suhu);
 
 Serial.print("  kelembaban="); 
 Serial.print(average_humadity);
 
 Serial.print("  ppm="); 
 Serial.print(average_ppm);
 
 Serial.print("  Hari=");
 Serial.print(hariF);
 
 Serial.print("  setpoint=");
 Serial.print(setpoint_suhu);
 
 Serial.print("  mode=");
 Serial.print(modeF_state);
 
 Serial.print("  kipas1=");
 Serial.print(kipas1F_state);
 
  Serial.print("  kipas2=");
 Serial.print(kipas2F_state);
 
  Serial.print("  kipas3=");
 Serial.print(kipas3F_state);
 
  Serial.print("  heater=");
 Serial.print(heaterF_state);

  Serial.print("  colpad=");
 Serial.println(colpadF_state);
  
}


void tampil_web(){
  
 Serial.print("sync=");
 Serial.print(web_sync);
 
 Serial.print("  mode="); 
 Serial.print(web_mode);
 
 Serial.print("  Setpoint"); 
 Serial.print(web_setpoint);
 
 Serial.print("  kipas1=");
 Serial.print(web_kipas1);

 Serial.print("  kipas2=");
 Serial.print(web_kipas2);

 Serial.print("  kipas3=");
 Serial.print(web_kipas3);
 
 Serial.print("  colpad=");
 Serial.print(web_colpad);

 Serial.print("  heater=");
 Serial.println(web_heater);
 
 
  
  }


  void tampil_state(){
    
 Serial.print("sync web=");
 Serial.print(web_sync);

 Serial.print("  sync Ard=");
 Serial.print(modeF_state_arduino);

 Serial.print("  sync kirim=");
 Serial.print(sync_state);
 
 Serial.print("  mode web="); 
 Serial.print(web_mode);

  Serial.print("  mode Ard=");
 Serial.print(modeF_state_arduino);

   Serial.print("  mode kirim=");
 Serial.println(modeF_state);
  


  }
