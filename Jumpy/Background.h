#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Entity.h"

class Background : public Entity
{
public:
	Background();
	virtual ~Background();

private:
	virtual void update(float deltaTime);
	float speed;
};

#endif // !BACKGROUND_H
