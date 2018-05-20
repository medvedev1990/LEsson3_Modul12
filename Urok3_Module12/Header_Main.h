#include "Header_Stuctures.h"

void DrawLine();
void CreateName(char *name, int len);
void CreatePeopleFullName(structPeopleFullName * name, int len);
void GenerateDate(structDate *date);

/* Задание 1 */
void GenerateWorkNomination(structWorkNomination *work);
void PrintInfoWork(structWork * work, int len);
structWork *CreateWork(int *count);

/* Задание 2 */
void GenerateDateRemedyMade(structDate *date);
void GenerateDateRemedyPurchase(structDate *date);
void GenerateRemedyNomination(structRemedyNomination *remedy);
void PrintInfoRemedy(structRemedy * remedy, int len);
structRemedy *CreateRemedy(int *count);

/* Задание 3 */
void PrintInfoBook(structBookInfo * book, int len);
void GenerateBookTitle(structBookTitle *book);
structBookInfo *CreateBook(int *count);

/* Задание 4 */
void GenerateCarType(structCarType *Car);
void GenerateCarMake(structCarMake *Car);
void GenerateCarEngeneType(structCarEngeneType *Car);
void PrintInfoCar(structCar * car, int len);
structCar *CreateCar(int *count);

/* Задание 5 */
void CreateGoupeName(char *name);
void GenerateDiscipline(structDiscipline *subject, int num);
void PrintInfoStudent(structStudent * student, int len);
structStudent *CreateStudent(int *count);



