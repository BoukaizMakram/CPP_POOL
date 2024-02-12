/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:13:06 by mboukaiz          #+#    #+#             */
/*   Updated: 2024/02/11 15:13:57 by mboukaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
public:
	Contact();
	void setContactInfo();
	void displayContact(int index) const;

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

class PhoneBook {
public:
	PhoneBook();
	void addContact();
	void searchContacts() const;

private:
	static const int maxContacts = 8;
	Contact contacts[maxContacts];
	int currentContactIndex;
};

Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

void Contact::setContactInfo() {
	std::cout << "Enter First Name: ";
	std::getline(std::cin, firstName);

	std::cout << "Enter Last Name: ";
	std::getline(std::cin, lastName);

	std::cout << "Enter Nickname: ";
	std::getline(std::cin, nickname);

	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, phoneNumber);

	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, darkestSecret);
}

void Contact::displayContact(int index) const {
	std::cout << std::setw(10) << index + 1 << "|"
			  << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName) << "|"
			  << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName) << "|"
			  << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << "|"
			  << std::endl;
}

PhoneBook::PhoneBook() : currentContactIndex(0) {}

void PhoneBook::addContact() 
{
	if (currentContactIndex < maxContacts) {
		contacts[currentContactIndex].setContactInfo();
		currentContactIndex++;
	} else {
		std::cout << "Phonebook is full. Deleting the oldest contact and adding a new one." << std::endl;
		// Replace the oldest contact by overwriting it with the new contact
		currentContactIndex = 0;
		contacts[currentContactIndex].setContactInfo();
	}
}

void PhoneBook::searchContacts() const {
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << "|"
			  << std::endl;

	for (int i = 0; i < currentContactIndex; ++i) {
		contacts[i].displayContact(i);
	}

	if (currentContactIndex == 0) {
		std::cout << "Phonebook is empty." << std::endl;
		return;
	}

	std::cout << "Enter the index of the contact you want to display: ";
	int index;
	std::cin >> index;
	std::cin.ignore();

	if (index > 0 && index <= currentContactIndex) {
		contacts[index - 1].displayContact(index - 1);
	} else {
		std::cout << "Invalid index. Please enter a valid index." << std::endl;
	}
}

int main() {
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::cin >> command;
		std::cin.ignore();

		if (!(std::cin >> command)) 
		{
			// Handle EOF or other input failure
			std::cout << "Input error or EOF encountered. Exiting." << std::endl;
			break;
		}
		if (command == "ADD") 
		{
			phoneBook.addContact();
		} 
		else if (command == "SEARCH") 
		{
			phoneBook.searchContacts();
		} 
		else if (command == "EXIT") 
		{
			std::cout << "Exiting phonebook. Contacts are lost forever!" << std::endl;
			break;
		} else 
		{
			std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
		}
	}

	return (0);
}
