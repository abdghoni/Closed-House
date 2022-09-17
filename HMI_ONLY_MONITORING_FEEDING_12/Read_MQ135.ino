 void hitung_amoniak(){
  
   VRL = (analogRead(mq135))*(4.37/1023.0);
   RS =(4.37/VRL-1)*10 ;//rumus untuk RS 
   ratio =RS/Ro;
   ppm=pow(10, ((log10(ratio)-b)/m)); 


     total_ppm=ppm;
     average_ppm=total_ppm;
     }
