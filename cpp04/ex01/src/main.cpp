/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 07:46:59 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/14 08:01:28 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Animal.hpp"
#include	"Cat.hpp"
#include	"Dog.hpp"
#include	<iostream>
#include	<iomanip>
#include	<sstream>

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

std::string	long_to_string( long num )
{
	std::string		str;
	std::stringstream	ss;

	ss << num;
	str = ss.str();
	return ( str );
}

void	test_Animal_v1( void )
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

void	test_Cat( Cat *cat, unsigned int first_getIdea_idx, unsigned int second_getIdea_idx, std::ostream& out )
{
	out << "getType(): " << cat->getType();
	out << " | getIdea( 0 ): " << cat->getIdea( first_getIdea_idx );
	out << " | getIdea( 1 ): " << cat->getIdea( second_getIdea_idx );
	out << " | getIndex(): " << cat->getIndex();
	out << " | getCurrentIdea(): " << cat->getCurrentIdea() << std::endl;
	out << std::endl;
}

void	test_Dog( Dog *dog, unsigned int first_getIdea_idx, unsigned int second_getIdea_idx, std::ostream& out )
{
	out << "getType(): " << dog->getType();
	out << " | getIdea( 0 ): " << dog->getIdea( first_getIdea_idx );
	out << " | getIdea( 1 ): " << dog->getIdea( second_getIdea_idx );
	out << " | getIndex(): " << dog->getIndex();
	out << " | getCurrentIdea(): " << dog->getCurrentIdea() << std::endl;
	out << std::endl;
}

void	test_Animal_basic_v2( Animal* animals[], unsigned short int size, unsigned int c_size, unsigned short int (*cmp)( unsigned int , unsigned int ) )
{
	unsigned short int lower;

	print_title( "Methods: getType() && getIdea( 0 ) && getIdea( 1 ) && getIndex() && getCurrentIdea() ( std::cout )", C_PURPLE, C_YELLOW );
	for ( unsigned int i = 0; i < c_size; i++ )
	{
		lower = cmp( i, size );
		std::cout << C_PURPLE"Animal* animals[ "C_WHITE << i << C_PURPLE" ]"C_WHITE << std::endl;
		switch ( lower )
		{
			case 1:
				test_Cat( dynamic_cast<Cat *>( animals[ i ] ), 0, 1, std::cout );
				break ;
			default:
				test_Dog( dynamic_cast<Dog *>( animals[ i ] ), 0, 1, std::cout );
				break ;
		}
		std::cout << std::endl;
	}
}

void	test_assignation_operator( Animal* animals[], unsigned short int size)
{
	print_title( "animals[ First Cat ] = animals[ First dog ]", C_PINK, C_YELLOW );
	std::cout << C_WHITE;
	*( static_cast<Cat *>( animals[ 0 ] ) ) = *( static_cast<Cat *>( animals[ size ] ) );
	std::cout << "animal[ 0 ] -> getIdea( 0 ): " << static_cast<Dog *>( animals[ 0 ] )->getIdea( 0 ) << std::endl;
	std::cout << "  		  |" << std::endl;
	std::cout << "  		  |" << std::endl;
	std::cout << "animal[ " << size << " ] -> getIdea( 0 ): " << static_cast<Dog *>( animals[ size ] )->getIdea( 0 ) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "animal[ 0 ] -> makeSound(): ";
	static_cast<Dog *>( animals[ 0 ] )->makeSound();
	std::cout << "  		  |" << std::endl;
	std::cout << "  		  |" << std::endl;
	std::cout << "animal[ " << size << " ] -> makeSound(): ";
	static_cast<Dog *>( animals[ size ] )->makeSound();
	std::cout << std::endl;
	print_title( "animals[ 0 ] = animals[ 0 ]", C_PINK, C_YELLOW );
	std::cout << C_WHITE;
	*( static_cast<Cat *>( animals[ 0 ] ) ) = *( static_cast<Cat *>( animals[ 0 ] ) );
	std::cout << "animal[ 0 ] -> getIdea( 0 ): " << static_cast<Cat *>( animals[ 0 ] )->getIdea( 0 );
	std::cout << " |---| getType(): " << static_cast<Cat *>( animals[ 0 ] )->getType();
	std::cout << " |---| makeSound(): ";
	static_cast<Dog *>( animals[ 0 ] )->makeSound();
	std::cout << std::endl;
}

void	test_addIdea_getIndex_getCurrentIdea( Animal* animals[], unsigned short int size, bool dog_edition )
{
	unsigned int	idx;
	std::string		title;
	std::string		idea;

	idx = dog_edition == true ? size : 0;
	print_title( "getIndex() && getCurrentIdea()", C_PINK, C_YELLOW );
	std::cout << C_WHITE;
	std::cout << "animals[ " << idx << " ]->getIndex(): " << static_cast<Cat *>( animals[ idx ] )->getIndex() << std::endl;
	std::cout << "animals[ " << idx << " ]->getCurrentIdea(): " << static_cast<Cat *>( animals[ idx ] )->getCurrentIdea() << std::endl;
	title = "Adding 99 ideas to animals[ " + long_to_string( idx ) + " ]: animals[ " + long_to_string( idx ) +  " ]->addIdea( \"Test Idea i\" )";
	print_title( title, C_PINK, C_YELLOW );
	std::cout << C_WHITE;
	for ( unsigned int i = 1; i < MAX_IDEAS; i++)
	{
		idea = "Test Idea " + long_to_string( i );
		static_cast<Cat *>( animals[ idx ] )->addIdea( idea );
	}
	print_title( "getIndex()", C_PINK, C_YELLOW );
	std::cout << C_WHITE;
	std::cout << "animals[ " << idx << " ]->getIndex(): " << static_cast<Cat *>( animals[ idx ] )->getIndex() << std::endl;
	std::cout << "animals[ " << idx << " ]->getCurrentIdea(): " << static_cast<Cat *>( animals[ idx ] )->getCurrentIdea() << std::endl;
	title = "Adding 1 idea to animals[ " + long_to_string( idx ) + " ]: animals[ " + long_to_string( idx ) +  " ]->addIdea( \"Overflow test idea\" )";
	print_title( title, C_PINK, C_YELLOW );
	std::cout << C_WHITE;
	static_cast<Cat *>( animals[ idx ] )->addIdea( "Overflow test idea" );
	print_title( "getIndex()", C_PINK, C_YELLOW );
	std::cout << C_WHITE;
	std::cout << "animals[ " << idx << " ]->getIndex(): " << static_cast<Cat *>( animals[ idx ] )->getIndex() << std::endl;
	std::cout << "animals[ " << idx << " ]->getCurrentIdea(): " << static_cast<Cat *>( animals[ idx ] )->getCurrentIdea() << std::endl;
	( void )size;
}

void	test_getIdea_idx( Animal* animals[], unsigned int idx, long int idea_idx )
{
	std::string		title;

	title = "animals[ " + long_to_string( idx ) + " ]: animals[ " + long_to_string( idx ) +  " ]->getIdea( " + long_to_string( idea_idx ) + " )";
	print_title( title, C_PINK, C_YELLOW );
	std::cout << C_WHITE;
	std::cout << "animals[ " << idx << " ]->getIdea( " << idea_idx << " ): " << static_cast<Cat *>( animals[ idx ] )->getIdea( idea_idx ) << std::endl;	
}

void	test_getIdea( Animal* animals[], unsigned short int size, bool dog_edition )
{
	unsigned int	idx;

	idx = dog_edition == true ? size : 0;
	test_getIdea_idx( animals, idx, -1 );
	test_getIdea_idx( animals, idx, 0 );
	test_getIdea_idx( animals, idx, 1 );
	test_getIdea_idx( animals, idx, 99 );
	test_getIdea_idx( animals, idx, 100 );
}

void	test_Animal_advanced_v2( Animal* animals[], unsigned short int size )
{
	print_title( "Assignation operator Tests", C_PURPLE, C_YELLOW);
	test_assignation_operator( animals, size );
	print_title( "addIdea && getIndex && getCurrenIdea Tests: Cat Edition", C_PURPLE, C_YELLOW);
	test_addIdea_getIndex_getCurrentIdea( animals, size, false );
	print_title( "addIdea && getIndex && getCurrenIdea Tests: Dog Edition", C_PURPLE, C_YELLOW);
	test_addIdea_getIndex_getCurrentIdea( animals, size, true );
	print_title( "getIdea Tests: Cat Edition", C_PURPLE, C_YELLOW);
	test_getIdea( animals, size, false );
	print_title( "getIdea Tests: Dog Edition", C_PURPLE, C_YELLOW);
	test_getIdea( animals, size, true );
	return ;
}

unsigned short int	lower_than( unsigned int num1, unsigned int num2 )
{
	if ( num1 < num2 )
		return ( 1 );
	return ( 0 );
}

void	test_Animal_v2( unsigned short int size )
{
	unsigned int		c_size;
	unsigned short int	lower;

	c_size = size * 2;
	print_title( "Constructors", C_GREEN, C_YELLOW );
	std::cout << C_GREEN"Animal* animals[ "C_WHITE << c_size << C_GREEN" ]"C_DEFAULT << std::endl;
	Animal* animals[ c_size ];
	std::cout << std::endl;

	for ( unsigned int i = 0; i < c_size; i++ )
	{
		lower = i < size;
		switch ( lower )
		{
			case 1:
				std::cout << C_GREEN"Animal* animals[ "C_WHITE << i << C_GREEN" ] = new Cat()"C_DEFAULT << std::endl;
				animals[ i ] = new Cat();
				dynamic_cast<Cat *>(animals[ i ])->addIdea( "Exploding Kittens" );
				break ;
			default:
				std::cout << C_GREEN"Animal* animals[ "C_WHITE << i << C_GREEN" ] = new Dog()"C_DEFAULT << std::endl;
				animals[ i ] = new Dog();
				dynamic_cast<Dog *>(animals[ i ])->addIdea( "Exploding Puppies" );
				break ;
		}
		std::cout << std::endl;
	}

	print_title( "BASIC", C_BLUE, C_YELLOW );
	test_Animal_basic_v2( animals, size, c_size, lower_than );
	print_title( "ADVANCED", C_BLUE, C_YELLOW );
	test_Animal_advanced_v2( animals, size );

	print_title( "Destructors", C_RED, C_YELLOW );
	for ( unsigned int i = 0; i < c_size; i++ )
	{
		std::cout << C_RED"animals[ "C_WHITE << i << C_RED" ]"C_DEFAULT << std::endl;
		delete animals[ i ];
		std::cout << std::endl;
	}
}

int	main( void )
{
	print_title( "Test: Animal V.1", C_BLUE, C_YELLOW );
	test_Animal_v1();
	print_title( "Test: Animal V.2", C_BLUE, C_YELLOW );
	test_Animal_v2( 5 );
	return ( 0 );
}