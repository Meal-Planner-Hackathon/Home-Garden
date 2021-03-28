#include <iostream>
#include <string>
using namespace std;

string name;
double area = 0;
double area_remaining = 0;
string direc = "menu";

int tomatoes = 0;

class fruitsandvegetables
{
public:
    void tomato();
    void avocado();
    void almond();
    void potato();
};

class meatsandnuts
{

};
void introduction() {

    direc = "menu";

    cout << "Welcome to our holistic health application: " << endl;

    cout << "Please enter your name:" << std::endl;
    cin >> name;
    cout << "Welcome: " << name << endl;

    cout << "Please enter the square footage of space you want to farm: " << endl;
    cin >> area;
    area_remaining = area;
}

void menu() {
    cout << "Select what you would like to farm: " << endl;

    cout << "1. Vegetables" << endl << "9. Finish or Restart Program" << endl;
    int menu;
    cin >> menu;

switch(menu) {
    case 1:
        direc = "vegetables";
        break;
    case 9:
        direc = "exit";
        break;
}
}

int use_area(double item_size, string name){
    int choice = 0;
    int amount = 0;
    double space = 0;

    choice:
    cout << "Would you like to add by quantity or fill an area?" << endl << "1. Quantity" << endl << "2. Area" << endl << "3. Cancel";
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
        if (space > area_remaining){
            space = 0;
            cout << "Not enough space." << endl;
            goto area;
        }
        
    }
    return amount;
}

void vegetables() {
    cout << "Select a vegetable to learn more about it: " << endl;
    cout << "1. Tomatoes " << endl << "2. Carrots" << endl << "3. Almonds" << endl << "4. Potatoes" << endl << "9. Exit Menu" << endl;
    int vegetables;
    cin >> vegetables;
    switch (vegetables) {
        case 1:
            cout << "You selected tomatoes!" << endl;
            tomatoes += use_area(.25,"tomatoes");
            break;
        case 2:
            cout << "You selected carrots!" << endl;
            break;
        case 3:
            cout << "You selected almonds!" << endl;
            break;
        case 4:
            cout << "You selected potatoes!" << endl;
            break;
        case 9:
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
        else if (direc == "intro"){
            introduction();
        }
        else if (direc == "menu"){
            menu();
        }
        else if(direc == "vegetables"){
            vegetables();
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
        double area_used = area - area_remaining;
        cout << "Garden Report:" << endl << "Garden Size: ";
        cout << area << endl;
        cout << "Area Used: ";
        cout << area_used << endl;
        cout << "Area Available: ";
        cout << area_remaining << endl;
    } else goto done;

    }
