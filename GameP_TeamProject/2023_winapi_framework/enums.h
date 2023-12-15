#pragma once

enum class KEY_STATE
{
	// NONE: �ȴ���
	// DOWN: �� ����
	// UP: ��
	// PRESS: ��������
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

	// LAST�ǹ�: ���̶�� ���̾�
};

enum class OBJECT_GROUP
{
	DEFAULT,
	PLAYER,
	WEAPON,
	MONSTER,
	BULLET,
	PARTICLE,
	Panel,
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
	WATER = 0, FIRE, ELECTRICITY, END
	// �� �� ����?...
};

enum class WEAPON_TYPE
{
	KNIFE, GUN, END
};

enum class PARTICLE_TYPE
{
	WATHER_ELEM = 0, FIRE_ELEM, ELECT_ELEM, ATTACK, HIT, AIM, END
};

enum class ENEMY_STATE
{
	IDLE,
	ATTACK,
	WAIT,
	CHASE,
};
enum class ENEMY_TYPE {
	MELEE_ENEMY,
	RANGE_ENEMY,
};

class Stat
{
public:


public:

};