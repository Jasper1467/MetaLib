#pragma once

namespace MetaLib
{
	enum
	{
		NOP = 0x90, // No operation

		// https://c9x.me/x86/html/file_module_x86_id_26.html
		CALL = 0xE8, // Call
		CALLF = 0x9A, // Call far (call to an address in a different segment)

		// https://c9x.me/x86/html/file_module_x86_id_147.html
		JMP = 0xE9, // Jump
		JMPF = 0xEA, // Jump far (jump to an address in a different segment, same privilage level)
		JMPS = 0xEB, // Jump short (range is limited from -128 to +127 from the current EIP value)

		// https://c9x.me/x86/html/file_module_x86_id_78.html
		ENTER = 0xC9, // Enter; Create a stack frame for a procedure

		// https://c9x.me/x86/html/file_module_x86_id_154.html
		LEAVE = 0xCA, // Leave; High Level Procedure Exit

		// https://c9x.me/x86/html/file_module_x86_id_134.html
		// https://en.wikipedia.org/wiki/HLT_(x86_instruction)
		HLT = 0xF4, // Stops instruction execution and places the processor in a HALT state
	};
}