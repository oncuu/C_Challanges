#include <iostream>
#include <vector>
#include <limits>

using namespace std;

/*
 On this project, I wanted to practice my basic C++ skills.
 So basically the user can perform operations on a list of numbers, including printing, calculating average,
 searching specific number on the list, finding smallest/largest amount, clearing the vector and the last option is quiting.
 */

int main() {
    char selection{};
    vector <int> list {};
    bool func = false;
    cout << "Welcome, please choice what would you like to do." << endl;
    do{
        // List of tasks.
        cout << "\n------------------------------------" << endl;
        cout << "P - Print list of numbers." << endl;
        cout << "A- Adding a number." << endl;
        cout << "M- Display the mean of the number." << endl;
        cout << "S - Display smallest number." << endl;
        cout << "L- Display largest number." << endl;
        cout << "T- Search number." << endl;
        cout << "C- Clear the list." << endl;
        cout << "Q- Quit." << endl;
        cout << "------------------------------------\n" << endl;
        cout << "\nEnter your choice: ";
        cin >> selection;
        tolower(selection);

        //Printing Values
        if (selection == 'p'){
            if(list.empty()){
                cout << "[] - empty list" << endl;
            }else{
                for(auto val:list){
                    cout << val << " ";
                }
            }

            // Adding additional items to list.
        }else if(selection == 'a'){
            bool dec = false;
            int add_num {};
            char decision {};
            do {
                cout << "Please type the number you would like to add: ";
                while (!(cin >> add_num)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Illegal entry, please type again. :";
                }
                list.push_back(add_num);
                cout << endl;
                cout << add_num << " added to the list." << endl;
                cout << "Would you like to add more? (Y/N)" << endl;
                cin >> decision;
                tolower(decision);

                if (decision == 'n'){
                    dec = true;
                }else if (decision == 'y'){
                    continue;
                }else {
                    cout << "Illegal entry" << endl;
                }
            }while(!dec);

            // Checking the average of the number.
        }else if(selection == 'm'){
            int sum {};
            int result{};
            if(list.empty()){
                cout << "[] - Unable to calculate the average, list is empty." << endl;
            }else{
                for(size_t i{0}; i < list.size(); ++i){
                    sum = sum + list.at(i);
                }
                result = sum / list.size();
                cout << result;
            }

            // Checking the smallest number on the list.
        }else if(selection == 's'){
            if(list.empty()){
                cout << "[] - Unable to find the smallest, list is empty." << endl;
            }else {
                int smallest = list[0];
                for (size_t i{0}; i < list.size(); ++i) {
                    if (list[i] < smallest) {
                        smallest = list[i];
                    }
                }
                cout << "Smallest number is " << smallest << " ." << endl;
            }

            // Checking the largest number.
        }else if(selection == 'l'){
            if(list.empty()){
                cout << "[] - Unable to find the largest, list is empty." << endl;
            }else {
                int largest = list[0];
                for (size_t i{0}; i < list.size(); ++i) {
                    if (list[i] > largest) {
                        largest = list[i];
                    }
                }
                cout << "Smallest number is " << largest << " ." << endl;
            }

            // Quit Option
        }else if(selection == 'q'){
            cout << "Thank you :) Goodbye" << endl;
            func = true;

            //Clearing the list
        }else if(selection == 'c') {
            list.clear();
            cout << "List is empty now." << endl;

            // Search option
        }else if(selection == 't'){
            if(list.empty()){
                cout << "[] - Unable to search, list is empty." << endl;
            }else {
                int num{};
                cout << "Please provide the number: ";
                while (!(cin >> num)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "You are searching a number, not a letter.";
                }
                int count {0};
                for(int i {0}; i<list.size(); ++i){
                    if(num == list.at(i)){
                        ++count;
                    }
                }
                if(count >= 1){
                    cout << "The number you provide " << num << " is " << count << " times on the list." << endl;
                }else{
                    cout << "Unfortunately the number you provide is not on the list." << endl;
                }
            }

            // Illegal entry
        }else{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Unknown selection please try again." << endl;
            cout << endl;
        }
    }while(!func);
    return 0;
}