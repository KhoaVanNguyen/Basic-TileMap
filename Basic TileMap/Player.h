#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "GameObject.h"
class Player : public GameObject
{
public:


	// Constructor
	Player(void);
	Player(int, int);
	Player(int, int, LPDIRECT3DDEVICE9);

	// Player's Action

	void MoveLeft();
	void MoveRight();


	~Player();
};

#endif