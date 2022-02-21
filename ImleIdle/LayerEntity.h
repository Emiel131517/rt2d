#ifndef LAYERENTITY_H
#define LAYERENTITY_H

#include <rt2d/Entity.h>

class LayerEntity : public Entity
{
public:
	LayerEntity();
	void update(float deltaTime);
	virtual ~LayerEntity();
private:

};

#endif // !LAYERENTITY_H