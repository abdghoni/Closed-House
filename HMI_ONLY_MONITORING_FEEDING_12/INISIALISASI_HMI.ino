void init_HMI()
{

home.attachPush(homePushCallback, &home);

  manualMonitorA.attachPush(manualMonitorAPushCallback, &manualMonitorA);
  otoMonitorA.attachPush(otoMonitorAPushCallback, &otoMonitorA);
  manualFeederA.attachPush(manualFeederAPushCallback, &manualFeederA);
  otoFeederA.attachPush(otoFeederAPushCallback, &otoFeederA);
  view.attachPush(viewPushCallback, &view);
  mntrBroilerA.attachPush(mntrBroilerAPushCallback, &mntrBroilerA);
  mntrFeederA.attachPush(mntrFeederAPushCallback, &mntrFeederA);
  save.attachPush(savePushCallback, &save); 

  HeaterOn.attachPush(HeaterOnPushCallback, &HeaterOn);
  kp1On.attachPush(kp1OnPushCallback, &kp1On);  
  kp2On.attachPush(kp2OnPushCallback, &kp2On);
  kp3On.attachPush(kp3OnPushCallback, &kp3On);
  EfOn.attachPush(EfOnPushCallback, &EfOn);
  
  Set1On.attachPush(Set1OnPushCallback, &Set1On);
  Set2On.attachPush(Set2OnPushCallback, &Set2On);

  Set3On.attachPush(Set3OnPushCallback, &Set3On);
  Set4On.attachPush(Set4OnPushCallback, &Set4On);

  Set5On.attachPush(Set5OnPushCallback, &Set5On);
  Batal.attachPush(BatalPushCallback, &Batal);
  
  Feeder1On.attachPush(Feeder1OnPushCallback, &Feeder1On);  
  Feeder2On.attachPush(Feeder2OnPushCallback, &Feeder2On);
  Feeder3On.attachPush(Feeder3OnPushCallback, &Feeder3On);

  plsb11.attachPush(plsb11PushCallback, &plsb11);
  minb12.attachPush(minb12PushCallback, &minb12);


  plsb21.attachPush(plsb21PushCallback, &plsb21);
  minb22.attachPush(minb22PushCallback, &minb22);


}
