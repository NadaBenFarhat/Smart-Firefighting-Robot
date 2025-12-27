#include <BluetoothSerial.h>
BluetoothSerial ESP_BT;

// Définition des pins
// Moteurs (roues ARRIÈRE)
#define GAUCHE_PLUS 27
#define GAUCHE_MOINS 26
#define DROITE_PLUS 25
#define DROITE_MOINS 33
// Capteurs de flamme (3x)
#define FLAME_LEFT 16    
#define FLAME_CENTER 17 
#define FLAME_RIGHT 4   

#define TRIG_PIN 12  // Capteur ultrason HC-SR04
#define ECHO_PIN 14

#define PUMP_PIN 23 // Pompe à eau
#define GAZ_SENSOR 22 //pin pour gaz
// Paramètres
int safe_distance = 18;    // Distance d'obstacle (cm)
int stop_distance = 12;    // Distance d'extinction (cm)
int flame_threshold = 800; // Seuil capteur flamme
int gas_threshold = 600;   // Seuil capteur gaz
int motor_speed = 200;     // PWM moteurs (0-255)

void setup() {
  Serial.begin(115200);
  ESP_BT.begin("FireFighter");

  // Configuration des pins
  pinMode(GAUCHE_PLUS, OUTPUT);
  pinMode(GAUCHE_MOINS, OUTPUT);
  pinMode(DROITE_PLUS, OUTPUT);
  pinMode(DROITE_MOINS, OUTPUT);
//GPIO34-39 sont INPUT par défaut
  pinMode(FLAME_LEFT, INPUT);
  pinMode(FLAME_CENTER, INPUT);
  pinMode(FLAME_RIGHT, INPUT);
  pinMode(GAZ_SENSOR, INPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(PUMP_PIN, OUTPUT);

  // Calibration initiale
  stopMotors();
  Serial.println("Robot initialisé");
  ESP_BT.println("STATUS:Prêt|SafeDist:" + String(safe_distance));
}

void loop() {
  // 1. Vérification gaz
  if (detectGas()) {
    ESP_BT.println("ALERTE: Gaz détecté!");
    delay(1000);
  }
  // 2. Mesure distance
  float distance = getDistance();
  // 3. Gestion priorisée
  if (distance < safe_distance && distance > 0) {
    handleObstacleWithFireCheck(distance);
  } 
  else if (detectFire()) {
    approachAndExtinguish();
  }
  else if (ESP_BT.available()) {
    handleBluetooth();
  }
  else {
    stopMotors();
  }
}

// Fonctions de mouvement 
void moveForward() {
  digitalWrite(GAUCHE_PLUS, HIGH);
  digitalWrite(GAUCHE_MOINS, LOW);
  digitalWrite(DROITE_PLUS, HIGH);
  digitalWrite(DROITE_MOINS, LOW);
}

void moveBackward() {
  digitalWrite(GAUCHE_PLUS, LOW);
  digitalWrite(GAUCHE_MOINS, HIGH);
  digitalWrite(DROITE_PLUS, LOW);
  digitalWrite(DROITE_MOINS, HIGH);
}

void turnLeft() {
  digitalWrite(GAUCHE_PLUS, LOW);
  digitalWrite(GAUCHE_MOINS, HIGH);
  digitalWrite(DROITE_PLUS, HIGH);
  digitalWrite(DROITE_MOINS, LOW);
}

void turnRight() {
  digitalWrite(GAUCHE_PLUS, HIGH);
  digitalWrite(GAUCHE_MOINS, LOW);
  digitalWrite(DROITE_PLUS, LOW);
  digitalWrite(DROITE_MOINS, HIGH);
}


void stopMotors() {
  digitalWrite(GAUCHE_PLUS, LOW);
  digitalWrite(GAUCHE_MOINS, LOW);
  digitalWrite(DROITE_PLUS, LOW);
  digitalWrite(DROITE_MOINS, LOW);
}

// Fonctions capteurs 
float getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  return  duration * 0.034 / 2;// Conversion en cm
}

bool detectFire(){
  int left = analogRead(FLAME_LEFT);
  int center = analogRead(FLAME_CENTER);
  int right = analogRead(FLAME_RIGHT);
  Serial.printf("Flammes: L=%d C=%d R=%d\n", left, center, right);
  return (left > flame_threshold  || center > flame_threshold  || right > flame_threshold);
}
bool detectGas(){
  return analogRead(GAZ_SENSOR) > gas_threshold;
}
// Fonction logique
void handleObstacleWithFireCheck(float distance) {
  if (detectFire()) {
    ESP_BT.println("FEU PROCHE:" + String(distance) + "cm");
    if (distance <= stop_distance) {
      activatePump();
    } else {
      approachFire();
    }
  } else {
    ESP_BT.println("OBSTACLE:" + String(distance) + "cm");
    avoidObstacle();
    delay(500);
    if (detectFire()) approachFire();
  }
}

void avoidObstacle() {
  moveBackward(800);
  turnRight(400);
}
void approachFire() {
  while (getDistance() > stop_distance && detectFire()) {
    moveForward(100);
    if (getDistance() < safe_distance && !detectFire()) {
      avoidObstacle();
      return;
    }
  }
  activatePump();
}
void activatePump() {
  stopMotors();
  digitalWrite(PUMP_PIN, HIGH);
  ESP_BT.println("EXTINCTION: Démarrage");
  delay(5000);
  digitalWrite(PUMP_PIN, LOW);
  ESP_BT.println("EXTINCTION: Terminé");
}
void approachAndExtinguish() {
  const unsigned long MAX_APPROACH_TIME = 15000; // 15s timeout
  const int APPROACH_STEP = 100; // Pas de 100ms
  unsigned long startTime = millis();

  ESP_BT.println("DEBUT: Approche du feu");

  while (millis() - startTime < MAX_APPROACH_TIME) {
    // 1. Vérifier la distance
    float distance = getDistance();
    if (distance <= stop_distance) {
      activatePump();
      return;
    }

    // 2. Vérifier que le feu persiste
    if (!detectFire()) {
      ESP_BT.println("INFO: Feu éteint ou disparu");
      stopMotors();
      return;
    }

    // 3. Lire les capteurs de flamme
    int left = analogRead(FLAME_LEFT);
    int center = analogRead(FLAME_CENTER);
    int right = analogRead(FLAME_RIGHT);

    // 4. Mouvement directionnel
    if (center > left && center > right) {
      moveForward(APPROACH_STEP); // Avance petit pas
    } 
    else if (left > right) {
      turnLeft(200); // Ajustement gauche
    }
    else {
      turnRight(200); // Ajustement droite
    }

    // 5. Vérifier les obstacles
    if (getDistance() < safe_distance && !detectFire()) {
      avoidObstacle();
      return;
    }
  }

  ESP_BT.println("ERREUR: Timeout approche");
  stopMotors();
}

void handleBluetooth() {
  char cmd = ESP_BT.read();
  
  switch(cmd) {
    case 'F': moveForward(); break;
    case 'B': moveBackward(); break;
    case 'L': turnLeft(); break;
    case 'R': turnRight(); break;
    case 'S': stopMotors(); break;
    case 'P': digitalWrite(PUMP_PIN, HIGH); break;
    case 'C': digitalWrite(PUMP_PIN, LOW); break;
    //case 'V': ESP_BT.println("STATUS:OK|BAT:75%|MODE:AUTO"); break;
    case 'D': // Réglage distance
      safe_distance = ESP_BT.parseInt();
      while (ESP_BT.available()) ESP_BT.read();
      ESP_BT.println("CONFIG: SafeDist=" + String(safe_distance));
      break;
  }
}
