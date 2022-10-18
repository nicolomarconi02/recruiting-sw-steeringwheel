PROGETTO RECRUITING-SW-STEERINGWHEEL

OBIETTIVO
  Creare un'interfaccia grafica di un volante di una vettura da corsa che includesse i sensori: 
    - RPM
    - SPEED
    - BMS HV VOLTAGE
    - BMS HV TEMPERATURE
    - BMS LV VOLTAGE
    - BMS LV TEMPERATURE
    - BMS LV CURRENT
    - MOTOR TEMPERATURE
    - INVERTER TEMPERATURE
    - POWER LIMITER

INTERFACCIA VOLANTE
  Quando si avvia l'applicazione viene visualizzata una griglia 3x3 e ogni cella rappresenta un sensore.
  
  Nella scelta di come comporre la griglia si è data più importanza ai valori del sensore BMS_HV_VOLTAGE e del BMS_HV_TEMP, che rappresentano la carica restante del veicolo e la temperatura delle celle delle batterie, dal momento che il software del volante è stato pensato per una vettura con motore elettrico.

  Nella prima colonna vengono rappresentati i valori dei sensori di temperatura, rispettivamente MOTOR_TEMP, BMS_LV_TEMP e INVERTER_TEMP, i quali cambiano di stato in base al valore del sensore:
    - blu con testo giallo e sottolineato --> stato critico (temperatura troppo bassa)
    - blu chiaro con testo bianco --> stato normale
    - azzurro scuro con testo bianco --> stato normale
    - verde acqua con testo bianco --> stato normale
    - nero con testo bianco --> stato con condizioni ottimali
    - verde giallognolo con testo bianco --> stato normale
    - giallo ocra con testo bianco --> stato normale
    - arancione con testo bianco --> stato normale
    - rosso con testo giallo e sottolineato --> stato critico (temperatura troppo alta)
  Gli stati dei sensori della temperatura cambiano di colore in base al valore, passando dal blu (freddo) al rosso (caldo)

  Nella seconda colonna vengono rappresentati i sensori SPEED e RPM che si trovano nella prima cella della colonna, e i sensori BMS_HV_VOLTAGE e BMS_HV_TEMP, quest'ultimo cambia di stato come i sensori di temperatura descritti precedentemente

  Nella terza colonna vengono rappresentati i sensori di POWER_LIMITER, BMS_LV_VOLTAGE e BMS_LV_CURRENT

  Per dare più continuità, a sinistra vengono rappresentati tutti i sensori di temperatura e a destra i sensori di voltaggio e corrente

INTERAZIONI TRA SENSORI
  All'avvio dell'applicazione vengono generati automaticamente tutti i valori di voltaggio e corrente perchè si è pensato che se i valori di questi sensori fossero zero, tutti gli altri sensori della vettura non potrebbero funzionare

  Il sensore POWER_LIMITER è stato pensato come una sorta di "marcia". Dal momento che un motore elettrico non dispone di una trasmissione vera e propria, e di conseguenza non dispone neanche di una scatola del cambio, il sensore POWER_LIMITER gestisce quanta potenza rilasciare dal motore. Per implementare queste assunzioni, si è pensato che il valore di POWER_LIMITER dovesse limitare i sensori SPEED e RPM, infatti:
    - valore POWER_LIMITER = 0 --> marcia neutra --> i valori dei sensori SPEED e RPM non possono aumentare, possono solo diminuire
    - valore POWER_LIMITER = 20 --> il valore del sensore SPEED non può superare il valore 40, può solo diminuire
                                --> il valore del sensore RPM non può superare il valore 4000, può solo diminuire
    - valore POWER_LIMITER = 40 --> il valore del sensore SPEED non può superare il valore 60, può solo diminuire
                                --> il valore del sensore RPM non può superare il valore 8000, può solo diminuire
    - valore POWER_LIMITER = 60 --> il valore del sensore SPEED non può superare il valore 80, può solo diminuire
                                --> il valore del sensore RPM non può superare il valore 10000, può solo diminuire
    - valore POWER_LIMITER = 80 --> il valore del sensore SPEED non può superare il valore 100, può solo diminuire
                                --> il valore del sensore RPM non può superare il valore 12000, può solo diminuire
    - valore POWER_LIMITER = 100 --> il valore del sensore SPEED può assumere tutti i valori consentiti (massimo 120 nel file "data.hpp")
                                --> il valore del sensore RPM può assumere tutti i valori consentiti (massimo 15000 nel file "data.hpp")

  Nel file "data.hpp" sono state scritte delle istruzioni per verificare direttamente la relazione tra il sensore POWER_LIMITER e i sensori SPEED e RPM