#ifndef LAYERENTITY_H
#define LAYERENTITY_H

#include <rt2d/entity.h>

class LayerEntity : public Entity {
public:
	LayerEntity();
	void update(float deltatTime);
	~LayerEntity();
private:

};

#endif // !LAYERENTITY_H
