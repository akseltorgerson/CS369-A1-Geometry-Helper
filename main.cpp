// Aksel Torgerson
// atorgerson

#include <iostream>
#include <cstring>
#include "functions.h"

using namespace std;

//
// Helper menu print functions.
//
void printMainMenu() {
  cout << "Welcome to Geometry Helper!" << endl;
  cout << "[1] Calculate a 2D area" << endl;
  cout << "[2] Calculate a 3D volume" << endl;
  cout << "[3] Exit" << endl;
  cout << "Please enter a menu item: ";
  return;
}

void print2dMenu() {
  cout << "Choose an Area to Compute:" << endl;
  cout << "[1] Circle" << endl;
  cout << "[2] Triangle" << endl;
  cout << "[3] Rectangle" << endl;
  cout << "[4] Return to main menu" << endl;
  cout << "Please enter a menu item: ";
  return;
}

void print3dMenu() {
  cout << "Choose a Volume to Compute:" << endl;
  cout << "[1] Sphere" << endl;
  cout << "[2] Cone" << endl;
  cout << "[3] Box" << endl;
  cout << "[4] Return to main menu" << endl;
  cout << "Please enter a menu item: ";
  return;
}

//
// Makes sure the user input is a positive float.
//
float getInput() {
  
  float retVal;
  cin >> retVal;

  if (cin.fail() || retVal <= 0) {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Please enter a postive number." << endl;
    return 0.0;
  }
  
  return retVal;

}

int main() {

  // Creating arbitrarily long array for the input string.
  char userSelect[64];
  int menuState = 1;  // 1 for main menu
                      // 2 for 2d
                      // 3 for 3d

  // 
  // Main program loop.
  //
  while (1) {
    
    // Scope variables.
    float ans, radius, width, height, length;

    //
    // Main Menu
    ///
    if (menuState == 1) {
      
      // Clear cin buffer for good looks :)
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      printMainMenu();
      cin >> userSelect;
      if (strcmp(userSelect, "1") == 0) {
        menuState = 2;
      } else if (strcmp(userSelect, "2") == 0) {
        menuState = 3;
      } else if (strcmp(userSelect, "3") == 0) {
        return 0;
      }
    } 

    //
    // 2D Menu
    //
    else if (menuState == 2) {
      
      // Print menu
      print2dMenu();
      cin >> userSelect;
      
      //
      // Circle
      //
      if (strcmp(userSelect, "1") == 0) {
        
        // Get input.
        do {
          cout << "Please enter the radius: ";
          radius = getInput();
        } while (radius <= 0.0);
        
        // Print input.
        ans = AreaOfCircle(radius);
        cout << "The area of the circle is: " << ans << endl;
        cout << "Press enter to return to the menu." << endl;
        cin >> ans;
        menuState = 1;

      } 

      //
      // Triangle
      //
      else if (strcmp(userSelect, "2") == 0) {
        
        // Get input.
        do {
          cout << "Please enter the width: ";
          width = getInput();
        } while (width <= 0.0);

        do {
          cout << "Please enter the height: ";
          width = getInput();
        } while (height <= 0.0);

        // Print input.
        ans = AreaOfTriangle(width, height);
        cout << "The area of the triangle is: " << ans << endl;
        cout << "Press enter to return to the menu." << endl;
        cin >> ans;
        menuState = 1;

      } 

      //
      // Rectangle
      //
      else if (strcmp(userSelect, "3") == 0) { 
        
        // Get input.
        do {
          cout << "Please enter the width: ";
          width = getInput();
        } while (width <= 0.0);

        do {
          cout << "Please enter the height: ";
          width = getInput();
        } while (height <= 0.0);

        // Print input.
        ans = AreaOfTriangle(width, height);
        cout << "The area of the rectangle is: " << ans << endl;
        cout << "Press enter to return to the menu." << endl;
        cin >> ans;
        menuState = 1;

      } 

      //
      // Return to main menu.
      //
      else if (strcmp(userSelect, "4") == 0) {
        menuState = 1;
      }
    } 

    //
    // 3D Menu
    //
    else if (menuState == 3) {
      print3dMenu();
      cin >> userSelect;
      if (strcmp(userSelect, "4") == 0) {
        menuState = 1;
      }
    } else {
      menuState = 1;
    }
  }
  return 0;
}

