#pragma once

#include <Windows.h>
#include <fstream>

// https://stackoverflow.com/a/16031507
#define KB(x) ((size_t)(x) << 10)
#define MB(x) ((size_t)(x) << 20)
#define GB(x) ((size_t)(x) << 30)
#define TB(x) ((size_t)(x) << 40)

namespace MetaLib
{
	inline byte* ReadWavFile(const char* szFileName)
	{
		byte* pBytes = nullptr;
		std::ifstream Stream(szFileName, std::ios::binary);

		Stream.seekg(0, std::ios::end);
		size_t nCount = Stream.tellg();

		pBytes = new byte[nCount];
		Stream.seekg(0, std::ios::beg);
		Stream.read((char*)pBytes, nCount);
		Stream.close();

		return pBytes;
	}

	inline void CreateWavFile(const char* szFileName, byte* pBytes)
	{
		std::ofstream Stream(szFileName, std::ios::binary);

		// Calculate amount of bytes
		size_t nCount = 0;
		for (nCount; pBytes[nCount] != 0; nCount++)
			;

		Stream.write((char*)pBytes, nCount);
		Stream.close();
	}
}