#include "../incl/Phonebook.hpp"

static void getValidInput(std::string& input, const std::string& prompt){
	while(input.empty()){
		std::cout << "Invalid Input. Try Again" << std::endl << prompt << ": ";
		while(!(getline(std::cin, input))){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Input Error, Try Again" << std::endl;
			}
	}
}

static void getContactInput(const std::string& prompt, std::string& input){
	std::cout << prompt;
	while(!(getline(std::cin, input))){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Input Error, Try Again" << std::endl;
	}
	if(input.empty()){
		getValidInput(input, prompt);
	}
}

void Phonebook::addContact(int index){
	std::string input;

    Contact& contact = getContact(index);
	contact.setIndexContact(index);
	getContactInput("First Name: ", input);
	contact.setFirstName(input);
	getContactInput("Last Name: ", input);
	contact.setLastName(input);
	getContactInput("Nickname: ", input);
	contact.setNickname(input);
	getContactInput("Phonenumber: ", input);
	contact.setPhonenumber(input);
	getContactInput("Darkest Secret: ", input);
	contact.setDarkestSecret(input);
}

static void truncateAndReplace(std::string& str, std::size_t maxl){
	if (str.length() >= 10){
		str.resize(maxl);
		str[maxl - 1] = '.';
	}
}

static void printColumn(const std::string& str){
	std::string truncated_str = str;
	truncateAndReplace(truncated_str, 10);
	std::cout << "|" << std::setw(10) << std::right << truncated_str;
}

void Phonebook::displaySavedContacts(){
	for(int i = 0; i < 8; i++){
		Contact& contact = getContact(i);
		if (contact.getFirstName().empty()){
			break;
		}
		printColumn(std::to_string(contact.getIndexContact()));
		printColumn(contact.getFirstName());
		printColumn(contact.getLastname());
		printColumn(contact.getNickname());
		std::cout << std::endl;
	}
}

Contact& Phonebook::getContact(int index){
	return m_contacts[index];
}

void Phonebook::displayOneContact(){
	int prompted_index = -1;
	while (true){
		std::cout << "Enter Index to Display Contact Information: ";
		if (std::cin >> prompted_index && prompted_index >= 0 && prompted_index < 8){
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break ;
		}
		else {
			if (std::cin.eof() || std::cin.bad()){
				// std::cin.clear();
				// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Error detected" << std::endl;
				std::exit(1);
			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong index. Pick one from 0 to 7" << std::endl;
		}
	}
	Contact& contact = getContact(prompted_index);
	if (contact.getFirstName().empty()){
		std::cout << "Contact at Provided Index is Empty" << std::endl;
		return ;
	}
	std::cout << "First Name: " + contact.getFirstName() << std:: endl;
	std::cout << "Last Name: " + contact.getLastname() << std::endl;
	std::cout << "Nickname: " + contact.getNickname() << std::endl;
	std::cout << "Phonenumber: " + contact.getPhonenumber() << std::endl;
	std::cout << "Darkest Secret: " + contact.getDarkestSecret() << std::endl;
}
