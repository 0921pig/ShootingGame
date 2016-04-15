#pragma once
#include "stdafx.h"
#include "Data_MovingCourse.h"

class CMovingCoursePattern
{
private:
	list<CData_MovingCourse> m_MovingCourseList;

public:
	CMovingCoursePattern();
	~CMovingCoursePattern();
};

