#include <iostream>
#include "DiamondTrap.hpp"

int main() {
    std::cout << "\n\033[33m--- Creating DiamondTraps ---\033[0m\n";
    DiamondTrap dt1;                     // default
    DiamondTrap dt2("Shiny");            // parameterized
    DiamondTrap dt3(dt2);                // copy constructor

    std::cout << "\n\033[33m--- Assignment ---\033[0m\n";
    DiamondTrap dt4;
    dt4 = dt2;                           // copy assignment

    std::cout << "\n\033[33m--- Who Am I ---\033[0m\n";
    dt1.whoAmI();
    dt2.whoAmI();
    dt3.whoAmI();
    dt4.whoAmI();

    std::cout << "\n\033[33m--- Attacks ---\033[0m\n";
    dt2.attack("TargetBot");
    dt3.attack("EnemyBot");

    std::cout << "\n\033[33m--- Damage & Repair ---\033[0m\n";
    dt2.takeDamage(30);
    dt2.beRepaired(15);
    dt2.takeDamage(120);   // should kill it
    dt2.beRepaired(50);    // should not work if dead

    std::cout << "\n\033[33m--- Destruction Order ---\033[0m\n";
    return 0;
}

