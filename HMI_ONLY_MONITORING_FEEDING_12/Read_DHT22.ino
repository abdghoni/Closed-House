
//---------------DHT22----------
   
void counter_suhu_kelembaban()
{
 uint32_t tsLastReport = 0;
 if (millis() - tsLastReport > REPORTING_PERIOD_MS_1) 
 {
  count_dht22+=1;

  tsLastReport = millis();
 }
}




void hitung_suhu_kelembaban()
{
    if(count_dht22==2){
    humadity[0] =(dht1.readHumidity());
    suhu[0]=    (dht1.readTemperature());
    }
    else if(count_dht22==4){
    humadity[1] = (dht2.readHumidity());
    suhu[1]= (dht2.readTemperature());
    }
    else if(count_dht22==6){
    humadity[3] =(dht4.readHumidity());
    suhu[3]= (dht4.readTemperature());
    }
    else if(count_dht22==8){
    humadity[4] =(dht5.readHumidity());
    suhu[4]= (dht5.readTemperature());
    }

    else if(count_dht22>=10&&count_dht22<20)
    {

   
  if (isnan(humadity[0]) || isnan(suhu[0]) ) 
  {
    
   total_suhu=suhu[1]+suhu[3]+suhu[4];
   total_humadity=humadity[1]+humadity[3]+humadity[4];
      
    average_suhu=(total_suhu/3);
    average_humadity=(total_humadity/3);
  }

  else if (isnan(humadity[1]) || isnan(suhu[1]) )
  {
    
   total_suhu=suhu[0]+suhu[3]+suhu[4];
   total_humadity=humadity[0]+humadity[3]+humadity[4];
      
    average_suhu=(total_suhu/3);
    average_humadity=(total_humadity/3);
  }

  else if (isnan(humadity[3]) || isnan(suhu[3]) ) 
  {
    
   total_suhu=suhu[1]+suhu[0]+suhu[4];
   total_humadity=humadity[1]+humadity[0]+humadity[4];
      
    average_suhu=(total_suhu/3);
    average_humadity=(total_humadity/3);
  }

  else if (isnan(humadity[4]) || isnan(suhu[4]) ) 
  {
    
   total_suhu=suhu[1]+suhu[3]+suhu[0];
   total_humadity=humadity[1]+humadity[3]+humadity[0];
      
    average_suhu=(total_suhu/3);
    average_humadity=(total_humadity/3);
  }


   else if (isnan(humadity[0]) || isnan(suhu[0]) || isnan(humadity[1]) || isnan(suhu[1]) ) 
   {
    
   total_suhu=suhu[3]+suhu[4];
   total_humadity=humadity[3]+humadity[4];
      
    average_suhu=(total_suhu/2);
    average_humadity=(total_humadity/2);
  }

  else if (isnan(humadity[0]) || isnan(suhu[0]) || isnan(humadity[3]) || isnan(suhu[3]) ) {
    
   total_suhu=suhu[1]+suhu[4];
   total_humadity=humadity[1]+humadity[4];
      
    average_suhu=(total_suhu/2);
    average_humadity=(total_humadity/2);
  }

   else if (isnan(humadity[0]) || isnan(suhu[0]) || isnan(humadity[4]) || isnan(suhu[4]) ) {
    
   total_suhu=suhu[1]+suhu[3];
   total_humadity=humadity[3]+humadity[1];
      
    average_suhu=(total_suhu/2);
    average_humadity=(total_humadity/2);
  }

  else if (isnan(humadity[1]) || isnan(suhu[1]) || isnan(humadity[3]) || isnan(suhu[3]) ) {
    
   total_suhu=suhu[0]+suhu[4];
   total_humadity=humadity[4]+humadity[0];
      
    average_suhu=(total_suhu/2);
    average_humadity=(total_humadity/2);
  }

   else if (isnan(humadity[1]) || isnan(suhu[1]) || isnan(humadity[4]) || isnan(suhu[4]) ) {
    
   total_suhu=suhu[0]+suhu[3];
   total_humadity=humadity[0]+humadity[3];
      
    average_suhu=(total_suhu/2);
    average_humadity=(total_humadity/2);
  }

   else if (isnan(humadity[3]) || isnan(suhu[3]) || isnan(humadity[4]) || isnan(suhu[4]) ) {
    
   total_suhu=suhu[0]+suhu[1];
   total_humadity=humadity[0]+humadity[1];
      
    average_suhu=(total_suhu/2);
    average_humadity=(total_humadity/2);
  }

  
   else if (isnan(humadity[0]) || isnan(suhu[0]) || isnan(humadity[1]) || isnan(suhu[1])|| isnan(humadity[3]) || isnan(suhu[3]) ) {
    
   total_suhu=suhu[4];
   total_humadity=humadity[4];
      
    average_suhu=(total_suhu);
    average_humadity=(total_humadity);
  }

   else if (isnan(humadity[0]) || isnan(suhu[0]) || isnan(humadity[1]) || isnan(suhu[1])|| isnan(humadity[4]) || isnan(suhu[4]) ) {
    
   total_suhu=suhu[3];
   total_humadity=humadity[3];
      
    average_suhu=(total_suhu);
    average_humadity=(total_humadity);
  }

   else if (isnan(humadity[0]) || isnan(suhu[0]) || isnan(humadity[4]) || isnan(suhu[4])|| isnan(humadity[3]) || isnan(suhu[3]) ) {
    
   total_suhu=suhu[1];
   total_humadity=humadity[1];
      
    average_suhu=(total_suhu);
    average_humadity=(total_humadity);
  }
   else if (isnan(humadity[4]) || isnan(suhu[4]) || isnan(humadity[1]) || isnan(suhu[1])|| isnan(humadity[3]) || isnan(suhu[3]) ) 
   {
    
   total_suhu=suhu[0];
   total_humadity=humadity[0];
      
    average_suhu=(total_suhu);
    average_humadity=(total_humadity);
  }
  
  else
  {
    
   total_suhu=suhu[0]+suhu[1]+suhu[3]+suhu[4];
   total_humadity=humadity[0]+humadity[1]+humadity[3]+humadity[4];
      
    average_suhu=(total_suhu/4);
    average_humadity=(total_humadity/4);
  }
  
    }
    else if(count_dht22==20)
    {
      count_dht22=0;
      }
}
