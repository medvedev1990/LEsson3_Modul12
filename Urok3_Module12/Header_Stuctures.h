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


/* ������� 1 */
struct structWorkNomination
{
	char charWorkNomination[30];
};

struct structWork
{
	int workGivenTimeHour; // ���������� ���������� ����� �� ���������� ������ ������
	int workSpendedTimeHour; // ������� ����������� ����� �� ���������� ������ 
	int workValueOfWork; // ��������� ������ 
	structWorkNomination workNomination; // ������������ ������; 
};

/* ������� 2 */
struct structRemedyNomination
{
	char charRemedyNomination[10];
};

struct structRemedy
{
	structRemedyNomination remedyNomination; // �������� ���������
	int remedyStorageTime; //���� �������� ��������� (� �����)
	structDate remedyMadeDate; // ���� ������������ ���������
	structDate remedyPurchaseDate; // ���� ������� ���������
	int remedyPrice; // ��������� ��������� 
};

/* ������� 3 */
struct structBookTitle
{
	char charBookAuthorLastName[15];
	char charBookAuthorFirstName[15];
	char charBookTitle[50]; // �������� �����; 
};


struct structBookInfo
{
	structBookTitle bookTitle; // �����; 
	int bookPrintRun; // �����; 
	int bookPrice; // ���� ���������� �����; 
	structDate bookIssueDate; // ��� �������
};

/* ������� 4 */
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
	structCarType carType; // ����� ����������, ��� ������ (�����, ������, ���������, ���������)
	structCarMake carMake; // �������������; 
	structDate carYearOfIssue; // ��� �������; 
	structCarEngeneType carEngeneType; // ��� ��������� (����������, ���������, �������)
	int carTotalDistance; // ����� ������ � ��; 
	int carPrice; // ����
};

/* ������� 5 */
struct structDiscipline
{
	char charDiscipline[10]; // ����������
	int intMark; // ������ �� ����������
};

struct structStudent
{
	structPeopleFullName studentFullName; // ������� � �������� ���������; 
	char studentGroupName[4]; // �������� ������
	int studentGroupNumber; // ����� ������; 
	structDiscipline studentPerformance[3]; // ������������ (������ �� ���� ���������); 
	int studentGrant; // ������ ���������
};


