#ifndef PLATFORM_H
#define PLATFORM_H

#include <rt2d/entity.h>

class Platform : public Entity {
public:
	Platform();
	virtual ~Platform();
	vitrual void Update(deltaTime);


private:
	Platform* platform
}

#endif // !PLATFORM_H

