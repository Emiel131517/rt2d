#ifndef HUDCONTAINER_H
#define HUDCONTAINER_H

#include <rt2d/entity.h>
#include "text.h"
#include "JumpBarBorder.h"
#include "JumpBarFill.h"

class HudContainer : public Entity {
public:
	HudContainer();
	void update(float deltaTime);
	virtual ~HudContainer();
	
	Text* scoreText;
	Text* highScoreText;

	JumpBarBorder* jumpBarBorder;
	JumpBarFill* jumpBarFill;

private:

};

#endif // !HUDCONTAINER_H
