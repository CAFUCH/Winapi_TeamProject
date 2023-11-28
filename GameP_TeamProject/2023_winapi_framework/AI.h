#pragma once
class State; class Enemy;
class AI {
public:
	AI(Enemy* _owner);
	~AI();
public:
	void InitState(ENEMY_STATE _enemyType);
	void AddState(ENEMY_STATE _enemyType, State* _state); //상태 추가
	void UpdateState();
	void ChangeState(ENEMY_STATE _enemyType); //상태 변경
	State* FindState(ENEMY_STATE _stateType);
public:
	Enemy* GetOnwer() const { return owner; }
private:
	Enemy* owner;
	State* curState;
	State* prevState;
	map<ENEMY_STATE, State*> state_maps;
};