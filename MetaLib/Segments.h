#pragma once

#include <Windows.h>

// https://wiki.skullsecurity.org/index.php/Registers
#define REG_EAX 0
#define REG_ECX 1
#define REG_EDX 2
#define REG_EBX 3

namespace MetaLib
{
	struct GetSectionInfoOutput_t
	{
		uintptr_t m_nStartAddress;
		uintptr_t m_nEndAddress;
		size_t m_nSize;
	};

	GetSectionInfoOutput_t* GetSectionInfo(uintptr_t nAddress, const char* szSectionName);
}