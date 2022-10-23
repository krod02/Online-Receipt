//
//  RecieptProject.cpp
//  Receipt Project
//
//  Created by Kevin Rodriguez on 2/16/22.
//

//#include "RecieptProject.hpp"
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;

struct menu{
    std::string menu_items[10] = {"/Users/krod/OneDrive - Florida Gulf Coast University/PRmenu.csv"};
    int prices[10] = {15,12,27,35,42,37,20,6,5,10};

};


//function that prints all values in structure
void print_menu(menu &item){
    cout << "\t\tHere is our menu selection\n\n";
    for(int i = 0; i < 10; i++){
        cout << i+1 <<". " << item.menu_items[i] << " ($" << item.prices[i] << ")\n";
    }
    
}


//function to take the users orders then  returns int corresponding to order which will be saved in vector
int take_order(){
    cout << "Please input the number of item you want to add to your order: \n";
    int order_input;
    cin >> order_input;
    if (order_input > 0 && order_input < 11){
        return order_input - 1;
    }else{
        cout << "Wrong input";
        exit(1);
    }
}


//function to display total price and calculates the price with taxes aswell
double display_total_price(std::vector<int> order){
    int total_price = order.size();
    cout << "Your current total price is (taxes included): $";
    //checks to see if there are any values in vector
    if(total_price == 0){
        return 0;
    }else{
        //accumulate adds up all the price values stored in vector
       double price_calculation = accumulate(order.begin(),order.end(),0);
        price_calculation = price_calculation + (price_calculation*.089);//calculates price and tax and stores in variable
        return price_calculation;
    }
}

//function calculates discount if applicable and returns float number
double calculate_discount(){
    cout << "Do you identify as a 1. Senior Citizen(5%), 2. Preferred member(8%), 3. Educator(2.5%), 4. Veteran(4%), 5. N/A\n";
    cout << "You will receive a discount if you are any of the above\n";
    cout << "Please input the number of the selected option\n ";
    int user_discount;
    cin >> user_discount;
    if(user_discount == 1){
        return .05;
    }else if(user_discount == 2){
        return .08;
    }else if(user_discount == 3){
        return .025;
    }else if(user_discount == 4){
        return .04;
    }else{
        return 0;
    }
}

//function to take payment. Allows user to choose if they want to pay in full of part of it
double take_payment(double final_price){
    cout << "Input amount you want to pay from the given price: ";
    double payment;
    cin >> payment;
    if (payment == final_price){
        cout << "Thank you for your payment. Have a great day!\n";
        return false;
    }else if(payment < final_price){
        double due_change;
        due_change = final_price - payment;
        cout << "You now owe " << due_change << "\n";
        return false;
    }else{
        double return_change;
        return_change = payment - final_price;
        cout << "Your change is: $"<< return_change << "\n";
        cout << "Have a great day!";
        return false;
    }
}
