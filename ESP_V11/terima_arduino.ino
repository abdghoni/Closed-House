
void terima_ard(){
  
if(data_masuk.receiveData())
{
  average_suhu=(float)data_in.data_suhu;
  average_suhu=(average_suhu/10);
  average_humadity=(float)data_in.data_kelembaban;
  average_humadity=(average_humadity/10);
  average_ppm=(float)data_in.data_amoniak;
  average_ppm=(average_ppm/10);
  setpoint_suhu_arduino=(float)data_in.data_setpoint;
  setpoint_suhu_arduino=setpoint_suhu_arduino/10;
  hariF=(float)data_in.data_hari;

  sync_state_arduino=(float)data_in.data_sync;
  
  modeF_state_arduino=(float)data_in.data_mode;
  
  kipas1F_state_arduino=(float)data_in.data_kipas1;
  kipas2F_state_arduino=(float)data_in.data_kipas2;
  kipas3F_state_arduino=(float)data_in.data_kipas3;
  
  heaterF_state_arduino=(float)data_in.data_heater;
  colpadF_state_arduino=(float)data_in.data_colpad;
    
}

}
 
void sinkron_arduino()
{
  setpoint_suhu=(float)setpoint_suhu_arduino;  
  
  sync_state=(float)sync_state_arduino;
  modeF_state=(float)modeF_state_arduino;
  
  kipas1F_state=(float)kipas1F_state_arduino;
  kipas2F_state=(float)kipas2F_state_arduino;
  kipas3F_state=(float)kipas3F_state_arduino;
  
  heaterF_state=(float)heaterF_state_arduino;
  colpadF_state=(float)colpadF_state_arduino;
}


void sinkron_web()
{

  setpoint_suhu=(float)web_setpoint;  
  
  sync_state=(float)web_sync;
  modeF_state=(float)web_mode;
  
  kipas1F_state=(float)web_kipas1;
  kipas2F_state=(float)web_kipas2;
  kipas3F_state=(float)web_kipas3;
  
  heaterF_state=(float)web_heater;
  colpadF_state=(float)web_colpad;
 

}
