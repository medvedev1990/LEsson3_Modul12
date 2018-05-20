struct structDate
{
	int intDay;
	int intMonth;
	int intYear;
};

struct structPeopleFullName
{
	char charLastName[10];
	char charFirstName[10];
	char charMiddleName[10];
};


/* Задание 1 */
struct structWorkNomination
{
	char charWorkNomination[30];
};

struct structWork
{
	int workGivenTimeHour; // выделенное количество часов на выполнение данной работы
	int workSpendedTimeHour; // реально затраченное время на выполнение работы 
	int workValueOfWork; // стоимость работы 
	structWorkNomination workNomination; // наименование работы; 
};

/* Задание 2 */
struct structRemedyNomination
{
	char charRemedyNomination[10];
};

struct structRemedy
{
	structRemedyNomination remedyNomination; // название лекарства
	int remedyStorageTime; //срок хранения лекарства (в годах)
	structDate remedyMadeDate; // дата изготовления лекарства
	structDate remedyPurchaseDate; // дата продажи лекарства
	int remedyPrice; // стоимость лекарства 
};

/* Задание 3 */
struct structBookTitle
{
	char charBookAuthorLastName[15];
	char charBookAuthorFirstName[15];
	char charBookTitle[50]; // название книги; 
};


struct structBookInfo
{
	structBookTitle bookTitle; // автор; 
	int bookPrintRun; // тираж; 
	int bookPrice; // цена экземпляра книги; 
	structDate bookIssueDate; // год издания
};

/* Задание 4 */
struct structCarType
{
	char charCarType[10];
};

struct structCarMake
{
	char charCarMake[10];
};

struct structCarEngeneType
{
	char charCarEngeneType[10];
};

struct structCar
{
	structCarType carType; // марка автомобиля, тип кузова (седан, хечбек, универсал, кабриолет)
	structCarMake carMake; // производитель; 
	structDate carYearOfIssue; // год выпуска; 
	structCarEngeneType carEngeneType; // тип двигателя (бензиновый, дизельный, газовый)
	int carTotalDistance; // общий пробег в км; 
	int carPrice; // цена
};

/* Задание 5 */
struct structDiscipline
{
	char charDiscipline[10]; // дисциплина
	int intMark; // оценка по дисциплине
};

struct structStudent
{
	structPeopleFullName studentFullName; // фамилия и инициалы студентов; 
	char studentGroupName[4]; // название группы
	int studentGroupNumber; // номер группы; 
	structDiscipline studentPerformance[3]; // успеваемость (массив из трех дисциплин); 
	int studentGrant; // размер стипендии
};


