#include "../incl/AMateria.hpp"

AMateria::AMateria(std::string const & type): m_type(type){
}

std::string const & AMateria::getType() const{
    return m_type;
}

void AMateria::use(ICharacter& target){
	std::cout << "* Materia used by " << target.getName() << " *";
}
