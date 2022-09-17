#include "Nextion.h"
#include <Wire.h>
#include <DS3231.h>
#include "DHT.h"
#include <Adafruit_GFX.h>
#include <SPI.h>
#include <SD.h>
#include "NexDualStateButton.h"
#include <EasyTransfer.h>
#include <avr/wdt.h>


EasyTransfer data_keluar, data_masuk;

//kirim ke esp

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


// terima dari esp

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

struktur_data data_out;
struktur_data2 data_in;

#define EF1 3
#define EF2 5
#define EF3 7
#define HTR 9
#define CLPD 11


#define DHTTYPE1 DHT22
#define DHTTYPE2 DHT22
#define DHTTYPE4 DHT22
#define DHTTYPE5 DHT22

#define dht_pin1 A2
#define dht_pin2 A4
#define dht_pin4 A8
#define dht_pin5 A0

DHT dht1(dht_pin1, DHTTYPE1);
DHT dht2(dht_pin2, DHTTYPE2);

DHT dht4(dht_pin4, DHTTYPE4);
DHT dht5(dht_pin5, DHTTYPE5);


const int mq135= A6;

#define RL 10
#define m -0.417 
#define b 0.858 

float Ro=135;
float VRL, RS, ratio,ppm;
float total_ppm=0, average_ppm=0;



int menit1, menit2, last_menit,last_menit2, timer1, timer2;
uint8_t menu, t_otomatis;
DS3231 clock;
RTCDateTime dt;
volatile int hariKe=0;
int day_now, day_last;
float setpoint_suhu;


float count_suhu1=20;
unsigned int count_save=5, save_state=0, count_dht22=0, count_down;

volatile int fase_ayam;
const int chipSelect = 53;

int CurrentPage=0;

#define REPORTING_PERIOD_MS     1000
#define REPORTING_PERIOD_MS_1   5

int jadwal1, jadwal3,jadwal2,  otomatis_state=1;
volatile int umur_ayam=0;
uint8_t counter[8]={2,2,2,2,2,2,2,2};

float humadity[5], suhu[5], total_suhu, 
      total_humadity=0, average_suhu=30, average_humadity=67;


int IdMode=0, IdFeed=0, IdSave=0;
bool kp1_state=0, kp2_state=0, kp3_state=0, Ef_state=0, Heater_state=0, Feeder1_state=0,Feeder2_state=0, Feeder3_state=0,
      line_state=1, hooper_state=1, sync_state=0, mode_state=0;

NexPage home = NexPage(0, 0, "home");
NexPage manualMonitorA = NexPage(1, 0, "manualMonitorA");  
NexPage otoMonitorA = NexPage(2, 0, "otoMonitorA"); 
NexPage manualFeederA = NexPage(3, 0, "manualFeederA");  
NexPage otoFeederA = NexPage(4, 0, "otoFeederA");  
NexPage view = NexPage(5, 0, "view");    
NexPage mntrBroilerA = NexPage(6, 0, "mntrBroilerA");
NexPage mntrFeederA = NexPage(7, 0, "mntrFeederA");
NexPage save = NexPage(8, 0, "save"); 

//--------------------------------------------------//


//-----------ACTUATOR----------//
NexButton HeaterOn = NexButton(1, 34, "b5");
NexButton kp1On = NexButton(1, 35, "b6");
NexButton kp2On = NexButton(1, 36, "b9");
NexButton kp3On = NexButton(1, 37, "b10");
NexButton EfOn = NexButton(1, 38, "b11");

NexButton Feeder1On = NexButton(3, 28, "b5");
NexButton Feeder2On = NexButton(3, 29, "b6");
NexButton Feeder3On = NexButton(3, 30, "b9");

NexNumber Kipas1 = NexNumber(1, 17, "manualMonitorA.kipasA1");
NexNumber Kipas2 = NexNumber(1, 18, "manualMonitorA.kipasA2");
NexNumber Kipas3 = NexNumber(1, 19, "manualMonitorA.kipasA3");
NexNumber Heater = NexNumber(1, 20, "manualMonitorA.heaterA1");
NexNumber Colpad = NexNumber(1, 21, "manualMonitorA.coolpadA1");

NexNumber Feed1 = NexNumber(3, 24, "manualFeederA.lineA1");
NexNumber Feed2 = NexNumber(3, 25, "manualFeederA.lineA2");
NexNumber Feed3 = NexNumber(3, 26, "manualFeederA.lineA3");

NexNumber Line1 = NexNumber(7, 17, "mntrFeederA.lineS");
NexNumber Hooper1 = NexNumber(7, 18, "mntrFeederA.HooperS");

NexButton Set1On = NexButton(1, 32, "b7");
NexButton Set3On = NexButton(2, 24, "b7");

NexButton Set2On = NexButton(3, 25, "b7");
NexButton Set4On = NexButton(4, 22, "b7");


NexButton Set5On = NexButton(8, 11, "b5");
NexButton Batal = NexButton(8, 12, "b6");

NexNumber IdMode1 = NexNumber(0, 24, "home.IdMode");
NexNumber IdFeed1 = NexNumber(3, 27, "manualFeederA.IdFeed1");
NexNumber IdSave1 = NexNumber(8, 14, "save.IdSave1");

NexNumber umur = NexNumber(0, 23, "home.umurAyam");


NexButton plsb11 = NexButton(2, 30, "b9");
NexButton minb12 = NexButton(2, 31, "b10");

NexButton plsb21 = NexButton(8, 10, "b9");
NexButton minb22 = NexButton(8, 9, "b10");

NexTouch *nex_listen_list[] = 
{
  &home, 
  &manualMonitorA, 
  &otoMonitorA, 
  &manualFeederA,
  &otoFeederA,
  &mntrBroilerA,
  &mntrFeederA,
  &view,
  &save,
  
  &HeaterOn,
  &kp1On,
  &kp2On,
  &kp3On,
  &EfOn,
  
  &Feeder1On,
  &Feeder2On,
  &Feeder3On,

  &Set1On,
  &Set2On,

  &Set3On,
  &Set4On,

  &Set5On,
  &Batal,
  
  &plsb11,
  &minb12,

  &plsb21,
  &minb22,

  NULL
};

void setup() 
{
  wdt_disable();
  Serial.begin(9600);
  Serial2.begin(115200);
  Serial3.begin(115200);
  
  data_keluar.begin(details(data_out), &Serial3);
  data_masuk.begin(details(data_in), &Serial3);
  
  
  nexInit();
  init_HMI();
  INIT_ACT(); 
  init_feeder();
  
 dht1.begin();
 dht2.begin();
 dht4.begin();
 dht5.begin();
  

  SD.begin(chipSelect);
  clock.begin();
  clock.setDateTime(__DATE__, __TIME__);

  IdMode1.setValue(IdMode);
  
  Kipas1.setValue(kp1_state);
  Kipas2.setValue(kp2_state); 
  Kipas3.setValue(kp3_state);
  Heater.setValue(Heater_state);
  Colpad.setValue(Ef_state);
  
  Line1.setValue(line_state);
  Hooper1.setValue(hooper_state);
  
  umur.setValue(umur_ayam);
  tampil_save();
  tampil_setpoint();
  wdt_enable(WDTO_8S);
}

void loop() 
{

scheduling();
counter_suhu_kelembaban();
hitung_suhu_kelembaban();
hitung_amoniak();

switch(CurrentPage)
{
case 0:

break;

case 1:

break;

case 2:

tampil_setpoint();
set_nilai_aktuator();

break;

case 3:

break;

case 4:

break;

case 5:


break;

case 6:


break;

case 7:

break;

case 8:

break;
}

tampil_all_suhu();
tampil_all_hum();
tampil_all_amoniak();
if(jadwal1==9)
{
tampil_AveSuhu();
}
else if (jadwal1==10)
{
tampil_AveHum();
}
else if (jadwal1==11)
{
tampil_AveAmoniak();
jadwal1=0;
}


//Serial.print(IdMode);
//Serial.println("  ");
//Serial.print(counter[1]);
//Serial.print("  ");
//Serial.print(counter[2]);
//Serial.print("  ");
//Serial.print(counter[3]);
//Serial.print("  ");

Serial.println(jadwal1);
//Serial.print(kp1_state);
//Serial.print("  ");
//Serial.print(kp2_state);
//Serial.print("  ");
//Serial.print(kp3_state);
//Serial.print("  ");
//Serial.print(Ef_state);
//Serial.print("  ");
//Serial.print(fase_ayam);
//Serial.print("  ");
//Serial.print(count_dht22);
//Serial.print("  ");
//Serial.print(average_suhu);
//Serial.print("  ");
//Serial.print(average_humadity);
//Serial.print("  ");
//Serial.println(average_ppm);

nexLoop(nex_listen_list);
}
