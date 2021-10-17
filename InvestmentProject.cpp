/* Ryan Ramirez, RLRamirez4812@gmail.com, (702)595-8430
 * Sophomore UNLV, 10/16/2021 */
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
using namespace std;
// Function Prototypes
double precentGL(double, double, double);
double userInitialInput(double);
double userCMV(double);
double holdingAmount(double, string);

void mainDisplay(double, double, double, double, string);
void repromptOnLoop(double, double, double, double, string, bool);

string assetChoice(string);
string lowerCase(string &);

/*
 * The main which calls the first function to being prompting the user for
 * inputs. Initializing variables as well.
 */
int main() {
    double initialInvestment = 0.0;
    double cmv = 0.0;
    double holdingsAmount = 0.0;
    double precentChange = 0.0;
    double holdings = 0;
    double percentChange = 0;
    string asset;
    bool loop;
    repromptOnLoop(percentChange, initialInvestment, cmv, holdings, asset,
                   loop);
}
/*
 * This is to turn yes or no inputs into lowercase to check for only lowercase
 * responses, bringing in the value by refrence.
 */
string lowerCase(string &entry) {
    string returnString;
    for (int i = 0; i < entry.size(); i++) {
        returnString = tolower(entry[i]);
    }
    return returnString;
}
/*
 * This function is where a majority of the other functions are called along
 * with the main display. Looping depending on if the user would like to enter
 * another asset.
 */
void repromptOnLoop(double percentChange, double initialInvestment, double cmv,
                    double holdings, string asset, bool loop) {
    bool check = false;
    bool responseCheck = false;
    string response;
    do {
        asset = assetChoice(asset);
        initialInvestment = userInitialInput(initialInvestment);
        holdings = holdingAmount(holdings, asset);
        cmv = userCMV(cmv);
        percentChange = precentGL(initialInvestment, cmv, holdings);

        mainDisplay(percentChange, initialInvestment, cmv, holdings, asset);
        cout << endl;
        cout << "Would you like to enter another asset? [Y/N]: ";
        cin >> response;
        do {
            if (lowerCase(response) == "y" || lowerCase(response) == "n") {
                break;
            } else {
                cout << "Invalid entry, try again" << endl;
                check = true;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (responseCheck);
        if (lowerCase(response) == "y") {
            check = true;
            cout << endl;
        } else {
            check = false;
            cout << "Thank you for using my program!" << endl;
        }
    } while (check);
}
/*
 * The main display for the data and calculations after being read in.
 */
void mainDisplay(double percentChange, double initialInvestment, double cmv,
                 double holdings, string asset) {
    cout << "+" << setfill('*') << setw(40) << "+";
    cout << "\nWith holding: " << setprecision(8) << holdings << " " << asset
         << endl;
    cout << "\nAt an initial investment of: $" << initialInvestment << endl;
    cout << "\nThe current market value is: $" << cmv << endl;
    cout << "\nDollar Cost per " << asset << " holding is: $" << setprecision(5)
         << initialInvestment / holdings << endl;
    cout << "\nInitial investment: $" << initialInvestment
         << " Current total value: $" << setprecision(7) << holdings * cmv
         << endl;
    cout << "\nThe percent change is: ";
    if (percentChange > 0) {
        cout << "+";
    }
    cout << setprecision(4) << percentChange << "%"
         << "  (";
    if (percentChange > 0) {
        cout << "+";
    }
    cout << setprecision(6) << percentChange << "%)" << endl;
    cout << "\nThe dollar change is: ";
    if ((cmv * holdings) - initialInvestment > 0) {
        cout << "+";
    }
    cout << "$" << setprecision(5) << (cmv * holdings) - initialInvestment
         << endl;
    cout << "+" << setfill('*') << setw(40) << "+";
}
/*
 * This is a calculation function that finds the percent change of an initial
 * investment and the current market value of that investment
 */
double precentGL(double initialInvestment, double cmv, double holdingAmount) {
    double tempCMVInvestment = cmv * holdingAmount;
    double tempUserInvestment = initialInvestment;
    double GL = tempCMVInvestment - tempUserInvestment;
    double percentChange =
        ((tempCMVInvestment - tempUserInvestment) / tempUserInvestment) * 100;
    return percentChange;
}
/*
 * This is for the initial investment input by a user
 */
double userInitialInput(double initialInvestment) {
    bool check = false;
    do {
        check = false;
        cout << "Enter initial investment: $";
        cin >> initialInvestment;
        if (initialInvestment <= 0) {
            cout << "Invalid entry, try again" << endl;
            check = true;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (check);
    return initialInvestment;
}
/*
 * This is for the initial current market value input by a user
 */
double userCMV(double cmv) {
    bool check = false;
    do {
        check = false;
        cout << "Enter current market value: $";
        cin >> cmv;
        if (cmv <= 0) {
            cout << "Invalid entry, try again" << endl;
            check = true;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (check);
    return cmv;
}
/*
 * This is for the initial holding amount input by a user
 */
double holdingAmount(double holdings, string asset) {
    bool check = false;
    do {
        check = false;
        cout << "Enter amount of " << asset << ": ";
        cin >> holdings;
        if (holdings <= 0) {
            cout << "Invalid entry, try again" << endl;
            check = true;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (check);
    return holdings;
}
/*
 * This is for the initial asset ticker/name input by a user
 */
string assetChoice(string asset) {
    bool check = false;
    do {
        check = false;
        cout << "Enter asset name: ";
        cin >> asset;
        if (cin.fail()) {
            cout << "Invalid entry, try again" << endl;
            check = true;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (check);
    return asset;
}
