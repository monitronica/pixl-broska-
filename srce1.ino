#define A 0
#define B 1
#define C 2
#define D 3
#define E 4

#define DELAY 1000

int c[5][4][2] = {
  { {A, B}, {A, C}, {A, D}, {A, E} },
  { {B, A}, {B, C}, {B, D}, {B, E} },
  { {C, A}, {C, B}, {C, D}, {C, E} },  
  { {D, A}, {D, B}, {D, C}, {D, E} },  
  { {E, A}, {E, B}, {E, C}, {E, D} }
};

int frames[][5] = {
 {  0b0000,
    0b0110,
    0b0011,
    0b0110,
    0b0000
  },
 {  0b0100,
    0b1110,
    0b0111,
    0b1110,
    0b0100
  },
  { 0b0000,
    0b0110,
    0b0011,
    0b0110,
    0b0000
  },
  { 0b0000,
    0b0000,
    0b0010,
    0b0000,
    0b0000
  },
  { 0b0000,
    0b0110,
    0b0011,
    0b0110,
    0b0000
   },
  { 0b0100,
    0b1110,
    0b0111,
    0b1110,
    0b0100
  },
  
  { 0b0000,
    0b0110,
    0b0011,
    0b0110,
    0b0000
   },
  { 0b0000,
    0b0000,
    0b0010,
    0b0000,
    0b0000
  },
  { 0b0000,
    0b0110,
    0b0011,
    0b0110,
    0b0000
  },
  { 0b0100,
    0b1110,
    0b0111,
    0b1110,
    0b0100
  },
  { 0b0000,
    0b0110,
    0b0011,
    0b0110,
    0b0000
    },
   {0b0000,
    0b0000,
    0b0010,
    0b0000,
    0b0000
  }
};

void setup(){
  pinMode( A, INPUT );
  pinMode( B, INPUT );
  pinMode( C, INPUT );
  pinMode( D, INPUT );
  pinMode( E, INPUT );
}

void display( int frame[5], int duration ){
  int times = 0;
  int x = 0;
  int y = 0;

  while( times < duration ){
    for( y = 0; y < 5; y++ ){
      for( x = 0; x < 4; x++ ){
        setup();
        if( frame[y] & (0b1000 >> x) ){
          light( c[y][x] );
          delayMicroseconds(DELAY);
          times++;
        }
      }
    }
  }
}

void light( int pins[2] ){
  pinMode( pins[0], OUTPUT );
  digitalWrite( pins[0], HIGH );

  pinMode( pins[1], OUTPUT );
  digitalWrite( pins[1], LOW );
}

void loop(){
  //test_loop();
  
   int i;
  for( i = 0; i < 10; i++ ){
    display( frames[i], 200 );
  }
}
