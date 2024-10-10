#include "pch.h"
#include "Stadium.h"
void Stadium::Init()
{
	_stadiumBody = CenterRect(640, 450, 1280, 900);
}
void Stadium::Render(HDC hdc)
{
	_stadiumBody.Draw(hdc);
}
void Stadium::Update()
{

}
void Stadium::Release()
{

}