void kirim_arduino()
{
  
data_out.esp_setpoint=(uint16_t)web_setpoint;

data_out.esp_mode=(uint16_t)web_mode;
data_out.esp_sync=(uint16_t)web_sync;


data_out.esp_kipas1=(uint16_t)web_kipas1;
data_out.esp_kipas2=(uint16_t)web_kipas2;
data_out.esp_kipas3=(uint16_t)web_kipas3;

data_out.esp_heater=(uint16_t)web_heater;
data_out.esp_colpad=(uint16_t)web_colpad;

data_keluar.sendData();  

  
}



void kirim_arduino_setpoint(){
  
data_out.esp_setpoint=(uint16_t)web_setpoint;

data_keluar.sendData();  

  
}
