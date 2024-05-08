#include "Player.h"
#include "CDTimer.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Player.fbx");
	assert(hModel_ >= 0);
}

void Player::Update()
{
	if (Input::IsKeyDown(DIK_LEFT))
	{
		transform_.position_.x += 5;
		cdtimer_->ResetTimer();
		cdtimer_->StatrTimer();
	}
	if (Input::IsKeyDown(DIK_RIGHT))
	{
		transform_.position_.x -= 5;
		cdtimer_->ResetTimer();
		cdtimer_->StatrTimer();
	}

}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
