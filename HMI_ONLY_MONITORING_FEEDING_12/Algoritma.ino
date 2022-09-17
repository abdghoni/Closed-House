


void algoritma_utama()
{
  switch(IdMode)
  {
    case 0:
    algoritma_otomatis();
    //Serial.print(timer1);
    break;

    case 1:
    algoritma_manual();
    break;
  }
}


void algoritma_otomatis()
{
switch(fase_ayam)
{
case 0:
count_suhu1=31;
setpoint_suhu=count_suhu1;
mode_otomatis();
break;

case 1:
count_suhu1=31;
setpoint_suhu=count_suhu1;
mode_otomatis();
break;


case 2:
count_suhu1=31;
setpoint_suhu=count_suhu1;
mode_otomatis();
break;


case 3:
count_suhu1=31;
setpoint_suhu=count_suhu1;
mode_otomatis();
break;

case 4:
count_suhu1=31;
setpoint_suhu=count_suhu1;
mode_otomatis();
break;


case 5:
count_suhu1=31;
setpoint_suhu=count_suhu1;
mode_otomatis();

break;
}
}


void algoritma_manual()
{
fungsi_aktuator();
}

void mode_otomatis(){
  
switch(otomatis_state){
  case 0:

//   mode-1 Jika: Suhu Lapangan > suhu_setpoint
//          tapi: Suhu Lapangan < Setpoint+3

 if(average_suhu>setpoint_suhu&&average_suhu<(setpoint_suhu+8))
  {
   kp1_state=1;
   kp2_state=1;
   kp3_state=1;
   Heater_state=0;
   Ef_state=1;
   
   digitalWrite(EF1, kp1_state);  
   digitalWrite(EF2, kp2_state);    
   digitalWrite(EF3, kp3_state);  
   digitalWrite(HTR, Heater_state);  
   digitalWrite(CLPD, Ef_state);
   //set_nilai_aktuator();
  }
  else if(average_suhu<setpoint_suhu&&average_suhu>(setpoint_suhu-5))
  {

//   mode-1 Jika: Suhu Lapangan < suhu_setpoint
//          tapi: Suhu Lapangan > Setpoint-3
   kp1_state=0;
   kp2_state=1;
   kp3_state=0;
   Heater_state=1;
   Ef_state=0;
   
   digitalWrite(EF1, kp1_state);  
   digitalWrite(EF2, kp2_state);    
   digitalWrite(EF3, kp3_state);  
   digitalWrite(HTR, Heater_state);  
   digitalWrite(CLPD, Ef_state);
   //set_nilai_aktuator();

  }
  break;

  case 1:
  if(average_suhu>setpoint_suhu&&average_suhu<(setpoint_suhu+8))
  {
   if(timer1>=0&&timer1<=3)
   { 
   kp1_state=1;
   kp2_state=1;
   kp3_state=1;
   Heater_state=0;
   Ef_state=1; 
   digitalWrite(EF1, kp1_state);  
   digitalWrite(EF2, kp2_state);    
   digitalWrite(EF3, kp3_state);  
   digitalWrite(HTR, Heater_state);  
   digitalWrite(CLPD, Ef_state);
  // set_nilai_aktuator();

  //Serial.println("suhu diatas : timer1-3");

  
   }
   if(timer1>=4&&timer1<=7)
   {
   kp1_state=1;
   kp2_state=0;
   kp3_state=1;
   Heater_state=0;
   Ef_state=1; 
   digitalWrite(EF1, kp1_state);  
   digitalWrite(EF2, kp2_state);    
   digitalWrite(EF3, kp3_state);  
   digitalWrite(HTR, Heater_state);  
   digitalWrite(CLPD, Ef_state);
   //Serial.println("suhu diatas : timer4-7");
   }
   if(timer1>=8&&timer1<=12)
   { 
   kp1_state=0;
   kp2_state=1;
   kp3_state=0;
   Heater_state=0;
   Ef_state=1; 
   digitalWrite(EF1, kp1_state);  
   digitalWrite(EF2, kp2_state);    
   digitalWrite(EF3, kp3_state);  
   digitalWrite(HTR, Heater_state);  
   digitalWrite(CLPD, Ef_state);
   //Serial.println("suhu diatas : time8-12");
   }  
     if(timer1>=13){
       timer1=0;}
  }
  else if(average_suhu<setpoint_suhu&&average_suhu>(setpoint_suhu-5))
  {
 if(timer1>=0&&timer1<=3)
   { 
   kp1_state=0;
   kp2_state=1;
   kp3_state=0;
   Heater_state=1;
   Ef_state=0; 
   digitalWrite(EF1, kp1_state);  
   digitalWrite(EF2, kp2_state);    
   digitalWrite(EF3, kp3_state);  
   digitalWrite(HTR, Heater_state);  
   digitalWrite(CLPD, Ef_state);
   //Serial.print("suhu dibawah : timer1-3");
   }
   if(timer1>=4&&timer1<=7)
   {
   kp1_state=1;
   kp2_state=0;
   kp3_state=1;
   Heater_state=1;
   Ef_state=0; 
   digitalWrite(EF1, kp1_state);  
   digitalWrite(EF2, kp2_state);    
   digitalWrite(EF3, kp3_state);  
   digitalWrite(HTR, Heater_state);  
   digitalWrite(CLPD, Ef_state);
   //Serial.print("suhu dibawah : timer4-7");

  
   }
   if(timer1>=8&&timer1<=12)
   { 
   kp1_state=0;
   kp2_state=0;
   kp3_state=0;
   Heater_state=1;
   Ef_state=0; 
   digitalWrite(EF1, kp1_state);  
   digitalWrite(EF2, kp2_state);    
   digitalWrite(EF3, kp3_state);  
   digitalWrite(HTR, Heater_state);  
   digitalWrite(CLPD, Ef_state);
 
  //Serial.print("suhu dibawah : timer8-12");

   }
   if(timer1>=13){
       timer1=0;}
  }
  break;

  case 2:
if(average_suhu>setpoint_suhu&&average_suhu<(setpoint_suhu+8))
  {
   if(timer1>=0&&timer1<=6)
   { 
   kp1_state=1;
   kp2_state=1;
   kp3_state=1;
   Heater_state=0;
   Ef_state=1; 
   digitalWrite(EF1, kp1_state);  
   digitalWrite(EF2, kp2_state);    
   digitalWrite(EF3, kp3_state);  
   digitalWrite(HTR, Heater_state);  
   digitalWrite(CLPD, Ef_state);
   //set_nilai_aktuator();
   }
   if(timer1>6&&timer1<=12)
   { 
   kp1_state=0;
   kp2_state=1;
   kp3_state=0;
   Heater_state=0;
   Ef_state=1; 
   digitalWrite(EF1, kp1_state);  
   digitalWrite(EF2, kp2_state);    
   digitalWrite(EF3, kp3_state);  
   digitalWrite(HTR, Heater_state);  
   digitalWrite(CLPD, Ef_state);
   //set_nilai_aktuator();

   }
      if(timer1>=13){
       timer1=0;}  
  }
  else if(average_suhu<setpoint_suhu&&average_suhu>(setpoint_suhu-5))
  {
 if(timer1>=0&&timer1<=6)
   { 
   kp1_state=0;
   kp2_state=1;
   kp3_state=0;
   Heater_state=1;
   Ef_state=0; 
   digitalWrite(EF1, kp1_state);  
   digitalWrite(EF2, kp2_state);    
   digitalWrite(EF3, kp3_state);  
   digitalWrite(HTR, Heater_state);  
   digitalWrite(CLPD, Ef_state);
   //set_nilai_aktuator();
   }
   if(timer1>6&&timer1<=12)
   { 
   kp1_state=1;
   kp2_state=0;
   kp3_state=1;
   Heater_state=1;
   Ef_state=0; 
   digitalWrite(EF1, kp1_state);  
   digitalWrite(EF2, kp2_state);    
   digitalWrite(EF3, kp3_state);  
   digitalWrite(HTR, Heater_state);  
   digitalWrite(CLPD, Ef_state);
   //set_nilai_aktuator();

   }
      if(timer1>=13){
       timer1=0;}  
  }
  break;
}
}



void algoritma_save()
{
  switch(save_state)
  {
  case 0 :
  if(IdSave==1)
  {
    save_state=1;
  }
  break;
  
  case 1 :
  
  counter_save();
  if(jadwal2==20||jadwal2==40)
  {
  Data_Logger();
  }

  
  
  if(timer2==count_save || IdSave==0)
  {
    timer2=0; 
    count_save=0;
    tampil_save();
    IdSave=0;
    IdSave1.setValue(IdSave);
    save_state=0;
  } 
  break;
  }
}
