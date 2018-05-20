#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <iostream>
#include "Header_Main.h"

FILE * fp;

void main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	DrawLine();
	printf("В работе имеется 5 заданий.\n");
	printf("Для выхода наберите 0.\n");
	DrawLine();
	int n;
	do
	{
		DrawLine();
		printf("Введите номер задания: ");
		scanf("%d", &n);
		DrawLine();
		switch (n)
		{
		case 1:
		{
			/*1. 1.	Создать бинарный файл, компонентами которого является структура,
			содержащая следующие поля:
			a. наименование работы;
			b. выделенное количество часов на выполнение данной работы;
			c. реально затраченное время на выполнение работы;
			d. стоимость работы.
			e. переписать бинарный файл так, чтобы увеличить стоимость работы на 20%,
			если работа была выполнена на 2 часа раньше запланированного времени	*/

			char path1[30] = "01.work1.txt";
			char path2[30] = "01.work2.txt";

			int count = 5;

			structWork *work;
			DrawLine();
			printf("Записываем данные в файл 01.work1.txt\n");

			work = CreateWork(&count);

			PrintInfoWork(work, count);
			DrawLine();
			if ((fp = fopen(path1, "w+b")) != NULL)
			{
				fwrite(work, count * sizeof(structWork), 1, fp);
			}
			else
			{
				printf("Ошибка!");
				exit(1);
			}

			fclose(fp);

			printf("\n");

			structWork *work2 = (structWork*)calloc(count, sizeof(structWork));
			DrawLine();
			printf("Считываем данные из файла 01.work1.txt\n");
			printf("Увеличиваем стоимость работы на 20%%: \n");
			DrawLine();
			if ((fp = fopen(path1, "r+b")) != NULL)
			{
				rewind(fp);

				fread(work2, count * sizeof(structWork), 1, fp);

				for (int i = 0; i < count; i++)
				{
					if (((work2 + i)->workGivenTimeHour - (work2 + i)->workSpendedTimeHour) >= 2)
					{
						(work2 + i)->workValueOfWork *= 1.20;
						PrintInfoWork((work2 + i), 1);
					}

				}

			}
			fclose(fp);
			printf("\n");
			if ((fp = fopen(path2, "w+b")) != NULL) // создаем бинарный файл для чтения/записи
			{
				fwrite(work2, count * sizeof(structWork), 1, fp);
			}
			fclose(fp);

			structWork *work3 = (structWork*)calloc(count, sizeof(structWork));
			DrawLine();
			printf("Записываем данные в файл 01.work2.txt\n");

			if ((fp = fopen(path2, "r+b")) != NULL) // создаем бинарный файл для чтения/записи
			{
				fread(work3, count * sizeof(structWork), 1, fp);
				PrintInfoWork(work3, count);
			}
			DrawLine();
			fclose(fp);

			printf("\n");
			system("pause");
			system("cls");
		}break;

		case 2:
		{
			/*2. Создать бинарный файл, компонентами которого является
			структура, содержащая следующие поля:
			a. название лекарства;
			b. срок хранения лекарства;
			c. дата продажи лекарства;
			d. стоимость лекарства.
			e. Переписать бинарный файл так, чтобы стоимость лекарства
			была бы снижена на 20%, если на момент продажи срок хранения
			лекарства превысил 3 года. */

			char path1[30] = "02.remedy1.txt";
			char path2[30] = "02.remedy2.txt";

			int count = 5;

			structRemedy *remedy;
			DrawLine();
			printf("Записываем данные в файл 01.remedy1.txt\n");

			remedy = CreateRemedy(&count);

			PrintInfoRemedy(remedy, count);

			if ((fp = fopen(path1, "w+b")) != NULL)
			{
				fwrite(remedy, count * sizeof(structRemedy), 1, fp);
			}
			else
			{
				printf("Ошибка!");
				exit(1);
			}
			DrawLine();
			fclose(fp);

			printf("\n");

			structRemedy *remedy2 = (structRemedy*)calloc(count, sizeof(structRemedy));
			DrawLine();
			printf("Считываем данные из файла 01.remedy1.txt\n");
			printf("Увеличиваем стоимость лекарства на 20%%: \n");

			if ((fp = fopen(path1, "r+b")) != NULL)
			{
				rewind(fp);

				fread(remedy2, count * sizeof(structRemedy), 1, fp);

				for (int i = 0; i < count; i++)
				{
					if ((
						((remedy2 + i)->remedyPurchaseDate.intDay + (remedy2 + i)->remedyPurchaseDate.intMonth * 12 + (remedy2 + i)->remedyPurchaseDate.intYear * 365) -
						((remedy2 + i)->remedyMadeDate.intDay + (remedy2 + i)->remedyMadeDate.intMonth * 12 + (remedy2 + i)->remedyMadeDate.intYear * 365)) >= 1095) // 3 года в днях
					{
						(remedy2 + i)->remedyPrice *= 0.80;
						PrintInfoRemedy((remedy2 + i), 1);
					}

				}

			}
			fclose(fp);
			DrawLine();
			printf("\n");

			if ((fp = fopen(path2, "w+b")) != NULL) // создаем бинарный файл для чтения/записи
			{
				fwrite(remedy2, count * sizeof(structRemedy), 1, fp);
			}
			fclose(fp);

			structRemedy *remedy3 = (structRemedy*)calloc(count, sizeof(structRemedy));
			DrawLine();
			printf("Записываем данные в файл 01.remedy2.txt\n");

			if ((fp = fopen(path2, "r+b")) != NULL) // создаем бинарный файл для чтения/записи
			{
				fread(remedy3, count * sizeof(structWork), 1, fp);
				PrintInfoRemedy(remedy3, count);
			}

			fclose(fp);
			DrawLine();

			printf("\n");
			system("pause");
			system("cls");

		}break;

		case 3:
		{
			/* 3. Создать бинарный файл с информацией об авторе и его книгах:
			a. автор;
			b. название книги;
			c. тираж;
			d. цена экземпляра книги;
			e. год издания.
			f. Распечатать информацию о всех авторах, которые в своих названиях
			используют ключевое слово «Убийство». */

			char path1[30] = "03.book1.txt";
			char path2[30] = "03.book2.txt";

			int count = 5;

			structBookInfo *book;
			DrawLine();
			printf("Записываем данные в файл 03.book1.txt\n");

			book = CreateBook(&count);

			PrintInfoBook(book, count);

			if ((fp = fopen(path1, "w+b")) != NULL)
			{
				fwrite(book, count * sizeof(structBookInfo), 1, fp);
			}
			else
			{
				printf("Ошибка!");
				exit(1);
			}

			fclose(fp);
			DrawLine();
			printf("\n");

			structBookInfo *book2 = (structBookInfo*)calloc(count, sizeof(structBookInfo));
			DrawLine();
			printf("Считываем данные из файла 03.book1.txt\n");
			printf("Информация о всех авторах, которые в своих названиях используют ключевое слово «Убийство»: \n");

			if ((fp = fopen(path1, "r+b")) != NULL)
			{
				rewind(fp);

				fread(book2, count * sizeof(structBookInfo), 1, fp);

				for (int i = 0; i < count; i++)
				{
					if ((strstr((book2 + i)->bookTitle.charBookTitle, "Убийство") != 0 || strstr((book2 + i)->bookTitle.charBookTitle, "убийство") != 0))
					{
						PrintInfoBook((book2 + i), 1);
					}

				}

			}
			fclose(fp);
			DrawLine();
			printf("\n");
			DrawLine();
			printf("Записываем данные в файл 03.book2.txt\n");

			if ((fp = fopen(path2, "w+b")) != NULL) // создаем бинарный файл для чтения/записи
			{
				fwrite(book2, count * sizeof(structBookInfo), 1, fp);
			}
			fclose(fp);

			structBookInfo *book3 = (structBookInfo*)calloc(count, sizeof(structBookInfo));

			if ((fp = fopen(path2, "r+b")) != NULL) // создаем бинарный файл для чтения/записи
			{
				fread(book3, count * sizeof(structBookInfo), 1, fp);
				PrintInfoBook(book3, count);
			}

			fclose(fp);
			DrawLine();
			printf("\n");
			system("pause");
			system("cls");

		}break;

		case 4:
		{
			/* 4. Создать бинарный файл с информацией об автомобилях:
			a. марка автомобиля;
			b. производитель;
			c. год выпуска;
			d. тип двигателя;
			e. общий пробег в км;
			f. цена.
			Вывести сведения об автомобилях, у которых пробег составляет
			менее 100 км с ценой менее 200000 тенге. */

			char path1[30] = "04.car1.txt";
			char path2[30] = "04.car2.txt";

			int count = 5;

			structCar *car;
			DrawLine();
			printf("Записываем данные в файл 04.car1.txt\n");

			car = CreateCar(&count);

			PrintInfoCar(car, count);

			if ((fp = fopen(path1, "w+b")) != NULL)
			{
				fwrite(car, count * sizeof(structCar), 1, fp);
			}
			else
			{
				printf("Ошибка!");
				exit(1);
			}
			DrawLine();
			fclose(fp);

			printf("\n");

			structCar *car2 = (structCar*)calloc(count, sizeof(structCar));
			DrawLine();
			printf("Считываем данные из файла 04.car1.txt\n");
			printf("Сведения об автомобилях, у которых пробег составляет менее 100 км с ценой менее 200000 тенге:\n");

			if ((fp = fopen(path1, "r+b")) != NULL)
			{
				rewind(fp);

				fread(car2, count * sizeof(structCar), 1, fp);

				for (int i = 0; i < count; i++)
				{
					if ((car2 + i)->carTotalDistance<100 && (car2 + i)->carPrice<200000)
					{
						PrintInfoCar((car2 + i), 1);
					}

				}

			}
			fclose(fp);
			DrawLine();
			printf("\n");
			DrawLine();
			printf("Записываем данные в файл 04.car2.txt\n");

			if ((fp = fopen(path2, "w+b")) != NULL) // создаем бинарный файл для чтения/записи
			{
				fwrite(car2, count * sizeof(structCar), 1, fp);
			}
			fclose(fp);

			structCar *car3 = (structCar*)calloc(count, sizeof(structCar));

			if ((fp = fopen(path2, "r+b")) != NULL) // создаем бинарный файл для чтения/записи
			{
				fread(car3, count * sizeof(structCar), 1, fp);
				PrintInfoCar(car3, count);
			}


			fclose(fp);
			DrawLine();
			system("pause");
			system("cls");

		}break;

		case 5:
		{
			/* 5. Создать бинарный файл, компонентами которого является структура, содержащая следующие поля:
			a. фамилия и инициалы студентов;
			b. номер группы;
			c. успеваемость (массив из трех дисциплин);
			d. размер стипендии.
			e. Переписать бинарный файл так, чтобы для студентов, у которых
			есть хотя бы одна двойка, размер стипендии должен быть уменьшен на 20%.*/

			char path1[30] = "05.student1.txt";
			char path2[30] = "05.student2.txt";

			int count = 5;

			structStudent *student;

			DrawLine();
			printf("Записываем данные в файл 05.student1.txt\n");

			student = CreateStudent(&count);

			PrintInfoStudent(student, count);

			if ((fp = fopen(path1, "w+b")) != NULL)
			{
				fwrite(student, count * sizeof(structStudent), 1, fp);
			}
			else
			{
				printf("Ошибка!");
				exit(1);
			}

			fclose(fp);

			//DrawLine();
			//printf("\n");
			//DrawLine();

			structStudent *student2 = (structStudent*)calloc(count, sizeof(structStudent));

			DrawLine();
			printf("Считываем данные из файла 05.student1.txt\n");
			printf("Студенты, у которых есть хотя бы одна двойка, размер стипендии уменьшен на 20%%:\n");

			if ((fp = fopen(path1, "r+b")) != NULL)
			{
				rewind(fp);

				fread(student2, count * sizeof(structStudent), 1, fp);

				int flag = 0;

				for (int i = 0; i < count; i++)
				{

					for (int j = 0; j < 3; j++)
					{
						if ((student2 + i)->studentPerformance[j].intMark == 2)
						{
							(student2 + i)->studentGrant *= 0.80;
							flag = 1;
							break;
						}
					}
					if (flag)
						PrintInfoStudent((student2 + i), 1);
					flag = 0;
					//DrawLine();
				}
			}
			fclose(fp);

			//DrawLine();
			//printf("\n");
			DrawLine();

			printf("Записываем данные в файл 05.student2.txt\n");

			if ((fp = fopen(path2, "w+b")) != NULL) // создаем бинарный файл для чтения/записи
			{
				fwrite(student2, count * sizeof(structStudent), 1, fp);
			}
			fclose(fp);

			structStudent *student3 = (structStudent*)calloc(count, sizeof(structStudent));

			if ((fp = fopen(path2, "r+b")) != NULL) // создаем бинарный файл для чтения/записи
			{
				fread(student3, count * sizeof(structStudent), 1, fp);
				PrintInfoStudent(student3, count);
			}

			fclose(fp);

			//DrawLine();
			printf("\n");
			system("pause");
			system("cls");

		}break;



		}
	} while (n != 0);

}
