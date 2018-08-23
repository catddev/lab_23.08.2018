#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>

using namespace std;

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn;

		switch (tn)
		{
		case 1:
		{
			// 1.	Объвить две переменные и два указателя. Присвоить указателям адреса переменных.
			// Сложить переменные, используя указатели и присвоить результат третьей переменной.
			// Вывести результат сложения на экран и адрес результата.

			int x = 3, y = 5, *p, *p1;
			p = &x;
			p1 = &y;

			int c = *p + *p1;
			p = &c;
			cout << c << ", adress: " << p << endl << endl;
		}
		break;
		case 2:
		{
			// Исправить код:

			int a = 2, b = 5;
			int *p1 = &a, *p2 = &b;
			cout << *p1 - *p2 << endl << endl;;

		}
		break;
		case 3:
		{
			// Исправить код:

			int a = 2, b = 5, res;
			int *p1 = &a, *p2 = &b;
			res = *p1 - *p2;
			cout << res << endl << endl;
		}
		break;
		case 4:
		{
			// Исправить код:

			const int SIZE = 10;
			int A[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
			int *p = A;
			for (int i = 0; i<SIZE; i++) //выполнить вывод массива используя указатели
				cout << *p++ << " ";
			cout << endl << endl;
		}
		break;
		case 5:
		{
			// 5.	Используя указатели заполнить массив случайными числами и вывести его на экран

			int ab[10];
			int *p;

			for (p = ab; p < ab + 10; p++)
			{
				*p = rand() % 100;
				cout << *p << " ";
			}
			cout << endl << endl;
		}
		break;
		case 6:
		{
			// 6. Дано натуральное число N и массив целых чисел.
			// Используя указатели, выяснить имеется ли в массиве хотя бы одно нечетное отрицательное число
			// и определить его местонахождение в массиве

			const int N=5;
			int n[N] = { 1, 3, 7, -4, -9 };
			int *p = n;

			for (; p < n + N; p++)
			{
				if (*p % 2 != 0 && *p < 0)
					cout << *p << ", index: " << p - n << endl;
			}
			cout << endl;
		}
		break;
		case 7:
		{
			// 7. Даны действительные числа а1, ..a16.
			// Используя указатели получить min(a1*a9, a2*a10, ..., a8*a16).
			int a[16] = {10, 2, 4, 6, 8, 13, 7, 9, -3, 10, 11, 12, 3, 4, 5, 7};
			int *p;
			int min = INT_MAX;
			int b = 0;

			for (p = a; p < a + 16/2; p++)
			{
				b = *p * *(p + 8);
				if (b < min) min = b;
				cout << b << endl;
			}
			cout << endl << min << endl << endl;;
		}
		break;
		case 8:
		{
			// 8. Дана последовательность a1, a2, ..., a20.
			// Используя указатели расположить положительные элементы последовательности,
			// стоящие на нечетных местах по возрастанию


			int a[20] = { 1, 2, 4, -16, 7, 8, 10, 12, 15, -75, 18, 17, 16, 3, 2, 1, 27, 90, 100, 0 };
			int *p = a;
			int *tmp;
			int i = 0;
			
			for (; p < a + 20; p++)
					cout << *p << " ";
				cout << endl;

				for (int pass = 1; pass < 20; pass++)
				{
					for (p = a + 1; p < a + 19; p += 2)
					{
						if (*p < 0) continue;
							if (*p > *(p + 2))
								swap(*p, *(p + 2));
					}
				}
					
				for (p = a; p < a + 20; p++)
					cout << *p << " ";
				cout << endl << endl;
		}
		break;
		case 9:
		{
			// 9. Дана последовательность x1, x2, ..., x20.
			// Используя указатели, элементы, cтоящие на нечетных местах,
			// расположить в порядке возрастания, а на четных в порядке убывания

			int a[20] = { 1, 2, 4, -5, 7, 8, 10, 12, 15, -16, 18, 17, 16, 3, 2, 1, 27, 90, 100, 0 };
			int *p = a;
			int *tmp;
			int i = 0;

			for (; p < a + 20; p++)
				cout << *p << " ";
			cout << endl;

			for (int pass = 1; pass < 20; pass++)
			{
				for (p = a + 1; p < a + 19; p += 2)
				{
					if (*p > *(p + 2))
						swap(*p, *(p + 2));
				}
				for (p = a; p < a + 19; p += 2)
				{
					if (*p < *(p + 2))
						swap(*p, *(p + 2));
				}
			}

			for (p = a; p < a + 20; p++)
				cout << *p << " ";
			cout << endl << endl;
		}
		break;
		case 10:
		{
			// 10. Дана последовательность a1, a2, ..., a15.
			// Используя указатели требуется упорядочить ее по возрастанию абсолютных значений элементов.
			int a[15] = { 1, 2, -5, 7, 8, 10, 12, 15, -16, 18, 17, 16, 3, 100, 0 };
			int *p = a;
			int *tmp;
			int i = 0;

			for (; p < a + 15; p++)
				cout << *p << " ";
			cout << endl;

			for (int pass = 0; pass < 14; pass++)
			{
				for (p = a; p < a + 14; p++)
				{
					if (abs(*p) > abs(*(p+1)))
						swap(*p, *(p+1));
				}
			}

			for (p = a; p < a + 15; p++)
				cout << *p << " ";
			cout << endl << endl;
		}
		case 11:
		{
			// 11. Используя указатели в упорядоченном по возрастанию массиве выяснить, что
			// больше элементов со значением > Р или элементов со значением < Р.

			int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 8, 8 };
			int *p = arr;
			int P;
			cin >> P;
			int x=0, y=0;

			for (; p < arr + 10; p++)
			{
				if (*p > P) x++;
				else if (*p < P) y++;
			}
			if (x > y) cout << "больше элементов со значением > Р" << endl << endl;;
			else if (x < y) cout << "больше элементов со значением < Р" << endl << endl;;
			/*else cout << "элементов со значением > Р и < Р поровну" << endl;*/ // if other size of an array

		}
		break;
		case 12:
		{
			// 12. Используя указатели в упорядоченном по возрастанию массиве подсчитать сумму элементов, 
			// pасположенных за элементом со значением Р и до
			// элемента со значением К(Р > К).
			int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			int *p = arr;
			int P, K;

			for (; p < arr + 10; p++)
				cout << *p << " ";
			cout << endl;
			cout << "choose elements P and K (Р > К)" << endl;
			cin >> P >> K;

			int x = 0, y = 0;

			for (; p < arr + 10; p++)
			{
				if (*p > P) x+=*p;
				if (*p < K) y +=*p;
			}
			cout << "суммa элементов, pасположенных за элементом со значением Р: " << x << endl;
			cout << "суммa элементов, pасположенных до элемента со значением К (Р > К): " << y << endl << endl;
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}