//
//  main.cpp
//  Receipt Project
//
//  Created by Kevin Rodriguez on 2/15/22.
//

#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>
#include "ReceiptProject.hpp"
#include "user_interactions(RP).hpp"
#include "fileOperationsRP.hpp"

using std::cout;
using std::cin;
using std::string;
using std::to_string;

//function to wrap information going into ejournal
void append_receipts(double num_price, double num_discount, double final_price){
    
    std::vector<string> receipt;//vector where variable containing info will be stored
    
    
    //std::setprecision(2);
    //everything is being concatinated into one variable
    string new_receipt;
    new_receipt =  "Total cost: " + to_string(num_price) + "\nDiscount: " + to_string(num_discount*100) + "%\nFinal bill: " + to_string(final_price) + "\n===============\n";
        
    receipt.push_back(new_receipt);
    
    append_lines(receipt);

}

int main() {
    do{
        menu item{};//initialize variable item with our structure type
        print_menu(item);//call to print menu using structure
        order.push_back(item.prices[take_order()]);//stores the item prices in vector using the take order function
        //since function returns a number, it uses that number to choose an item in the prices structure
        
        
    }while(!check_for_exit());
    //used the following lines to only display two numbers after decimal points
    cout << std::fixed;
    cout<< std::setprecision(2);
    
    //made two variables equal to the values the functions returns ino order to calculate final price using total price and discount applicable
    double num_discount = calculate_discount();
    double num_price = display_total_price(order);
    //code to calculate price with discount
    double final_price;
    double total_discount = num_price * num_discount;
    final_price = num_price - (total_discount);
    cout << final_price << "\n";
    
    append_receipts(num_price, num_discount, final_price);
    
    //code to allow user to make more then one payment if needed
    //was not able to figure out how to maintain the value of the price after first payment
    //value would reset back to original price.
    //Decided to leave it like this because it at least ends the program even after incomplete payment
    bool end_program = true;
    while(end_program){
        end_program = take_payment( final_price);
    }
}
