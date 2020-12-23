#pragma once
#include <iostream>
class Vector2D
{
	//定義一個平面向量
	public:
		float x;
		float y;

		Vector2D();
		Vector2D(float x, float y);

		//基本運算
		Vector2D& add(const Vector2D& vec);//加法
		Vector2D& subtract(const Vector2D& vec);//減法
		Vector2D& multiply(const Vector2D& vec);//乘法
		Vector2D& divide(const Vector2D& vec);//除法

		//重載運算子
		friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
		friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
		friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
		friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);
		Vector2D& operator+=(const Vector2D& vec);
		Vector2D& operator-=(const Vector2D& vec);
		Vector2D& operator*=(const Vector2D& vec);
		Vector2D& operator/=(const Vector2D& vec);
};