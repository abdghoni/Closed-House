void INIT_ACT(){
  
pinMode(EF1, OUTPUT);
pinMode(EF2, OUTPUT);
pinMode(EF3, OUTPUT);
pinMode(HTR, OUTPUT);
pinMode(CLPD, OUTPUT);

digitalWrite(EF1, LOW);
digitalWrite(EF2, LOW);
digitalWrite(EF3, LOW);
digitalWrite(HTR, LOW);
digitalWrite(CLPD, LOW);
}



void kp1OnPushCallback(void *ptr)
{
  

delay(50);
counter[0]+=1;
if(counter[0]%2==0){kp1_state=1;}
else {kp1_state=0;}
Kipas1.setValue(kp1_state);


}



void kp2OnPushCallback(void *ptr)
{

delay(50);
counter[1]+=1;
if(counter[1]%2==0)
{kp2_state=1;}
else {kp2_state=0;}
Kipas2.setValue(kp2_state); 


}

void kp3OnPushCallback(void *ptr)
{

delay(50);
counter[2]+=1;
if(counter[2]%2==0)
{kp3_state=1;}
else {kp3_state=0;}
Kipas3.setValue(kp3_state);

}


void HeaterOnPushCallback(void *ptr)
{

delay(50);
counter[3]+=1;
if(counter[3]%2==0){Heater_state=1;}
else {Heater_state=0;}

Heater.setValue(Heater_state);

}

void EfOnPushCallback(void *ptr)
{

delay(50);
counter[4]+=1;
if(counter[4]%2==0){Ef_state=1;}
else {Ef_state=0;}
Colpad.setValue(Ef_state);

}

void Feeder1OnPushCallback(void *ptr)
{
delay(50);
counter[5]+=1;
if(counter[5]%2==0){Feeder1_state=1;}
else {Feeder1_state=0;}
Feed1.setValue(Feeder1_state);

}

void Feeder2OnPushCallback(void *ptr)
{
delay(50);
counter[6]+=1;
if(counter[6]%2==0){Feeder2_state=1;}
else {Feeder2_state=0;}
Feed2.setValue(Feeder2_state);
}

void Feeder3OnPushCallback(void *ptr)
{
  delay(50);
counter[7]+=1;
if(counter[7]%2==0){Feeder3_state=1;}
else {Feeder3_state=0;}
Feed3.setValue(Feeder3_state);
}

void Set1OnPushCallback(void *ptr)
{
  IdMode=1;
  
  IdMode1.setValue(IdMode);
  
  kp1_state=0;
  kp2_state=0;
  kp3_state=0;
  Heater_state=0;
  Ef_state=0;
  
Kipas1.setValue(kp1_state);
Kipas2.setValue(kp2_state);
Kipas3.setValue(kp3_state);
Colpad.setValue(Ef_state);
Heater.setValue(Heater_state);

}

void Set3OnPushCallback(void *ptr)
{
 IdMode=0;
 IdMode1.setValue(IdMode);
 
    Kipas1.setValue(kp1_state);
    Kipas2.setValue(kp2_state); 
    Kipas3.setValue(kp3_state);
    Heater.setValue(Heater_state);
    Colpad.setValue(Ef_state);
    jadwal3=0;
}

void Set2OnPushCallback(void *ptr)
{
 /// IdFeed=1;
  Feeder1_state=0;
  Feeder2_state=0;
  Feeder3_state=0;
  
Feed1.setValue(Feeder1_state);
Feed2.setValue(Feeder2_state);
Feed3.setValue(Feeder3_state);

 for(int i=5; i<8; i++)
 {
 counter[i]=1;
 }
// IdFeed1.setValue(IdFeed);
}



void Set4OnPushCallback(void *ptr)
{
  IdFeed=0;
  IdFeed1.setValue(IdFeed);
  
}



void Set5OnPushCallback(void *ptr)
{
  save_state=1;
  IdSave=1;
  IdSave1.setValue(IdSave);
}


void BatalPushCallback(void *ptr)
{
  save_state=0;
  IdSave=0;
  IdSave1.setValue(IdSave);
}

void fungsi_aktuator()

{
digitalWrite(EF1, kp1_state);  
digitalWrite(EF2, kp2_state);    
digitalWrite(EF3, kp3_state);  
digitalWrite(HTR, Heater_state);  
digitalWrite(CLPD, Ef_state);  
  
  
}
