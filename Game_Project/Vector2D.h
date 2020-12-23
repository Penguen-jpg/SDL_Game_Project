#pragma once
#include <iostream>
class Vector2D
{
	//�w�q�@�ӥ����V�q
	public:
		float x;
		float y;

		Vector2D();
		Vector2D(float x, float y);

		//�򥻹B��
		Vector2D& add(const Vector2D& vec);//�[�k
		Vector2D& subtract(const Vector2D& vec);//��k
		Vector2D& multiply(const Vector2D& vec);//���k
		Vector2D& divide(const Vector2D& vec);//���k

		//�����B��l
		friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
		friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
		friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
		friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);
		Vector2D& operator+=(const Vector2D& vec);
		Vector2D& operator-=(const Vector2D& vec);
		Vector2D& operator*=(const Vector2D& vec);
		Vector2D& operator/=(const Vector2D& vec);
};