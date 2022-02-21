#ifndef MATERIAL_H
#define MATERIAL_H

#include "GameEntity.h"
class Material : public GameEntity
{
public:
	Material();
	void update(float deltaTime);
	virtual ~Material();

	int worth;
private:

};

#endif // !MATERIAL_H