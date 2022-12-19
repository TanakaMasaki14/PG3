#pragma once
#include<stdio.h>

class IShape
{
private:


public:
	/// <summary>
	/// –ÊÏ‚ğ‹‚ß‚é
	/// </summary>
	/// <returns></returns>
	virtual float size() = 0;

	/// <summary>
	/// •`‰æ
	/// </summary>
	virtual void Draw() = 0;
};

