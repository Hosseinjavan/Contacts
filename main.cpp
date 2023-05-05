#include <iostream>
#include <string>
using namespace std;

class ContactNode {
private:
    std::string name;
    std::string email;
    std::string phone;
    ContactNode* next;

public:
    ContactNode(const std::string& name, const std::string& email,
                const std::string& phone)
                : name(name)
                , email(email)
                , phone(phone)
                , next(next){}

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        this->name = name;
    }

    const std::string &getEmail() const {
        return email;
    }

    void setEmail(const std::string &email) {
        this->email = email;
    }

    const std::string &getPhone() const {
        return phone;
    }

    void setPhone(const std::string &phone) {
        this->phone = phone;
    }

    ContactNode *getNext() const {
        return next;
    }

    void setNext(ContactNode *next) {
        this->next = next;
    }
};

class ContactsList {
private:
    ContactNode* head;
public:
    // Constructors
    ContactsList()
    {
        head = nullptr;
    }
    ContactsList(const ContactsList& other)
    {
        head = other.head;
    }

    // Destructor
    ~ContactsList()
    {
        ContactNode *current = head;
        while(current != nullptr)
        {
            ContactNode *temp = current;
            current = current->getNext();
            delete temp;
        }
    }

    // Operators
    ContactsList& operator=(const ContactsList& other) // Replace operator
    {
        head = other.head;
        return *this;
    }

    ContactsList operator+(const ContactsList& other)  // Concatenation operator
    {
        ContactNode *it = head;
        while(it != nullptr)
        {
            it = it->getNext();
        }
        it->setNext(other.head);
        return *this;
    }

    ContactsList operator-(const ContactsList other)    // Subtraction operator
    {
        ContactNode *it = head;
        while(it->getNext() != other.head)
        {
            it = it->getNext();
        }
        it->setNext(nullptr);
        return *this;
    }

    bool operator==(const ContactsList& other)         // Equality operator
    {
        return head == other.head;
    }

    ContactNode& operator[](int index)                 // Subscript operator
    {
        ContactNode *it = head;
        int counter = 0;
        while(counter < index && it != nullptr)
        {
            counter++;
            it = it->getNext();
        }
        return *it;
    }

    // Insertion method
    void addContact(const std::string& name, const std::string& email,
                    const std::string& phone){
        ContactNode *it = head;
        if(head == nullptr)
        {
            head = new ContactNode(name, email, phone);
            return;
        }
        while (it->getNext() != nullptr)
        {
            it = it->getNext();
        }
        it->setNext(new ContactNode(name, email, phone));
    }

    // Deletion methods
    void removeByName(const std::string& name) // Removes the contact with matching name
    {
        if(head->getName() == name)
        {
            head = head->getNext();
            return;
        }
        ContactNode *it = head;
        while(it->getNext()->getName() != name)
        {
            it = it->getNext();
        }
        it->setNext(it->getNext()->getNext());
    }

    // Search methods
    ContactNode* searchByName(const std::string& name)    // Returns the node with matching name
    {
        ContactNode *it = head;
        while(it != nullptr)
        {
            if(it->getName() == name)
            {
                return it;
            }
            it = it->getNext();
        }
        return nullptr;
    }

    ContactNode* searchByEmail(const std::string& email)  // Returns the node with matching email
    {
        ContactNode *it = head;
        while(it != nullptr)
        {
            if(it->getEmail() == email)
            {
                return it;
            }
            it = it->getNext();
        }
        return nullptr;
    }

    ContactNode* searchByPhone(const std::string& phone)  // Returns the node with matching phone
    {
        ContactNode *it = head;
        while(it != nullptr)
        {
            if(it->getPhone() == phone)
            {
                return it;
            }
            it = it->getNext();
        }
        return nullptr;
    }

    // Print methods
    void print()
    {
        ContactNode *it = head;
        while(it != nullptr)
        {
            std::cout << "Name: " << it->getName() << ", Email: " << it->getEmail() << ", Phone: " << it->getPhone() << std::endl;
            it = it->getNext();
        }
    }

    // Edit method
    void editContact(const std::string& name, const std::string& newEmail,
                     const std::string& newPhone) // Edits the contact with matching name
    {
        ContactNode *found = searchByName(name);
        if(found)
        {
            found->setEmail(newEmail);
            found->setPhone(newPhone);
        }
    }
};

// main function to use all the methods
int main()
{
    ContactsList contactsList;
    contactsList.addContact("mostafa", "mostafa@yahoo.com", "1");
    contactsList.addContact("esmaeel", "esmaeel@yahoo.com", "2");
    contactsList.addContact("abolfazl", "abol@gmail.com", "3");
    contactsList.editContact("mostafa", "newEmail", "4");
    ContactNode *temp = contactsList.searchByName("mostafa");
    cout << temp->getEmail() << endl;
    ContactNode index_test = contactsList[0];
    cout << index_test.getName() << endl;
    index_test = contactsList[2];
    cout << index_test.getName() << endl;
    contactsList.print();
    contactsList.removeByName("esmaeel");
    contactsList.print();
}
