#define ROW1 2
#define ROW2 3
#define ROW3 4
#define ROW4 5
#define ROW5 6
#define ROW6 7

#define COL1 13
#define COL2 12
#define COL3 11
#define COL4 10
#define COL5 9
#define COL6 8

const int row[] = {ROW1, ROW2, ROW3, ROW4, ROW5, ROW6};
const int col[] = {COL1,COL2, COL3, COL4, COL5, COL6};

int H[6][6] = {{0,0,1,1,0,0},
		       {0,0,1,1,0,0},
		       {0,0,0,0,0,0},
		       {0,0,0,0,0,0},
		       {0,0,1,1,0,0},
		       {0,0,1,1,0,0},
		       };

int A[6][6] = {{1,0,0,0,0,1},
		       {0,0,0,0,0,0},
		       {0,0,1,1,0,0},
		       {0,0,0,0,0,0},
		       {0,0,1,1,0,0},
		       {0,0,1,1,0,0},
		       };

int P[6][6] = {{0,0,0,0,0,0},
		       {0,0,0,0,0,0},
		       {0,0,1,1,0,0},
		       {0,0,0,0,0,0},
		       {0,0,1,1,1,1},
		       {0,0,1,1,1,1},
		       };

int Y[6][6] = {{0,0,1,1,0,0},
		       {1,0,0,0,0,1},
		       {1,1,0,0,1,1},
		       {1,1,0,0,1,1},
		       {1,1,0,0,1,1},
		       {1,1,0,0,1,1},
		       };

int _s[6][6] = {{1,1,1,1,1,1},
		       {1,1,1,1,1,1},
		       {1,1,1,1,1,1},
		       {1,1,1,1,1,1},
		       {1,1,1,1,1,1},
		       {1,1,1,1,1,1},
		       };

int N[6][6] = {{0,1,1,1,0,0},
		       {0,0,1,1,0,0},
		       {0,0,0,1,0,0},
		       {0,0,1,0,0,0},
		       {0,0,1,1,0,0},
		       {0,0,1,1,1,0},
		       };

int E[6][6] = {{0,0,0,0,0,0},
		       {0,0,1,1,1,1},
		       {0,0,1,1,1,1},
		       {0,0,0,0,0,0},
		       {0,0,1,1,1,1},
		       {0,0,0,0,0,0},
		       };

int W[6][6] = {{0,0,1,1,0,0},
		       {0,0,1,1,0,0},
		       {0,0,1,1,0,0},
		       {0,0,0,0,0,0},
		       {0,0,1,1,0,0},
		       {0,1,1,1,1,0},
		       };

int R[6][6] = {{0,0,0,0,0,1},
		       {0,0,1,1,1,0},
		       {0,0,1,1,1,0},
		       {0,0,0,0,0,1},
		       {0,0,1,1,0,1},
		       {0,0,1,1,1,0},
		       };

int _2[6][6] = {{1,0,0,0,1,1},
		       {1,0,1,1,0,1},
		       {1,1,1,0,1,1},
		       {1,1,0,1,1,1},
		       {1,0,1,1,1,1},
		       {1,0,0,0,0,1},
		       };

int _0[6][6] = {{1,1,0,0,1,1},
		       {1,0,1,1,0,1},
		       {1,0,1,1,0,1},
		       {1,0,1,1,0,1},
		       {1,0,1,1,0,1},
		       {1,1,0,0,1,1},
		       };

int _1[6][6] = {{1,1,0,0,1,1},
		       {1,0,1,0,1,1},
		       {1,1,1,0,1,1},
		       {1,1,1,0,1,1},
		       {1,1,1,0,1,1},
		       {1,00,0,0,0,1},
		       };

int _exs[6][6] = {{1,1,0,0,1,1},
		       {1,1,0,0,1,1},
		       {1,1,0,0,1,1},
		       {1,1,0,0,1,1},
				{1,1,1,1,1,1},
		       {1,1,0,0,1,1}
		       };

void setup() {
  //Serial.begin(9600);
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  
  Display(H);
  Display(A);
  Display(P);
  Display(P);
  Display(Y);
  
  Display(_s);
  
  Display(N);
  Display(E);
  Display(W);
  
  Display(_s);
  
  Display(Y);
  Display(E);
  Display(A);
  Display(R);
  
  Display(_s);
  
  Display(_2);
  Display(_0);
  Display(_2);
  Display(_1);
  
  Display(_exs);
  Display(_exs);
  Display(_exs);
  
  Display(_s);
  Display(_s);
}

void  Char(int matrix[6][6]){
  for (int c = 0; c < 6; c++){

    digitalWrite(col[c], HIGH);
    for (int r = 0; r < 6; r++){
      if (matrix[r][c] == 1){
        digitalWrite(row[r], HIGH);
      }
      else if (matrix[r][c] == 0) {
        digitalWrite(row[r], LOW);
      }
      delay(1);
    }
    for (int r = 0; r < 6; r++){
      digitalWrite(row[r], HIGH);
     delay(1);
    }
  
    digitalWrite(col[c], LOW);
  }
}

void Display(int matrix[6][6]){
  int counter;
  for (counter = 0; counter <= 20; counter++){
  	Char(matrix);
  }
  for (counter = 0; counter <= 2; counter++){
  	Char(_s);
  }
}