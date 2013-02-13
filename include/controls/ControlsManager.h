#ifndef CONTROLSMANAGER_H
#define CONTROLSMANAGER_H

#include "Controls.h"

#include <string>

#define CurrentControls ControlsManager::getCurrentControls()

// Classe gérant les différents schémas de contrôles disponibles.

class ControlsManager
{
public:
	static bool readControlsFromFile(std::string fname);
	static bool writeControlsToFile(std::string fname);
	static void createControls();

	static Controls* getCurrentControls();
private:
	ControlsManager();

	static Controls *m_CurrentControls;
};

#endif // CONTROLSMANAGER_H
