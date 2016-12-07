
//multiplication factors copy paste the values@#$%^&*#@$%^*&()&(^%$#
float multfactor[3][8] = {};
int subfactor[3][8] = {}; //subtraction factor
//float mtwo[3][2] = {};
//int stwo[3][2] = {};

int white_threshold = 900;
int black_threshold = 200;


//int opts_six_min[6][5] = {};//array of minimum values of big array
//int opts_two_min[2][5] = {};//array of minimum values of small array

void caliberation(){
  int opts = 6;//number of opts in selected array
  boolean selection_ok = false;
  int pin = 0;
  short index = 0;
  Serial.println("Give 1 to 6 number to caliberate specific array");
  while(!selection_ok){
    index  = Serial.parseInt();
    if(index == 1 || index == 3 || index == 5) {
      opts = 6;
      selection_ok = true; 
    }
    else if(index == 2 || index == 4 || index == 6) {
      opts = 2;
      selection_ok = true;
    }
    else {
      Serial.println("Give a number between 1 and 6"); 
    }
  }
  
  int opt_data[opts][5];//array for storing the 5 values for each opt
  int sum_samples[opts];//sum of recorded 5 values
  int average1[opts] ;//average values of the opts for one color black or white
  int average2[opts] ;//average values of opts for another color
    
  if(opts==6) {
    switch(index){
      case(1): pin = 0;break;
      case(3): pin = 8; break;
      case(5): pin = 16; break;
    }
  }
  
  else {
    switch(index){
      case(2): pin = 0;break;
      case(4): pin = 8; break;
      case(6): pin = 16; break; 
    }
  }
   //Ask for white values or blacks
   boolean color_selection = false;
   boolean color = false;//will remain false for black color and will become true for white color 
   Serial.println("Give 1 for white range value recording or give 0 for black value recording");
   
   while(!color_selection) {
     int t = Serial.parseInt();
     if(t==0) {
       color_selection = true;
     }
     else if(t==1) {
       color_selection = true;
       color=true;
     }
     else {
       Serial.println("give value 1 for white or 0 for black");
     }
   }
   
   //begin taking data
   for(int i= 0;i<5;i++){
     int copy_pin = pin;
     for(int j= 0;j<opts;j++){
        copy_pin++;
        if(opts==2){copy_pin += 6;}
         int val = reading(pin);
         sum_samples[j] += val;
        if(color){if(val<white_threshold){Serial.println();
                                   Serial.print("Opt gave wrong value-");
                                   Serial.print(pin);}}
        else{if(val>black_threshold){Serial.println();
                                   Serial.print("Opt gave wrong value-");
                                   Serial.print(pin);}}
                                  
        delay(200);

   }
 }
   Serial.println();
   for(int i = 0;i<opts;i++){average1[i] = sum_samples[i]/5;Serial.print(average1[i]);Serial.print("    ");}//count average values of recorded values
   
   //code repetion for another set of values
   for(int i = 0; i < opts; i++){sum_samples[i] = 0;}
   color_selection = false;
   color = false;//will remain false for black color and will become true for white color 
   Serial.println("Give 1 for white range value recording or give 0 for black value recording");
   while(!color_selection){
     int t = Serial.parseInt();
     if(t==0){color_selection = true;}
     else if(t==1){color_selection = true;color=true;}
     else{Serial.println("give value 1 for white or 0 for black");}
   }
   
   //begin taking data
   for(int i= 0;i<5;i++){
     int copy_pin = pin;
     for(int j= 0;j<opts;j++){
        copy_pin++;
        if(opts==2){pin += 6;}
         int val = reading(copy_pin);
         sum_samples[j] += val;
        if(color){if(val<white_threshold){Serial.println();
                                   Serial.print("Opt gave wrong value-");
                                   Serial.print(pin);}}
        else{if(val>black_threshold){Serial.println();
                                   Serial.print("Opt gave wrong value-");
                                   Serial.print(pin);}}
                                  
        delay(200);

   }
 }
 Serial.println();
   for(int i = 0;i<opts;i++){average2[i] = sum_samples[i]/5;Serial.print(average2[i]);Serial.print("    ");}  
   //calculate addition and multiplication factors now\
  // int addition_factor[opts] = {};
   //float multiplication_factor[opts] = {};
   Serial.println("Multiplication Factors");
   for(int i = 0; i<opts; i++){
     int j = 1024/abs(average2[i]-average1[i]);
     Serial.print(j);
     Serial.print("    ");
   }
 }


