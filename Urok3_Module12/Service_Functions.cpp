#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<locale.h>
#include<time.h>
#include "Header_Main.h"

void DrawLine()
{
	printf("-------------------------------------------------------------------------------------------------------------------------------\n");
}

void CreateName(char *name, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		if (i == 0)
			*(name + i) = (char)(65 + rand() % 24);
		else
			*(name + i) = (char)(97 + rand() % 24);
	}
	*(name + len) = '\0';

}

void CreatePeopleFullName(structPeopleFullName * name, int len)
{
	CreateName(name->charLastName, len);
	CreateName(name->charLastName, len);
	CreateName(name->charMiddleName, len);
}

void GenerateDate(structDate *date)
{
	date->intDay = 1 + rand() % 31;
	date->intMonth = 1 + rand() % 12;
	date->intYear = 1940 + rand() % 60;
}

/* Задание 1 */

void GenerateWorkNomination(structWorkNomination *work)
{
	int num;
	num = 0 + rand() % 4;

	switch (num)
	{
	case 0:
		strcpy(work->charWorkNomination, "Создание Web-сайта");
		break;

	case 1:
		strcpy(work->charWorkNomination, "Создание мобильного приложения");
		break;

	case 2:
		strcpy(work->charWorkNomination, "Ремонт компьютера");
		break;

	case 3:
		strcpy(work->charWorkNomination, "Консультация специалиста");
		break;
	}
}

void PrintInfoWork(structWork * work, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("#%2d. Наименование работы: %s, веделенное время: %d часов, затраченное время: %d часов, стоимость работы: %d\n",
			i + 1,
			(work + i)->workNomination.charWorkNomination,
			(work + i)->workGivenTimeHour,
			(work + i)->workSpendedTimeHour,
			(work + i)->workValueOfWork);
		//printf("\n");
	}
}

structWork *CreateWork(int *count)
{
	structWork *work = (structWork*)calloc(*count, sizeof(structWork));
	if (work != NULL)
	{
		for (int i = 0; i < *count; i++)
		{
			GenerateWorkNomination(&(work + i)->workNomination);
			(work + i)->workGivenTimeHour = 3 + rand() % 6;
			(work + i)->workSpendedTimeHour = 4 + rand() % 5;
			(work + i)->workValueOfWork = 10000 + rand() % 20000;
		}
	}
	else
	{
		printf("Ошибка!");
		exit(1);
	}
	return work;
}

/* Задание 2 */
void GenerateDateRemedyMade(structDate *date)
{
	date->intDay = 1 + rand() % 31;
	date->intMonth = 1 + rand() % 12;
	date->intYear = 2013 + rand() % 2;
}

void GenerateDateRemedyPurchase(structDate *date)
{
	date->intDay = 1 + rand() % 31;
	date->intMonth = 1 + rand() % 12;
	date->intYear = 2015 + rand() % 3;
}


void GenerateRemedyNomination(structRemedyNomination *remedy)
{
	int num;
	num = 0 + rand() % 4;

	switch (num)
	{
	case 0:
		strcpy(remedy->charRemedyNomination, "Панадол");
		break;

	case 1:
		strcpy(remedy->charRemedyNomination, "Парацетамол");
		break;

	case 2:
		strcpy(remedy->charRemedyNomination, "Цитрамон");
		break;

	case 3:
		strcpy(remedy->charRemedyNomination, "Аспирин");
		break;
	}
}

void PrintInfoRemedy(structRemedy * remedy, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("#%2d. Наименование лекарства: %s, срок хранения (в годах): %d, дата изготовления: %d.%d.%d, дата продажи: %d.%d.%d, стоимость лекарства: %d\n",
			i + 1,
			(remedy + i)->remedyNomination.charRemedyNomination,
			(remedy + i)->remedyStorageTime,
			(remedy + i)->remedyMadeDate.intDay,
			(remedy + i)->remedyMadeDate.intMonth,
			(remedy + i)->remedyMadeDate.intYear,
			(remedy + i)->remedyPurchaseDate.intDay,
			(remedy + i)->remedyPurchaseDate.intMonth,
			(remedy + i)->remedyPurchaseDate.intYear,
			(remedy + i)->remedyPrice);
	}
}

structRemedy *CreateRemedy(int *count)
{
	structRemedy *remedy = (structRemedy*)calloc(*count, sizeof(structRemedy));
	if (remedy != NULL)
	{
		for (int i = 0; i < *count; i++)
		{
			GenerateRemedyNomination(&(remedy + i)->remedyNomination);
			(remedy + i)->remedyStorageTime = 2 + rand() % 5;
			GenerateDateRemedyMade(&(remedy + i)->remedyMadeDate);
			GenerateDateRemedyPurchase(&(remedy + i)->remedyPurchaseDate);
			(remedy + i)->remedyPrice = 100 + rand() % 200;
		}
	}
	else
	{
		printf("Ошибка!");
		exit(1);
	}
	return remedy;
}

/* Задание 3 */

void GenerateBookTitle(structBookTitle *book)
{
	int num;
	num = 0 + rand() % 4;

	switch (num)
	{
	case 0:
		strcpy(book->charBookAuthorLastName, "Кристи");
		strcpy(book->charBookAuthorFirstName, "Агата");
		strcpy(book->charBookTitle, "Убийство в Восточном Экспрессе");
		break;

	case 1:
		strcpy(book->charBookAuthorLastName, "Хейр");
		strcpy(book->charBookAuthorFirstName, "Сирил");
		strcpy(book->charBookTitle, "Чисто английское убийство");
		break;

	case 2:
		strcpy(book->charBookAuthorLastName, "Толстой");
		strcpy(book->charBookAuthorFirstName, "Лев");
		strcpy(book->charBookTitle, "Война и мир");
		break;

	case 3:
		strcpy(book->charBookAuthorLastName, "Гоголь");
		strcpy(book->charBookAuthorFirstName, "Николай");
		strcpy(book->charBookTitle, "Ревизор");
		break;
	}
}

void PrintInfoBook(structBookInfo * book, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("#%2d. Наименование книги: %s, автор: %s %s, тираж: %d, год издания: %d.%d.%d, цена: %d\n",
			i + 1,
			(book + i)->bookTitle.charBookTitle,
			(book + i)->bookTitle.charBookAuthorFirstName,
			(book + i)->bookTitle.charBookAuthorLastName,
			(book + i)->bookPrintRun,
			(book + i)->bookIssueDate,
			(book + i)->bookPrice);
	}
}

structBookInfo *CreateBook(int *count)
{
	structBookInfo *book = (structBookInfo*)calloc(*count, sizeof(structBookInfo));
	if (book != NULL)
	{
		for (int i = 0; i < *count; i++)
		{
			GenerateBookTitle(&(book + i)->bookTitle);
			(book + i)->bookPrintRun = 10000 + rand() % 5000; // тираж
			(book + i)->bookPrice = 1000 + rand() % 2000;
			GenerateDate(&(book + i)->bookIssueDate);
		}
	}
	else
	{
		printf("Ошибка!");
		exit(1);
	}
	return book;
}

/* Задание 4 */

void GenerateCarType(structCarType *Car)
{
	int num;
	num = 0 + rand() % 4;

	switch (num)
	{
	case 0:
		strcpy(Car->charCarType, "Седан");
		break;

	case 1:
		strcpy(Car->charCarType, "Хечбек");
		break;

	case 2:
		strcpy(Car->charCarType, "Универсал");
		break;

	case 3:
		strcpy(Car->charCarType, "Кабриолет");
		break;
	}
}

void GenerateCarMake(structCarMake *Car)
{
	int num;
	num = 0 + rand() % 4;

	switch (num)
	{
	case 0:
		strcpy(Car->charCarMake, "BMW");
		break;

	case 1:
		strcpy(Car->charCarMake, "AUDI");
		break;

	case 2:
		strcpy(Car->charCarMake, "Mersedes");
		break;

	case 3:
		strcpy(Car->charCarMake, "Lada 2106");
		break;
	}
}

void GenerateCarEngeneType(structCarEngeneType *Car)
{
	int num;
	num = 0 + rand() % 4;

	switch (num)
	{
	case 0:
		strcpy(Car->charCarEngeneType, "бензиновый");
		break;

	case 1:
		strcpy(Car->charCarEngeneType, "дизельный");
		break;

	case 2:
		strcpy(Car->charCarEngeneType, "газовый");
		break;

	case 3:
		strcpy(Car->charCarEngeneType, "холодный термояд");
		break;
	}
}

void PrintInfoCar(structCar * car, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("#%2d. Производитель: %s, марка автомобиля: %s, год выпуска: %d.%d.%d, тип двигателя: %s, пробег: %d, цена: %d\n",
			i + 1,
			(car + i)->carMake.charCarMake,
			(car + i)->carType.charCarType,
			(car + i)->carYearOfIssue,
			(car + i)->carEngeneType.charCarEngeneType,
			(car + i)->carTotalDistance,
			(car + i)->carPrice);
	}
}

structCar *CreateCar(int *count)
{
	structCar *car = (structCar*)calloc(*count, sizeof(structCar));
	if (car != NULL)
	{
		for (int i = 0; i < *count; i++)
		{
			GenerateCarType(&(car + i)->carType);
			GenerateCarMake(&(car + i)->carMake);
			GenerateDate(&(car + i)->carYearOfIssue);
			GenerateCarEngeneType(&(car + i)->carEngeneType);
			(car + i)->carTotalDistance = 10 + rand() % 150;
			(car + i)->carPrice = 170000 + rand() % 100000;
		}
	}
	else
	{
		printf("Ошибка!");
		exit(1);
	}
	return car;
}


/* Задание 5 */
void CreateGoupeName(char *name)
{
	for (int i = 0; i < 3; i++)
	{
		*(name + i) = (char)(65 + rand() % 24);
	}
	*(name + 4) = '\0';

}

void GenerateDiscipline(structDiscipline *subject, int num)
{
	subject->intMark = 2 + rand() % 4;

	switch (num)
	{
	case 0:
		strcpy(subject->charDiscipline, "Физика");
		break;

	case 1:
		strcpy(subject->charDiscipline, "Математика");
		break;

	case 2:
		strcpy(subject->charDiscipline, "Информатика");
		break;
	}
}

void PrintInfoStudent(structStudent * student, int len)
{
	//DrawLine();
	for (int i = 0; i < len; i++)
	{
		DrawLine();
		printf("#%2d. ФИО: %s %s %s, номер группы: %s-%d, размер стипендии: %d\n",
			i + 1,
			(student + i)->studentFullName.charLastName,
			(student + i)->studentFullName.charFirstName,
			(student + i)->studentFullName.charMiddleName,
			(student + i)->studentGroupName,
			(student + i)->studentGroupNumber,
			(student + i)->studentGrant);
		for (int j = 0; j < 3; j++)
		{
			printf("предмет: %s - %d\n",
				(student + i)->studentPerformance[j].charDiscipline,
				(student + i)->studentPerformance[j].intMark);
		}
	}
	//DrawLine();
	printf("\n");
}

structStudent *CreateStudent(int *count)
{
	structStudent *student = (structStudent*)calloc(*count, sizeof(structStudent));
	if (student != NULL)
	{
		for (int i = 0; i < *count; i++)
		{
			CreatePeopleFullName(&(student + i)->studentFullName, 10);
			CreateGoupeName((student + i)->studentGroupName);
			(student + i)->studentGroupNumber = 100 + rand() % 555;
			for (int j = 0; j < 3; j++)
			{
				GenerateDiscipline(&(student + i)->studentPerformance[j], j);
			}
			(student + i)->studentGrant = 20000 + rand() % 50000;
		}
	}
	else
	{
		printf("Ошибка!");
		exit(1);
	}
	return student;
}

