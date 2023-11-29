#pragma once

enum class KEY_STATE
{
	// NONE: 안눌림
	// DOWN: 딱 눌림
	// UP: 뗌
	// PRESS: 누르는중
	NONE, DOWN, UP, PRESS
};

enum class KEY_TYPE
{
	LEFT, RIGHT, UP, DOWN,
	Q, W, E, R, T, Y, U, I, O, P,
	A, S, D, F, G, H, J, K, L,
	Z, X, C, V, B, N, M,
	CTRL, LALT, LSHIFT, SPACE,
	ENTER, TAB, ESC, LBUTTON, RBUTTON, END

	// LAST의미: 끝이라는 뜻이야
};

enum class OBJECT_GROUP
{
	DEFAULT,
	PLAYER,
	WEAPON,
	MONSTER,
	BULLET,
	UI,
	END = 30
};

enum class PEN_TYPE
{
	HOLLOW, RED, GREEN,
	BLUE, YELLOW, END
};

enum class BRUSH_TYPE
{
	HOLLOW, RED, GREEN,
	BLUE, YELLOW, END
};

enum class EVENT_TYPE
{
	DELETE_OBJECT,
	CREATE_OBJECT,
	SCENE_CHANGE,
	END
};

enum class ENTITY_ELEMENT_TYPE
{
	NONE, WATER, FIRE, ELECTRICITY, END
	// 물 불 전기?...
};

enum class WEAPON_TYPE
{
	KNIFE, GUN, END
};

enum class ENEMY_STATE
{
	IDLE,
	ATTACK,
	WAIT,
	CHASE,
};

class Stat
{
public:


public:

};