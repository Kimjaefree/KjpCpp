#include "pch.h"
#include "Day19Scene.h"
#include "Texture.h"
#include "Sprite.h"




void Day19Scene::Init()
{
	_mainTexture = new Texture();
	_wRock = new Texture();
	_bRock = new Texture();

	_mainTexture = _mainTexture->LoadBmp(L"../Resources/Day19/omok.bmp");
	_wRock = _wRock->LoadBmp(L"../Resources/Day19/wRock.bmp");
	_bRock = _bRock->LoadBmp(L"../Resources/Day19/bRock.bmp");

	// 흑돌 선
	_state = Day19SceneState::bRockTurn;

	// 보드 배열 0으로 다 초기화 (다 빈칸(0)으로 만들기)
	memset(_board, 0, sizeof(_board));  // 0 - 빈칸, 1 - 흑돌, 2 - 백돌
}
void Day19Scene::Render(HDC hdc)
{
	// 바둑판 그리기
	_mainTexture->Render(hdc, 0, 0);
	
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_board[i][j] == 1) {
				// 보드에 입력된 값이 1 이면 흑돌 그리기
				_bRock->Render(hdc, 10 + i * CELL_SIZE, 10 + j * CELL_SIZE);
			}
			else if (_board[i][j] == 2) {
				// 보드에 입력된 값이 2 이면 백돌 그리기
				_wRock->Render(hdc, 10 + i * CELL_SIZE, 10 + j * CELL_SIZE);
			}
		}
		// 승리 조건 돌 개수 디버깅 용도
		{
			wstring bRockCountStr = ::format(L"bRockCount : [{}]" , _rockCount);
			Draw::Text(hdc, 800, 0, bRockCountStr);
		}

		// 보드 좌표 디버깅
		{
			wstring boardPosStr = ::format(L"boardX[{}],boardY[{}]", _boardX,_boardY);
			Draw::Text(hdc, 800, 20, boardPosStr);
		}
	}

}
void Day19Scene::Update()
{

	switch (_state)
	{
	case Day19SceneState::bRockTurn:
		Update_bRock();
		break;
	case Day19SceneState::wRockTurn:
		Update_wRock();
		break;
	case Day19SceneState::win:
		break;
	default:
		break;
	}
	// 마우스 왼쪽 클릭이 눌렸을 때
}
void Day19Scene::Release()
{

}

void Day19Scene::Update_bRock()
{
	// 왼쪽 마우스버튼을 클릭했다면
	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		// 마우스의 위치를 가져오고
		_mousepos = Input->GetMousePos();

		// 클릭 좌표를 바둑판 셀 좌표로 변환
		_boardX = static_cast<int>(_mousepos.x / CELL_SIZE);
		_boardY = static_cast<int>(_mousepos.y / CELL_SIZE);
		// 보드가 돌이 없고 비어있다면
		if (_board[_boardX][_boardY] == 0)
		{
			// 흑돌을 그린다 (흑돌이 1이니까)
			_board[_boardX][_boardY] = 1;
			CountRock(_boardX, _boardY, 1);
			_state = Day19SceneState::wRockTurn;
		}
	}
}

void Day19Scene::Update_wRock()
{
	// 왼쪽 마우스버튼을 클릭했다면
	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		// 마우스의 위치를 가져오고
		 _mousepos = Input->GetMousePos();

		// 클릭 좌표를 바둑판 셀 좌표로 변환
		 _boardX = static_cast<int>(_mousepos.x / CELL_SIZE);
		 _boardY = static_cast<int>(_mousepos.y / CELL_SIZE);

		// 빈 칸인 경우에만 돌을 놓음
		 if (_board[_boardX][_boardY] == 0)
		 {
			 _board[_boardX][_boardY] = 2;  // 백돌 배치
			 CountRock(_boardX, _boardY, 2);
			 _state = Day19SceneState::bRockTurn;
		 }
	}
}

void Day19Scene::CountRock(int x, int y, int rockColor)
{
	// 총 상,하,좌,우 4방향을 검사해야 하므로 전체 4번 반복
	for (int loop = 0; loop < 4; loop++)
	{
		_rockCount = 1;  // 돌 개수 count 변수 1로 초기화 (자신 포함)

		// 우측, 우측 대각선 아래, 하단, 우측 대각선 위 방향 검사
		for (int i = 1; i < 5; i++)
		{
			_rx = x + (i * _rightX[loop]);
			_ry = y + (i * _rightY[loop]);

			// 범위 검사와 돌 색 검사
			if (_rx >= 0 && _rx < BOARD_SIZE && _ry >= 0 && _ry < BOARD_SIZE && _board[_rx][_ry] == rockColor)
			{
				_rockCount++;  // 돌 개수 증가
			}
			else
			{
				break;  // 범위를 벗어나거나 다른 돌이 나오면 중지
			}
		}

		// 좌측, 좌측 대각선 위, 상단, 좌측 대각선 아래 방향 검사
		for (int i = 1; i < 5; i++)
		{
			_lx = x - (i * _leftX[loop]);
			_ly = y - (i * _leftY[loop]);

			// 범위 검사와 돌 색 검사
			if (_lx >= 0 && _lx < BOARD_SIZE && _ly >= 0 && _ly < BOARD_SIZE && _board[_lx][_ly] == rockColor)
			{
				_rockCount++;  // 돌 개수 증가
			}
			else
			{
				break;  // 범위를 벗어나거나 다른 돌이 나오면 중지
			}
		}

		// 돌 개수가 5개가 되면 승리 처리
		if (_rockCount >= 5)
		{
			_state = Day19SceneState::win;
			return;  // 더 이상 다른 방향을 검사할 필요 없음
		}
	}
}

