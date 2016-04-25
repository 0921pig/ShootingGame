#pragma once

/* 여기에 들어있는 enum은 꼭 여기에 있어야 하는 것들만 있다. 나머지는 각자에게 더 맞는 위치에 있다. */



enum SceneNo
{
	SceneNo_None,
	SceneNo_Lobby,
	SceneNo_Stage1,
	SceneNo_End
};

enum SortID
{
	SortID_None = -1,
	SortID_Back,
	SortID_Enemy,
	SortID_Player,
	SortID_AirCraft,
	SortID_End,
	SortID_MaxSize,
};

enum DIR4
{
	DIR4_LEFT,
	DIR4_UP,
	DIR4_RIGHT,
	DIR4_DOWN,
};

enum DIR8
{
	LEFTUP,
	LEFT,
	UP,
	RIGHTUP,
	RIGHT,
	RIGHTDOWN,
	DOWN,
	LEFTDOWN,
};

enum AircraftTypeOfPlayer
{
	AT_None,
	AT_SuperHornet,
	AT_Stealth,
	AT_Raptor,
	AT_Harrier,
	AT_Phantom,
	AT_Random
};


enum AttackPattern_Type
{
	AttackType_None,
	AttackType_Basic_01,
};

enum MovingPattern_Type
{
	MovingType_None,
	MovingType_Basic_01,
};