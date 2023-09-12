#include <iostream>
#include <stdlib.h>   
#include <windows.h>
void process(int* point, int* narr, int* w, int* h, int* t, int* i)
{

	system("cls");//отрисовка
	for (*i = 0; *i < (*h) * (*w); (*i)++)
	{
		if ((*i / (*w) != 0) && (*i / (*w) != (*h - 1)) && (*i % (*w) != 0) && (*i % (*w) != (*w) - 1))
		{
			if (*(point + *i) == 1)
			{
				std::cout << *(point + *i) - 1 << " ";
			}
			else
			{
				std::cout << "  ";
			}
		}
		if ((((*i % (*w) == (*w) - 2))) && ((*i / (*w) != 0) && (*i / (*w) != (*h - 1)) && (*i % (*w) != 0) && (*i % (*w) != (*w) - 1)))
		{
			std::cout << std::endl;
		}

	}
	/* //full draw
(with lines) for (int *i = 0; i < (*h) * (*w); *i++)
	{

			std::cout << *(point + *i) << " ";

		if ((((*i % (*w) == (*w) - 1))) )
		{
			std::cout << std::endl;
		}

	}*/
	Sleep(*t);
	//array processing

	for (*i = 0; *i < (*w) * (*h); (*i)++)//test for dead cells
	{
		if ((*i / (*w) != 0) && (*i / (*w) != (*h - 1)) && (*i % (*w) != 0) && (*i % (*w) != (*w) - 1))
		{

			if ((*(point + *i) == 0) && ((*(point + *i + 1) + *(point + *i - 1) + *(point + *i + *w) + *(point + *i - *w) + *(point + *i + 1 - *w) + *(point + *i - 1 - *w) + *(point + *i - 1 + *w) + *(point + *i + 1 + *w)) == 3))
			{
				narr[*i] = 1;
			}
			else
			{
				narr[*i] = 0;
			}

		}
	}
	for (*i = 1; *i < (*w) * (*h); (*i)++)//test for live cells
	{


		if ((*(point + *i) == 1) && (((*(point + *i + 1) + *(point + *i - 1) + *(point + *i + *w) + *(point + *i - *w) + *(point + *i + 1 - *w) + *(point + *i - 1 - *w) + *(point + *i - 1 + *w) + *(point + *i + 1 + *w)) == 2) || ((*(point + *i) == 1) && ((*(point + *i + 1) + *(point + *i - 1) + *(point + *i + *w) + *(point + *i - *w) + *(point + *i + 1 - *w) + *(point + *i - 1 - *w) + *(point + *i - 1 + *w) + *(point + *i + 1 + *w)) == 3))))
		{
			narr[*i] = 1;
		}
		else if (((*(point + *i) == 1)))
		{
			narr[*i] = 0;
		}

	}

	// change old scene with new one
	for (*i = 0; *i < (*w) * (*h); (*i)++)
	{


		*(point + *i) = narr[*i];

	}
	//mirror again
	for (*i = 0; *i < (*h) * (*w); (*i)++)//side mirroring
	{
		if ((*i / (*w) == 0) && (*i % (*w) != 0) && (*i % (*w) != (*w) - 1))
		{
			*(point + *i) = *(point + *i + (*w) * (*h - 2));
		}
		else if (((*i / (*w) == (*h - 1)) && (*i % (*w) != 0) && (*i % (*w) != (*w) - 1)))
		{
			*(point + *i) = *(point + *i - (*w) * (*h - 2));
		}
		else if (((*i / (*w) != (*h - 1)) && (*i % (*w) == 0) && (*i / (*w) != 0)))
		{
			*(point + *i) = *(point + *i + (*w - 2));
		}
		else if (((*i / (*w) != (*h - 1)) && (*i % (*w) == (*w - 1)) && (*i / (*w) != 0)))
		{
			*(point + *i) = *(point + *i - (*w - 2));
		}
		//now corners
		else if (((*i / (*w) == 0) && (*i % (*w) == 0)))
		{
			*(point + *i) = *(point + *i + ((*w) * (*h - 2) + (*w - 2)));
		}
		else if (((*i / (*w) == *h - 1) && (*i % (*w) == *w - 1)))
		{
			*(point + *i) = *(point + *i - ((*w) * (*h - 2) + (*w - 2)));
		}
		else if (((*i / (*w) == *h - 1) && (*i % (*w) == 0)))
		{
			*(point + *i) = *(point + *i - (*w) * (*h - 2) + (*w - 2));
		}
		else if (((*i / (*w) == 0) && (*i % (*w) == *w - 1)))
		{
			*(point + *i) = *(point + *i + (*w) * (*h - 2) - (*w - 2));
		}

	}
	process(point, narr, w, h, t, i);
}
int main()
{
	int* w = new int;
	int* h = new int;
	int* t = new int;
	int* i = new int;
	std::cout << "Input width lower than 108:";//значения максимальные для разрешения моего ноутбука в полноэкранном режиме. При превышении высоты камеру просто начнет мотать, а ширина просто испортит изображение полностью
	std::cin >> *w;
	std::cout << "Input height lower than 52:";
	std::cin >> *h;
	std::cout << "Input time for one tick in ms:";
	std::cin >> *t;
	int* parr2 = new int[(*h) * (*w)];
	int* narr = new int[(*w) * (*h)];
	for (*i = 0; *i < (*h) * (*w); (*i)++)//array creation
	{
		parr2[*i] = 0;
	}

	//place for first gen mods
	/*//frame
 for (*i = 0; *i < (*h) * (*w); (*i)++)
	{
		if ((*i / (*w) == 1) || (*i / (*w) == (*h) - 2) || (*i%(*w)==1)|| (*i % (*w) == (*w)-2))
		{
			parr2[i] = 1;
		}
	}*/
	//basic glider, block and blinker for 50x50 for using comment out (random fill)
	parr2[53] = 1;
	parr2[53 + *w] = 1;
	parr2[51 + *w] = 1;
	parr2[53 + 2 * (*w)] = 1;
	parr2[52 + 2 * (*w)] = 1;
	parr2[70] = 1;
	parr2[71] = 1;
	parr2[72] = 1;
	parr2[20] = 1;
	parr2[21] = 1;
	parr2[22] = 1;
	parr2[320] = 1;
	parr2[321] = 1;
	parr2[320+*w] = 1;
	parr2[321+*w] = 1;
	
	//random fill 
	/*for (*i = 0; *i < (*h) * (*w); (*i)++)
	{
		if ((*i / (*w) != 0) && (*i / (*w) != (*h - 1)) && (*i % (*w) != 0) && (*i % (*w) != (*w) - 1))
		{
			parr2[*i] = rand() % 2;
		}
	}*/

	for (*i = 0; *i < (*h) * (*w); (*i)++)//side mirroring
	{
		if ((*i / (*w) == 0) && (*i % (*w) != 0) && (*i % (*w) != (*w) - 1))
		{
			parr2[*i] = parr2[*i + (*w) * (*h - 2)];
		}
		else if (((*i / (*w) == (*h - 1)) && (*i % (*w) != 0) && (*i % (*w) != (*w) - 1)))
		{
			parr2[*i] = parr2[*i - (*w) * (*h - 2)];
		}
		else if (((*i / (*w) != (*h - 1)) && (*i % (*w) == 0) && (*i / (*w) != 0)))
		{
			parr2[*i] = parr2[*i + (*w - 2)];
		}
		else if (((*i / (*w) != (*h - 1)) && (*i % (*w) == (*w - 1)) && (*i / (*w) != 0)))
		{
			parr2[*i] = parr2[*i - (*w - 2)];
		}
		//now corners
		else if (((*i / (*w) == 0) && (*i % (*w) == 0)))
		{
			parr2[*i] = parr2[*i + ((*h - 2) * (*w) + (*w - 2))];
		}
		else if (((*i / (*w) == *h - 1) && (*i % (*w) == *w - 1)))
		{
			parr2[*i] = parr2[*i - ((*h - 2) * (*w) + (*w - 2))];
		}
		else if (((*i / (*w) == *h - 1) && (*i % (*w) == 0)))
		{
			parr2[*i] = parr2[*i - (*h - 2) * (*w) + (*w - 2)];
		}
		else if (((*i / (*w) == 0) && (*i % (*w) == *w - 1)))
		{
			parr2[*i] = parr2[*i + (*h - 2) * (*w) - (*w - 2)];
		}

	}
	process(parr2, narr, w, h, t, i);
	return 0;
}

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
