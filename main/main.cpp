
#include <iostream>
#include <dlfcn.h>
#include "Composant1.h"
#include "Composant2.h"

int main(int argc, char ** argv)
{

	int choice = -1;

	while (choice != 1 &&  choice != 2) {
		std::cout << "Enter the component id : " << std::endl;
		std::cin >> choice;
	}
	void* hundler = nullptr;

	if (choice == 1) {
		hundler = dlopen("./libComposant1.so", RTLD_LAZY);
	} else {
		hundler = dlopen("./libComposant2.so", RTLD_LAZY);
	}

	if (!hundler) {
		std::cerr << "dlopen : " << dlerror() << std::endl;
		exit(EXIT_FAILURE);
	}

	int (*dlsym_function) (int, int);

	if (choice == 1) {
		dlsym_function = (int (*) (int, int)) dlsym(hundler, "composant1");
	} else {
		dlsym_function = (int (*) (int, int)) dlsym(hundler, "composant2");
	}


	if (!dlsym_function) {
		std::cerr << "dlsym : " << dlerror() << std::endl;
		std::cout<<"ERREUR dlsym_function"<<std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "Valeur : " <<  dlsym_function(data1, data2) << std::endl;


		
	//char *(*getComposant1Version)() = (char *(*)())dlsym(Composant1_, "getComposant1Versionv");
	//if (!getComposant1Version) {
        //        printf ("Error dlsym: %s\n", dlerror());
        //        exit(EXIT_FAILURE);
        //}

	int data1=3;
	int data2=5;
	int valeur1=composant1(data1,data2);
	int valeur2=composant2(data1,data2);

	//std::cout << getComposant1Version() << std::endl;
	//std::cout << getComposant2Version() << std::endl;
	std::cout << "valeur 1 :" << valeur1 << " valeur 2 :" << valeur2 << std::endl;

	//dlclose(Composant1_);
	//dlclose(Composant2_);
	
	dlclose(hundler);
	exit(EXIT_SUCCESS);
	

}
