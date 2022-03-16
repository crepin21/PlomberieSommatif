/*
  Titre      : Systeme de plomberie
  Auteur     : Crepin Vardin Fouelefack
  Date       : 16/03/2022
  Description: Lorsqu'il y a contact sur le detecteur de conductivite la led s'allume et l'etat est envoye sur ThingsBoard
  Version    : 0.0.1
*/



 #include <Arduino.h>
//#include "WIFIConnector_MKR1000.h"
//#include "MQTTConnector.h"
//#include "wifiStatus.h"
const int TouchPin          = 1;
volatile int EtatPompe      = 0;
volatile int EtatTouchPin   = 0;
//int PreviousCounter         = 0;
int LedPin                  = 2;
//int BoutonValue             = 0;

void alert(){
    digitalWrite(LedPin, HIGH);
    EtatPompe = 1;
    EtatTouchPin = 1;
}

void setup() {
 Serial.begin(9600);              //
 // wifiConnect();                  //Branchement au réseau WIFI
  //MQTTConnect();                  //Branchement au broker MQTT

  pinMode(TouchPin, INPUT);
   pinMode(LedPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(TouchPin), alert, HIGH );
  
}


// Boucle infinie qui permet au uC de faire une ou plusieurs taches sans arrêt

void loop() {
    
    digitalWrite(LedPin, LOW); 
    EtatPompe = 0;            
   // appendPayload("AlertPompe", EtatPompe);  //Ajout de la valeur de la broche A1 au message MQTT
    //sendPayload();                                   //Envoie du message via le protocole MQTT

}
