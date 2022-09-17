void tampil_AveSuhu(){
  String comman = "home.t2.txt=\""+String(average_suhu,2)+"\"";
  Serial2.print(comman);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}


void tampil_AveHum(){
  String comman = "home.t3.txt=\""+String(average_humadity, 2)+"\"";
  Serial2.print(comman);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}


void tampil_AveAmoniak(){
  String comman = "home.t4.txt=\""+String(average_ppm,2)+"\"";
  Serial2.print(comman);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void tampil_number(int n)
{
  String comman = "n0.val=\""+String(n)+"\"";
  Serial2.print(comman);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}


void tampil_all_suhu()
{
  String comman[4];
  if(jadwal1==1)
  {
  comman[0] = "mntrBroilerA.t23.txt=\""+String(suhu[0],2)+"\"";
  Serial2.print(comman[0]);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
  }
  else if(jadwal1==2)
  {
  comman[1] = "mntrBroilerA.t24.txt=\""+String(suhu[1],2)+"\"";
  Serial2.print(comman[1]);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
  }
  else if(jadwal1==3)
  {
  comman[2] = "mntrBroilerA.t25.txt=\""+String(suhu[3],2)+"\"";
  Serial2.print(comman[2]);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
  }
  else if(jadwal1==4)
  {
  comman[3] = "mntrBroilerA.t26.txt=\""+String(suhu[4],2)+"\"";
  Serial2.print(comman[3]);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
  }
 }


void tampil_all_hum(){
String comman[4];
  if(jadwal1==5)
  {
  comman[0] = "mntrBroilerA.t28.txt=\""+String(humadity[0],2)+"\"";
  Serial2.print(comman[0]);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
  }
  if(jadwal1==6)
  {
  comman[1] = "mntrBroilerA.t29.txt=\""+String(humadity[1],2)+"\"";
  Serial2.print(comman[1]);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
  
  }
  if(jadwal1==7)
  {
  comman[2] = "mntrBroilerA.t30.txt=\""+String(humadity[3],2)+"\"";
  Serial2.print(comman[2]);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
  
  }
  if(jadwal1==8)
  {
  comman[3] = "mntrBroilerA.t31.txt=\""+String(humadity[4],2)+"\"";
  Serial2.print(comman[3]);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
  }
  
 
}


void tampil_all_amoniak(){
String comman;
  
  comman= "mntrBroilerA.t21.txt=\""+String(average_ppm,2)+"\"";
  Serial2.print(comman);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
  
 
}



void tampil_setpoint()
{
  String comman = "otoMonitorA.t11.txt=\""+String(count_suhu1,2)+"\"";
  Serial2.print(comman);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

}


void tampil_save()
{
  String comman = "save.t0.txt=\""+String(count_save)+"\"";
  Serial2.print(comman);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);

}

void tampil_count_down_save()
{
  String comman = "save.t0.txt=\""+String(count_down)+"\"";
  Serial2.print(comman);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
}

void set_nilai_aktuator(){
    Kipas1.setValue(kp1_state);
    Kipas2.setValue(kp2_state); 
    Kipas3.setValue(kp3_state);
    Heater.setValue(Heater_state);
    Colpad.setValue(Ef_state);
  
}
