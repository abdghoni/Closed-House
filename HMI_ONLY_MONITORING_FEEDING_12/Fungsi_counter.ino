
void scheduling()
{
 uint32_t tsLastReport = 0;
 if (millis() - tsLastReport > REPORTING_PERIOD_MS) 
 {
 jadwal3+=1;
 jadwal1+=1;
 hitung_umur_ayam();
 Fase_ayam();
 algoritma_utama();
 algoritma_save();
 
 kirim_semua();
 tsLastReport = millis();
 wdt_reset();
 }

 
}
