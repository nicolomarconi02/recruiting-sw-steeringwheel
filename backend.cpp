#include "backend.h"

BackEnd::BackEnd(QObject *parent) :
    QObject(parent)
{
}

// DEFINIZIONE FUNZIONI UTILIZZATE NEL FILE "main.qml" PER ACCEDERE AI VALORI DEI SENSORI
float BackEnd::valueRPM(){
    return m_valueRPM;
}
float BackEnd::valueSPEED(){
    return m_valueSPEED;
}
float BackEnd::valuePOWERLIMITER(){
    return m_valuePOWERLIMITER;
}
float BackEnd::valueBMSHVTEMP(){
    return m_valueBMSHVTEMP;
}
float BackEnd::valueBMSLVTEMP(){
    return m_valueBMSLVTEMP;
}
float BackEnd::valueINVERTERTEMP(){
    return m_valueINVERTERTEMP;
}
float BackEnd::valueMOTORTEMP(){
    return m_valueMOTORTEMP;
}
float BackEnd::valueBMSHVVOLTAGE(){
    return m_valueBMSHVVOLTAGE;
}
float BackEnd::valueBMSLVVOLTAGE(){
    return m_valueBMSLVVOLTAGE;
}
float BackEnd::valueBMSLVCURRENT(){
    return m_valueBMSLVCURRENT;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// DEFINIZIONE FUNZIONI UTILIZZATE NEL FILE "main.qml" PER ACCEDERE ALLO STATO DI UN SENSORE
QString BackEnd::stateMOTORTEMP(){
    return m_stateMOTORTEMP;
}
QString BackEnd::stateINVERTERTEMP(){
    return m_stateINVERTERTEMP;
}
QString BackEnd::stateBMSHVTEMP(){
    return m_stateBMSHVTEMP;
}
QString BackEnd::stateBMSLVTEMP(){
    return m_stateBMSLVTEMP;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// DEFINIZIONE FUNZIONI UTILIZZATE NEL FILE "backend.h" PER MEMORIZZARE I VALORI DEI SENSORI
void BackEnd::setValueRPM(const float value){

    // CONTROLLO SE IL NUOVO VALORE E' UGUALE AL VALORE GIA' MEMORIZZATO, SE SI' ALLORA ESCO DALLA FUNZIONE
    if(m_valueRPM == value)
        return;

    // CONTROLLO DEI VALORI, POWER_LIMITER UTILIZZATO COME "MARCIA": POWER_LIMITER = 0 CORRISPONDE ALLA MARCIA NEUTRA
    // SE IL NUOVO VALORE E' PIU' GRANDE DI UN CERTO VALORE CHE DIPENDE DALLA "MARCIA" ATTUALE, ESCO DALLA FUNZIONE
    if(m_valuePOWERLIMITER == 0 && m_valueRPM < value)
        return;
    if(m_valuePOWERLIMITER == 20 && value > 4000)
        return;
    if(m_valuePOWERLIMITER == 40 && value > 8000)
        return;
    if(m_valuePOWERLIMITER == 60 && value > 10000)
        return;
    if(m_valuePOWERLIMITER == 80 && value > 12000)
        return;

    // SE NESSUNA DELLE CONDIZIONI PRECEDENTI SI VERIFICA ALLORA MEMORIZZA IL VALORE DEL SENSORE E
    // NOTIFICA AL FILE "main.qml" CHE IL VALORE E' STATO CAMBIATO
    m_valueRPM = value;
    emit valueRPMChanged();
}
void BackEnd::setValueSPEED(const float value){

    // CONTROLLO SE IL NUOVO VALORE E' UGUALE AL VALORE GIA' MEMORIZZATO, SE SI' ALLORA ESCO DALLA FUNZIONE
    if(m_valueSPEED == value)
        return;

    // CONTROLLO DEI VALORI, POWER_LIMITER UTILIZZATO COME "MARCIA": POWER_LIMITER = 0 CORRISPONDE ALLA MARCIA NEUTRA
    // SE IL NUOVO VALORE E' PIU' GRANDE DI UN CERTO VALORE CHE DIPENDE DALLA "MARCIA" ATTUALE, ESCO DALLA FUNZIONE
    if(m_valuePOWERLIMITER == 0 && m_valueSPEED < value)
        return;
    if(m_valuePOWERLIMITER == 20 && value > 40)
        return;
    if(m_valuePOWERLIMITER == 40 && value > 60)
        return;
    if(m_valuePOWERLIMITER == 60 && value > 80)
        return;
    if(m_valuePOWERLIMITER == 80 && value > 100)
        return;

    // SE NESSUNA DELLE CONDIZIONI PRECEDENTI SI VERIFICA ALLORA MEMORIZZA IL VALORE DEL SENSORE E
    // NOTIFICA AL FILE "main.qml" CHE IL VALORE E' STATO CAMBIATO
    m_valueSPEED = value;
    emit valueSPEEDChanged();
}
void BackEnd::setValuePOWERLIMITER(const float value){

    // CONTROLLO SE IL NUOVO VALORE E' UGUALE AL VALORE GIA' MEMORIZZATO, SE SI' ALLORA ESCO DALLA FUNZIONE
    if(m_valuePOWERLIMITER == value)
        return;

    // SE NESSUNA DELLE CONDIZIONI PRECEDENTI SI VERIFICA ALLORA MEMORIZZA IL VALORE DEL SENSORE, MOLTIPLICALO PER 100 PER OTTENERE IL FORMATO "val%"
    // E NOTIFICA AL FILE "main.qml" CHE IL VALORE E' STATO CAMBIATO
    m_valuePOWERLIMITER = value * 100;
    emit valuePOWERLIMITERChanged();
}
void BackEnd::setValueBMSHVTEMP(const float value){

    // CONTROLLO SE IL NUOVO VALORE E' UGUALE AL VALORE GIA' MEMORIZZATO, SE SI' ALLORA ESCO DALLA FUNZIONE
    if(m_valueBMSHVTEMP == value)
        return;

    // SE NESSUNA DELLE CONDIZIONI PRECEDENTI SI VERIFICA ALLORA MEMORIZZA IL VALORE DEL SENSORE,
    // IMPOSTA LO STATO DEL SENSORE DI TEMPERATURA E
    // NOTIFICA AL FILE "main.qml" CHE IL VALORE E' STATO CAMBIATO
    m_valueBMSHVTEMP = value;
    setStateBMSHVTEMP(m_stateBMSHVTEMP);
    emit valueBMSHVTEMPChanged();
}
void BackEnd::setValueBMSLVTEMP(const float value){

    // CONTROLLO SE IL NUOVO VALORE E' UGUALE AL VALORE GIA' MEMORIZZATO, SE SI' ALLORA ESCO DALLA FUNZIONE
    if(m_valueBMSLVTEMP == value)
        return;

    // SE NESSUNA DELLE CONDIZIONI PRECEDENTI SI VERIFICA ALLORA MEMORIZZA IL VALORE DEL SENSORE,
    // IMPOSTA LO STATO DEL SENSORE DI TEMPERATURA E
    // NOTIFICA AL FILE "main.qml" CHE IL VALORE E' STATO CAMBIATO
    m_valueBMSLVTEMP = value;
    setStateBMSLVTEMP(m_stateBMSLVTEMP);
    emit valueBMSLVTEMPChanged();
}
void BackEnd::setValueINVERTERTEMP(const float value){

    // CONTROLLO SE IL NUOVO VALORE E' UGUALE AL VALORE GIA' MEMORIZZATO, SE SI' ALLORA ESCO DALLA FUNZIONE
    if(m_valueINVERTERTEMP == value)
        return;

    // SE NESSUNA DELLE CONDIZIONI PRECEDENTI SI VERIFICA ALLORA MEMORIZZA IL VALORE DEL SENSORE,
    // IMPOSTA LO STATO DEL SENSORE DI TEMPERATURA E
    // NOTIFICA AL FILE "main.qml" CHE IL VALORE E' STATO CAMBIATO
    m_valueINVERTERTEMP = value;
    setStateINVERTERTEMP(m_stateINVERTERTEMP);
    emit valueINVERTERTEMPChanged();
}
void BackEnd::setValueMOTORTEMP(const float value){

    // CONTROLLO SE IL NUOVO VALORE E' UGUALE AL VALORE GIA' MEMORIZZATO, SE SI' ALLORA ESCO DALLA FUNZIONE
    if(m_valueMOTORTEMP == value)
        return;

    // SE NESSUNA DELLE CONDIZIONI PRECEDENTI SI VERIFICA ALLORA MEMORIZZA IL VALORE DEL SENSORE,
    // IMPOSTA LO STATO DEL SENSORE DI TEMPERATURA E
    // NOTIFICA AL FILE "main.qml" CHE IL VALORE E' STATO CAMBIATO
    m_valueMOTORTEMP = value;
    setStateMOTORTEMP(m_stateMOTORTEMP);
    emit valueMOTORTEMPChanged();
}
void BackEnd::setValueBMSHVVOLTAGE(const float value){

    // CONTROLLO SE IL NUOVO VALORE E' UGUALE AL VALORE GIA' MEMORIZZATO, SE SI' ALLORA ESCO DALLA FUNZIONE
    if(m_valueBMSHVVOLTAGE == value)
        return;

    // SE NESSUNA DELLE CONDIZIONI PRECEDENTI SI VERIFICA ALLORA MEMORIZZA IL VALORE DEL SENSORE E
    // NOTIFICA AL FILE "main.qml" CHE IL VALORE E' STATO CAMBIATO
    m_valueBMSHVVOLTAGE = value;
    emit valueBMSHVVOLTAGEChanged();
}
void BackEnd::setValueBMSLVVOLTAGE(const float value){

    // CONTROLLO SE IL NUOVO VALORE E' UGUALE AL VALORE GIA' MEMORIZZATO, SE SI' ALLORA ESCO DALLA FUNZIONE
    if(m_valueBMSLVVOLTAGE == value)
        return;

    // SE NESSUNA DELLE CONDIZIONI PRECEDENTI SI VERIFICA ALLORA MEMORIZZA IL VALORE DEL SENSORE E
    // NOTIFICA AL FILE "main.qml" CHE IL VALORE E' STATO CAMBIATO
    m_valueBMSLVVOLTAGE = value;
    emit valueBMSLVVOLTAGEChanged();
}
void BackEnd::setValueBMSLVCURRENT(const float value){

    // CONTROLLO SE IL NUOVO VALORE E' UGUALE AL VALORE GIA' MEMORIZZATO, SE SI' ALLORA ESCO DALLA FUNZIONE
    if(m_valueBMSLVCURRENT == value)
        return;

    // SE NESSUNA DELLE CONDIZIONI PRECEDENTI SI VERIFICA ALLORA MEMORIZZA IL VALORE DEL SENSORE E
    // NOTIFICA AL FILE "main.qml" CHE IL VALORE E' STATO CAMBIATO
    m_valueBMSLVCURRENT = value;
    emit valueBMSLVCURRENTChanged();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// DEFINIZIONE FUNZIONI UTILIZZATE NEL FILE "backend.h" PER MEMORIZZARE LO STATO DEI SENSORI DI TEMPERATURA
void BackEnd::setStateMOTORTEMP(const QString s){

    // IMPOSTA IL RANGE DI VALORI CONSIDERATI A "NORMA" E CALCOLA L'INCREMENTO CON 7 RANGE NON CRITICI
    float min = 20; float max = 80;
    float increment = (max - min) / 7.0f;

    // PRIMO RANGE, CRITICO
    if(m_valueMOTORTEMP < min){
        m_stateMOTORTEMP = "criticalBlueState";
    }

    // SECONDO RANGE, NORMALE
    else if((m_valueMOTORTEMP > min && m_valueMOTORTEMP <= (min + increment))){
        m_stateMOTORTEMP = "lightBlueState";
    }

    // TERZO RANGE, NORMALE
    else if((m_valueMOTORTEMP > (min + increment) && m_valueMOTORTEMP <= (min + 2*increment))){
        m_stateMOTORTEMP = "azureState";
    }

    // QUARTO RANGE, NORMALE
    else if((m_valueMOTORTEMP > (min + 2*increment) && m_valueMOTORTEMP <= (min + 3*increment))){
        m_stateMOTORTEMP = "greenBlueState";
    }

    // QUINTO RANGE, CONDIZIONI OTTIMALI
    else if(m_valueMOTORTEMP > (min + 3*increment) && m_valueMOTORTEMP <= (max - 3*increment)){
        m_stateMOTORTEMP = "blackState";
    }

    // SESTO RANGE, NORMALE
    else if((m_valueMOTORTEMP > (max - 3*increment) && m_valueMOTORTEMP <= (max - 2*increment))){
        m_stateMOTORTEMP = "greenYellowState";
    }

    // SETTIMO RANGE, NORMALE
    else if((m_valueMOTORTEMP > (max - 2*increment) && m_valueMOTORTEMP <= (max - increment))){
        m_stateMOTORTEMP = "goldState";
    }

    // OTTAVO RANGE, NORMALE
    else if((m_valueMOTORTEMP > (max - increment) && m_valueMOTORTEMP <= max)){
        m_stateMOTORTEMP = "orangeState";
    }

    // NONO RANGE, CRITICO
    else if(m_valueMOTORTEMP > max){
        m_stateMOTORTEMP = "criticalRedState";
    }

    // SE CAMBIA LO STATO DEL SENSORE DI TEMPERATURA ALLORA NOTIFICA AL FILE "main.qml" CHE LO STATO E' CAMBIATO
    if(m_stateMOTORTEMP != s)
        emit stateMOTORTEMPChanged();
}

void BackEnd::setStateINVERTERTEMP(const QString s){

    // IMPOSTA IL RANGE DI VALORI CONSIDERATI A "NORMA" E CALCOLA L'INCREMENTO CON 7 RANGE NON CRITICI
    float min = 20; float max = 70;
    float increment = (max - min) / 7.0f;

     // PRIMO RANGE, CRITICO
    if(m_valueINVERTERTEMP < min){
        m_stateINVERTERTEMP = "criticalBlueState";
    }

    // SECONDO RANGE, NORMALE
    else if((m_valueINVERTERTEMP > min && m_valueINVERTERTEMP <= (min + increment))){
        m_stateINVERTERTEMP = "lightBlueState";
    }

    // TERZO RANGE, NORMALE
    else if((m_valueINVERTERTEMP > (min + increment) && m_valueINVERTERTEMP <= (min + 2*increment))){
        m_stateINVERTERTEMP = "azureState";
    }

    // QUARTO RANGE, NORMALE
    else if((m_valueINVERTERTEMP > (min + 2*increment) && m_valueINVERTERTEMP <= (min + 3*increment))){
        m_stateINVERTERTEMP = "greenBlueState";
    }

    // QUINTO RANGE, CONDIZIONI OTTIMALI
    else if(m_valueINVERTERTEMP > (min + 3*increment) && m_valueINVERTERTEMP <= (max - 3*increment)){
        m_stateINVERTERTEMP = "blackState";
    }

    // SESTO RANGE, NORMALE
    else if((m_valueINVERTERTEMP > (max - 3*increment) && m_valueINVERTERTEMP <= (max - 2*increment))){
        m_stateINVERTERTEMP = "greenYellowState";
    }

    // SETTIMO RANGE, NORMALE
    else if((m_valueINVERTERTEMP > (max - 2*increment) && m_valueINVERTERTEMP <= (max - increment))){
        m_stateINVERTERTEMP = "goldState";
    }

    // OTTAVO RANGE, NORMALE
    else if((m_valueINVERTERTEMP > (max - increment) && m_valueINVERTERTEMP <= max)){
        m_stateINVERTERTEMP = "orangeState";
    }

    // NONO RANGE, CRITICO
    else if(m_valueINVERTERTEMP > max){
        m_stateINVERTERTEMP = "criticalRedState";
    }

    // SE CAMBIA LO STATO DEL SENSORE DI TEMPERATURA ALLORA NOTIFICA AL FILE "main.qml" CHE LO STATO E' CAMBIATO
    if(m_stateINVERTERTEMP != s)
        emit stateINVERTERTEMPChanged();
}

void BackEnd::setStateBMSHVTEMP(const QString s){

    // IMPOSTA IL RANGE DI VALORI CONSIDERATI A "NORMA" E CALCOLA L'INCREMENTO CON 7 RANGE NON CRITICI
    float min = 20; float max = 40;
    float increment = (max - min) / 7.0f;

     // PRIMO RANGE, CRITICO
    if(m_valueBMSHVTEMP < min){
        m_stateBMSHVTEMP = "criticalBlueState";
    }

    // SECONDO RANGE, NORMALE
    else if((m_valueBMSHVTEMP > min && m_valueBMSHVTEMP <= (min + increment))){
        m_stateBMSHVTEMP = "lightBlueState";
    }

    // TERZO RANGE, NORMALE
    else if((m_valueBMSHVTEMP > (min + increment) && m_valueBMSHVTEMP <= (min + 2*increment))){
        m_stateBMSHVTEMP = "azureState";
    }

    // QUARTO RANGE, NORMALE
    else if((m_valueBMSHVTEMP > (min + 2*increment) && m_valueBMSHVTEMP <= (min + 3*increment))){
        m_stateBMSHVTEMP = "greenBlueState";
    }

    // QUINTO RANGE, CONDIZIONI OTTIMALI
    else if(m_valueBMSHVTEMP > (min + 3*increment) && m_valueBMSHVTEMP <= (max - 3*increment)){
        m_stateBMSHVTEMP = "blackState";
    }

    // SESTO RANGE, NORMALE
    else if((m_valueBMSHVTEMP > (max - 3*increment) && m_valueBMSHVTEMP <= (max - 2*increment))){
        m_stateBMSHVTEMP = "greenYellowState";
    }

    // SETTIMO RANGE, NORMALE
    else if((m_valueBMSHVTEMP > (max - 2*increment) && m_valueBMSHVTEMP <= (max - increment))){
        m_stateBMSHVTEMP = "goldState";
    }

    // OTTAVO RANGE, NORMALE
    else if((m_valueBMSHVTEMP > (max - increment) && m_valueBMSHVTEMP <= max)){
        m_stateBMSHVTEMP = "orangeState";
    }

    // NONO RANGE, CRITICO
    else if(m_valueBMSHVTEMP > max){
        m_stateBMSHVTEMP = "criticalRedState";
    }

    // SE CAMBIA LO STATO DEL SENSORE DI TEMPERATURA ALLORA NOTIFICA AL FILE "main.qml" CHE LO STATO E' CAMBIATO
    if(m_stateBMSHVTEMP != s)
        emit stateBMSHVTEMPChanged();
}

void BackEnd::setStateBMSLVTEMP(const QString s){

    // IMPOSTA IL RANGE DI VALORI CONSIDERATI A "NORMA" E CALCOLA L'INCREMENTO CON 7 RANGE NON CRITICI
    float min = 20; float max = 50;
    float increment = (max - min) / 7.0f;

     // PRIMO RANGE, CRITICO
    if(m_valueBMSLVTEMP < min){
        m_stateBMSLVTEMP = "criticalBlueState";
    }

    // SECONDO RANGE, NORMALE
    else if((m_valueBMSLVTEMP > min && m_valueBMSLVTEMP <= (min + increment))){
        m_stateBMSLVTEMP = "lightBlueState";
    }

    // TERZO RANGE, NORMALE
    else if((m_valueBMSLVTEMP > (min + increment) && m_valueBMSLVTEMP <= (min + 2*increment))){
        m_stateBMSLVTEMP = "azureState";
    }

    // QUARTO RANGE, NORMALE
    else if((m_valueBMSLVTEMP > (min + 2*increment) && m_valueBMSLVTEMP <= (min + 3*increment))){
        m_stateBMSLVTEMP = "greenBlueState";
    }

    // QUINTO RANGE, CONDIZIONI OTTIMALI
    else if(m_valueBMSLVTEMP > (min + 3*increment) && m_valueBMSLVTEMP <= (max - 3*increment)){
        m_stateBMSLVTEMP = "blackState";
    }

    // SESTO RANGE, NORMALE
    else if((m_valueBMSLVTEMP > (max - 3*increment) && m_valueBMSLVTEMP <= (max - 2*increment))){
        m_stateBMSLVTEMP = "greenYellowState";
    }

    // SETTIMO RANGE, NORMALE
    else if((m_valueBMSLVTEMP > (max - 2*increment) && m_valueBMSLVTEMP <= (max - increment))){
        m_stateBMSLVTEMP = "goldState";
    }

    // OTTAVO RANGE, NORMALE
    else if((m_valueBMSLVTEMP > (max - increment) && m_valueBMSLVTEMP <= max)){
        m_stateBMSLVTEMP = "orangeState";
    }

    // NONO RANGE, CRITICO
    else if(m_valueBMSLVTEMP > max){
        m_stateBMSLVTEMP = "criticalRedState";
    }

    // SE CAMBIA LO STATO DEL SENSORE DI TEMPERATURA ALLORA NOTIFICA AL FILE "main.qml" CHE LO STATO E' CAMBIATO
    if(m_stateBMSLVTEMP != s)
        emit stateBMSLVTEMPChanged();
}
