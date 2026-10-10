#include <iostream>
using namespace std;

class A
{
    double value;

public:
    A(double v = 0)
    {
        value = v;
    }

    A operator+(A b)
    {
        return A(value + b.value);
    }

    A operator-(A b)
    {
        return A(value - b.value);
    }

    A operator*(A b)
    {
        return A(value * b.value);
    }

    A operator/(A b)
    {
        if (b.value == 0)
            return A(0);

        return A(value / b.value);
    }

    bool operator>(A b)
    {
        return value > b.value;
    }

    bool operator<(A b)
    {
        return value < b.value;
    }

    bool operator==(A b)
    {
        return value == b.value;
    }

    operator double() const
    {
        return value;
    }
};

template<class T>
class Matrix
{
    T* arr;
    int size;

public:
    Matrix();
    Matrix(const Matrix<T>& b);
    ~Matrix();

    void Input();
    void Random();
    void Output();

    Matrix<T> operator+(Matrix<T> b);
    Matrix<T> operator-(Matrix<T> b);
    Matrix<T> operator*(Matrix<T> b);
    Matrix<T> operator/(Matrix<T> b);

    T Max();
    T Min();
};

template<class T>
Matrix<T>::Matrix()
{
    size = 4;
    arr = new T[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = T(0);
    }
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& b)
{
    size = b.size;
    arr = new T[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = b.arr[i];
    }
}

template<class T>
Matrix<T>::~Matrix()
{
    delete[] arr;
}

template<class T>
void Matrix<T>::Input()
{
    for (int i = 0; i < size; i++)
    {
        double x;
        cin >> x;
        arr[i] = T(x);
    }
}

template<class T>
void Matrix<T>::Random()
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = T(rand() % 9 + 1);
    }
}

template<class T>
void Matrix<T>::Output()
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
        if (i % 2 == 1)
        {    
            cout << endl;
        }
    }
}

template<class T>
Matrix<T> Matrix<T>::operator+(Matrix<T> b)
{
    Matrix<T> result;
    for (int i = 0; i < size; i++)
    {
        result.arr[i] = arr[i] + b.arr[i];
    }
    return result;
}

template<class T>
Matrix<T> Matrix<T>::operator-(Matrix<T> b)
{
    Matrix<T> result;
    for (int i = 0; i < size; i++)
    {
        result.arr[i] = arr[i] - b.arr[i];
    }
    return result;
}

template<class T>
Matrix<T> Matrix<T>::operator*(Matrix<T> b)
{
    Matrix<T> result;
    for (int i = 0; i < size; i++)
    {
        result.arr[i] = arr[i] * b.arr[i];
    }
    return result;
}

template<class T>
Matrix<T> Matrix<T>::operator/(Matrix<T> b)
{
    Matrix<T> result;
    for (int i = 0; i < size; i++)
    {
        if (b.arr[i] == T(0))
        {    result.arr[i] = T(0); }
        else
        {    result.arr[i] = arr[i] / b.arr[i]; }
    }
    return result;
}

template<class T>
T Matrix<T>::Max()
{
    T max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {    
            max = arr[i];
        }
    }
    return max;
}

template<class T>
T Matrix<T>::Min()
{
    T min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {    
            min = arr[i];
        }
    }
    return min;
}

int main()
{
    srand(time(0));

    Matrix<int> a;
    Matrix<int> b;

    a.Random();
    b.Random();

    cout << "Matrix A:" << endl;
    a.Output();

    cout << "Matrix B:" << endl;
    b.Output();

    cout << "A + B:" << endl;
    (a + b).Output();

    cout << "A - B:" << endl;
    (a - b).Output();

    cout << "A * B:" << endl;
    (a * b).Output();

    cout << "A / B:" << endl;
    (a / b).Output();

    cout << "Max = " << a.Max() << endl;
    cout << "Min = " << a.Min() << endl;

    Matrix<A> x;
    Matrix<A> y;

    x.Random();
    y.Random();

    cout << "\nMatrix X:" << endl;
    x.Output();

    cout << "Matrix Y:" << endl;
    y.Output();

    cout << "X + Y:" << endl;
    (x + y).Output();

    cout << "X - Y:" << endl;
    (x - y).Output();

    cout << "X * Y:" << endl;
    (x * y).Output();

    cout << "X / Y:" << endl;
    (x / y).Output();

    cout << "Max X = " << x.Max() << endl;
    cout << "Min X = " << x.Min() << endl;

    return 0;
}
