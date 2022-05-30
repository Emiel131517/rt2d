#ifndef HUDCONTAINER_H
#define HUDCONTAINER_H

#include <rt2d/entity.h>
#include "text.h"
#include "JumpBar.h"

class HudContainer : public Entity {
public:
	HudContainer();
	void update(float deltaTime);
	virtual ~HudContainer();
	
	Text* scoreText;
	Text* highScoreText;
	JumpBar* jumpBar;
private:

};

#endif // !HUDCONTAINER_H
