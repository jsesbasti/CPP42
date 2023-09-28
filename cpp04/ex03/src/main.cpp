/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 07:49:24 by jsebasti          #+#    #+#             */
/*   Updated: 2023/09/28 12:34:57 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<iomanip>
#include	"AMateria.hpp"
#include	"MateriaSource.hpp"
#include	"Character.hpp"
#include	"Ice.hpp"
#include	"Cure.hpp"

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

// int main( void )
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }

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

int main( void )
{
	print_title( "1. Creating MateriaSource", C_GREEN, C_YELLOW );
	IMateriaSource* src = new MateriaSource();
	std::cout << std::endl;
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	print_title( "2. \"src\" learning 5 materias", C_GREEN, C_YELLOW );
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << std::endl;
	Ice	*mat = new Ice();
	src->learnMateria(mat);
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	print_title( "3. Creating Character \"vilma\" and \"oktorok\"", C_GREEN, C_YELLOW );
	Character* vilma = new Character("vilma");
	vilma->printMaterias();
	std::cout << std::endl;

	Character* oktorok = new Character("oktorok");
	oktorok->printMaterias();
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	print_title( "4. \"vilma\" trying to equip 5 materias and \"oktorok\" one materia", C_GREEN, C_YELLOW );
	vilma->equip(NULL);

	AMateria* tmp;
	tmp = src->createMateria("ice");
	vilma->equip(tmp);
	tmp = src->createMateria("ice");
	vilma->equip(tmp);
	tmp = src->createMateria("cure");
	vilma->equip(tmp);
	tmp = src->createMateria("cure");
	vilma->equip(tmp);
	tmp = src->createMateria("ice");
	vilma->equip(tmp);

	std::cout << std::endl;
	vilma->printMaterias();

	std::cout << std::endl;
	tmp = src->createMateria("ice");
	oktorok->equip(tmp);
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	print_title( "5. Testing Character Assignation overload \"vilma = oktorok\" for deep copy and changed vilma afterwards", C_GREEN, C_YELLOW );
	*oktorok = *vilma;

	vilma->unequip(2);
	std::cout << "VILMA" << std::endl;
	vilma->printMaterias();
	std::cout << std::endl;

	std::cout << "OKTOROK" << std::endl;
	oktorok->printMaterias();
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	print_title( "6. Testing character copy constructor for deep copy \"stardust = Character(vilma)\" and changed vilma afterwards", C_GREEN, C_YELLOW );

	vilma->printMaterias();
	Character* stardust = new Character(*vilma);
    stardust->printMaterias();

	tmp = src->createMateria("ice");
	vilma->equip(tmp);
	std::cout << "VILMA" << std::endl;
	vilma->printMaterias();
	std::cout << std::endl;

	std::cout << "STARDUST" << std::endl;
    stardust->printMaterias();


	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	print_title( "7. \"vilma\" using all equiped materias on \"oktorok\" ", C_GREEN, C_YELLOW );
	vilma->use(0, *oktorok);
	vilma->use(1, *oktorok);
	vilma->use(2, *oktorok);
	vilma->use(3, *oktorok);
	vilma->use(10, *oktorok);
	vilma->use(-1, *oktorok);
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	print_title( "8. \"vilma\" trying to use unequiped materias on \"oktorok\" ", C_GREEN, C_YELLOW );
	vilma->unequip(0);
	vilma->use(0, *oktorok);

	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	print_title( "9. New character \"lucifer\" equipping and unequipping materias", C_GREEN, C_YELLOW );
	ICharacter* lucifer = new Character("lucifer");
	AMateria *cure = new Cure;
	AMateria *ice = new Ice;

	lucifer->equip(cure);
	lucifer->equip(ice);
	lucifer->equip(cure);
	lucifer->equip(ice);
	std::cout << cure << std::endl;
	lucifer->unequip(0);
	lucifer->unequip(1);
	lucifer->unequip(2);
	lucifer->unequip(3);
	std::cout << cure << std::endl;
	lucifer->equip(cure);
	lucifer->equip(ice);

	lucifer->printMaterias();
	lucifer->printFloor();

	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	print_title( "10. Testing if unequiped materia is freed", C_GREEN, C_YELLOW );

	ICharacter* test = new Character("test");

	tmp = src->createMateria("ice");
	test->equip(tmp);
   	test->unequip(0);

	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	print_title( "11. Deleting \"vilma\", \"oktorok\", \"stardust\" and \"lucifer\"", C_RED, C_YELLOW );

	print_title( "11 -> TEST", C_RED, C_YELLOW );
	delete test;
	std::cout << std::endl;

	print_title( "11 -> LUCIFER", C_RED, C_YELLOW );
	delete lucifer;
	std::cout << std::endl;

	print_title( "11 -> STARDUST", C_RED, C_YELLOW );
	stardust->printMaterias();
	stardust->printFloor();
	delete stardust;
	std::cout << std::endl;

	print_title( "11 -> OKTOROK", C_RED, C_YELLOW );
	oktorok->printMaterias();
	oktorok->printFloor();
	delete oktorok;
	std::cout << std::endl;

	print_title( "11 -> VILMA", C_RED, C_YELLOW );
	vilma->printMaterias();
	vilma->printFloor();
	delete vilma;
	std::cout << std::endl;

	print_title( "11 -> SRC", C_RED, C_YELLOW );
	delete src;

	return (0);
}