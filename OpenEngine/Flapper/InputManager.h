#ifndef INPUTMANAGER
#define INPUTMANAGER
#include "../Engine/IO/Keyboard.h"
#include "../Engine/IO/Mouse.h"
#include "Flapper.h"


class InputManager
{
	Flapper* flapper;


public:
	InputManager(Flapper* _flapper);

	void Update();
};

#endif
