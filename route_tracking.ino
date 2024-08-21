int x; // Record the Action.
float X; // current coords.
float Y; // current coords.
int mov; // for reverse action.
float xx=0;     // Step value in X axis.
float yy=0.02;  // Step value in Y axis.
float degree=0; // Direction of the car.

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600);    //Hardware Serial of ESP32
  X = 1000; // Choo 
  Y = 1001;
  mov = 1;
}

void loop() {
  if(Serial2.available()) x = (int)Serial2.read(); // reading commands from a Bluetooth module. 
  x = action(x);
    if(x==82|| x==76 ){
         Serial2.write(83);
         delay(1);
         int r=0;
          while(r<=150){
            Serial2.write(x);
            delay(1);
            r++;
          }
        Serial2.write(83);
        x=83;
   }
   else Serial2.write(x);
   delay(1);
}

// ************ Measures for An Action ************

int action(int x){
  float x2 =  X;
  float y2 = Y;
  measure(x,&x2,&y2);
  X= x2;
  Y= y2;
  return x;
}
// ************ Measures for An Action ************

// ************ measure ************
void measure(int x, float *a,float *b){
  if (x==70){
      if(mov==2){
        degree += 180;
        if(degree>=360)degree = degree-360;
        mov = 1;
      }
      get_d();
      *a+=xx;
      *b+=yy;
     }
     else if(x==66){
      //back
      if(mov==1){
        degree += 180;
        if(degree>=360)degree = degree-360;
        mov = 2;
     }
      get_d();
      *a+=xx;
      *b+=yy;
     }
     else if(x==82 || x==76){
       if(x==82)degree+=45;
       else degree-=45;
       if(degree>=360)degree=0;
       else if(degree<=-30)degree = 315;
       get_d();
     }
}

// ************ measure ************

// ************ Update the direction of the car: ************
void get_d(){
  float z = (float)degree/360;
  float X_NEW = sin((z)*2*PI);
  float Y_NEW = cos((z)*2*PI);
    yy=Y_NEW * 0.02;
    xx=X_NEW * 0.02;
}
// ************ Update the direction of the car: ************
