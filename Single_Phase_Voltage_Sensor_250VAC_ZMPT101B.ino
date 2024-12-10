/*int sin1 = 0;
float y =0;
float mapFloat(float x, float in_min, float in_max, float out_min, float out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  float sum = 0;


  /*for (int i = 0; i <651 ; i++) {
   sin1 = analogRead(A0);
    y = map(sin1, 294, 723, -325, 325);
    sum += y * y;
    delay(1); 
  }
  
  sin1 = analogRead(A0);

  float y = mapFloat(sin1, 294, 723, -325.0, 325.0);
  //float rmsVoltage = sqrt(sum / 651) ;
  /*Serial.print("RMS Voltage: ");
  Serial.println(rmsVoltage);
  Serial.println(sin1);


  delay(500); 
}*/




double sensorValue1 = 0;
double sensorValue2 = 0;
int crosscount = 0;
int climb_flag = 0;
int val[100];
int max_v = 0;
double VmaxD = 0;
double VeffD = 0;
double Veff = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  for ( int i = 0; i < 100; i++ ) {
    sensorValue1 = analogRead(A0);
    if (analogRead(A0) > 511) {
      val[i] = sensorValue1;
    }
    else {
      val[i] = 0;
    }
    delay(1);
  }

  max_v = 0;

  for ( int i = 0; i < 100; i++ )
  {
    if ( val[i] > max_v )
    {
      max_v = val[i];
    }
    val[i] = 0;
  }
  if (max_v != 0) {


    VmaxD = max_v;
    VeffD = VmaxD / sqrt(2);
    Veff = (((VeffD - 420.76) / -90.24) * -210.2) + 210.2;
  }
  else {
    Veff = 0;
  }
  Serial.print("Voltage: ");
  Serial.println(Veff);
  VmaxD = 0;

  delay(100);
}