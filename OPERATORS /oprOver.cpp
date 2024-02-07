#include<iostream>
#include<string>

struct Vector {
	float x, y;

	Vector(float x, float y):x(x), y(y) {}

	Vector add(const Vector& other) const {
		return Vector(x + other.x, y+other.y);

		// return operator+(other); //Same ⬆
	}

	Vector multiply(const Vector& other) const {
		return Vector(x * other.x, y * other.y);
	}

	Vector operator+(const Vector& other) const {
		return Vector(x + other.x, y + other.y);
	}

	//Vector operator+(const Vector& other) const {
	//	return *this + other;			//Same ⬆
	//}


	/*Vector operator+(const Vector& other) const {
		return add(other);
	}*/

	Vector operator*(const Vector& other) const {
		return Vector(x * other.x, y * other.y);
	}

	
};

std::ostream& operator<<(std::ostream& stream, const Vector& other) {
	stream << other.x << "," << other.y;
	return stream;
}


int main()
{
	Vector position(4.0f, 4.0f);

	Vector speed(5.0f, 5.0f);

	Vector powerUp(2.0f, 2.0f);

	Vector result1 = position.add(speed.multiply(powerUp));
	
	Vector result2 = position + speed * powerUp;



	std::cout<<"result1: " << result1 << " " <<"result2: " << result2 << std::endl;

	system("pause>0");
}
