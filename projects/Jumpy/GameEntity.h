#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <rt2d/entity.h>

class GameEntity : public Entity {
public:

	GameEntity();
	void update(float deltaTime);
	~GameEntity();

	float width;
	float height;

private:

};

#endif // !GAMEENTITY_H