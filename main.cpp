#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string name;
double area = 0;
double area_remaining = 0;
string direc = "menu";

int beans = 0;
int broccoli = 0;
int carrots = 0;
int potatoes = 0;

int bell_peppers = 0;
int strawberries = 0;
int tomatoes = 0;
int watermelons = 0;

void introduction() {

    direc = "menu";

    cout << "Welcome to our Home Garden: " << endl;

    cout << "Please enter your name:" << std::endl;
    cin >> name;
    cout << "Welcome: " << name << endl;

        validation:
        cout << "Please enter the square footage of space you want to farm: " << endl;
        cin >> area;

        if (cin.fail() || area < 0){
            cin.clear();
            cin.ignore(10000, '\n');
            goto validation;
        }

    area_remaining = area;
}

void menu() {
    cout << "Select what you would like to farm: " << endl;

    cout << "1. Vegetables" << endl << "2. Fruit" << endl << "3. Show Garden" << endl << "4. Finish or Restart Program" << endl;
    int menu;
    cin >> menu;

switch(menu) {
    case 1:
        direc = "vegetables";
        break;
    case 2:
        direc = "fruits";
        break;
    case 3:
        direc = "show cart";
        break;
    case 4:
        direc = "exit";
        break;
}
}

int use_area(double item_size, string name){
    int choice = 0;
    int amount = 0;
    double space = 0;

    choice:
    cout << "Would you like to add by quantity or fill an area?" << endl << "1. Quantity" << endl << "2. Area" << endl << "3. Cancel" << endl;
    cin >> choice;
    if (choice != 1 && choice != 2 && choice != 3){
        goto choice;
    } else if(choice == 1){
        quantity:
        cout << "How many " + name + " would you like?" << endl;
        cin >> amount;
        if (amount * item_size > area_remaining){
            cout << "You don't have enough space." << endl;
            goto quantity;
        }
        area_remaining -= (amount * item_size);

    } else if (choice == 2){
        area:
        cout << "How many square feet do you want to fill with " + name + "?" << endl;
        cin >> space;
        if (space > area_remaining || item_size > space){
            space = 0;
            cout << "Not enough space." << endl;
            goto area;
        }
        double remainder = fmod(space, item_size);
        int rounding = 0;
        if (remainder != 0){
            rounding:
            cout << "Would you like to round down to the nearest size a group of these items can occupy?" << endl << "1. Yes" << endl << "2. No" <<endl;
            cin >> rounding;
            if (rounding != 1 && rounding != 2){
                goto rounding;
            } else if(rounding == 1){
                space -= remainder;
            }
        }
        area_remaining -= space;
        if (rounding == 1) {
            amount = space / item_size;
        } else {
            amount = (space - remainder) / item_size;
        }
    }
    return amount;
}

void cart_item (int amount, double size, string name){
    if (amount > 0){
        double item_area = size * amount;
        cout << amount;
        cout << " ";
        cout << name;
        cout << " which will cover ";
        cout << item_area;
        cout << " square feet (";
        cout << size;
        cout << " square feet each)" << endl;
    }
}

void show_vegetables(){
    if (beans + broccoli + carrots + potatoes > 0) {
        cout << "Vegetables:" << endl;
        cart_item(beans, 1.0 / 9, "beans");
        cart_item(broccoli, 1, "broccoli");
        cart_item(carrots, 1.0 / 16, "carrots");
        cart_item(potatoes, 1.0 / 4, "potatoes");
    }
}

void show_fruit(){
    if (bell_peppers + strawberries + tomatoes + watermelons > 0) {
        cout << "Fruits" << endl;
        cart_item(bell_peppers, 1, "bell peppers");
        cart_item(strawberries, 1.0 / 4, "strawberries");
        cart_item(tomatoes, 1, "tomatoes");
        cart_item(watermelons, 2, "watermelons");
        cout << endl;
    }
}

void show_cart(){
    direc = "menu";

    double area_used = area - area_remaining;
    cout << "Garden Size: ";
    cout << area << endl;
    cout << "Area Used: ";
    cout << area_used << endl;
    cout << "Area Available: ";
    cout << area_remaining << endl;
    cout << "Garden Contents: " << endl;

    show_vegetables();
    show_fruit();
}



void vegetables() {
    cout << "Select a vegetable to learn more about it: " << endl;
    cout << "1. Beans " << endl << "2. Broccoli" << endl << "3. Carrots" << endl << "4. Potatoes" << endl << "5. Exit Menu" << endl;
    int vegetables;
    cin >> vegetables;
    switch (vegetables) {
        case 1:
            cout << "You selected beans!" << endl;
            beans += use_area(1.0/9,"beans");
            break;
        case 2:
            cout << "You selected broccoli!" << endl;
            broccoli += use_area(1, "broccoli");
            break;
        case 3:
            cout << "You selected carrots!" << endl;
            carrots += use_area(1.0/16, "carrots");
            break;
        case 4:
            cout << "You selected potatoes!" << endl;
            potatoes += use_area(1.0/4, "potatoes");
            break;
        case 5:
            direc = "menu";
            break;

    }
}

void fruits() {
    cout << "Select a vegetable to learn more about it: " << endl;
    cout << "1. Bell Peppers " << endl << "2. Strawberry" << endl << "3. Tomatoes" << endl << "4. Watermelon" << endl << "5. Exit Menu" << endl;
    int fruits;
    cin >> fruits;
    switch (fruits) {
        case 1:
            cout << "You selected bell peppers!" << endl;
            bell_peppers += use_area(1,"bell peppers");
            break;
        case 2:
            cout << "You selected strawberry!" << endl;
            strawberries += use_area(1/4, "strawberries");
            break;
        case 3:
            cout << "You selected tomatoes!" << endl;
            tomatoes += use_area(1, "tomatoes");
            break;
        case 4:
            cout << "You selected watermelons!" << endl;
            watermelons += use_area(2, "watermelons");
            break;
        case 5:
            direc = "menu";
            break;

    }
}

int space(double ){

};

int main() {

    main:
    int done_confirmation = 0;

    introduction();

    while(true){
        if (area_remaining == 0){
            cout << "You have used all of your space!" << endl;
            break;
        }
        else if (direc == "exit"){
            break;
        }
        else if (direc == "show cart"){
            show_cart();
        }
        else if (direc == "intro"){
            introduction();
        }
        else if (direc == "menu"){
            menu();
        }
        else if(direc == "vegetables"){
            vegetables();
        }
        else if (direc == "fruits"){
            fruits();
        }
    }

    done:
    cout << "Would you like to: " << endl << "1. Start Again" << endl << "2. Finish" << endl;
    cin >> done_confirmation;

    if(done_confirmation == 1){
        area_remaining = area;
        direc = "intro";
        tomatoes = 0;
        goto main;
    }
    else if (done_confirmation == 2){
        cout << "Garden Report:" << endl;
        show_cart();
        cout << "Goodbye ";
        cout << name;
        cout << ".";
    } else goto done;

    }
