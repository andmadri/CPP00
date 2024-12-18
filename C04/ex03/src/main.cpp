#include "../incl/Character.hpp"
#include "../incl/MateriaSource.hpp"
#include "../incl/Ice.hpp"
#include "../incl/Cure.hpp"

int main(){

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

	me->unequip(1);
	me->use(1, *bob);

	tmp = src->createMateria("air");
	me->equip(tmp);
	me->use(3, *bob);

	me->unequip(3);


	delete bob;
	delete me;
	delete src;
	return 0;

}