
#include <iostream>

#include "Composant1.h"
#include "Composant2.h"


int main(int argc, char ** argv)
{

	void *Composant1_;
	void *Composant2_;

	Composant1_ = dlopen (argv[1], RTLD_LAZY);
	if (!Composant1_) {
		printf ("Error dlopen: %s\n", dlerror());
        	exit(EXIT_FAILURE);
    	}

	Composant2_ = dlopen (argv[2], RTLD_LAZY);
	if (!Composant2_) {
		printf ("Error dlopen: %s\n", dlerror ());
		exit(EXIT_FAILURE);
    	}

	int (*composant1)(int, int) = (int (*)(int, int))dlsym(Composant1_, "Composant1-test1");
	if (!composant1) {
                printf ("Error dlsym: %s\n", dlerror());
                exit(EXIT_FAILURE);
        }
	int (*composant2)(int, int) = (int (*)(int, int))dlsym(Composant2_, "Composant2-test2");
	if (!composant2) {
                printf ("Error dlsym: %s\n", dlerror());
                exit(EXIT_FAILURE);
        }
	
	char *(*getComposant1Version)() = (char *(*)())dlsym(Composant1_, "getComposant1Versionv");
	if (!getComposant1Version) {
                printf ("Error dlsym: %s\n", dlerror());
                exit(EXIT_FAILURE);
        }
	
	char *(*getComposant2Version)() = (char *(*)())dlsym(Composant2_, "getComposant2Versionv");
	if (!getComposant2Version) {
                printf ("Error dlsym: %s\n", dlerror());
                exit(EXIT_FAILURE);
        }

	int data1=3;
	int data2=5;
	int valeur1=composant1(data1,data2);
	int valeur2=composant2(data1,data2);

	std::cout << getComposant1Version() << std::endl;
	std::cout << getComposant2Version() << std::endl;
	std::cout << "valeur 1 :" << valeur1 << " valeur 2 :" << valeur2 << std::endl;

	dlclose(Composant1_);
	dlclose(Composant2_);
	

}
