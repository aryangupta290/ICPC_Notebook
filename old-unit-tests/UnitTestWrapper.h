#pragma once
// 3456789012345678901234567890123456789012345678901234

#include "global.h"
#include "UnitTest.h"
#include "UnitTestManager.h"

class UnitTestWrapper
{
public:
	UnitTestWrapper(UnitTest* unitTest):
		m_unitTest(unitTest)
	{
		UnitTestManager::getInstance()->registerWrapper(this);
	}

	~UnitTestWrapper()
	{
		if(m_unitTest != NULL)
			delete m_unitTest;
	}

public:
	UnitTest* getUnitTest()
	{
		return m_unitTest;
	}

private:
	UnitTest* m_unitTest;
};
