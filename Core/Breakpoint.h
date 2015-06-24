#pragma once
#include "stdafx.h"

enum class BreakpointType
{
	Execute = 0,
	Read = 1,
	Write = 2
};

class Breakpoint
{
public:
	Breakpoint(BreakpointType type, uint32_t addr, bool isAbsoluteAddr);
	~Breakpoint();

	bool Breakpoint::Matches(uint32_t memoryAddr, uint32_t absoluteAddr)
	{
		return _enabled && ((memoryAddr == _addr && !_isAbsoluteAddr) || (absoluteAddr == _addr && _isAbsoluteAddr));
	}

	uint32_t GetAddr()
	{
		return _addr;
	}

	bool IsAbsoluteAddr()
	{
		return _isAbsoluteAddr;
	}

	BreakpointType GetType()
	{
		return _type;
	}

	wstring GetTypeText()
	{
		switch(_type) {
			case BreakpointType::Execute: return L"Exec";
			case BreakpointType::Read: return L"Read";
			case BreakpointType::Write: return L"Write";
		}
		return L"";
	}

	bool IsEnabled()
	{
		return _enabled;
	}

	void SetEnabled(bool enabled)
	{
		_enabled = enabled;
	}

	void UpdateBreakpoint(BreakpointType type, uint32_t addr, bool isAbsoluteAddr, bool enabled)
	{
		_type = type;
		_addr = addr;
		_isAbsoluteAddr = isAbsoluteAddr;
		_enabled = enabled;
	}
	
private:
	BreakpointType _type;
	uint32_t _addr;
	bool _isAbsoluteAddr;
	bool _enabled;
};