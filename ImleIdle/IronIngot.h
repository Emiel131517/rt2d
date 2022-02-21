#ifndef IRONINGOT_H
#define IRONINGOT_H

#include "Material.h"
class IronIngot : public Material
{
public:
	IronIngot();
	void update(float deltaTime);
	virtual ~IronIngot();
private:

};

#endif // !IRONINGOT_H