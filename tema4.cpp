#include <iostream>
#include <memory>
#include <string>
using namespace std;

//deleter
struct Deleter {
	void operator()(int* ptr) const
	{
		cout << "Stergerea resursei: " << *ptr << endl;
		delete ptr;
	}
};

//resource manager
class ResourceManager {
public:
	//constructor care aloca o resursa
	ResourceManager(int valoare) : resource_(new int(valoare), Deleter()) {
		cout << "Resursa creata cu valoarea: " << *resource_ << endl;
	}

	//constructor de copiere
	ResourceManager(const ResourceManager& other) : resource_(other.resource_) {
		cout << "Resursa copiata: " << *resource_<< endl;
	}

	//getter
	int getValue() const {
		return *resource_;
	}

	//setare valori
	void setValue(int valoare) {
		*resource_ = valoare;
	}

private:
	shared_ptr<int> resource_;  //shared_ptr cu deleter
};

int main() 
{
	ResourceManager resource1(30);

	//copiere
	ResourceManager resource2 = resource1;

	//modificare valoare
	resource2.setValue(60);

	cout << "Valoarea pentru resource1: " << resource1.getValue() << endl;
	cout << "Valoarea pentru resource2: " << resource2.getValue() << endl;

	return 0;
}

