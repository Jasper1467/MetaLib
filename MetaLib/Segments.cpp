#include "Segments.h"
#include <cstdint>

MetaLib::GetSectionInfoOutput_t* MetaLib::GetSectionInfo(uintptr_t nAddress, const char* szSectionName)
{
	const auto pDosHeader = reinterpret_cast<PIMAGE_DOS_HEADER>(nAddress);
	if (pDosHeader->e_magic != IMAGE_DOS_SIGNATURE)
		return nullptr;

	const auto pNtHeaders = reinterpret_cast<PIMAGE_NT_HEADERS>(nAddress + pDosHeader->e_lfanew);
	if (pNtHeaders->Signature != IMAGE_NT_SIGNATURE)
		return nullptr;

	IMAGE_SECTION_HEADER* pSectionHeader = IMAGE_FIRST_SECTION(pNtHeaders);
	uint16_t nSections = pNtHeaders->FileHeader.NumberOfSections;

	// Look through all sections
	while (nSections > 0)
	{
		// Found a matching segment
		if (!strcmp(szSectionName, (const char*)pSectionHeader->Name))
		{
			MetaLib::GetSectionInfoOutput_t* pInfo;
			pInfo->m_nStartAddress = nAddress + pSectionHeader->VirtualAddress;
			pInfo->m_nSize = pSectionHeader->SizeOfRawData;
			pInfo->m_nEndAddress = pInfo->m_nStartAddress + pInfo->m_nSize;
			return pInfo;
		}

		// Goto next section, decrease amount of sections left
		pSectionHeader++;
		nSections--;
	}

	return nullptr;
}