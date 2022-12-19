#pragma once
#pragma once

class Enemy
{
private:
	//メンバ関数ポインタテーブル
	static void (Enemy::* spFuncTable[])();

	//行動フェーズ
	static enum class Phase
	{
		MeleeAttack,
		Shot,
		Secession
	};
	//フェーズ
	Phase phase_ = Phase::MeleeAttack;

	void MeleeAttack();
	void Shot();
	void Secession();

public:
	void Update();
	void Draw();
};

