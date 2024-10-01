#include "pch.h"
#include "Game.h"

using namespace Collision;
Game::Game()
{

}
Game::~Game()
{

}

void Game::Init(HWND hWnd)
{
    this->_hwnd = hWnd;

    //1. _hdc를 유저에게 보여줄 DC로 받아준다.
    this->_hdc = ::GetDC(_hwnd);


    //==========================================
    //   ## 더블버퍼링 세팅 ##
    //==========================================

    //2. _hdc 화면과 똑같은 크기의 화면을 생성한다.
    _hdcBack = ::CreateCompatibleDC(_hdc);
    // 윈도우의 크기를 받아옴
    ::GetClientRect(_hwnd, &_rect);
    // hdc와 호환되는 비트맵 생성
    _bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom);
    //_hdcBack에 _bmpBack 연결
    HBITMAP prev = (HBITMAP)SelectObject(_hdcBack, _bmpBack);
    // 기존에 적용되어있던 _hdcBack 비트맵 삭제
    DeleteObject(prev);


    _input.Init(_hwnd);


    _player = CenterRect(300, 100, 80, 80);
    _anotherRc = CenterRect(800, 800, 300, 300);
    _wrapRc = CenterRect(300, 100, 300, 300);
}

void Game::Update()
{
    _input.Update();
    // 해보면서 생긴 궁금점
    // 1. 윈도우 프로시저로 상하좌우 어디가 맞닿았는지 확인해서 맞닿은 부분에 따라 사각형을 이동시키는 조건을 이런식으로 검사해도 되는지
    // else if (RectInRect(_player, _wrapRc) && _player.pos.x - _player.width / 2 == _wrapRc.pos.x - _wrapRc.width / 2)
    if (_input.GetKey(KeyCode::Left))
    {
        _player.pos.x -= 0.5;
        // 플레이어 사각형과 rc1 사각형이 충돌했을 때 밀어내기
        if (RectInRect(_player, _anotherRc))
        {
            _anotherRc.pos.x -= 0.5;
            // 플레이어를 감싸고 있는 사각형과 다른 사각형이 충돌 했을 때
            if (RectInRect(_anotherRc, _wrapRc))
            {
                // 다른 사각형의 중심점으로 플레이어 사각형 이동
                _player.pos.x = _anotherRc.pos.x;
                _player.pos.y = _anotherRc.pos.y;
            }
        }
        else if (RectInRect(_player, _wrapRc) && _player.pos.x - _player.width / 2 == _wrapRc.pos.x - _wrapRc.width / 2) // 플레이어 사각형과 플레이어를 감싸고있는 사각형과 충돌했을 때 
        {
            _wrapRc.pos.x -= 0.5;
        }
    }
    if (_input.GetKey(KeyCode::Up))
    {
        _player.pos.y -= 0.5;
        if (RectInRect(_player, _anotherRc))
        {
            _anotherRc.pos.y -= 0.5;
            // 플레이어를 감싸고 있는 사각형과 다른 사각형이 충돌 했을 때
            if (RectInRect(_anotherRc, _wrapRc))
            {
                // 다른 사각형의 중심점으로 플레이어 사각형 이동
                _player.pos.x = _anotherRc.pos.x;
                _player.pos.y = _anotherRc.pos.y;
            }
        }
        else if (RectInRect(_player, _wrapRc) && _player.pos.y - _player.height / 2 == _wrapRc.pos.y - _wrapRc.height / 2) // 플레이어 사각형과 플레이어를 감싸고있는 사각형과 충돌했을 때 
        {
            _wrapRc.pos.y -= 0.5;
        }
    }
    if (_input.GetKey(KeyCode::Right))
    {
        _player.pos.x += 0.5;
        if (RectInRect(_player, _anotherRc))
        {
            _anotherRc.pos.x += 0.5;
            // 플레이어를 감싸고 있는 사각형과 다른 사각형이 충돌 했을 때
            if (RectInRect(_anotherRc, _wrapRc))
            {
                // 다른 사각형의 중심점으로 플레이어 사각형 이동
                _player.pos.x = _anotherRc.pos.x;
                _player.pos.y = _anotherRc.pos.y;
            }
        }
        else if (RectInRect(_player, _wrapRc) && _player.pos.x + _player.width / 2 == _wrapRc.pos.x + _wrapRc.width / 2) // 플레이어 사각형과 플레이어를 감싸고있는 사각형과 충돌했을 때 
        {
            _wrapRc.pos.x += 0.5;
        }
    }
    if (_input.GetKey(KeyCode::Down))
    {
        _player.pos.y += 0.5;
        if (RectInRect(_player, _anotherRc))
        {
            _anotherRc.pos.y += 0.5;
            // 플레이어를 감싸고 있는 사각형과 다른 사각형이 충돌 했을 때
            if (RectInRect(_anotherRc, _wrapRc))
            {
                // 다른 사각형의 중심점으로 플레이어 사각형 이동
                _player.pos.x = _anotherRc.pos.x;
                _player.pos.y = _anotherRc.pos.y;
            }
        }
        else if (RectInRect(_player, _wrapRc) && _player.pos.y + _player.height / 2 == _wrapRc.pos.y + _wrapRc.height / 2) // 플레이어 사각형과 플레이어를 감싸고있는 사각형과 충돌했을 때 
        {
            _wrapRc.pos.y += 0.5;
        }
    }
}

void Game::Render()
{
    _anotherRc.Draw(_hdcBack);
    _wrapRc.Draw(_hdcBack);
    _player.Draw(_hdcBack);

    //==========================================
    //   ## 더블버퍼링 세팅 ##
    //==========================================

    // 1. hdcBack의 내용을  hdc로 복사한다.
    BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);

    // 2. hdcBack의 내용을 깨끗이 지운다.
    PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
}