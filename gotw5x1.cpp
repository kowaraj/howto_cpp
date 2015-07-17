#include <iostream>
using namespace std;

class Animal
{
public:
	void eat() { std::cout << "I'm eating generic food." << endl; }
	virtual void veat() { std::cout << "I'm veating generic food." << endl; }
};

class Cat : public Animal
{
public:
	void eat() { std::cout << "I'm eating a rat." << endl; }
	void veat() { std::cout << "I'm veating a RAT! - Virtual function overridden in Cat" << endl; }
};

void func(Animal *xyz) { 

	/*
	Without "virtual" you get "early binding". 
	Which implementation of the method is used gets decided at compile time
	based on the type of the pointer that you call through.
	
	With "virtual" you get "late binding". 
	Which implementation of the method is used gets decided at run time 
	based on the type of the pointed-to object - what it was originally constructed as. 
	This is not necessarily what you'd think based on the type of the pointer that points to that object.
	*/

	xyz->eat(); 
	xyz->veat(); // !!! outputs: "I'm eating a rat. for Cat"
}

int main() 
{ 
	Animal *animal = new Animal;
	Cat *cat = new Cat;

	//animal->eat(); // outputs: "I'm eating generic food."
	//cat->eat();    // outputs: "I'm eating a rat."

	func(animal); // outputs: "I'm eating generic food."
	func(cat);    // outputs: "I'm eating generic food."
}
