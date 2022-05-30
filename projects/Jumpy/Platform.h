#ifndef PLATFORM_H
#define PLATFORM_H

#include "GameEntity.h"

class Platform : public GameEntity {
public:
	bool giveScore;

	Platform();
	virtual ~Platform();
	virtual void update(float deltaTime);

private:
	float speed;

};

#endif // !PLATFORM_H

