#define hooper1 37
#define line1 33
#define motor1 35

bool line, hooper;


void init_feeder()
{
  pinMode(hooper1, OUTPUT);
  pinMode(line1, OUTPUT);
  pinMode(motor1, OUTPUT);

  digitalWrite(hooper1, hooper);
  digitalWrite(line, line);
  digitalWrite(motor1, LOW);

}


void baca_sensor_proximity()
{
 line =digitalRead(line1);
 hooper =digitalRead(hooper1);  
}

void actuator_motor()
{
  digitalWrite(motor1, Feeder1_state);
}
void algoritma_feeder()
{
  switch(IdFeed){
  case 0:

  break;
  
  case 1:
  //otomatis
  baca_sensor_proximity();
  actuator_motor();
  break;
    
  }
}
