//Brandon Markham
//Prime Integer Algorithm
//05/16/20

int userNum;
int origNum;
int count;
char userChoice;


void setup() {
  Serial.begin(9600);
  Serial.println("Please enter an integer greater than 2 to see if it is prime.");
  Serial.println("If the entered number is not prime, the program will display ");
  Serial.println("the closest prime integer less than the number entered.\n");
}

void loop() {
  while (Serial.available() == 0) {
  }

  userNum = Serial.parseInt();
  Serial.print("Number entered was: ");
  Serial.println(userNum);

  while (userNum <= 2) {
    Serial.println("Please enter a valid input greater than 2.\n");

    while (Serial.available() == 0) {
    }
    userNum = Serial.parseInt();
    Serial.print("The number entered was: ");
    Serial.println(userNum);
  }

  origNum = userNum;
  PrimeInteger(userNum, origNum, count);

  Serial.print("Would you like to test another integer?\n");
  Serial.print("Select Y for yes and N for no.\n\n");

  while (Serial.available() == 0) {
  }
  userChoice = Serial.read();
  Serial.print("User choice was: ");
  Serial.println(userChoice);

  while (userChoice != 'y' && userChoice != 'Y' && userChoice != 'n' && userChoice != 'N') {
    Serial.println("Please enter valid input Y/y or N/n.\n");

    while (Serial.available() == 0) {
    }
    userChoice = Serial.read();
    Serial.print("User choice was: ");
    Serial.println(userChoice);
  }

  while (userChoice == 'Y' || userChoice == 'y') {
    Serial.println("Please enter another integer greater than 2.\n");
    break;
  }

  while (userChoice == 'N' || userChoice == 'n') {
    Serial.println("This program has terminated successuflly.");
    delay(1000);
    exit(0);
  }
}

void PrimeInteger(int uNum, int oNum, int c) {

  bool isPrimeInteger = true;

  if (uNum <= 1) {
    isPrimeInteger = false;
  }

  for (int i = 2; i <= uNum / 2; ++i) {
    if (uNum % i == 0) {
      isPrimeInteger = false;
      break;
    }
  }

  if (isPrimeInteger && c > 0) {
    Serial.print(uNum);
    Serial.print(" is the closest prime integer to ");
    Serial.print(oNum);
    Serial.println(".");
    Serial.println();
    return;
  }

  else if (isPrimeInteger) {
    Serial.print(uNum);
    Serial.print(" is a prime number\n");
    Serial.println();
    return;
  }

  if (!isPrimeInteger) {
    c++;
    uNum = uNum - 1;
    PrimeInteger(uNum, oNum, c);
  }
}