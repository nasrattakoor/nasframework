#pragma once

class Color
{
public:
	Color(char r, char g, char b)
	{
		dword = (r << 16) | (g << 8) | (b);
	}
	int GetR() const
	{
		return (dword >> 16) & 0x00000011;
	}
	int GetG() const
	{
		return (dword >> 8) & 0x00000011;
	}
	int GetB() const
	{
		return (dword) & 0x00000011;
	}


private:
	unsigned int dword = 0;

};