#ifndef PLATFORM_H
#define PLATFORM_H

#include <rt2d/entity.h>

class Platform : public Entity {
public:
	Platform();
	virtual ~Platform();
	virtual void update(float deltaTime);

private:
	float speed;

};

#endif // !PLATFORM_H

