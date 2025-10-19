#include "Serializer.hpp"
#include <iostream>

int main(void){

	Data topSecret;

	topSecret.id = 1;
	topSecret.name = "Agent Smith";
	topSecret.phoneNumber = 406688111;

	std::cout << "\033[32m=====BEFORE SERIALIZE=====\033[0m" << std::endl;
	std::cout << "Pointer address: " << &topSecret << std::endl;
	std::cout << "Details of Agent: " << topSecret.id 
			  << ", " << topSecret.name << ", " 
			  << topSecret.phoneNumber << std::endl << std::endl;

	uintptr_t serialized = Serializer::serialize(&topSecret);
	std::cout << "Serialized pointer: " << serialized
              << " \033[32m<--- Serialization works!\033[0m\n\n";

	std::cout << "\033[32m=====AFTER DESERIALIZE=====\033[0m" << std::endl;
	Data* deserializedData = Serializer::deserialize(serialized);
	std::cout << "Pointer address: " << deserializedData << std::endl;
	std::cout << "Deserialized information: " << deserializedData->id 
			  << ", " << deserializedData->name << ", " 
			  << deserializedData->phoneNumber << std::endl;

	return 0;
}