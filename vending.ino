#include <MenuBackend.h>
#include <Bounce2.h>
#include <LiquidCrystal.h>
#include<Keypad.h> // KEYPAD LIBRARY FOR KEYPAD INTERFACING 
#include<Servo.h>// LIBRARY FOR SERVO MOTOR




int lastButtonPushed = 0;
String menuUse = "";

int cost = 5000;
int flag = 1;


int num;
int items[12];


Servo servo_Motor1;

Servo servo_Motor2;

Servo servo_Motor3;

Servo servo_Motor4;

Servo servo_Motor5;

Servo servo_Motor6;

Servo servo_Motor7;

Servo servo_Motor8;

Servo servo_Motor9;

Servo servo_Motor10;

Servo servo_Motor11;

Servo servo_Motor12;

int  orangeCost = 5000;
int  appleCost = 3000;
int  berryCost = 2000;
int  teaCost = 2000;
int  coffeeCost = 5000;
int  nesCost = 2000;
int  chickenCost = 3000;
int  meatCost = 1000;
int  oloviyeCost = 3000;
int  bergerCost = 4000;
int  cheeseCost = 6000;
int  hotdogCost = 4000;




const int rs = 16, en = 17, d4 = 18, d5 = 19, d6 = 20, d7 = 21;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char keys[4][4] = { // LAYOUT OF KEYPAD

  {'7', '8', '9', 'C'},
  {'4', '5', '6', 'B'},
  {'1', '2', '3', 'A'},
  {'*', '0', '#', 'D'}
};

byte rowPin[4] = {4, 5, 6, 7}; // ROW PINS OF KEYPAD
byte colPin[4] = {3, 2, 1, 0}; // COLUMN PINS OF KEYPAD
Keypad keypad = Keypad(makeKeymap(keys), rowPin, colPin, 4, 4);







void menuChanged (MenuChangeEvent changed);
void menuUsed (MenuUseEvent used);

MenuBackend menu = MenuBackend (menuUsed, menuChanged);
MenuItem drink = MenuItem ("Drink");
MenuItem coldDrink = MenuItem ("Cold Drink");

MenuItem orrange = MenuItem ("orange");
MenuItem apple = MenuItem ("apple");
MenuItem berry = MenuItem ("berry");

MenuItem warmDrink = MenuItem ("Warm Drink");
MenuItem tea = MenuItem ("Tea");
MenuItem Coffee = MenuItem ("Coffee");
MenuItem Nescofee = MenuItem ("Nescofee");

MenuItem sandwich = MenuItem ("Sandwich");
MenuItem coldSandwich = MenuItem ("Cold Sandwich");

MenuItem oloviyeh = MenuItem ("oloviyeh");
MenuItem chicken = MenuItem ("chicken");
MenuItem meat = MenuItem ("meat");

MenuItem hotSandwich = MenuItem ("hot Sandwich");
MenuItem hotDog = MenuItem ("hot dog");
MenuItem hamberger = MenuItem ("hamberger");
MenuItem cheeseburgur = MenuItem ("cheeseburgur");



void setup ()
{

  lcd.begin(16, 2);
  lcd.print("Hello Vending");
  delay(1000);
  lcd.clear();








  menu.getRoot ().add (drink);
  drink.addRight (sandwich);
  drink.add(coldDrink).addRight(warmDrink);
  coldDrink.add(orrange).addRight(apple).addRight(berry);
  warmDrink.add(tea).addRight(Coffee).addRight(Nescofee);
  sandwich.add(coldSandwich).addRight(hotSandwich);
  coldSandwich.add(oloviyeh).addRight(chicken).addRight(meat);
  hotSandwich.add(hotDog).addRight(hamberger).addRight(cheeseburgur);


}

void loop ()
{

  if (flag == 1) {

    readBuutton ();
    navigateMenus ();
  }


}



void menuChanged (MenuChangeEvent changed)
{
  //بعد از جابه حایی بین گزینه های منو کد های این قسمت به صورت خودکار اجرا میشوند



  lcd.clear ();
  MenuItem newMenuItem = changed.to; //آیتمی را که بر روی آن قرار داریم بدست می آوریم


  if ( newMenuItem.getName () == menu.getRoot () ) {
    lcd.print ("Main Menu       ");
  }
  else if ( newMenuItem.getName () == "Drink" ) {
    lcd.print ("Drink           ");
  }
  else if ( newMenuItem.getName () == "Cold Drink" ) {
    lcd.print ("Cold Drink");
  }
  else if ( newMenuItem.getName () == "Warm Drink" ) {
    lcd.print ("Warm Drink   ");
  }
  else if ( newMenuItem.getName () == "Sandwich" ) {
    lcd.print ("Sandwich           ");
  }
  else if ( newMenuItem.getName () == "Cold Sandwich" ) {
    lcd.print ("Cold Sandwich   ");
  }


  else if ( newMenuItem.getName () == "hot Sandwich" ) {
    lcd.print ("hot Sandwich   ");
  }

  else if ( newMenuItem.getName () == "Tea" ) {
    lcd.print ("Tea   ");
  }
  else if ( newMenuItem.getName () == "Coffee" ) {
    lcd.print ("Coffee   ");
  }
  else if ( newMenuItem.getName () == "Nescofee" ) {
    lcd.print ("Nescofee   ");
  }
  //  else if ( newMenuItem.getName () == "Item3" ){
  //    lcd.print ("Item3           ");
  //    }

  else if ( newMenuItem.getName () == "orange" ) {
    lcd.print ("orange           ");
  }

  else if ( newMenuItem.getName () == "apple" ) {
    lcd.print ("apple           ");
  }

  else if ( newMenuItem.getName () == "berry" ) {
    lcd.print ("berry           ");
  }

  else if ( newMenuItem.getName () == "oloviyeh" ) {
    lcd.print ("oloviyeh           ");
  }

  else if ( newMenuItem.getName () == "chicken" ) {
    lcd.print ("chicken          ");
  }


  else if ( newMenuItem.getName () == "meat" ) {
    lcd.print ("chicken           ");
  }


  else if ( newMenuItem.getName () == "hot dog" ) {
    lcd.print ("hot dog          ");
  }


  else if ( newMenuItem.getName () == "hamberger" ) {
    lcd.print ("hamberger           ");
  }

  else if ( newMenuItem.getName () == "cheeseburgur" ) {
    lcd.print ("hamberger           ");
  }
}

void menuUsed (MenuUseEvent used)
{
  //بعد از استفاه از یک منو ، کد های موجود در این قسمت به صورت خودکار فراخوانی مشود


  lcd.clear ();
  lcd.print ("You choosed        ");
  lcd.setCursor (1, 1);
  lcd.print (used.item.getName ());
  delay(1000);
  menuUse = used.item.getName ();
  flag = 0;
  buy(menuUse);




}


void readBuutton ()
{


  char pressed = keypad.getKey();

  if (pressed) {


    if (pressed == '#') {


      lcd.clear();
      lcd.print("enter");
      delay(1000);
      lcd.clear();
      lastButtonPushed = 25;

    }

    if (pressed == '*') {


      lcd.clear();
      lcd.print("esc");
      delay(1000);
      lcd.clear();
      lastButtonPushed = 24;


    }

    if (pressed == 'D') {


      lcd.clear();
      lcd.print("right");
      delay(1000);
      lcd.clear();
      lastButtonPushed = 23;


    }


    if (pressed == 'A') {


      lcd.clear();
      lcd.print("left");
      delay(1000);
      lcd.clear();
      lastButtonPushed = 22;


    }
  }


}



void navigateMenus ()
{

  //ایتمی که بر روی آن قرار داریم را بدست می آوریم
  MenuItem currentMenu = menu.getCurrent ();

  switch ( lastButtonPushed ) {
    case 25:
      if ( !(currentMenu.moveDown ()) ) { //if the current menu has a child and has been pressed enter then menu navigate to item below
        menu.use ();
      }
      else { //otherwise, if menu has no child and has been pressed enter the current menu is used
        menu.moveDown ();

      }
      break;
    case 24:

      menu.toRoot ();  //به ابتدای منو باز می گردیم

      break;
    case 23:
      //به ایتم سمت راست حرکت می کنیم
      menu.moveRight ();
      break;
    case 22:
      //به آیتم سمت چپ حرکت میکنیم
      menu.moveLeft ();
      break;
  }
  lastButtonPushed = 0;
}


void rotate(Servo servo , int pin) {

  if (servo.read() == 180) {

    servo.attach(pin);
    servo.write(0);


  }

  else {

    servo.attach(pin);
    servo.write(180);

  }

}



void buy(String menuUse) {
  //
  //
  String temp = "";
  int i;
  lcd.clear();
  lcd.print("enter number");
  delay(1000);
  lcd.clear();

  while (flag == 0) {
    char press = keypad.getKey();





    if (press) {


      if (press == 'C') {


        //           lcd.print(temp);
        num = temp.toInt();
        delay(1000);
        lcd.clear();
        lcd.print("number you want: ");
        lcd.setCursor(0, 1);
        lcd.print(temp.toInt());
        delay(1000);
        lcd.clear();

        if (menuUse == "orange") {


          lcd.print("final cost: ");
          lcd.setCursor(1, 1);
          lcd.print(orangeCost * num);


          for (int i = 0; i < num; i++) {

            rotate(servo_Motor1, 22);
            delay(2000);

          }


        }


        if (menuUse == "apple") {

          lcd.print("final cost: ");
          lcd.setCursor(1, 1);
          lcd.print(appleCost *num);


          for (int i = 0; i < num; i++) {

            rotate(servo_Motor2, 23);
            delay(2000);

          }


        }


        if (menuUse == "berry") {

          lcd.print("final cost: ");
          lcd.setCursor(1, 1);
          lcd.print(berryCost * num);

          for (int i = 0; i < num; i++) {

            rotate(servo_Motor3, 24);
            delay(2000);

          }


        }


        if (menuUse == "Tea") {

          lcd.print("final cost: ");
          lcd.setCursor(1, 1);
          lcd.print(teaCost * num);

          for (int i = 0; i < num; i++) {

            rotate(servo_Motor4, 25);
            delay(2000);

          }


        }



        if (menuUse == "Coffee") {

          lcd.print("final cost: ");
          lcd.setCursor(1, 1);
          lcd.print(coffeeCost * num);


          for (int i = 0; i < num; i++) {


            rotate(servo_Motor5, 26);
            delay(2000);
          }



        }





        if (menuUse == "Nescofee") {

          lcd.print("final cost: ");
          lcd.setCursor(1, 1);
          lcd.print(nesCost * num);

          for (int i = 0; i < num; i++) {
            rotate(servo_Motor6, 27);
            delay(2000);
          }

        }






        if (menuUse == "oloviyeh" ) {

          lcd.print("final cost: ");
          lcd.setCursor(1, 1);
          lcd.print(oloviyeCost * num);



          for (int i = 0; i < num; i++) {
            rotate(servo_Motor7, 28);
            delay(2000);
          }

        }





        if (menuUse == "chicken" ) {

          lcd.print("final cost: ");
          lcd.setCursor(1, 1);
          lcd.print(chickenCost * num);
          for (int i = 0; i < num; i++) {

            rotate(servo_Motor8, 34);
            delay(2000);
          }

        }






        if (menuUse == "meat" ) {

          lcd.print("final cost: ");
          lcd.setCursor(1, 1);
          lcd.print(meatCost * num);



          for (int i = 0; i < num; i++) {
            rotate(servo_Motor9, 29);
            delay(2000);
          }

        }







        if (menuUse == "hot dog" ) {

          lcd.print("final cost: ");
          lcd.setCursor(1, 1);
          lcd.print(hotdogCost *num);
          for (int i = 0; i < num; i++) {
            rotate(servo_Motor10, 30);
            delay(2000);
          }

        }



      


      if (menuUse == "hamberger" ) {

        lcd.print("final cost: ");
        lcd.setCursor(1, 1);
        lcd.print(bergerCost * num);
        for (int i = 0; i < num; i++) {
          rotate(servo_Motor11, 31);
          delay(2000);
        }

      }


    



    if (menuUse == "cheeseburgur" ) {

      lcd.print("final cost: ");
      lcd.setCursor(1, 1);
      lcd.print(cheeseCost *num);
      for (int i = 0; i < num; i++) {
        rotate(servo_Motor12, 33);
        delay(2000);
      }

    }


      
    
  




  flag = 1;
  num = 0;
  
  

      } 


else {

  lcd.print(press);
  temp += press;
}

    

  }
  }
}
