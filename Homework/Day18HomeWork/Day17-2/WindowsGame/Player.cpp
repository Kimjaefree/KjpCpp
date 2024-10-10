#include "pch.h"
#include "Player.h"
#include "Ball.h"
#include "Stadium.h"
void Player::Init()
{
	// �÷��̾� 1�� 2�� ũ�� ����
	_p1Body = CenterRect(100, 450, 30, 100);
	_p2Body = CenterRect(1250, 450, 30, 100);
}
void Player::Render(HDC hdc)
{
	//�÷��̾� 1�� 2 �׸���
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

	// �÷��̾�1 ������
	if (InputManager::GetInstance()->GetKey(KeyCode::Up))
	{
		_p1Body.pos.y -= _moveSpeed * Time->GetDeltaTime();
	}
	if (InputManager::GetInstance()->GetKey(KeyCode::Down))
	{
		_p1Body.pos.y += _moveSpeed * Time->GetDeltaTime();
	}
	// �÷��̾�2 ������
	if (InputManager::GetInstance()->GetKey(KeyCode::W))
	{
		_p2Body.pos.y -= _moveSpeed * Time->GetDeltaTime();
	}
	if (InputManager::GetInstance()->GetKey(KeyCode::S))
	{
		_p2Body.pos.y += _moveSpeed * Time->GetDeltaTime();
	}
	// ������ ��Ŭ���� �� ������
	if (InputManager::GetInstance()->GetKey(KeyCode::RightMouse))
	{
		_targetPoint = Input->GetMousePos();
	}


	Vector2 ballDir = Vector2(_targetPoint.x - ballBody.pos.x, _targetPoint.y - ballBody.pos.y);

	if (1.0f < ballDir.Length())
	{
		ballDir = ballDir.Normalize();

		//���� * �ӵ�
		ballBody.pos.x += ballDir.x * _ballSpeed * Time->GetDeltaTime();
		ballBody.pos.y += ballDir.y * _ballSpeed * Time->GetDeltaTime();
	}

	// �浹üũ
	// �÷��̾�1�� ���� �浹���� ��, �÷��̾�2�� �浹���� ��
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
	else if (Collision::RectInRect(ballRect*, stadiumRect*)) // ���� ����忡 �浹���� ��
	{
		int width = tmp.right - tmp.left;
		int height = tmp.bottom = tmp.top;
		// ���� �Ʒ��� �΋H��
		if (width > height)
		{
			// Ball�� Temp.Top�� �΋H��
			if (ballRect.top == tmp.top)
			{
				ballBody.pos.y = -ballBody.pos.y;
			}
			else if (ballRect.bottom == tmp.bottom)
			{
				ballBody.pos.y;
			}
		}
		else // �����̳� ������ �΋H��
		{
			if (ballRect.left == tmp.left)
			{
				_player2Score++; // �÷��̾�2 ���� ����
			}
			else if (ballRect.right == tmp.right)
			{
				_player1Score++; // �÷��̾�1 ���� ����
			}
		}

		_ball->SetBody(ballBody);
	}
}
void Player::Release()
{

}

