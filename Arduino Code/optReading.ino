int in[8] = {1,2,3,4,5,6,7,8};
float mfactor[8] = {1.52,1.52,1.52,1.52,1.56,1.53,1.47,1.50};
int sfactor[8] = {100,100,100,100,104,112,101,132};
int thresholds[6] = {670,1000,1000,1000,1000,855};
int sum = 0;

//int in2[2] = {7,8};
int reading(int this_opt){
 sum = 0;
  for(int i= 0;i<5;i++){
   sum += analogRead(in[this_opt]);  
  }
  int average = int(sum/5);
  if(average >= thresholds[this_opt]){return 1;}
  else return 0;
}

/*
//read 0 to 23
int reading(int this_opt){//function for current  reading of opts
  int b1 = bitRead(this_opt,0);
  int b2 = bitRead(this_opt,1);
  int b3 = bitRead(this_opt,2);
  int caliberated = 0;//sum of 5 values and then average then multiplied with multiplication factor and then subtracted  with subtraction factors
  if(this_opt<8){//left arrays
    for(int i = 0;i <5; i++){ 
      digitalWrite(22,b1);
      digitalWrite(24,b2);
      digitalWrite(26,b3);
      caliberated = analogRead(A1);}
    Serial.print("   ");
    Serial.print(caliberated);
    caliberated /= 5;
    caliberated = int(multfactor[1][this_opt]*caliberated - subfactor[1][this_opt]);
    return caliberated;}
  else if(this_opt>7 || this_opt< 16){//mid arrays
    for(int i = 0;i <5; i++){
      digitalWrite(28,b1);
      digitalWrite(30,b2);
      digitalWrite(32,b3);
      caliberated = analogRead(A2);}
    Serial.print("   ");
    Serial.print(caliberated);
    caliberated /=5;
    caliberated = int(multfactor[2][this_opt-8]*caliberated - subfactor[1][this_opt-8]);
    return caliberated;}
  else if(this_opt> 15 || this_opt <24){//right part arrays
    for(int i = 0;i <5; i++){
      digitalWrite(34,b1);
      digitalWrite(36,b2);
      digitalWrite(38,b3);
      caliberated = analogRead(A3);}
    Serial.print("   ");
    Serial.print(caliberated);
    caliberated /= 5;
    caliberated = int(multfactor[2][this_opt-16]*caliberated - subfactor[1][this_opt-16]);
    return caliberated; }
}*/
