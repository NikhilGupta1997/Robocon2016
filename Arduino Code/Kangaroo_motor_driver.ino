//configuration
#define kangaroo_baud_rate 9600
KangarooSerial  K(Serial1);
KangarooChannel K1(K, '1');
KangarooChannel K2(K, '2');
void kangaroo_init()
{
  Serial1.begin(kangaroo_baud_rate);
  K1.start();
  K1.home().wait();
  K1.s(0);
  Serial.println("channel 1 started");
  K2.start();
  K2.home().wait();
  K2.s(0);
  Serial.println("channel 2 started");
  delay(1000);
}
void kangaroo_for_line(int left,int right){
  K1.s(left);
  K2.s(right);
}
void kangaroo_update(float r, float rpm_max) {
  int rpml, rpmr ;                                     //rpm of both motors

  if (r >= 0) {
    rpmr = rpm_max;
    rpml = 1 * rpm_max * ((d / 2 - r) / (d / 2 + r)); // don't change
  }
  else {
    rpmr = rpm_max * ((d / 2 + r) / (d / 2 - r));      // don't change
    rpml = rpm_max;
  }
  K1.s(k * rpmr);
  K2.s(k * rpml);
}

void kangaroo_rotate(float rpmr, float rpml) {
  K1.s(k * rpmr);
  K2.s(k * rpml);
}


