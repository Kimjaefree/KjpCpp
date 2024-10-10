#include "pch.h"
#include "Player.h"
#include "Ball.h"
#include "Stadium.h"
void Player::Init()
{
	// 플레이어 1과 2의 크기 지정
	_p1Body = CenterRect(100, 450, 30, 100);
	_p2Body = CenterRect(1250, 450, 30, 100);
}
void Player::Render(HDC hdc)
{
	//플레이어 1과 2 그리기
	_p1Body.Draw(hdc); 
	_p2Body.Draw(hdc);
}
void Player::Update()
{
	RECT player1Rect = _p1Body.ToRect();
	RECT player2Rect = _p2Body.ToRect();
	CenterRect ballBody = _ball->GetBody();
	CenterRect stadiumBody = _stadium->GetBody();
	RECT ballRect = ballBody.ToRect();
	RECT stadiumRect = stadiumBody.ToRect();
	RECT tmp;

	// 플레이어1 움직임
	if (InputManager::GetInstance()->GetKey(KeyCode::Up))
	{
		_p1Body.pos.y -= _moveSpeed * Time->GetDeltaTime();
	}
	if (InputManager::GetInstance()->GetKey(KeyCode::Down))
	{
		_p1Body.pos.y += _moveSpeed * Time->GetDeltaTime();
	}
	// 플레이어2 움직임
	if (InputManager::GetInstance()->GetKey(KeyCode::W))
	{
		_p2Body.pos.y -= _moveSpeed * Time->GetDeltaTime();
	}
	if (InputManager::GetInstance()->GetKey(KeyCode::S))
	{
		_p2Body.pos.y += _moveSpeed * Time->GetDeltaTime();
	}
	// 시작후 우클릭시 공 움직임
	if (InputManager::GetInstance()->GetKey(KeyCode::RightMouse))
	{
		_targetPoint = Input->GetMousePos();
	}


	Vector2 ballDir = Vector2(_targetPoint.x - ballBody.pos.x, _targetPoint.y - ballBody.pos.y);

	if (1.0f < ballDir.Length())
	{
		ballDir = ballDir.Normalize();

		//방향 * 속도
		ballBody.pos.x += ballDir.x * _ballSpeed * Time->GetDeltaTime();
		ballBody.pos.y += ballDir.y * _ballSpeed * Time->GetDeltaTime();
	}

	// 충돌체크
	// 플레이어1과 공이 충돌했을 때, 플레이어2와 충돌했을 때
	if (::IntersectRect(&tmp, &player1Rect, &ballRect))
	{
		int width = tmp.right - tmp.left;
		int height = tmp.bottom = tmp.top;
		if (width < height)
		{
			if (player1Rect.right == tmp.right)
			{
				ballBody.pos.x;
			}
			else if (player1Rect.left == tmp.left)
			{
				ballBody.pos.x = -ballBody.pos.x;
			}
		}
		else
		{
			if (player1Rect.top == tmp.top)
			{
				ballBody.pos.y = -ballBody.pos.y;
			}
			else if (player1Rect.bottom == tmp.bottom)
			{
				ballBody.pos.y;
			}
		}
		_ball->SetBody(ballBody);
	}
	else if (::IntersectRect(&tmp, &player2Rect, &ballRect))
	{
		int width = tmp.right - tmp.left;
		int height = tmp.bottom = tmp.top;

		if (width < height)
		{
			if (player2Rect.right == tmp.right)
			{
					
			}
			else if (player2Rect.left == tmp.left)
			{
				ballBody.pos.x = -ballBody.pos.x;
			}
		}
		else
		{
			if (player2Rect.top == tmp.top)
			{
				ballBody.pos.y = -ballBody.pos.y;
			}
			else if (player2Rect.bottom == tmp.bottom)
			{
				ballBody.pos.y;
			}
		}
		_ball->SetBody(ballBody);
	}
	else if (Collision::RectInRect(ballRect*, stadiumRect*)) // 공이 경기장에 충돌했을 때
	{
		int width = tmp.right - tmp.left;
		int height = tmp.bottom = tmp.top;
		// 위나 아래에 부딫힘
		if (width > height)
		{
			// Ball이 Temp.Top에 부딫힘
			if (ballRect.top == tmp.top)
			{
				ballBody.pos.y = -ballBody.pos.y;
			}
			else if (ballRect.bottom == tmp.bottom)
			{
				ballBody.pos.y;
			}
		}
		else // 좌측이나 우측에 부딫힘
		{
			if (ballRect.left == tmp.left)
			{
				_player2Score++; // 플레이어2 점수 증가
			}
			else if (ballRect.right == tmp.right)
			{
				_player1Score++; // 플레이어1 점수 증가
			}
		}

		_ball->SetBody(ballBody);
	}
}
void Player::Release()
{

}

