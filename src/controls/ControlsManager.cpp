#include "controls/ControlsManager.h"

Controls *ControlsManager::m_CurrentControls = NULL;

			 /* static */ void ControlsManager::createControls()
{
	delete m_CurrentControls;
	m_CurrentControls = new Controls();
}

			 /* static */ Controls* ControlsManager::getCurrentControls()
{
	if(!m_CurrentControls)
		createControls();
	return m_CurrentControls;
}
