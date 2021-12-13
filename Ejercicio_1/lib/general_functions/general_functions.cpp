#include "general_functions.h"

#include "AwesomeLibrary.h"

using std::cout;


void showCreationMessage(string objectName, bool articleMale, unsigned int lines)
{
	setForegroundColor(Color::GREEN);

	articleMale ? cout << "Se ha creado un " << objectName << ".\n" : cout << "Se ha creado una " << objectName << ".\n";

	// Hice el casteo estático con lines para que no me aparezca el warning de que no coincide el "signed" con el "unsigned".
	for (int i = 0; i < static_cast<int>(lines); i++)
	{
		cout << "\n";
	}

	setForegroundColor(Color::WHITE);
}
void showDestructionMessage(string objectName, bool articleMale, unsigned int lines)
{
	setForegroundColor(Color::RED);

	articleMale ? cout << "El " << objectName << " ha sido eliminado de la memoria.\n" : cout << "La " << objectName << " ha sido eliminada de la memoria.\n";

	// Hice el casteo estático con lines para que no me aparezca el warning de que no coincide el "signed" con el "unsigned".
	for (int i = 0; i < static_cast<int>(lines); i++)
	{
		cout << "\n";
	}

	setForegroundColor(Color::WHITE);
}
