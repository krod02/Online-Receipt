//
//  user_interactions(RP).cpp
//  Receipt Project
//
//  Created by Kevin Rodriguez on 2/16/22.
//

#include "user_interactions(RP).hpp"

#include <iostream>
#include <string>


bool check_for_exit() {
    // Ask if they want to leave and leave on "n"
    // Returns true if they want to exit, false if still want to continue
    std::string leave = "n"; // Leave flag - checked at end, "n" leaves loop
    std::cout << "\nDo you have more items you want to order?";
    std::cin >> leave;
    if (leave[0] == 'n' || leave[0] == 'N') {
        return true;
    }
    return false;
}
