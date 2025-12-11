#include <iostream>
#include "clsLogScreen.h"
#include "clsCurrency.h"

using namespace std;

int main()
{
	while(true) {
		if (!clsLogScreen::ShowLoginScreen()) {
			break;
		}
	}
}

