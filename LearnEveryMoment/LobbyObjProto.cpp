#include "LobbyObjProto.h"
#include "Include.h"

CLobbyObjProto::CLobbyObjProto()
{
}


CLobbyObjProto::~CLobbyObjProto()
{
}

HRESULT CLobbyObjProto::InitProtoInstance()
{
	/*CInfo_Obj ObjInfo;
	ZeroMemory(&ObjInfo, sizeof(ObjInfo));
*/
	// �� STL �� ���������� �ּҰ����� ���ĵȴ�.
	//m_MapProto.insert(make_pair(L"Ball", new CBall()));

	return S_OK;
}
