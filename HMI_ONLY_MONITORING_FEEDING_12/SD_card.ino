void Data_Logger(){
   dt = clock.getDateTime();
   File myFile = SD.open("datalog.txt", FILE_WRITE);
    if(myFile){
    myFile.print(dt.month);
    myFile.print("/");
    myFile.print(dt.day);
    myFile.print("/");
    myFile.print(dt.year);
    myFile.print(" ");
    myFile.print(dt.hour);
    myFile.print(":");
    myFile.print(dt.minute);
    myFile.print(":");
    myFile.print(dt.second);
    myFile.print("-----");
    myFile.print(" Amonia:");
    myFile.print(average_ppm);
    myFile.print(" Suhu:");
    myFile.print(average_suhu);
    myFile.print(" Kelmbaban:");
    myFile.println(average_humadity);    
    myFile.close(); 
    Serial.println("Saved"); 
    }
  }
