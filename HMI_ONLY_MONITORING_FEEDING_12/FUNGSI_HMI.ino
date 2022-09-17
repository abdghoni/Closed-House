void homePushCallback(void *ptr)  
{
  CurrentPage=0;
   
}  

void manualMonitorAPushCallback(void *ptr)  
{
  CurrentPage=1; 
}  



void otoMonitorAPushCallback(void *ptr)  
{
  CurrentPage=2; 
}




void manualFeederAPushCallback(void *ptr)  
{
  CurrentPage=3; 
}  



void otoFeederAPushCallback(void *ptr)  
{
  CurrentPage=4; 
}  

  


void viewPushCallback(void *ptr)  
{
  CurrentPage=5 ; 
}


void mntrBroilerAPushCallback(void *ptr)  
{
  CurrentPage=6; 
}

void mntrFeederAPushCallback(void *ptr)  
{
  CurrentPage=7; 
}


void savePushCallback(void *ptr)  
{
  CurrentPage=8; 
}


void plsb11PushCallback(void *ptr) {
  count_suhu1+=1;
  tampil_setpoint();
}
void minb12PushCallback(void *ptr) {
  count_suhu1-=1;
  tampil_setpoint();
}



void plsb21PushCallback(void *ptr) {
count_save+=1;
tampil_save();
}
void minb22PushCallback(void *ptr) {
count_save-=1;
tampil_save();
}
