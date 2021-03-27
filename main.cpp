#include <iostream>
#include <string>
using namespace std;

string name;
double area = 0;
double area_remaining = 0;
string direc = "menu";
bool done = false;

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

    cout << "1. Vegetables" << endl << "9. Exit Program" << endl;
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


void vegetables() {
    cout << "Select a vegetable to learn more about it: " << endl;
    cout << "1. Tomatoes " << endl << "2. Carrots" << endl << "3. Almonds" << endl << "4. Potatoes" << endl << "9. Exit Menu" << endl;
    int vegetables;
    cin >> vegetables;
    switch (vegetables) {
        case 1:
            cout << "You selected tomatoes!";
            break;
        case 2:
            cout << "You selected carrots!";
            break;
        case 3:
            cout << "You selected almonds!";
            break;
        case 4:
            cout << "You selected potatoes!";
            break;
        case 9:
            direc = "menu";
            break;

    }
}

int space(double ){

};

int main() {

    int done_confirmation = 0;

    introduction();

    while(done != true){
        if (area_remaining == 0){
            cout << "You have used all of your space!" << endl;
            break;
        }
        if (direc == "menu"){
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
        direc = "menu"; // blank seedcount later
    }
    else if (done_confirmation == 2){
        cout << "Garden Report" << endl;
    } else goto done;

    }
