#pragma once
#include "GSprite.h"
#include "Global.h"
class GameObject
{
public:
	NORMAL_DIRECTION direction;
	GSprite* sprite;
	int x, y;
	int width, height;
	int vX, vY;

	void CreateSprite();

	// virtual
	virtual void Draw();

//	void OnCollision(NORMAL_DIRECTION);
	
	
	GameObject(void);
	GameObject(float _x, float _y);
	~GameObject();

	friend int CheckCollision(GameObject, GameObject);
	float SweptAABB(GameObject b1, GameObject b2, float &normalx, float &normaly);
};

