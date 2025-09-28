#include <iostream>
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main(){

	//Subject default's test
	std::cout << "\033[33m---------Subject Tests---------\033[0m\n";
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	//Own tests
	std::cout << "\n\033[36m---------Own Tests---------\033[0m\n";
	
	// Test 1: Deep Copy and Independence
	std::cout << "\n=== Test 1: Deep Copy Test ===\n";
	Character alice("Alice");
	alice.equip(new Ice());
	alice.equip(new Cure());
	
	Character bob_copy(alice);  // Copy constructor
	Character charlie("Charlie");
	charlie = alice;  // Assignment operator
	
	std::cout << "Original: " << alice.getName() << std::endl;
	std::cout << "Copy constructor: " << bob_copy.getName() << std::endl;
	std::cout << "Assignment: " << charlie.getName() << std::endl;
	
	// Test that copies are independent
	alice.use(0, bob_copy);
	bob_copy.use(0, alice);
	charlie.use(1, alice);
	
	// Test 2: Inventory Overflow
	std::cout << "\n=== Test 2: Inventory Overflow ===\n";
	Character fullInventory("FullGuy");
	std::cout << "Equipping 6 materias (should only keep first 4):\n";
	fullInventory.equip(new Ice());     // Slot 0
	fullInventory.equip(new Cure());    // Slot 1
	fullInventory.equip(new Ice());     // Slot 2
	fullInventory.equip(new Cure());    // Slot 3
	fullInventory.equip(new Ice());     // Should be deleted
	fullInventory.equip(new Cure());    // Should be deleted
	
	fullInventory.use(0, alice);
	fullInventory.use(1, alice);
	fullInventory.use(2, alice);
	fullInventory.use(3, alice);
	fullInventory.use(4, alice);  // Invalid index
	
	// Test 3: Unequip and Floor System
	std::cout << "\n=== Test 3: Unequip and Floor System ===\n";
	Character unequipTest("UnequipGuy");
	unequipTest.equip(new Ice());
	unequipTest.equip(new Cure());
	
	std::cout << "Before unequip:\n";
	unequipTest.use(0, alice);
	unequipTest.use(1, alice);
	
	unequipTest.unequip(0);  // Remove ice
	std::cout << "After unequipping slot 0:\n";
	unequipTest.use(0, alice);  // Should do nothing
	unequipTest.use(1, alice);  // Should still work
	
	// Test 4: MateriaSource Overflow
	std::cout << "\n=== Test 4: MateriaSource Overflow ===\n";
	MateriaSource* overflowSrc = new MateriaSource();
	std::cout << "Learning 6 materias (should only keep first 4):\n";
	overflowSrc->learnMateria(new Ice());
	overflowSrc->learnMateria(new Cure());
	overflowSrc->learnMateria(new Ice());
	overflowSrc->learnMateria(new Cure());
	overflowSrc->learnMateria(new Ice());   // Should be deleted
	overflowSrc->learnMateria(new Cure());  // Should be deleted
	
	// Test creating materias
	AMateria* created1 = overflowSrc->createMateria("ice");
	AMateria* created2 = overflowSrc->createMateria("cure");
	AMateria* created3 = overflowSrc->createMateria("nonexistent");
	
	if (created1) {
		alice.equip(created1);
		alice.use(0, bob_copy);
	}
	if (created2) {
		alice.equip(created2);
	}
	if (!created3) {
		std::cout << "Correctly returned NULL for unknown materia type\n";
	}
	
	delete overflowSrc;
	
	// Test 5: Invalid Operations
	std::cout << "\n=== Test 5: Invalid Operations ===\n";
	Character errorTest("ErrorGuy");
	
	// Invalid indices
	errorTest.use(-1, alice);
	errorTest.use(10, alice);
	errorTest.unequip(-1);
	errorTest.unequip(10);
	
	// Null materia
	errorTest.equip(nullptr);
	
	// Empty slots
	errorTest.use(0, alice);  // Empty slot
	errorTest.unequip(0);     // Empty slot
	
	// Test 6: MateriaSource Copy
	std::cout << "\n=== Test 6: MateriaSource Copy ===\n";
	MateriaSource* original = new MateriaSource();
	original->learnMateria(new Ice());
	original->learnMateria(new Cure());
	
	MateriaSource copy1(*original);  // Copy constructor
	MateriaSource copy2;
	copy2 = *original;  // Assignment operator
	
	// Test that all can create materias
	AMateria* fromOriginal = original->createMateria("ice");
	AMateria* fromCopy1 = copy1.createMateria("cure");
	AMateria* fromCopy2 = copy2.createMateria("ice");
	
	if (fromOriginal && fromCopy1 && fromCopy2) {
		std::cout << "All MateriaSource copies work correctly\n";
		alice.equip(fromOriginal);
		alice.equip(fromCopy1);
		alice.equip(fromCopy2);
	}
	
	delete original;
	
	std::cout << "\n\033[32m=== All Tests Completed Successfully! ===\033[0m\n";
	return 0;
}
