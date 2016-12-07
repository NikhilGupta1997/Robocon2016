//libraries
#include <USBSabertooth.h>  // for slider and pole climbing 
#include <Servo.h>          // for fan
#include <Kangaroo.h>       // for drive/maxon motor
#include <PS3USB.h>         // PS3 controller
#include <SPI.h>            // PS3
#include <math.h>
#include <digitalWriteFast.h>

// configuration
#define serial_baud_rate 115200    // for debugging
boolean enable_debug = true;          // for debugging
boolean kangaroo_driver = true;
boolean line_follow = true;


// constants
float d = 40;                     // vary this to change the roc
int k = 15;                         // to vary speed.
float pi = 3.1415926535;
float inf_roc  = 100000 ;//technically roc for st. line should be infinite

int t = 5;                                              // PS3 threshold
float lhy, l2, r2, rhy, rhx;                            // rhy is for slider
boolean sqr, crs, cir, tri, l1, r1, up, down, ps, left, right, srt; // l1 and r1 is for servo motor
float dia = 0.1;                          // diameter of front wheel in meter
int resolution = 4096;                    // resolution of encoder of front wheel
float increment = pi * dia / resolution;  // distance travelled in one tick

int Apin = 2;
int Bpin = 3;
//////////////////VARIABLES////////////////

float rpm = 150;                                // position(in meter) from encoder in front wheel
int velocity;
int tiltVel;

void setup() {
  if (enable_debug) {
    Serial.begin(serial_baud_rate);
    Serial.println("serial initilized");
  }
  PS3_init();
  Serial.println("PS3 initialized");
  if (kangaroo_driver) {
    kangaroo_init();
    delay(1000);
    Serial.println("kangaroo initilized");
  }

  //mux 1 input
  pinMode(22, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(26, OUTPUT);
  //mux 2 input
  pinMode(28, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(32, OUTPUT);
  //mux 3 input
  pinMode(34, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(38, OUTPUT);
  pinMode(Apin, INPUT);
  pinMode(Bpin, INPUT);
}

void loop() {
  PS3_getValue();

  if(ps)
  {
    line_follow = !line_follow;
  }
  
  if (kangaroo_driver && !line_follow)
  {
    if (abs(lhy) < t) {
      if (abs(rhx) < t) {
        kangaroo_update(0, 0);
      }
      else if (rhx > t) {
        kangaroo_rotate(rhx, -rhx);
      } else if (rhx < t) {
        kangaroo_rotate(rhx, -rhx);
      } else {
        kangaroo_update(0, 0);           // to stop both motors
      }
    }
    if (abs(lhy) > t && l2 < t && r2 < t) {
      kangaroo_update(0, lhy);           // for straight motion
    }
    if (l2 > t && abs(lhy) > t) {
      kangaroo_update(l2, lhy);          // for turning left
    }
    if (r2 > t && abs(lhy) > t) {
      kangaroo_update(-r2, lhy);         // for turning right
    }
  }
  if (line_follow) {
    if (abs(lhy) > t || abs(rhy) > t) {
      velocity  = lhy;
      tiltVel = rhy;
      line_drive(velocity, tiltVel);
    }
  }

  ////////////////////////////////////////////////////////////
}
