//to be updated
  //declare our error variables for PID
  float E = 0, S = 0, PE = 0, D = 0;
  
  //declare the PID constants
  int max_speed = 1000 ;
  int threshold = 0;
  float radius = 255;
  float ki = 0;
  float kp = 1.5;
  float kd = 4;
  float mf = 5.5; //multiplication factor
  int DELAY = 30;
  float rotate = 0; 
  int rot_read = 0;
  int weights[6] = {-255,-128,-64,64,128,255};
  int flag = 0;
  int counter = 0;
  int weighed[6];
  int V1, V2;
  
void line_drive(int V,int Vtilt){
  PE = E; //set previous error to last error value
  flag = 0;
  E = 0;
  counter = 0;
  radius = 255;
  Serial.println(radius);
  Serial.println("");
  for(int i = 0; i < 6; i++){
    int r = reading(i);
    if(r == 1){
      counter++;
      E += r*weights[i];
      flag = 1; 
    }
if(counter>1)
    E = E/counter;
    
    Serial.print(r);
    Serial.print("    ");}
    Serial.println("");
 
    S += E; //add error to summation of previous errors
    Serial.print("Error");
    Serial.println(E);
    if(flag == 0 && fabs(PE) > 100){
      E = PE;
    }
    D = PE - E;
    if( E == 0){
      radius = 0;
    }
     
    rotate = float(kp * E + ki * S + kd  * D);
    rot_read = Vtilt/2; // get rotaianal velocity from PS3 controller
//
//     //limiting the maximum value of rotate velocity
//    if (rotate > max_speed / 2)
//      rotate = max_speed / 2;
//    if (rotate < -max_speed / 2)
//      rotate = -max_speed / 2;
//    
//    if(rotate > 0){
//      V1 = V * (max_speed - abs(rotate)-rot_read) / 128 + rotate/4;
//      V2 = V * (max_speed - abs(rotate)-rot_read) / 128 + rotate;
//    }
//
//    if(rotate < 0){
//      V1 = V * (max_speed - abs(rotate)-rot_read) / 128 + rotate;
//      V2 = V * (max_speed - abs(rotate)-rot_read) / 128 + rotate/4;
//    }
//    
//    float ratio = max_speed /  max(abs(V1), max(abs(V2), max_speed)); //calculate ratio to set motor speeds
//    
//    V1 *= ratio;
//    V2 *= ratio;
    if(E!=0){
      if(rotate>0){
    radius = (float)radius - (float)(rotate/mf);
   
      }
      else
      { radius = - (float)radius - (float)(rotate/mf);
       
      
      }
     }
      Serial.print("radius  ");
Serial.println(radius);
      Serial.print("speed  ");
Serial.println(V);
radius = -radius/23;
  kangaroo_update(radius, V);
//    kangaroo_for_line(V1,V2); //drive motors  
  }  
  
