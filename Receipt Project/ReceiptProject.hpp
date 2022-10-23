//
//  RecieptProject.hpp
//  Receipt Project
//
//  Created by Kevin Rodriguez on 2/16/22.
//

#ifndef RecieptProject_hpp
#define RecieptProject_hpp


#include <array>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>

struct menu{
    std::string menu_items[10] = {"Firecracker Shrimp","Shrimp Cocktail"
        ,"Grilled Salmon","Filet Mignon"
        , "Sea Bass","New York Strip Steak", "Grouper Sandwich"
        ,"Caesar Salad","House salad","Strawberry Shortcake ala Mode"};
    int prices[10] = {15,12,27,35,42,37,20,6,5,10};

};

//function that prints all values in structure
void print_menu(menu &item);

//vector that takes in the users orders and stores it
std::vector<int> order;

//function to take the users orders then  returns int corresponding to order which will be saved in vector
int take_order();

//function to display total price and calculates the price with taxes aswell
double display_total_price(std::vector<int> order);
    
//function calculates discount if applicable and returns float number
double calculate_discount();

//function to take payment. Allows user to choose if they want to pay in full of part of it
double take_payment(double final_price);


#endif /* RecieptProject_hpp */
