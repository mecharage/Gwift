#ifndef OBJECTSMANAGER_H
#define OBJECTSMANAGER_H

class ObjectsManager
{
public:
	ObjectsManager();
	virtual ~ObjectsManager();

	void performTick(float elapsedSeconds);
};

#endif // OBJECTSMANAGER_H
