#pragma once
class State; class Enemy;
class AI {
public:
	AI(Enemy* _owner);
	~AI();
public:
	void AddState(ENEMY_STATE _enemyType, State* _state); //���� �߰�
	State* FindState(ENEMY_STATE _stateType);
	void UpdateState();
	void ChangeState(State* _state); //���� ����
public:
	Enemy* owner;
private:
	State* curState;
	State* prevState;
	map<ENEMY_STATE, State*> state_maps;
};