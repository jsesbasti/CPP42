/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 07:46:59 by jsebasti          #+#    #+#             */
/*   Updated: 2023/10/27 10:13:47 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Animal.hpp"
#include	"Cat.hpp"
#include	"Dog.hpp"
#include	"WrongAnimal.hpp"
#include	"WrongCat.hpp"
#include	<iostream>
#include	<iomanip>

#define FILL		40
#define C_DEFAULT	"\033[0m"
#define C_RED		"\033[1;91m"
#define C_GREEN		"\033[1;92m"
#define C_YELLOW	"\033[1;93m"
#define C_BLUE		"\033[1;94m"
#define C_PINK		"\033[1;95m"
#define C_CYAN		"\033[1;96m"
#define C_WHITE		"\033[1;97m"
#define C_PURPLE	"\033[1;38;2;150;25;250m"

void    print_title( std::string msg, std::string clr_text, std::string clr_border )
{
	int	fill;
	int	odd;
	int	size;

	size = msg.length() >= FILL ? msg.length() + 10 : FILL;
	fill = ( size - msg.length() ) / 2;
	odd = msg.length() < FILL ? msg.length() % 2 : 0;
	std::cout << clr_border;
	std::cout << "\n " << std::setfill( '_' ) << std::setw( size ) << "" << std::endl;
	std::cout << "|" << std::setfill( ' ' ) << std::setw( size + 1 ) << "|" << std::endl;
	std::cout << "|" << std::setfill( ' ' ) << std::setw( size + 1 ) << "|" << std::endl;
	std::cout << "|" << std::setfill( ' ' ) << std::setw( fill + odd ) << "" << clr_text << msg << clr_border << std::setw( fill + 1 ) << "|" << std::endl;
	std::cout << "|" << std::setfill( ' ' ) << std::setw( size + 1 ) << "|" << std::endl;
	std::cout << "|" << std::setfill( '_' ) << std::setw( size + 2 ) << "|\n" << std::endl;
	std::cout << C_DEFAULT;
}

void	test_WrongAnimal( void )
{
	print_title( "Constructors", C_GREEN, C_YELLOW );
	std::cout << C_GREEN"const WrongAnimal* wrongAnimal"C_DEFAULT << std::endl;
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	std::cout << std::endl;
	std::cout << C_GREEN"const WrongAnimal* wrongAnimalCat"C_DEFAULT << std::endl;
	const WrongAnimal* wrongAnimalCat = new WrongCat();
	std::cout << std::endl;
	std::cout << C_GREEN"const WrongCat* wrongCat"C_DEFAULT << std::endl;
	const WrongCat* wrongCat = new WrongCat();

	print_title( "Methods: getType", C_PURPLE, C_YELLOW );
	std::cout << "wrongAnimal -> " << wrongAnimal->getType() << " " << std::endl;
	std::cout << "wrongAnimalCat -> " << wrongAnimalCat->getType() << " " << std::endl;
	std::cout << "wrongCat -> " << wrongCat->getType() << " " << std::endl;

	print_title( "Methods: makeSound", C_PURPLE, C_YELLOW );
	std::cout << "wrongAnimal -> ";
	wrongAnimal->makeSound();
	std::cout << "wrongAnimalCat -> ";
	wrongAnimalCat->makeSound();
	std::cout << "wrongCat -> ";
	wrongCat->makeSound();

	print_title( "Destructors", C_RED, C_YELLOW );
	std::cout << C_RED"wrongAnimal"C_DEFAULT << std::endl;
	delete wrongAnimal;
	std::cout << std::endl;
	std::cout << C_RED"wrongAnimalCat"C_DEFAULT << std::endl;
	delete wrongAnimalCat;
	std::cout << std::endl;
	std::cout << C_RED"wrongCat"C_DEFAULT << std::endl;
	delete wrongCat;
}

void	test_Animal( void )
{
	print_title( "Constructors", C_GREEN, C_YELLOW );
	std::cout << C_GREEN"const Animal* animal"C_DEFAULT << std::endl;
	const Animal* animal = new Animal();
	std::cout << std::endl;
	std::cout << C_GREEN"const Animal* animalDog"C_DEFAULT << std::endl;
	const Animal* animalDog = new Dog();
	std::cout << std::endl;
	std::cout << C_GREEN"const Animal* animalCat"C_DEFAULT << std::endl;
	const Animal* animalCat = new Cat();
	std::cout << std::endl;
	std::cout << C_GREEN"const Dog* dog"C_DEFAULT << std::endl;
	const Dog* dog = new Dog();
	std::cout << std::endl;
	std::cout << C_GREEN"const Cat* cat"C_DEFAULT << std::endl;
	const Cat* cat = new Cat();

	print_title( "Methods: getType", C_PURPLE, C_YELLOW );
	std::cout << "animal -> " << animal->getType() << " " << std::endl;
	std::cout << "animalDog -> " << animalDog->getType() << " " << std::endl;
	std::cout << "animalCat -> " << animalCat->getType() << " " << std::endl;
	std::cout << "dog -> " << dog->getType() << " " << std::endl;
	std::cout << "cat -> " << cat->getType() << " " << std::endl;

	print_title( "Methods: makeSound", C_PURPLE, C_YELLOW );
	std::cout << "animal -> ";
	animal->makeSound();	
	std::cout << "animalDog -> ";
	animalDog->makeSound();
	std::cout << "animalCat -> ";
	animalCat->makeSound();
	std::cout << "dog -> ";
	dog->makeSound();
	std::cout << "cat -> ";
	cat->makeSound();

	print_title( "Destructors", C_RED, C_YELLOW );
	std::cout << C_RED"animal"C_DEFAULT << std::endl;
	delete animal;
	std::cout << std::endl;
	std::cout << C_RED"animalDog"C_DEFAULT << std::endl;
	delete animalDog;
	std::cout << std::endl;
	std::cout << C_RED"animalCat"C_DEFAULT << std::endl;
	delete animalCat;
	std::cout << std::endl;
	std::cout << C_RED"dog"C_DEFAULT << std::endl;
	delete dog;
	std::cout << std::endl;
	std::cout << C_RED"cat"C_DEFAULT << std::endl;
	delete cat;
}

int	main( void )
{
	print_title( "Test: Animal", C_BLUE, C_YELLOW );
	test_Animal();
	print_title( "Test: WrongAnimal", C_BLUE, C_YELLOW );
	test_WrongAnimal();
	return ( 0 );
}