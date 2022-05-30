#ifndef JUMPBAR_H
#define JUMPBAR_H

#include "GameEntity.h"

class JumpBar : public GameEntity
{
public:
	JumpBar();
	void update(float deltaTime);
	~JumpBar();

	GameEntity* border;
	GameEntity* fill;

	float fillWidthScale;
	
	float borderHeight;
	float borderWidth;

	float fillHeight;
	float fillWidth;

private:

};

#endif // !JUMPBAR_H
