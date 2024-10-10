#include "pch.h"
#include "Ball.h"
void Ball::Init()
{
	_ballBody = CenterRect(200, 450, 20, 20);
}
void Ball::Render(HDC hdc)
{
	_ballBody.Draw(hdc);
}
void Ball::Update()
{

}
void Ball::Release()
{

}