#pragma once

#include "Base.h"

/* 1. 현재 화면에 보여줘야할 레벨의 주소를 보관한다. */
/* 2. 현재 보유하고 있는 레벨의 반복적인 업데이트와 렌더를 수행한다.*/
/* 3. 다른 레벨로 교체 시, 기존레벨을 파괴 and 기존 레벨용 자원을 해제한다. */

BEGIN(Engine)

class CLevel_Manager final : public CBase
{
private:
	CLevel_Manager();
	virtual ~CLevel_Manager() = default;

public:
	HRESULT Initialize();
	void Update(_float fTimeDelta);
	HRESULT Render();

public:
	HRESULT Change_Level(class CLevel* pNewLevel);

private:
	class CLevel*				m_pCurrentLevel = { nullptr };	

public:
	static CLevel_Manager* Create();
	virtual void Free() override;
};

END