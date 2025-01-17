#pragma once

#include "Client_Defines.h"
#include "Level.h"

/* 1. 로딩 장면에 필요한 객체를 만들고, 리소스를 로드한다. */
/* 2. 로딩 장면을 유저에게 보여준다. */


BEGIN(Client)

class CLevel_Loading final : public CLevel
{
private:
	CLevel_Loading(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual ~CLevel_Loading() = default;

public:
	virtual HRESULT Initialize(LEVELID eNextLevelID);
	virtual void Update(_float fTimeDelta) override;
	virtual HRESULT Render() override;

private:
	LEVELID				m_eNextLevelID = {};
	class CLoader*		m_pLoader = { nullptr };

public:
	static CLevel_Loading* Create(LPDIRECT3DDEVICE9 pGraphic_Device, LEVELID eNextLevelID);
	virtual void Free() override;
};

END