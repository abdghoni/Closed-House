void kirim_semua()
{
data_out.data_suhu=(average_suhu*10);
data_out.data_kelembaban=(average_humadity*10);
data_out.data_amoniak=(average_ppm*10);
data_out.data_setpoint=(setpoint_suhu*10);
data_out.data_hari=hariKe;
data_out.data_sync=sync_state;
data_out.data_mode=mode_state;
data_out.data_kipas1=kp1_state;
data_out.data_kipas2=kp2_state;
data_out.data_kipas3=kp3_state;
data_out.data_heater=Heater_state;
data_out.data_colpad=Ef_state;  
data_keluar.sendData();  
}
