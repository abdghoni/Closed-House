void hitung_umur_ayam()
{
 dt = clock.getDateTime();
 day_now=dt.second;
 menit2=dt.minute;
 if(day_now!=day_last)
 {
  hariKe+=1;
  umur_ayam=hariKe;
  umur.setValue(umur_ayam);
  
 }
 day_last=day_now;


if(menit2!=last_menit2)
 {
 timer1+=1; 
 }
 last_menit2=menit2;
 
 }


 void counter_save()
 {
 dt = clock.getDateTime();
 menit1=dt.minute;
 jadwal2=dt.second; 
 if(menit1!=last_menit)
 {
 timer2+=1; 
 count_down=count_save-timer2;
 
 tampil_count_down_save();
 }
 last_menit=menit1;
 }

void Fase_ayam()
{
 if(hariKe>=0&&hariKe<=7)
 {
 fase_ayam=0;
 }
 else if (hariKe>=8&&hariKe<=14)
 {
 fase_ayam=1;
 }
 else if (hariKe>=15&&hariKe<=21)
 {
 fase_ayam=2;
 }
 else if (hariKe>=22&&hariKe<=28)
 {
 fase_ayam=3;
 }
 else if (hariKe>=29&&hariKe<=35)
 {
 fase_ayam=4;
 }
 else if (hariKe>=36&&hariKe<=42)
 {
 fase_ayam=5;
 }
 else if (hariKe>42)
{
 hariKe=0;
}
}
