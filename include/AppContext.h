#ifndef APPCONTEXT_H
#define	APPCONTEXT_H

#include "ObjectsManager.h"

class AppContext
{
public:
	static bool init();
	static void clean() throw();

	static void mainLoop();
	static void stopMainLoop();

	static void setObjectsManager(ObjectsManager *objManager);
	static ObjectsManager* getObjectsManager();

private:
	AppContext();

	static bool m_KeepLooping;
	static ObjectsManager *m_ObjectsManager;
};

#endif	/* APPCONTEXT_H */
